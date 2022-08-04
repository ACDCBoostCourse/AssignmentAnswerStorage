#include <iostream>
#include <string>

using namespace std;

int *sorted(int *arr, bool status);
void swap(int &a, int &b);
int main() {
    int items[4] = {1, 5, 3, 2};
    int *newItems;
    newItems = sorted(items, true);

    for (int item : items) {
        cout << item << ' '; // 1 5 3 2
    }

    cout << endl;

    for (int i = 0; i < 4; i++) {
        cout << newItems[i] << ' '; // 1 2 3 5
    }
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int *sorted(int *arr, bool status) {
    int *buffer = new int[4];
    cout << "Size : " << sizeof(buffer) / sizeof(int) << endl;
    for (int i = 0; i < 4; i++) {
        buffer[i] = arr[i];
    }
    int minmax;
    int minmaxIndex;
    if (status) {
        for (int i = 1; i < 4; i++) {
            minmax = buffer[i - 1];
            minmaxIndex = i - 1;
            for (int j = i; j < 4; j++) {
                if (minmax > buffer[j]) {
                    minmax = buffer[j];
                    minmaxIndex = j;
                }
            }
            swap(buffer[i - 1], buffer[minmaxIndex]);
        }
    }

    else {
        for (int i = 1; i < 4; i++) {
            minmax = buffer[i - 1];
            minmaxIndex = i - 1;
            for (int j = i; j < 4; j++) {
                if (minmax < buffer[j]) {
                    minmax = buffer[j];
                    minmaxIndex = j;
                }
            }
            swap(buffer[i - 1], buffer[minmaxIndex]);
        }
    }

    return buffer;
}
