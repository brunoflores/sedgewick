#include "complex.h"

Complex Complex_init(float Re, float Im) {
  Complex t;
  t.Re = Re;
  t.Im = Im;
  return t;
}

float Re(Complex z) { return z.Re; }
float Im(Complex z) { return z.Im; }

Complex Complex_mult(Complex a, Complex b) {
  Complex t;
  t.Re = a.Re * b.Re - a.Im * b.Im;
  t.Im = a.Re * b.Im + a.Im * b.Re;
  return t;
}
