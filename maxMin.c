#include <stdio.h>

// Function to find the maximum and minimum elements in an array
void findMaxMin(int arr[], int low, int high, int* max, int* min) {
    // Base case: If there is only one element in the array
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    // If there are two elements in the array
    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            *max = arr[high];
            *min = arr[low];
        } else {
            *max = arr[low];
            *min = arr[high];
        }
        return;
    }

    // If there are more than two elements, divide the array into two halves
    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;

    // Recursively find the maximum and minimum in the left and right halves
    findMaxMin(arr, low, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

    // Determine the overall maximum and minimum
    if (leftMax > rightMax) {
        *max = leftMax;
    } else {
        *max = rightMax;
    }

    if (leftMin < rightMin) {
        *min = leftMin;
    } else {
        *min = rightMin;
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max, min;
    findMaxMin(arr, 0, size - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
