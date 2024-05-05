#include <stdio.h>
#define getArraySize(x) *(&x + 1) - x

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

/*int main() {
    int nums1[] = {10, 50, 1};
    int nums2[] = {10, 2, 5, 1, 8, 20};
	
	printf("3: %d\n", getArraySize(nums1));
	printf("6: %d\n", getArraySize(nums2));

    getArraySize(nums1);
    getArraySize(nums2);
	
    printf("Output for nums1: %d\n", isTriangular(nums1, getArraySize(nums1)));
    printf("Output for nums2: %d\n", isTriangular(nums2, getArraySize(nums2)));

    return 0;
}*/

//PseudoCode

// Algoritm isTriangular(*A, N) {
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

// Summation of Three Nested Loop = O (n^3)