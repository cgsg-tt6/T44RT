/* Troitskaya Tamara, 11.02.2023
 */

#ifndef __vec_h_
#define __vec_h_

#include <iostream>
#include <cmath>
#include <cassert>

template<typename T>
class vec
{
public:
  T x, y, z;

  // for debugging
  void print(void)
  {
    std::cout << x << " " << y << " " << z;
  }

  /* Constructors.
   */
  vec(void) : x(0), y(0), z(0)
  {
  }

  vec(T A) : x(A), y(A), z(A)
  {
  }

  vec(T A, T B, T C) : x(A), y(B), z(C)
  {
  }

  /* В аргументах мы пишем &V чтоб передавать ссылку, а не копировать значение, второе медленнее.
   * const так как не меняет значение
   */
  vec operator+(const vec& V)
  {
    return vec(x + V.x, y + V.y, z + V.z);
  }

  //vec& operator+=(vec& V) {}
};

#endif __vec_h_
