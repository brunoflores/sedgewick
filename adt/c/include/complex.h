typedef struct {
  float Re;
  float Im;
} Complex;

Complex Complex_init(float, float);

float Re(Complex);
float Im(Complex);

Complex Complex_mult(Complex, Complex);
