
// Inspiration :
// Peter Meyers
// Eric Rorem
// Barry Schaudt
// Tony Leclerc
// Mark Vojkovich
// Jeff Ely

#include <X_graphics.h>

static int	 TheWidth ;
static int       TheHeight ;
static int	 TheDepth;

static Display	*TheDisplay;
static Window    TheRootWindow;
static int	 TheScreenNumber;
static Window	 TheWindow;
static Pixmap	 ThePixmap;
static XID	 TheDrawable;
static GC	 TheWindowContext;
static GC	 ThePixmapContext;


//static char         *TheFont = "9x15" ;
//static char         *TheFont = "8x13" ;
//static char         *TheFont = "9x15bold" ;
//static char         *TheFont = "6x9" ;
static char         *TheFont = "10x20" ;
//static char         *TheFont = "12x24" ;


static XFontStruct  *TheFontInfo;

static unsigned long Grays[256];



int Clear_Buffer_X() 
{
   unsigned long int p ;

   //   XSetForeground(TheDisplay, ThePixmapContext, 0);

   //   p = 0xffffff ; // white
   //   XSetForeground(TheDisplay, ThePixmapContext, p);

   // have decided that it is best to this to simply
   // use the color that was last instantiated
   // you want to avoid having a call to this inadvertently
   // also changing the "last" color and either of the codes
   // that is commented out above clearly did this

   XFillRectangle(TheDisplay, TheDrawable, ThePixmapContext, 
                                           0, 0, TheWidth, TheHeight);
   XFlush(TheDisplay);  
}



int Init_X (int swidth, int sheight)
{
    XGCValues vals;
    Colormap TheColormap;
    XColor TheColor;
    int i;

    TheWidth = swidth ;
    TheHeight = sheight ;


    TheDisplay = XOpenDisplay("\0");
    TheRootWindow = DefaultRootWindow(TheDisplay);
    TheScreenNumber = DefaultScreen(TheDisplay); 
    TheDepth = DefaultDepth(TheDisplay, TheScreenNumber);
    if (TheDepth != 24) {
      printf("24 bit color not supported.\n") ;
      printf("Color function not likely to work.\n") ;
    }
    TheWindow = XCreateSimpleWindow(TheDisplay, TheRootWindow,
                        0, 0, TheWidth, TheHeight, 0, 0, 0);

    if (!TheWindow) return 0 ;

    ThePixmap = XCreatePixmap(TheDisplay, TheRootWindow, TheWidth, TheHeight, 
				TheDepth);

    if (!ThePixmap) return 0 ;

    TheDrawable = ThePixmap;

    
    XMapWindow(TheDisplay, TheWindow);
    XSelectInput(TheDisplay, TheWindow, ExposureMask |
					StructureNotifyMask |
					PointerMotionMask | 
					ButtonPressMask |
					KeyPressMask );




    /*
    TheWindowContext = XCreateGC(TheDisplay, TheWindow, 0, 0);
    // this is a bad idea ... see test t02.c for an example
    // of what can happen to the behavior of the event handler,
    //       int Handle_Events_X(int *px, int *py)
    // if you do this, you'll get runaway calls to Handle_Events
    // with the default condition being met and this produces
    // a great deal of tearing in the animation of t02.c
    */




    /* also a bad idea...same behavior as above
    vals.graphics_exposures = 1; // True
    */

    // so this is what you want :
    vals.graphics_exposures = 0; // False
    TheWindowContext = XCreateGC(TheDisplay, TheWindow,
                                 GCGraphicsExposures, &vals);
    if (!TheWindowContext) return 0;


    ThePixmapContext = XCreateGC(TheDisplay, ThePixmap, 0, 0);
    if (!ThePixmapContext) return 0;


    TheColormap = DefaultColormap(TheDisplay, TheScreenNumber);
    for(i = 0; i < 256; i++) {
	TheColor.green = TheColor.blue = TheColor.red = (i << 8) | i;
	TheColor.flags = DoRed | DoGreen | DoBlue;
	XAllocColor(TheDisplay, TheColormap, &TheColor);
	Grays[i] = TheColor.pixel;
    }
 

    TheFontInfo = XLoadQueryFont(TheDisplay, TheFont) ;
    //    XSetFont(TheDisplay, TheWindowContext, TheFontInfo->fid) ;
    XSetFont(TheDisplay, ThePixmapContext, TheFontInfo->fid) ;




    //   XClearWindow(TheDisplay, TheWindow);
    //   XClearArea(TheDisplay, TheWindow, 0,0,0,0,False); // same as above
    XClearArea(TheDisplay, TheWindow, 0,0,0,0,True); 
                  // Does the boolean matter here?


    // most people expect a white piece of paper
    // with a black pencil
    Set_Color_Rgb_X (255,255,255) ; // white
    Clear_Buffer_X() ; // otherwise you can inherit garbage
    // from the parent window

    //    Set_Color_Rgb_X (255,0,255) ; // purple
    //    Fill_Rectangle_X(10,10,50,80) ;
    // above was just a test

    Copy_Buffer_X() ;
    XFlush(TheDisplay);  

    // XSync(TheDisplay, False) ; // seems unnecessary

    Set_Color_Rgb_X (0,0,0) ; // black pencil
    return 1 ;
}



