#include <stdio.h>

/* A function to calculate maximum sum of subarray
of size window_size in an array of size arr_size using sliding window technique.
*/
int findMaximumSum(int arr[], int arr_size, int window_size) {
    /* calculate the sum of first window_size elements of the array
    and store that sum in a variable named running_sum. */
    int max_result = 0;
    for (int i = 0; i < window_size; i++)
        max_result += arr[i];

    /* Calculate sum of the remaining windows by
    summing up the next element subtracting the
    previous element. */
    int running_sum = max_result;
    for (int i = window_size; i < arr_size; i++) {
        running_sum = running_sum + (arr[i] - arr[i - window_size]);
        /* If running_sum is greater than max_result,
        update max_result with the value of running_sum. */
        if (running_sum > max_result) {
            max_result = running_sum;
        }
    }

    return max_result;
}

int main() {
    int arr_size = 5;
    int arr[] = {10, 20, 10, 30, 5};
    int window_size = 3;
    int answer = findMaximumSum(arr, arr_size, window_size);
    printf("%d\n", answer);
    return 0;
}