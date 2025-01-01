#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int low = 0;
    int high = matrixSize * (*matrixColSize) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Mid index in the "virtual" 1D array

        // Convert mid index to 2D coordinates
        int midRow = mid / (*matrixColSize);   // Row index
        int midCol = mid % (*matrixColSize);   // Column index

        if (matrix[midRow][midCol] == target) {
            return true;
        } else if (matrix[midRow][midCol] < target) {
            low = mid + 1;  // Search in the right half
        } else {
            high = mid - 1;  // Search in the left half
        }
    }

    return false;  // Target not found
}