int Close_Down_X()
{
    XDestroyWindow(TheDisplay, TheWindow);
    XFreeGC(TheDisplay, TheWindowContext);
    XFreeGC(TheDisplay, ThePixmapContext);
    XFreePixmap(TheDisplay, ThePixmap);
    XCloseDisplay(TheDisplay);
}





int Select_Gray_X (double color)
{
  int ci ;
   ci = (int)(color * 255.0) ;
   XSetForeground(TheDisplay, ThePixmapContext, Grays[ci]);
}



int Draw_Triangle_X_UN (double x0, double y0,
                        double x1, double y1,
                        double x2, double y2)
// this has been superseded
{
    XPoint Points[4];

    Points[0].x = (short int)x0 ;
    Points[0].y = (short int)y0 ;
    Points[1].x = (short int)x1 ;
    Points[1].y = (short int)y1 ;
    Points[2].x = (short int)x2 ;
    Points[2].y = (short int)y2 ;

    XFillPolygon(TheDisplay, TheDrawable, ThePixmapContext, Points, 3,
					Convex, CoordModeOrigin);

    /*
    XDrawLines(TheDisplay, TheDrawable, ThePixmapContext, Points, 4,
					CoordModeOrigin);
    */

    /*
    XDrawPoints(TheDisplay, TheDrawable, ThePixmapContext, Points, 3,
							CoordModeOrigin);
    */

}



int Copy_Buffer_X()
{
   XCopyArea(TheDisplay, ThePixmap, TheWindow, TheWindowContext,
	     0, 0, TheWidth, TheHeight, 0,0) ;
			
}

int Flush_X()
{
   XFlush(TheDisplay) ;
}


int Copy_Buffer_And_Flush_X()
{
   XCopyArea(TheDisplay, ThePixmap, TheWindow, TheWindowContext,
	     0, 0, TheWidth, TheHeight, 0,0) ;
   XFlush(TheDisplay) ;

}


int Sync_X (int bool_val)
{
   XSync(TheDisplay, bool_val) ;
}





int Send_Expose_Event()
{
  XExposeEvent e ;
  //  XEvent e ;
  // doesn't look like you have to actually fill in any
  // of the subfields of e

  e.type = Expose ;
  //e.serial
  e.send_event = 1 ;
  e.display = TheDisplay ;
  //  e.window = TheWindow ;
  e.window = PointerWindow ;
  //  e.window = InputFocus ;
  //e.x
  //e.y
  //e.width
  //e.height
  e.count = 1 ;

  // XSendEvent (TheDisplay, TheWindow, 0, 0 , (XEvent *)&e) ;
  XSendEvent (TheDisplay, TheWindow, 0, ExposureMask, (XEvent *)&e) ;
  // XSendEvent (TheDisplay, TheWindow, 1, ExposureMask, &e) ;

}



