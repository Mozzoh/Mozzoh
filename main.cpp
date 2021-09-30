#include <stdio.h>
#include <stdlib.h>
#include <adder.hpp>

#include <glad/glad.h>
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
#include <GLFW/glfw3.h>
//#include <ft2build.h>
//#include FT_FREETYPE_H


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

int main(int argc, char const *argv[])
{
  /* code */
  printf("%s\n","\nHello Library World!\n" );
  //printf("\n");
  printf("Testing add: %5.2f\n", add(1.3f, 77.6f));

  GLFWwindow* window;
  int width, height;

  //unsigned int texture;
  //glGenTextures(1, &texture);


  if( !glfwInit() )
  {
      fprintf( stderr, "Failed to initialize GLFW\n" );
      exit( EXIT_FAILURE );
  }


  window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
  if (!window)
  {
      fprintf( stderr, "Failed to open GLFW window\n" );
      glfwTerminate();
      exit( EXIT_FAILURE );
  }
  glfwMakeContextCurrent(window);
  glfwSetWindowOpacity(window, 0.2f);


  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      printf("%s\n", "Failed to initialize GLAD");
      return -1;
  }

  //FT_Library ft;

  //if(FT_Init_FreeType(&ft)) {
    //fprintf(stderr, "Could not init freetype library\n");
    //return 1;
  //}

  // Main loop
  while( !glfwWindowShouldClose(window) )
  {
      // Swap buffers
      glfwSwapBuffers(window);

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      processInput(window);
      //glfwPollEvents();
      glfwWaitEvents();
  }

  // Terminate GLFW
  glfwTerminate();
  printf("%s\n", "Terminated . . ." );
  // Exit program
  exit( EXIT_SUCCESS );

  return 0;
}
