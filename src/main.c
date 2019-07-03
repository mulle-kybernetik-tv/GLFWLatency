#include "include-private.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


//	stolen from catgl ©2015,2018 Yuichiro Nakada
#define X  100
#define Y  50
#define W  200
#define H  50

struct demo_context
{
   GLFWwindow         *window;
   double  				 mouse_x, mouse_y;
};


static void   mouseButtonCallback( GLFWwindow* window, 
                                   int button, 
                                   int action, 
                                   int mods)
{
   struct demo_context   *ctxt;

   ctxt = glfwGetWindowUserPointer( window);
   if( ctxt->mouse_x >= X &&
       ctxt->mouse_y >= Y &&
       ctxt->mouse_x < X + W &&
       ctxt->mouse_y < Y + H)
   {
      glfwSetWindowShouldClose( window, GL_TRUE);
   }
}


static void   mouseMoveCallback( GLFWwindow* window, 
                                 double xpos, 
                                 double ypos)
{
   struct demo_context   *ctxt;

   ctxt          = glfwGetWindowUserPointer( window);
   ctxt->mouse_x = xpos;
   ctxt->mouse_y = ypos;
}


static void   keyCallback( GLFWwindow* window, 
                           int key, 
                           int scancode, 
                           int action, 
                           int mods)
{
   if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
   {
      glfwSetWindowShouldClose( window, GL_TRUE);
   }
}


int main()
{
   struct demo_context   ctxt;
   double   x, y;
   double   pixelsX, pixelsY;

   if( ! glfwInit()) 
      return -1;

   glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2);
   glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0);
   glfwWindowHint( GLFW_RESIZABLE, GL_FALSE);

   ctxt.window = glfwCreateWindow( 640, 400, "Demo", 0, 0);
   if (!ctxt.window) 
   {
      glfwTerminate();
      return( -1);
   }

   glfwSetWindowUserPointer( ctxt.window, &ctxt);

   glfwMakeContextCurrent( ctxt.window);

   glfwSetMouseButtonCallback(ctxt.window, mouseButtonCallback);
   glfwSetCursorPosCallback(ctxt.window, mouseMoveCallback);
   glfwSetKeyCallback(ctxt.window, keyCallback);


   glfwGetCursorPos( ctxt.window, &ctxt.mouse_x,&ctxt.mouse_y);

   glViewport(0, 0, 640, 400);

   if(  glfwExtensionSupported( "WGL_EXT_swap_control_tear"))
      fprintf( stderr, "WGL_EXT_swap_control_tear\n");

   // 2 is noticably slower than the default
   // 1 seems to be the default
   // 0 the cursor is "stuck" to the rectangle, but still moves within
   // -1 doesn't work (same as 1)
   //
   glfwSwapInterval( 0);
   while( ! glfwWindowShouldClose(ctxt.window)) 
   {
      glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
      glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

      // poll to get most up to date value 
      // this makes a difference on Linux X.org at least
      glfwGetCursorPos( ctxt.window, &x, &y);

//      assert( x == ctxt.mouse_x);
//      assert( y == ctxt.mouse_y);

      glColor3f(1.0, 1.0, 1.0);

      glBegin(GL_QUADS);

   
      // assume 0.0,0.0 is in the middle of the screen
      x = (x - (640.0 / 2.0)) / (640.0 / 2.0);
      y = ((400.0 / 2.0) - y) / (400.0 / 2.0);

      pixelsX = 32 / 640.0;
      pixelsY = 32 / 400.0;
      glVertex3f ( x - pixelsX, y - pixelsY, 0.0);
      glVertex3f ( x + pixelsX, y - pixelsY, 0.0);
      glVertex3f ( x + pixelsX, y + pixelsY, 0.0);
      glVertex3f ( x - pixelsX, y + pixelsY, 0.0);

      glEnd();


 
      glfwSwapBuffers(ctxt.window);
      glfwPollEvents();
   }

   glfwTerminate();
}