int Handle_Events_X(int *px, int *py)
{
    int DummyInt;
    Window DummyWindow;
    XEvent event;
    int x,y ;
    KeySym keysym ;
    char buffer[10] ;
    int bufsize = 10 ;
    XComposeStatus compose ;



MORE_EVENTS:

    XNextEvent(TheDisplay, &event);

    switch(event.type) {


    case Expose:

      //      printf("An Expose event has occurred\n") ;

        Copy_Buffer_And_Flush_X() ;
             // this is new ... when the window is uncovered
	     // this will regenerate it from the buffer

	*px = 0 ; *py = 0 ;
        return -1 ;
	break;	


    case MotionNotify:

      /*
        // This will give coords relative to the upper left of the
        // physical device (?)/ root window (?) NOT the window
        // being displayed
	x = event.xmotion.x_root;
	y = event.xmotion.y_root;
      */


        // while this gives coords relative to the upper left
        // of the window being displayed...so, for example,
        // suppose we target mouse movement around the center
        // of the window that is being displayed.  this will give
        // a certain (x,y). suppose we drag the window and 
        // then again target mouse movement near the center of
        // the moved window.  this will give the same (x,y).

	x = event.xmotion.x ;
	y = event.xmotion.y ;
	// this will also give "correct" values if the motion
	// of the mouse carries it off the window


        y = TheHeight-1 - y ;

	if(event.xmotion.state & Button3Mask) {
	    *px = x ;	    *py = y ;
	} else 
	if(event.xmotion.state & Button1Mask) {
	    *px = x ;	    *py = y ;
	} else {
	    goto MORE_EVENTS;
	}

	return -2 ;
	break;


    case ButtonPress:

      /*
        // This will give coords relative to the upper left of the
        // physical device (?)/ root window (?) NOT the window
        // being displayed
	XQueryPointer(TheDisplay, TheWindow, &DummyWindow, &DummyWindow,
				&x, &y, &DummyInt, &DummyInt, &DummyInt);
      */


        // while this gives coords relative to the upper left
        // of the window being displayed...so, for example,
        // suppose we click the mouse at the center
        // of the window that is being displayed.  this will give
        // a certain (x,y). suppose we drag the window and 
        // then again click the mouse at the center of
        // the moved window.  this will give the same (x,y).
        x = event.xbutton.x ;
        y = event.xbutton.y ;


        y = TheHeight-1 - y ;

        *px = x ; *py = y ;

	return -3 ;
	break;


    case ConfigureNotify:

	if((event.xconfigure.width == TheWidth) &&
	  (event.xconfigure.height == TheHeight)){ break; }

	TheWidth = event.xconfigure.width;
	TheHeight = event.xconfigure.height;

	XFreePixmap(TheDisplay, ThePixmap);
	ThePixmap = XCreatePixmap(TheDisplay, TheRootWindow,
                                      TheWidth, TheHeight, TheDepth);
	XClearWindow(TheDisplay, TheWindow);

        TheDrawable = ThePixmap;

	*px = TheWidth ; *py = TheHeight ;
	return -4 ;
	break;		


    case KeyPress:

        XLookupString (&(event.xkey), buffer, bufsize, &keysym, &compose) ;
	*px = 0 ; *py = 0 ;
	return keysym;
	break;


    default:

	*px = 0 ; *py = 0 ;
        return -5 ;
	break;

    }

    if(XPending(TheDisplay)) {
	goto MORE_EVENTS;
    }


    *px = 0 ; *py = 0 ;
    return -6 ; // This actually does happen
                //e.g when you move the window.
    // I think the reason the default doesn't pick
    // that case up is that such an action isn't
    // placed on the display event queue because
    // of the way Init_X has set things up with
    // XSelectInput(...

}



int Get_Events_X (int *d)
// d needs to point to 2 or more ints
// merely repackages Handle_Events_X
{
  int s,x,y ;
  s = Handle_Events_X (&x,&y) ;
  d[0] = x ; 
  d[1] = y ;
  return s ;
}


int Get_Events_DX (double *d)
// d needs to point to 2 or more doubles
// merely repackages Handle_Events_X
{
  int s,x,y ;
  s = Handle_Events_X (&x,&y) ;
  d[0] = x ; 
  d[1] = y ;
  return s ;
}



////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////




int Set_Color_Rgb_X (int r, int g, int b)
{
  unsigned long int p ;

  if (r < 0) r = 0 ; else if (r > 255) r = 255 ;
  if (g < 0) g = 0 ; else if (g > 255) g = 255 ;
  if (b < 0) b = 0 ; else if (b > 255) b = 255 ;

  p = (r << 16) | (g  << 8) | (b) ;
  XSetForeground(TheDisplay, ThePixmapContext, p) ;
}



int Set_Color_Rgb_DX (double dr, double dg, double db)
{
  int r,g,b ;
  unsigned long int p ;

  r = (int)(255*dr) ;
  g = (int)(255*dg) ;
  b = (int)(255*db) ;

  if (r < 0) r = 0 ; else if (r > 255) r = 255 ;
  if (g < 0) g = 0 ; else if (g > 255) g = 255 ;
  if (b < 0) b = 0 ; else if (b > 255) b = 255 ;

  p = (r << 16) | (g  << 8) | (b) ;
  XSetForeground(TheDisplay, ThePixmapContext, p) ;
}






