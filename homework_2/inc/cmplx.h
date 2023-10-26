#ifndef CMPLX_H
#define CMPLX_H

#include <math.h>
#define PI 3.1415926536

typedef float cmplx_t[2];


// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c);

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c);

// returns |a|
double cmplx_mag(cmplx_t a);

// returns phase in radians of a 
double cmplx_phs(cmplx_t a);

// returns real part of mag/_phs
double cmplx_real(double mag, double phs);

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs);

// returns dft transformation of complex input signal
// SOURCE: https://en.wikipedia.org/wiki/Discrete_Fourier_transform
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N);

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N);

#endif