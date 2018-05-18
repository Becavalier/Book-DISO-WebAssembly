#include <iostream>

using namespace std;



void quickSort(int[] a, int start, int end) {
    if (start >= end)   
        return;

    int t = a[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (a[j] < t) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, end);
    quickSort(a, start, i);
    quickSort(a, i + 2, end);
}

int main (int argc, char **argv) {
    int x[] = {0 ,4, 2, 9, 10, 55};
    quickSort(x, 1, sizeof(x) / sizeof(int));

    return 0;
}