int Point_X (int x, int y) 
{
    XDrawPoint(TheDisplay, TheDrawable, ThePixmapContext, 
               x, TheHeight - 1 - y) ;
}




int Safe_Point_X (int x, int y)
{
    if ((x < 0) || (y < 0) || (x >= TheWidth) || (y >= TheHeight)) {return 0 ;}
    XDrawPoint(TheDisplay, TheDrawable, ThePixmapContext,
               x,  TheHeight - 1 - y) ;
    return 1 ;
}





int Line_X (int xs, int ys, int xe, int ye)
{
    XDrawLine (TheDisplay, TheDrawable, ThePixmapContext,
               xs, TheHeight-1-ys,
               xe, TheHeight-1-ye);
}






int Safe_Line_X (int ixs, int iys, int ixe, int iye)
{
  double xs, ys, xe, ye ; // doubles for accuracy in clipping 
  double t, xedge, yedge ;


  if (  (ixs >= 0 ) && (ixs < TheWidth)  
     && (ixe >= 0 ) && (ixe < TheWidth)  
     && (iys >= 0 ) && (iys < TheHeight)  
     && (iye >= 0 ) && (iye < TheHeight)  ) {

    XDrawLine (TheDisplay, TheDrawable, ThePixmapContext,
               ixs, TheHeight-1-iys,
               ixe, TheHeight-1-iye );

    return 1 ;

  }





  xs = ixs ; ys = iys ; xe = ixe ; ye = iye ;

// start to end 
// in       in      leave line alone...draw it all 
// in      out      replace end 
// out      in      replace start 
// out     out      don't draw the line 


// clip against all 4 sides of screen 



// first clip against y = 0 

 yedge = 0 ;
 if (ys >= yedge) {
     if (ye >= yedge) {
         // start is in, end is in , leave alone...next test 
     }
     else {
         // start is in, end is out, replace end...next test 
         t = (yedge - ys)/(ye - ys) ; 
             // ye cannot be ys .. no div by 0 worry 
         xe = xs + t*(xe - xs) ;
         ye = yedge ;
     }
 } else {
     if (ye >= yedge) {
         //start is out, end is in, replace start...next test 
         t = (yedge - ys)/(ye - ys) ; 
             // ye cannot be ys .. no div by 0 worry 
         xs = xs + t*(xe - xs) ;
         ys = yedge ;

     }
     else {
         // both are out...don't draw line at all 
         goto CLend ;
     }
 }

// second, clip against y = TheHeight - 1 

 yedge = TheHeight - 1 ;
 if (ys <= yedge) {
     if (ye <= yedge) {
         // start is in, end is in , leave alone...next test 
     }
     else {
         // start is in, end is out, replace end...next test 
         t = (yedge - ys)/(ye - ys) ; 
             // ye cannot be ys .. no div by 0 worry 
         xe = xs + t*(xe - xs) ;
         ye = yedge ;
     }
 } else {
     if (ye <= yedge) {
         //start is out, end is in, replace start...next test 
         t = (yedge - ys)/(ye - ys) ; 
             // ye cannot be ys .. no div by 0 worry 
         xs = xs + t*(xe - xs) ;
         ys = yedge ;

     }
     else {
         // both are out...don't draw line at all 
         goto CLend ;
     }
 }


// third, clip against x = 0 

 xedge = 0 ;
 if (xs >= xedge) {
     if (xe >= xedge) {
         // start is in, end is in , leave alone...next test 
     }
     else {
         // start is in, end is out, replace end...next test 
         t = (xedge - xs)/(xe - xs) ; 
             // xe cannot be xs .. no div by 0 worry 
         ye = ys + t*(ye - ys) ;
         xe = xedge ;
     }
 } else {
     if (xe >= xedge) {
         //start is out, end is in, replace start...next test 
         t = (xedge - xs)/(xe - xs) ; 
             // xe cannot be xs .. no div by 0 worry 
         ys = ys + t*(ye - ys) ;
         xs = xedge ;

     }
     else {
         // both are out...don't draw line at all 
         goto CLend ;
     }
 }

// finally, clip against x = TheWidth - 1 

 xedge = TheWidth - 1 ;
 if (xs <= xedge) {
     if (xe <= xedge) {
         // start is in, end is in , leave alone...next test 
     }
     else {
         // start is in, end is out, replace end...next test 
         t = (xedge - xs)/(xe - xs) ; 
             // xe cannot be xs .. no div by 0 worry 
         ye = ys + t*(ye - ys) ;
         xe = xedge ;
     }
 } else {
     if (xe <= xedge) {
         //start is out, end is in, replace start...next test 
         t = (xedge - xs)/(xe - xs) ; 
             // xe cannot be xs .. no div by 0 worry 
         ys = ys + t*(ye - ys) ;
         xs = xedge ;

     }
     else {
         // both are out...don't draw line at all 
         goto CLend ;
     }
 }


    XDrawLine (TheDisplay, TheDrawable, ThePixmapContext,
               (int)xs, (int)(TheHeight-1-ys),
               (int)xe, (int)(TheHeight-1-ye) );


 CLend : 

    return 1 ;

}





