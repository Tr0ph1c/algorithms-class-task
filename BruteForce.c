#include <stdio.h>

int bruteIsTriangular(int *A, int N) {
    if (N < 3)
        return 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

//PseudoCode

// Algorithm isTriangular(A[], N) {
//     if (N < 3)
//         return 0;

//     for i = 0 to N - 2 step 1 do
//     {
//         for  j = i + 1 to N - 1 step 1 
//         {
//             for k = j + 1 to N step 1 
//                 {
//                 if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) then
//                 {
//                     return 1;
//                 }
//             }
//         }
//     }

//     return 0;
// }

// Summation of Three Nested Loop = O (N^3)