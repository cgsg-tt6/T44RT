/*
 * Troitskaya Tamara, 11.02.2023
 */

#ifndef __vec_h_
#define __vec_h_

#include <iostream>
#include <cmath>
#include <cassert>

// do we need a namespace here?

template<typename T>
class vec
{
public:
  T x, y, z;

  // for debugging
  void print(void)
  {
    std::cout << x << " " << y << " " << z << std::endl;
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

  /* ¬ аргументах мы пишем &V чтоб передавать ссылку, а не копировать значение, второе медленнее.
   * const так как не мен€ет значение
   */
  vec operator+(const vec& V) const
  {
    return vec(x + V.x, y + V.y, z + V.z);
  }

  vec& operator+=(vec& V)
  {
    x += V.x;
    y += V.y;
    z += V.z;
    return *this;
  }

  vec& operator-(void) const
  {
    x = -x;
    y = -y;
    z = -z;
    return *this;
  }

  /* ѕокомпонентное умножение.
   * Ќужно дл€ цветов.
   */
  vec operator*(const vec& v) const
  {
    return vec(x * v.x, y * v.y, z * v.z);
  }

  vec& operator*=(const vec& v)
  {
    x *= v.x;
    y *= v.y;
    z *= v.y;
    return this;
  }

  /* ”множение на скал€р.
   */
  vec operator*(T N) const
  {
    return vec(N * x, N * y, N * z);
  }

  vec& operator*=(T N)
  {
    x *= N;
    y *= N;
    z *= N;
    return this;
  }
    
  /* Dot vec.
   */
  T operator&(const vec& v) const
  {
    return x * v.x + y * v.y + z * v.z;
  }

  /* Cross vec.
   */
  vec operator%(const vec& v) const
  {
    return vec(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
  }

  double len(void) const
  {
    return sqrt(x * x + y * y + z * z);
  }

  /* Changes this vector to normalized - it's length equals 1.
   */
  vec& Normalized(void)
  {
    double l = this->len();
    if (l != 0 && l != 1)
    {
      x /= l;
      y /= l;
      z /= l;
    }
    return *this;
  }

  /* Returns new vector, wich length equals 1.
   */
  vec Normalize(void) const
  {
    double l = this->len();
    if (l != 0 && l != 1)
    {
      return vec(x / l, y / l, z / l);
    }
    return vec(x, y, z);
  }

// раз не понимаю - не буду использовать
#if 0
  /* »спользование [] как у массива. v[0] = v.x
   * Edits vector data.
   * I - index.
   */
  T& operator[](int I)
  {
    // assert is like if but in case 'false' it throws error.
    assert(I >= 0 && I <= 2);
    return *(&x + I);
  }

  // не понимаю, что происходит...
  /*const*/ T operator[](int I) const
  {
    assert(I >= 0 && I <= 2);
    return *(&x + I);
  }
#endif

  /* Random numbers from 0 to 1.
   */
  static T R0(void)
  {
    return rand() / (T)RAND_MAX;
  }

  /* Random numbers from -1 to 1.
   */
  static T R1(void)
  {
    return 2 * rand() / (T)RAND_MAX - 1;
  }

  /* Random vectors.
   */
  static vec Rnd0(void)
  {
    return vec(R0(), R0(), R0());
  }

  static vec Rnd1(void)
  {
    return vec(R1(), R1(), R1());
  }
};

#endif __vec_h_