int Rectangle_X (int xlow, int ylow, int width, int height) 
{
    XDrawRectangle(TheDisplay, TheDrawable, ThePixmapContext,
                   xlow,  TheHeight-1-ylow-height,
                   width,height);
}




int Fill_Rectangle_X (int xlow, int ylow, int width, int height)
{
    XFillRectangle(TheDisplay, TheDrawable, ThePixmapContext,
                   xlow, TheHeight-1-ylow-height,
                   width, height);
}



int Triangle_X (int x1, int y1, 
                 int x2, int y2,
                 int x3, int y3)
{
  XPoint Points[4];

  Points[0].x = (x1);
  Points[0].y = (TheHeight-1-y1);
  Points[1].x = (x2);
  Points[1].y = (TheHeight-1-y2);
  Points[2].x = (x3);
  Points[2].y = (TheHeight-1-y3);
  Points[3].x = Points[0].x;
  Points[3].y = Points[0].y;

  XDrawLines(TheDisplay, TheDrawable,ThePixmapContext,
                               Points, 4, CoordModeOrigin);
}




int Fill_Triangle_X (int x1, int y1,
                      int x2, int y2,
                      int x3, int y3)
{
  XPoint Points[3];

  Points[0].x = (x1);
  Points[0].y = (TheHeight-1-y1);
  Points[1].x = (x2);
  Points[1].y = (TheHeight-1-y2);
  Points[2].x = (x3);
  Points[2].y = (TheHeight-1-y3);


  XFillPolygon(TheDisplay, TheDrawable, ThePixmapContext,
                Points, 3, Convex, CoordModeOrigin);
}





int Polygon_X (int *x, int *y, int npts)
{
   XPoint xpoint[1000] ;
   int k ;

   if (npts <= 0) return 0 ;

   if (npts > 1000) {
      printf("\nPolygon+X has been asked to deal with %d points.\n",
             npts) ;
      printf("Points past first 1000 ignored.\n") ;
      npts = 1000 ;
   }

   for (k = 0 ; k < npts ; k++) {
        xpoint[k].x = x[k] ; 
        xpoint[k].y = TheHeight -1 - y[k] ;
   }

   XDrawLines(TheDisplay,TheDrawable,ThePixmapContext,
                       xpoint,npts,  CoordModeOrigin);
   XDrawLine(TheDisplay,TheDrawable,ThePixmapContext,
                    xpoint[0].x, xpoint[0].y,
                         xpoint[npts-1].x, xpoint[npts-1].y ) ;

   return 1 ;
}



int Polygon_DX (double *x, double *y, int npts)
{

   XPoint xpoint[1000] ;
   int k ;

   if (npts <= 0) return 0 ;

   if (npts > 1000) {
      printf("\nPolygon+X has been asked to deal with %d points.\n",
             npts) ;
      printf("Points past first 1000 ignored.\n") ;
      npts = 1000 ;
   }

   for (k = 0 ; k < npts ; k++) {
        xpoint[k].x = (int)x[k] ;
        xpoint[k].y = (int)(TheHeight -1 - y[k]) ;
   }

   XDrawLines(TheDisplay,TheDrawable,ThePixmapContext,
                       xpoint,npts,  CoordModeOrigin);
   XDrawLine(TheDisplay,TheDrawable,ThePixmapContext,
                    xpoint[0].x, xpoint[0].y,
                         xpoint[npts-1].x, xpoint[npts-1].y ) ;

   return 1 ;
}



