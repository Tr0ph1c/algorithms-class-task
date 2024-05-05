#include <stdio.h>
#define getArraySize(x) *(&x + 1) - x

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int mergeIsTriangular(int *A, int N) {
    if (N < 3)
        return 0;

    mergeSort(A, 0, N - 1);

    for (int i = 0; i < N - 2; i++) {
        if ((long long)A[i] + A[i + 1] > A[i + 2])
            return 1;
    }

    return 0;
}

//Pesudo Code
// Algorithm merge(arr[], l,  m,  r) {
//      n1 <- m - l + 1;
//      n2 <- r - m;

//     L[n1], R[n2];

//     for i <- 0 to n1 step 1
//         L[i] <- arr[l + i];
//     for j <- 0 to n2 step 1
//         R[j] <- arr[m + 1 + j];

//     i <- 0;
//     j <- 0;
//     k <- l;

//     while (i < n1 and j < n2) do {
//         if (L[i] <= R[j]) then {
//             arr[k] <- L[i];
//             i++;
//         } else {
//             arr[k] <- R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) do {
//         arr[k] <- L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) do {
//         arr[k] <- R[j];
//         j++;
//         k++;
//     }
// }

// Algorithm mergeSort(arr[], l, r) {
//     if (l < r) do {
//         int m <- l + (r - l) / 2;

//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);

//         merge(arr, l, m, r);
//     }
// }

// Algorithm isTriangular(int A[], int N) {
//     if (N < 3) then
//         return 0;

//     mergeSort(A, 0, N - 1);

//     for i = 0 to N - 2 step 1 do
//     {
//         if (A[i] + A[i + 1] > A[i + 2])
//             return 1;
//     }

//     return 0;
// }

// Analysis:
//
// T(N) = 2T(N/2) + 2O(N)
//
// Worst case:
// O(N log N)