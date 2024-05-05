#include <stdio.h>
#define GAP printf("\n\n\n\n");

int main () {
    // 0 -> Exit
    // 1 -> bruteforce
    // 2 -> mergesort
    // 3 -> recursive
    char running = 1;

    size_t algorithm = 0;
    size_t arr_size = 0;

    while (running) {
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

        // END fill array

        GAP

        printf("Result of the algorithm applied:\n");

        switch (algorithm) {
            case 1:
                printf("%s", bruteIsTriangular(arr, arr_size)? "The array is triangular" : "The array is not triangular");
            break;
            case 2:
                printf("%s", mergeIsTriangular(arr, arr_size)? "The array is triangular" : "The array is not triangular");
            break;
            case 3:
                printf("%s", recursiveIsTriangular(arr, arr_size, 0, 0, 0)? "The array is triangular" : "The array is not triangular");
            break;
        }

        printf("\n\n");

        char again = 0;
        printf("Go again? (y/n)\n");
        scanf("\n%c", &again);
        if (again != 'y') break;
    }

    return 0;
}