int Fill_Polygon_X (int *x, int *y, int npts)
{
   XPoint xpoint[1000] ;
   int k ;

   if (npts <= 0) return 0 ;

   if (npts > 1000) {
      printf("\nFill_Polygon_X has been asked to deal with %d points.\n",
             npts) ;
      printf("Points past first 1000 ignored.\n") ;
      npts = 1000 ;
   }

   for (k = 0 ; k < npts ; k++) {
        xpoint[k].x = x[k] ; 
        xpoint[k].y = TheHeight -1 - y[k] ;
   }


   XFillPolygon(TheDisplay,TheDrawable,ThePixmapContext,
                xpoint,npts,Nonconvex,CoordModeOrigin);   

   return 1 ;

}


int Fill_Polygon_DX (double *x, double *y, int npts)
{
   XPoint xpoint[1000] ;
   int k ;

   if (npts <= 0) return 0 ;

   if (npts > 1000) {
      printf("\nFill_Polygon_X has been asked to deal with %d points.\n",
             npts) ;
      printf("Points past first 1000 ignored.\n") ;
      npts = 1000 ;
   }

   for (k = 0 ; k < npts ; k++) {
        xpoint[k].x = (int)x[k] ; 
        xpoint[k].y = (int)(TheHeight -1 - y[k]) ;
   }


   XFillPolygon(TheDisplay,TheDrawable,ThePixmapContext,
                xpoint,npts,Nonconvex,CoordModeOrigin);   


   return 1 ;
}




int Horizontal_Single_Pixel_Line_X (int x0, int x1, int y)
{
   int t,x ;
   int j,n ;

   // protect against an offscreen line
   if (y < 0) return 0 ;
   if (y >= TheHeight) return 0 ;

   if (x0 < 0) x0 = 0 ;
   else if (x0 >= TheWidth) x0 = (TheWidth - 1) ;
   if (x1 < 0) x1 = 0 ;
   else if (x1 >= TheWidth)  x1 = (TheWidth - 1) ;
   // end protection code


   if (x1 < x0) { t = x1 ; x1 = x0 ; x0 = t ; }

   //   for (x = x0 ; x <= x1 ; x++) { Point(x,y) ;   }
   Line_X (x0,y, x1,y) ;

   return 1 ;
} 







int Circle_X (int a, int b, int r)
{
 int x,y,e,e1,e2 ;

 x = r ;
 y = 0 ;
 e = 0;

 while (x >= y) {

       Safe_Point_X( a+x,b+y) ;   Safe_Point_X( a-x,b+y) ;
       Safe_Point_X( a+x,b-y) ;   Safe_Point_X( a-x,b-y) ;

       Safe_Point_X( a+y,b+x) ;   Safe_Point_X( a-y,b+x) ;
       Safe_Point_X( a+y,b-x) ;   Safe_Point_X( a-y,b-x) ;

       e1 =  e + y + y + 1 ;
       e2 = e1 - x - x + 1 ;
       y  =  y + 1 ;

       if ( abs(e2) < abs(e1) ) {
              x = x - 1 ;
              e = e2 ;
       } else e = e1 ;

     } 

} 




int Fill_Circle_X (int a, int b, int r)
{
 int x,y,e,e1,e2 ;

 x = r ;
 y = 0 ;
 e = 0;

 while (x >= y) {

       Horizontal_Single_Pixel_Line_X (a-x, a+x, b+y) ;
       Horizontal_Single_Pixel_Line_X (a-x, a+x, b-y) ;

       Horizontal_Single_Pixel_Line_X (a-y, a+y, b+x) ;
       Horizontal_Single_Pixel_Line_X (a-y, a+y, b-x) ;

       e1 =  e + y + y + 1 ;
       e2 = e1 - x - x + 1 ;
       y  =  y + 1 ;

       if ( abs(e2) < abs(e1) ) {
              x = x - 1 ;
              e = e2 ;
       } else e = e1 ;

     } 

} 





int Font_Pixel_Height_X ()
// Returns the height of the font in pixels. 
{
     return TheFontInfo->max_bounds.ascent + TheFontInfo->max_bounds.descent;
}



// the void * delcarations below allow for the passing of
// arrays of characters (usual usage) but also, for instance,
// an array of doubles that is composed of packed characters


int String_Pixel_Width_X (void *s)
// Returns the length, in pixels, of the string s 
{
     int len;

     len = strlen((char *)s);

     return XTextWidth(TheFontInfo, (char *)s, len);
}





