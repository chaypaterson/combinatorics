#include <stdio.h>
#include <math.h>

int main(void) {
    int c = 2;

    printf("m,\tK,\tV,\tA,\tV/m!\n");
    {
        unsigned int K = c;
        unsigned int V = 1;
        int m = 1;
        double A = c;
        double deltaA = c;
        double tol = 1e-6;
        unsigned int mfact = 1;
        double VM = 1;
        while (1) {
            printf("%d,\t%d,\t%d,\t%f,\t%g\n",m,K,V,A,VM);
            K = (m + 1) * K + c + 1 - m * m;
            V = (m + 1) * V + 1;
            deltaA = A - (double) K / V;
            A -= deltaA;
            mfact *= m + 1;
            VM = (double) V / mfact;
            ++m;
            if ((m > 4) && (fabs(deltaA) < tol))
                break;
        };
        printf("%d,\t%d,\t%d,\t%f,\t%g\n",m,K,V,A,VM);
        printf("A: %g,\ntol: %g\n", A, deltaA);
    }
    return 0;
}
