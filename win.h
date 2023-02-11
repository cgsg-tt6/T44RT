/*
 * Troitskaya Tamara, 01.02.2023
 */

// it didn't compile because of x64 instead of x86 and incorrect glut files.

#include <thread> // terminate(); (like exit(30); but in cpp)

#include <glut.h>

namespace ttrt
{
  class win
  {
  private:

    /* OpenGL initialization.
     * I don't quite know what to write.
     */
    win(void)
    {
      // OpenGl initialization.
      int argc = 1;
      char* argv[] = { const_cast<char*>("t44rt.exe") };

      // copy & paste from previous OpenGL project
      /* Initialization */
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

      /* Create window */
      glutInitWindowPosition(0, 0);
      glutInitWindowSize(300, 600);
      glutCreateWindow("Ray Tracing Project");

      glutDisplayFunc(Display);
      glutKeyboardFunc(Keyboard);
    }

    /* Keyboard handling function.
     */
    static void Keyboard(unsigned char Key, int X, int Y)
    {
      // exiting by "Esc" button
      if (Key == 27)
        std::terminate();
    }

    /* I don't quite know what to write.
     */
    static void Display(void)
    {
      // 2D вывод: Instance.Frm.Draw
      glClearColor(0.30, 0.47, 0.8, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      //View.Draw();
      glFinish();
      glutSwapBuffers();
      glutPostRedisplay();
    }
    static win Instance; // the only one instance of "win" type's object

  public:
    // frame Frm;

    /* Getter of the instance of object of win type
     */
    static win & Get(void)
    {
      return Instance;
    }

    /* OpenGL runner.
     */
    void Run(void)
    {
      glutMainLoop();
    }
  };
}