int Draw_String_X (void *s, int x, int y)
// Draw the string s, with the lower left hand corner at (x,y)
{
     int len;

     len = strlen((const char *)s);

     XDrawString(TheDisplay,TheDrawable,ThePixmapContext,
                                         x,TheHeight-1-y,
                                         (char *)s, len);
}




int Get_Current_Dimensions_X (int dimensions[2])
{
  dimensions[0] = TheWidth ;
  dimensions[1] = TheHeight ;
}


int Get_Current_Dimensions_DX (double dimensions[2]) 
{
  dimensions[0] = TheWidth ;
  dimensions[1] = TheHeight ;
}


int Change_Pen_Dimensions_X (int w, int h)
{
  printf("Change_Pen_Dimensions_X  not implemented\n") ;
  return 0 ;
}



int Draw_Text_X (
               int num_lines_of_text,
               void *lines_of_text, // an array of pointers
               double startx, 
               double starty,
               double height,
               double x_over_y_ratio,
               double extra_space_between_letters_fraction,
               double extra_space_between_lines_fraction) 
{
  printf("Change_Pen_Dimensions_X  not implemented\n") ;
  return 0 ;
}



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


void fputintB (int x, FILE *fp)
{
   char *p ;
   int c[4],i ;

   p = (char *) &x ;

   for (i = 0 ; i < 4 ; i++) {
        c[i] = *p ;
        p++ ;
   }

   for (i = 3 ; i >= 0 ; i--) {
        fputc(c[i], fp) ;
   }

}




int fgetintB (FILE *fp)
{
   char *p ;
   int c[4],i ;
   int x ;
   char q ;

   for (i = 3 ; i >= 0 ; i--) {
        c[i] = fgetc(fp) ;
   }



   p = (char *) &x ;

   for (i = 0 ; i < 4 ; i++) {
        q = c[i] ;
        *p = q ;;
        p++ ;
   }

   return x ;
}







void  XImage_To_XWD_File (XImage *pxim,  FILE *fp)
{
  // assumes full color but uses full 32 bits per pixel
 int header_size, file_version, format, depth ;
 int xoffset, byte_order, bitmap_unit, bitmap_order, bitmap_pad ;
 int bits_per_pixel, bytes_per_line, visual_class ;
 int redmask, greenmask, bluemask ;
 int bitsperrgb, numentriesincolormap, numcolorstructures ;
 int windowwidth, windowheight, windowx, windowy, windowborderwidth ;
 int numbytestowrite ;
 int width,height ;

 header_size = 104 ;
 fputintB(header_size,fp) ;

 file_version = 7 ;
 fputintB(file_version,fp) ; 

 format = 2 ; // ZPixmap
 fputintB(format,fp) ;

 depth = 24 ;
 fputintB(depth,fp) ;

 width = pxim->width ;
 fputintB(width,fp) ;

 height = pxim->height ;
 fputintB(height,fp) ;

 xoffset = 0 ;
 fputintB(xoffset,fp) ;

 byte_order = 0 ;
 fputintB(byte_order,fp) ;

 bitmap_unit = 32 ;
 fputintB(bitmap_unit,fp) ;

 bitmap_order = 0 ;
 fputintB(bitmap_order,fp) ;

 bitmap_pad = 32  ;
 fputintB(bitmap_pad,fp) ;

 bits_per_pixel = 32 ;
 fputintB(bits_per_pixel,fp) ;

 bytes_per_line = width * 4 ;
 fputintB(bytes_per_line,fp) ;

 visual_class = 5 ; // more than one sample per pixel
 fputintB(visual_class,fp) ;

 redmask = 0x00ff0000 ;
 fputintB(redmask,fp) ;

 greenmask = 0x0000ff00 ;
 fputintB(greenmask,fp) ;

 bluemask = 0x000000ff ;
 fputintB(bluemask,fp) ;

 // bitsperrgb = 8 ; // hard to believe
 bitsperrgb = 24 ; 
 fputintB(bitsperrgb,fp) ;

 numentriesincolormap = 0 ; // not used :
 fputintB(numentriesincolormap,fp) ;

 numcolorstructures = 0 ;
 fputintB(numcolorstructures,fp) ;

 windowwidth = width ;
 fputintB(windowwidth,fp) ;

 windowheight = height ;
 fputintB(windowheight,fp) ;

 windowx = 0 ; // how crucial is this ?
 fputintB(windowx,fp) ;

 windowy = 0 ; // how crucial is this ?
 fputintB(windowy,fp) ;

 windowborderwidth = 0 ;
 fputintB(windowborderwidth,fp) ;


 // null terminated window name fleshed out to multiple of 4 bytes
 fputc('\0',fp) ;
 fputc('\0',fp) ;
 fputc('\0',fp) ;
 fputc('\0',fp) ;


 numbytestowrite =   bytes_per_line * height ;

 fwrite( pxim->data, numbytestowrite, 1, fp) ;

}











