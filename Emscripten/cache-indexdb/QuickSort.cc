#include <iostream>
#include <vector>
#include <emscripten.h>

using namespace std;

// 定义用于交换两个位置元素值的函数；
void swap (char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void printArr (char arr[], char length) {
    vector<char> t(arr, arr + length);
    for (auto &e : t) {
        cout << (int)e << " ";
    }
    cout << endl;
}

// 函数以序列最右侧的元素作为“基准数”进行交换过程；
char partition (char arr[], char low, char high) {
    // 选择基准数；
    char pivot = arr[high];  
    char i = (low - 1); 

    // 遍历元素，并交换基准数两侧的元素；
    for (char j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 置位基准数字；
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


extern "C" char* EMSCRIPTEN_KEEPALIVE quickSort(char arr[], char low, char high) {
    if (low < high) {
        printArr(arr, high + 1);
        // 获得下一次交换的序列区间；
        char pi = partition(arr, low, high);
        
        // 继续递归排列左右两部分序列；
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return arr;
}

