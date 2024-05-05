#include <stdio.h>
#define getArraySize(x) *(&x + 1) - x

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

/*int main() {
    int nums1[] = {10, 50, 1};
    int nums2[] = {10, 2, 5, 1, 8, 20};

    printf("Output for nums1: %d\n", isTriangular(nums1, getArraySize(nums1), 0, 1, 2));
    printf("Output for nums2: %d\n", isTriangular(nums2, getArraySize(nums2), 0, 1, 2)); 

    return 0;
}*/

//PseudoCode

// Algorithm isTriangular(*A,  N,  i,  j, k) {
//     if (i >= N - 2) then {
//         return 0;
//      }
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

//T(n) = T(n-1) + O(n) = O(n^2)