void XImage_From_XWD_File (XImage *pxim, FILE *fp)
{
  // assumes full color but uses full 32 bits per pixel

 int header_size, file_version, format, depth ;
 int xoffset, byte_order, bitmap_unit, bitmap_order, bitmap_pad ;
 int bits_per_pixel, bytes_per_line, visual_class ;
 int redmask, greenmask, bluemask ;
 int bitsperrgb, numentriesincolormap, numcolorstructures ;
 int windowwidth, windowheight, windowx, windowy, windowborderwidth ;
 int numbytestowrite ;

 int width,height ;

 int c, numbytestoread ;


 header_size = fgetintB(fp) ;
 file_version = fgetintB(fp) ;
 format = fgetintB(fp) ;
 depth = fgetintB(fp) ;
 width =  fgetintB(fp) ;
 height =  fgetintB(fp) ;
 xoffset = fgetintB(fp) ;
 byte_order = fgetintB(fp) ;
 bitmap_unit = fgetintB(fp) ;
 bitmap_order = fgetintB(fp) ;
 bitmap_pad = fgetintB(fp) ;
 bits_per_pixel = fgetintB(fp) ;
 bytes_per_line = fgetintB(fp) ;
 visual_class = fgetintB(fp) ;
 redmask = fgetintB(fp) ;
 greenmask = fgetintB(fp) ;
 bluemask = fgetintB(fp) ;
 bitsperrgb = fgetintB(fp) ;
 numentriesincolormap = fgetintB(fp) ;
 numcolorstructures = fgetintB(fp) ;
 windowwidth = fgetintB(fp) ;
 windowheight = fgetintB(fp) ;
 windowx = fgetintB(fp) ;
 windowy = fgetintB(fp) ;
 windowborderwidth = fgetintB(fp) ;

 // null terminated window name fleshed out to multiple of 4 bytes
 c = fgetc(fp) ; c = fgetc(fp) ; c = fgetc(fp) ; c = fgetc(fp) ;

 /* ++++++++++++++++++++++++ */
 
 pxim->width = width ;
 pxim->height = height ;
 pxim->depth = depth ;
 pxim->xoffset = xoffset ;
 pxim->format = format ;
 pxim->bitmap_unit = bitmap_unit ;
 pxim->bitmap_pad = bitmap_pad ;
 pxim->bytes_per_line = bytes_per_line ;
 pxim->bits_per_pixel = bits_per_pixel ;
 pxim->byte_order = byte_order ;
 pxim->bitmap_bit_order = bitmap_order ;



 /* on users head to have freed up any previous memory that pxim->data
    might have pointed to...trying to free it up here will cause faults
    if not already pointing to something sane */


 numbytestoread =   pxim->bytes_per_line * pxim->height ;
 pxim->data = (char *)malloc(numbytestoread) ;
 if (pxim->data == NULL) {
      printf("ERROR: XImage_From_XWD_File : can't malloc space needed\n") ;
      printf("Program terminating\n\n") ;
      exit(1) ;
 }

 fread (pxim->data, numbytestoread, 1, fp) ;

 rewind(fp) ;

}





int Save_Image_To_File_X (void *filename)
// return 1 if successful else 0
{
  FILE *fp ;
  XImage *pxim ;

  fp = fopen ((char *)filename,"w") ;
  if (fp == NULL) {
    printf("Save_Image_To_File_X cannot open file %s\n",(char *)filename) ;
    return 0 ;
  }

  //  pxim = XGetImage (TheDisplay, TheWindow,0,0, TheWidth, TheHeight) ;
  pxim = XGetImage (TheDisplay, TheDrawable, 0,0, TheWidth, TheHeight,
                      AllPlanes, ZPixmap) ;

  XImage_To_XWD_File (pxim,  fp) ;

  fclose(fp) ;

  return 1 ;
}
