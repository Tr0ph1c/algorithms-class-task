#include <stdio.h>

int recursiveIsTriangular(int *A, int N, int i, int j, int k) {
    if (i >= N - 2)
        return 0;

    if (j >= N - 1) {
        return recursiveIsTriangular(A, N, i + 1, i + 2, i + 3);
    }

    if (k >= N) {
        return recursiveIsTriangular(A, N, i, j + 1, j + 2);
    }

    if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) {
        return 1;
    }

    return recursiveIsTriangular(A, N, i, j, k + 1);
}

//PseudoCode

// Algorithm isTriangular(A[], N, i, j, k) {
//     if (i >= N - 2) then {
//         return 0;
//     }
//     if (j >= N - 1) then 
//     {
//         return isTriangular(A, N, i + 1, i + 2, i + 3);
//     }
//     if (k >= N) then 
//     {
//         return isTriangular(A, N, i, j + 1, j + 2);
//     }

//     if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) then
//     {
//         return 1;
//     }

//     return isTriangular(A, N, i, j, k + 1);
// }

// Analysis:
//
// T(N) = T(N-1) + O(N)
//
// Worst case:
// O(N^2)