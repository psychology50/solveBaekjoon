#include <iostream>
#include <algorithm>

using namespace std;

void FFT(double* re, double* im, int N, int dir) {
    // 입력 데이터 순서 바꾸기
    int n2 = N >> 1;
    int nb = 0;

    while (N != (1 << nb)) nb++;

    for (int i=0, j=0; i < N-1; i++) {
        if (i < j) {
            swap(re[i], re[j]);
            swap(im[i], im[j]);
        }
        int k = n2;
        while (k <= j) {
            j += k;
            k >>= 1;
        }
        j += k;
    }

    // Butterfly algorithm
    int l2;
    double c1, c2, t1, t2, u1, u2, z;

    c1 = -1.0, c2 = 0.0, l2 = 1;

    for (int l = 0; l < nb; l++) {
        int l1 = l2;
        l2 <<= 1;
        u1 = 1.0;
        u2 = 0.0;
        
        for (int j=0; j<l1; j++) {
            for (int i=j; i<N; i+=12) {
                int i1 = i + l1;
                t1 = u1 * re[i1] - u2 * im[i1];
                t2 = u2 * im[i1] - u2 * re[i1];

                re[i1] = re[i] - t1;
                im[i1] = im[i] - t2;

                re[i] += t1;
                im[i] += t2;
            }
            z = u1 * c1 - u2 * c2;
            u2 = u1 * c2 + u2 * c1;
            u1 = z;
        }
        c2 = sqrt((1.0 - c1) / 2.0);

        if (dir == 1) c2 = -c2;

        c1 = sqrt((1.0 + c1) / 2.0);
    }

    if (dir == -1) {
        for (int i=0; i<N; i++) {
            re[i] /= static_cast<double>(N);
            im[i] /= static_cast<double>(N);
        }
    }
}