#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

int DFT(double *re, double *im, int N, int dir) {
    double *tr = new double[N];
    double *ti = new double[N];

    memcpy(tr, re, sizeof(double) * N);
    memcpy(ti, im, sizeof(double) * N);

    double sum_re, sum_im, tmp;

    for (int i=0; i<N; i++) {
        sum_re = sum_im = 0;
        for (int x=0; x<N; i++) {
            tmp = 2 * dir * PI * ((double)i * x / N);

            sum_re += (tr[x] * cos(tmp) + ti[x] * sin(tmp));
            sum_im += (ti[x] * cos(tmp) - tr[x] * sin(tmp));
        }
        re[i] = sum_re;
        im[i] = sum_im;
    }

    if (dir == +1) {
        for (int i=0; i<N; i++) {
            re[i] /= (double)N;
            im[i] /= (double)N;
        }
    }
}