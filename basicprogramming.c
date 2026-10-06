#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void process_1() {
    printf("7");
}
void process_2(int arr[], int n) {
    if(arr[0] > arr[1]) {
        printf("Bigger");
    } else if(arr[0] == arr[1]) {
        printf("Equal");
    } else {
        printf("Smaller");
    }
}

/*
void process_3(int arr[], int n) {
    if(arr[0] >= arr[1] && arr[0] <= arr[2]) {
        printf("%d\n", arr[0]);
    } else if (arr[1] >= arr[0] && arr[1] <= arr[2]) {
        printf("%d\n", arr[1]);
    } else {
        printf("%d\n", arr[2]);
    }
}
*/

void process_3(int arr[], int n) {
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        printf("%d", a);
    } else if ((b >= a && b <= c) || (b >= c && b <= a)) {
        printf("%d", b);
    } else {
        printf("%d", c);
    }
}

void process_4(int arr[], int n) {
    int i;
    long long sum;
    sum = 0;
    for(i = 0; i < n; ++i) {
        sum += arr[i];
    }
    printf("%lld", sum);
}
void process_5(int arr[], int n) {
    int i;
    long long sum = 0;
    for(i = 0; i < n; ++i) {
        if((arr[i] % 2) == 0) {
            sum += arr[i];
        }
    }
    printf("%lld", sum);
}

void process_6(int arr[], int n) {
    int i;
    char output[n + 1];
    for(i = 0; i < n; i++) {
        output[i] = 'a' + (arr[i] % 26);
    }

    output[n] = '\0';
    printf("%s", output);
}

/*
void process_7(int arr[], int n) {

    int i = 0;
    i = arr[i];

    if(i < 0 || i > n - 1) {
        printf("Out\n");
        return;
    } else if( i == n - 1) {
        printf("Done\n");
        return;
    } else {
        i = arr[i];
    }
}
*/

/*
void process_7(int arr[], int n) {
    int visited[n];

    for (int j = 0; j < n; j++) {
        visited[j] = 0;
    }

    int i = 0;
    while (1) {
        if (i < 0 || i >= n) {
            printf("Out");
            return;
        }

        if (i == n - 1) {
            printf("Done");
            return;
        }

        if (visited[i]) {
            printf("Cyclic");
            return;
        }
        visited[i] = 1;
        i = arr[i];
    }
}
*/

void process_7(int arr[], int n) {
    int visited[n];

    for (int j = 0; j < n; j++) {
        visited[j] = 0;
    }

    int i = 0;

    while (1) {
        if (visited[i]) {
            printf("Cyclic\n");
            return;
        }

        visited[i] = 1;

        i = arr[i];

        if (i < 0 || i >= n) {
            printf("Out\n");
            return;
        }

        if (i == n - 1) {
            printf("Done\n");
            return;
        }
    }
}

void process_arr(int arr[], int n, int t) {
        switch(t) {
            case 1:
                process_1();
                break;
            case 2:
                process_2(arr, n);
                break;
            case 3:
                process_3(arr, n);
                break;
            case 4: 
                process_4(arr, n);
                break;
            case 5:
                process_5(arr, n);
                break;
            case 6:
                process_6(arr, n);
                break;
            case 7: 
                process_7(arr, n);
                break;
            default:
                break;
        }
}

/*
void print_arr(int arr[], int n) {
    int i, cur;
    for(i = 0; i < n; i++) {
        if(fscanf(stdin, "%d", &cur) != 1) {
        }
        printf("%d ", cur);
        arr[i] = cur;
    }
    printf("\n");
}
*/
int main() {

    int n,t;
    if(fscanf(stdin, "%d %d", &n, &t) != 2) {
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return EXIT_FAILURE;
        }
    }

    process_arr(arr, n, t);

    return EXIT_SUCCESS;
}


/*
 * given two integers N and t
 *
 * and
 *
 * array A of N integers (0-based indexing)
 *
 * based on the value of t, you will perform an action on A
 *
 * 
 *
 * t -> action needed table below (link below)
 *
 * https://open.kattis.com/problems/basicprogramming1
 *
 *
 *
 * notes:
 *
 *
 * it looks like we need to iterate Array A.
 * we compare t against A[i] to see if we enter the if statement...
 *
 *
 * todo:
 *
 *
 * 1. capture input values
 *  1. N
 *  2. t
 *  3. array
 *
 *
 * 2. iterate A mechanism
 * 3. create switch statement
 * 4. invoke function per switch statement
 *  - follow instructiuon from linked above
 *
 *
 *
 *
 *  notes: 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
