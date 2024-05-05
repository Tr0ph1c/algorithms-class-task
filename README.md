<h1>Algorithms Task</h1>
<h3>Find triangle in array algorithm</h3>

[Problem](#problem)<br>
[Solutions](#solutions)<br>
[Time Complexity](#time-complexity)<br>
[How To Build](#how=to-build)<br>

## Problem
A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if:
- O<P<Q<N
- A[P] + A[Q] > A[R]
- A[Q] + A[R] > A[P]
- A[R] + A[P] > A[Q]

For example, consider array A such that: A[0] = 10 A[1] = 2 A[2] = 5 A[3] = 1 A[4] = 8 A[5] = 20<br>
Triplet (0, 2, 4) is triangular.

Write a function that, given a zero-indexed array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

- Example 1: Input: nums = [10 , 50 , 1]            Output: 0
- Example 2: Input: nums = [10 , 2 , 5 ,1 , 8 , 20] Output: 1

## Solutions
Brute force method:<br>
_With 3 iterators loop over the array and check every step if the conditions are met._<br>
```c
// pseudocode
Algorithm isTriangular(A[], N) {
    if (N < 3)
        return 0;

    for i = 0 to N - 2 step 1 do
        for  j = i + 1 to N - 1 step 1 
            for k = j + 1 to N step 1 
                if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) then
                    return 1;

    return 0;
}
```

Merge sort method:<br>
_Firstly we sort the array using merge sort, then we iterate once over the function checking for the condition to be met between 3 consecutive elements._<br>
```c
// pseudocode
Algorithm isTriangular(A[], N) {
    if (N < 3) then
        return 0;

    MergeSort(A, 0, N - 1);

    for i = 0 to N - 2 step 1 do
        if (A[i] + A[i + 1] > A[i + 2])
            return 1;

    return 0;
}
```

Recursive method:<br>
_We emulate iterators on the array but its a recursive function._<br>
```c
// pseudocode
Algorithm isTriangular(A[], N, i, j, k) {
    if (i >= N - 2) then
        return 0;

    if (j >= N - 1) then
        return isTriangular(A, N, i + 1, i + 2, i + 3);

    if (k >= N) then
        return isTriangular(A, N, i, j + 1, j + 2);

    if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] && A[k] + A[i] > A[j]) then
        return 1;

    return isTriangular(A, N, i, j, k + 1);
}
```

## Time Complexity
**Brute force method:**<br>
Summation of Three Nested Loop = O (N^3)<br>

**Merge sort method:**<br>
T(N) = 2T(N/2) + 2O(N)<br>
O(N log N)<br>

**Recursive method:**<br>
T(N) = T(N-1) + O(N)<br>
O(N^2)<br>

## How To Build
**Clone the repo and run** `build.bat` or `./build.sh` for linux, the file `main.exe` will get compiled.
