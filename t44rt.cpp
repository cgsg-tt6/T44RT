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
  //ttrt::win& MyWin = ttrt::win::Get();
  
  // Scenes, Rendering...
  
  //MyWin.Run();


  // checking vec.h
  //*
  vec<double> A = vec<double>(3, 4, 5), B = vec<double>(6);
  //int C = A & B;
  A.print();
  B.print();
  ///B = A.Normalize();
  //A += B;
  //A = -A;
  //std::cout << C << " " << A.len();
  //B[0] += 1;
  B.print();
  //std::cout << B[2];

  //*/

  return 0;
}
