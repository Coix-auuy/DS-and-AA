//
// Created by nightmare on 2021/7/13.
//
#include "const.cpp"

typedef int ElemType;

void ShellSort(ElemType a[], int length) {
    int h = 1;
    while (h < length / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
                swap(a[j], a[j - h]);
        }
        h = h / 3;
    }
}

int main() {
    int a[10] = {10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
    ShellSort(a, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << ' ';
    cout << endl;
}

