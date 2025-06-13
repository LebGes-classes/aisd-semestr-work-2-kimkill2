using namespace std;
#include <iostream>
#include <cmath>
//
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = (low - 1);
//
//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }
//
// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
//
// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
//
// void StoogeSort(int arr[], int len) {
//     if (len < 2) return;
//
//     if (len == 2) {
//         if (arr[0] > arr[1]) {
//             swap(arr[0], arr[1]);
//         }
//         return;
//     }
//     int t = len / 3;
//     StoogeSort(arr, len - t);
//     StoogeSort(arr + t, len - t);
//     StoogeSort(arr, len-t);
//
//     printArray(arr, len);
// }
//
// int main() {
//     int arr[6] = {10, 9 ,6, 1, 5, 4};
//     cout << "Original list ";
//     printArray(arr, 6);
//     quickSort(arr, 0, 5);
//     cout << "Changed List ";
//     printArray(arr, 6);
//
//
//     return 0;
// }
//
//
//
//

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int len) {
    int task = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    printArray(arr, len);
}

void combSort(int arr[], int len) {
    int gap = len;
    bool swapped = true;
    double factor = 1.5;

    do {
        gap = max(1, (int) (gap * factor));
        if (gap < 1) gap = 1;
        swapped = false;

        for (int i = 0; i + gap < len; ++i) {
            if (arr[i] > arr[i+gap]) {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
        if (gap == 1 && !swapped) break;
    } while (true);
}

int main() {
    int arr1[3] {5, 3, 7};
    int arr2[3] {5, 3, 7};
    int len = 3;
    cout << "Original array: ";
    printArray(arr1, len);
    cout << "Comb sort: ";

    combSort(arr1, len);
    printArray(arr1, len);

    cout << "Bubble sort: ";
    bubbleSort(arr2, len);

    return 0;
}