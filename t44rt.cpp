/*
 * Troitskaya Tamara, 01.02.2023
 * Purpose: Main file of the program.
 *          Calls functions from other files.
 */

#include "win.h"
#include "vec.h"

/* Main function of the project. 
 * Calls all the functions needed.
 */
int main( void )
{
  ttrt::win& MyWin = ttrt::win::Get();
  
  // Scenes, Rendering...
  
  MyWin.Run();

  return 0;
}
