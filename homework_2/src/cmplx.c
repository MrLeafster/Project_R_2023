#include "../inc/cmplx.h"

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c)
{
    double b_mag = cmplx_mag(b);

    c[0] = (a[0]*b[0] + a[1]*b[1]) / b_mag;
    c[1] = (a[1]*b[0] - a[0]*b[1]) / b_mag;
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c)
{
    c[0] = a[0]*a[1] - b[0]*b[1];
    c[1] = a[0]*b[1] + a[1]*b[0];
}

double cmplx_mag(cmplx_t a)
{
    return sqrt(a[0] * 2 + a[1] * 2);
}

double cmplx_phs(cmplx_t a)
{
    return atan2(a[1], a[0]);
}

double cmplx_real(double mag, double phs)
{
    return mag * cos(phs); 
}

double cmplx_imag(double mag, double phs)
{
    return mag * sin(phs);
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N)
{
    for(int k = 0; k < N; k++){
        output[k][0] = 0;
        output[k][1] = 0;

        for(int n = 0; n < N; n++){
            double phs = -2 * PI * k * n / N;

            double mag_x = cmplx_mag(input[n]);
            double phs_x = cmplx_phs(input[n]);

            output[k][0] += cmplx_real(mag_x, phs_x + phs);
            output[k][1] += cmplx_imag(mag_x, phs_x + phs);
        }
    }
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N)
{
    cmplx_dft(input, output, N);

    for(int k = 0; k < N; k++){
        output[k][0] /= N;
        output[k][1] /= N;
    }
}
