#include <math.h>
#include "core.h"

//We store primorials here, to iterate over.
long long int prim[13] = { 1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230, 200560490130, 7420738134810  };

//Computes a single value, at n, and stores it in byte size
int8_t compute_single(long long int n) {
    long long int residue = n;
    int8_t ret = 0;
    int i;
    for (i = sizeof(prim) / sizeof(prim[0]) - 1; i >= 0; --i) {
        if (residue >= prim[i] && prim[i] != 0) {
            residue = residue % prim[i];
            ++ret;
        }
    }
    return ret;
}

//Computes 0 - N (inclusive) and stores it in a int8 array (byte array)
void compute(long long int N, int8_t *out) {
    long long int i;
    for (i = 0; i <= N; ++i) {
        out[i] = compute_single(i);
    }
}
