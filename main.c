#include <stdio.h>
#define GAP printf("\n\n\n\n");

int bruteIsTriangular(int*, int);
int mergeIsTriangular(int*, int);
int recursiveIsTriangular(int*, int, int, int, int);

int main () {
    // 0 -> Exit
    // 1 -> bruteforce
    // 2 -> mergesort
    // 3 -> recursive
    size_t algorithm = 0;

    char running = 1;
    char input_mode = 0;

    // dynamic size for input mode
    size_t arr_size = 0;

    while (running) {
        // Choose algorithm
        int choice = 0;
        printf("Main Menu:\n0) Exit\n1) Brute Force Algorithm\n2) Merge Sort Algorithm\n3) Recursive Algorithm\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                running = 0;
                continue;
            break;
            case 1: break; case 2: break; case 3: break;
            default:
            printf("\nUndefined Choice...");
            continue;
        }

        algorithm = choice;

        // END choose algorithm

        GAP

        // Input mode or Preset mode
        printf("0) Input mode\n1) Preset mode\nChoice: ");
        scanf("%d", &choice);

        input_mode = (choice)? 0 : 1;
        // END Input mode or Preset mode

        GAP

        if (input_mode) {
            printf("Construct the array:\n");

            printf("Size of the array: ");
            scanf("%d", &choice);

            arr_size = choice;
            choice = 0;

            int arr[arr_size];

            while (arr_size != choice++) {
                printf("\nArray[%d] = ", choice);
                scanf("%d", &arr[choice]);
            }

            printf("Result of the algorithm applied:\n");

            switch (algorithm) {
                case 1:
                    printf("%s", bruteIsTriangular(arr, arr_size)? "The array is triangular" : "The array is not triangular");
                break;
                case 2:
                    printf("%s", mergeIsTriangular(arr, arr_size)? "The array is triangular" : "The array is not triangular");
                break;
                case 3:
                    printf("%s", recursiveIsTriangular(arr, arr_size, 0, 1, 2)? "The array is triangular" : "The array is not triangular");
                break;
            }
        } else {
            int arr1[] = {1, 2, 3, 4, 5};
            int arr2[] = {7, 9, 20};
            int arr3[] = {1, 10, 5, 8};

            switch (algorithm) {
                case 1:
                    printf("{1, 2, 3, 4, 5}: %s\n", bruteIsTriangular(arr1, 5)? "The array is triangular" : "The array is not triangular");
                    printf("{7, 9, 20}: %s\n", bruteIsTriangular(arr2, 3)? "The array is triangular" : "The array is not triangular");
                    printf("{1, 10, 5, 8}: %s\n", bruteIsTriangular(arr3, 4)? "The array is triangular" : "The array is not triangular");
                break;
                case 2:
                    printf("{1, 2, 3, 4, 5}: %s\n", mergeIsTriangular(arr1, 5)? "The array is triangular" : "The array is not triangular");
                    printf("{7, 9, 20}: %s\n", mergeIsTriangular(arr2, 3)? "The array is triangular" : "The array is not triangular");
                    printf("{1, 10, 5, 8}: %s\n", mergeIsTriangular(arr3, 4)? "The array is triangular" : "The array is not triangular");
                break;
                case 3:
                    printf("{1, 2, 3, 4, 5}: %s\n", recursiveIsTriangular(arr1, 5, 0, 1, 2)? "The array is triangular" : "The array is not triangular");
                    printf("{7, 9, 20}: %s\n", recursiveIsTriangular(arr2, 3, 0, 1, 2)? "The array is triangular" : "The array is not triangular");
                    printf("{1, 10, 5, 8}: %s\n", recursiveIsTriangular(arr3, 4, 0, 1, 2)? "The array is triangular" : "The array is not triangular");
                break;
            }
        }

        GAP

        // Go again?
        char again = 0;
        printf("Go again? (y/n)\n");
        scanf("\n%c", &again);
        if (again != 'y') break;
    }

    return 0;
}