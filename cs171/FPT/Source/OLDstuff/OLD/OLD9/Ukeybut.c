
#include "graphics.h"



/******************************************************************************/

             /* WAIT by peter myers dec 1991 */
             /* IS written by peter myers march 1992 */

/******************************************************************************/



void WaitButton(int *x, int *y)

/* returns control when there is a button down event
   returns the mouse coordinates in x and y */
{
     XEvent report;
     int done = 0;

     while(!done)
     {
          XNextEvent(mydisplay,&report);
          done = ((report.type == ButtonPress)
               && (report.xany.window == mywindow));
/*               && (report.xany.window = mywindow)); */
     }
     *x = report.xbutton.x;
     *y = HEIGHT-1 - report.xbutton.y;
}  /* WaitButton */



char WaitKey()
{
     XEvent report;
     KeySym keysym;
     char buffer[10];
     int bufsize = 10;
     XComposeStatus compose;

     /* the only way this loop will be broken is by a return */
     while(1)
     {
          XNextEvent(mydisplay,&report);
          /* done only if the event was a key down and
             if the key pressed was a character */
          if (report.type == KeyPress)
          {
               XLookupString(&(report.xkey),buffer,bufsize,&keysym,&compose);

               /* if its a keyboard character return it */
               if (((keysym >= XK_KP_Space)
                 && (keysym <= XK_KP_9))
                || ((keysym >= XK_space)
                 && (keysym <= XK_asciitilde)))
                    return buffer[0];

               /* if its a return, enter or linefeed return '\n' */
               else if ((keysym == XK_Return) || (keysym == XK_KP_Enter)
                     || (keysym == XK_Linefeed))
                    return '\n';
          }
     }
}  /* WaitKey */






int IsButton(int *x, int *y)

/* Returns non-zero, and (x,y), if the mouse button has been pressed,
   returns zero otherwise. */
{
     XEvent report;

     if ((XCheckWindowEvent(mydisplay,mywindow,ButtonPressMask,&report))
      && (report.xany.window == mywindow))
     {

          *x = report.xbutton.x;
          *y = HEIGHT-1 - report.xbutton.y;
          return 1;
     }

     return 0;
}  /* IsButton */





int IsKey(char *c)

/* returns non-zero, and the character c, if a key has been pressed,
   returns zero otherwise. */
{
     XEvent report;
     KeySym keysym;
     char buffer[10];
     int bufsize = 10;
     XComposeStatus compose;

     if ((XCheckWindowEvent(mydisplay,mywindow,KeyPressMask,&report))
      && (report.xany.window == mywindow))
     {
          XLookupString(&(report.xkey),buffer,bufsize,&keysym,&compose);

          /* if its a keyboard character return it */
          if (((keysym >= XK_KP_Space)
            && (keysym <= XK_KP_9))
           || ((keysym >= XK_space)
            && (keysym <= XK_asciitilde)))
               *c = buffer[0];

          /* if its a return, enter or linefeed return '\n' */
          else if ((keysym == XK_Return) || (keysym == XK_KP_Enter)
                || (keysym == XK_Linefeed))
               *c = '\n';

          return 1;
     }

     return 0;
}  /* IsKey */


////////////////////////////////////////////////////////////


int Wait_Key()
// waits for a key to be pressed and then returns keysym
// ...allows non-ascii keycodes
{
     XEvent report;
     KeySym keysym;
     char buffer[10];
     int bufsize = 10;
     XComposeStatus compose;

     /* the only way this loop will be broken is by a return */
     while(1)
     {
          XNextEvent(mydisplay,&report);
          /* done only if the event was a key down and
             if the key pressed was a character */
          if (report.type == KeyPress)
          {
               XLookupString(&(report.xkey),buffer,bufsize,&keysym,&compose);

               return keysym ;
          }
     }
}  







int Is_Key()
// returns keysm if key has been pressed
// returns -1 otherwise
// ...allows non-ascii keycodes
// does not wait
{
     XEvent report;
     KeySym keysym;
     char buffer[10];
     int bufsize = 10;
     XComposeStatus compose;

     if ((XCheckWindowEvent(mydisplay,mywindow,KeyPressMask,&report))
      && (report.xany.window == mywindow))
     {
          XLookupString(&(report.xkey),buffer,bufsize,&keysym,&compose);
          return keysym;
     }

     return -1 ;
} 













