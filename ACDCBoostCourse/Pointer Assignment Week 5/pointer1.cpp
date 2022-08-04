#include <iostream>
#include <string>

using namespace std;

void sort(int *arr, bool status);
void swap(int &a, int &b);

int main() {
 int items[4] = {1,5,3,2};
 sort(items, true);

 for(int item : items){
  cout << item << ' ';  // 1 2 3 5
 }

 cout << endl;
 sort(items, false);

 for(int item : items){
  cout << item << ' ';  // 5 3 2 1
 }
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void sort(int *arr, bool status) {
    int minmax;
    int minmaxIndex;
    if (status) {
        for (int i = 1; i < 4; i++) {
            minmax = arr[i - 1];
            minmaxIndex = i - 1;
            for (int j = i; j < 4; j++) {
                if (minmax > arr[j]) {
                    minmax = arr[j];
                    minmaxIndex = j;
                }
            }
            swap(arr[i - 1], arr[minmaxIndex]);
        }
    }

    else {
        for (int i = 1; i < 4; i++) {
            minmax = arr[i - 1];
            minmaxIndex = i - 1;
            for (int j = i; j < 4; j++) {
                if (minmax < arr[j]) {
                    minmax = arr[j];
                    minmaxIndex = j;
                }
            }
            swap(arr[i - 1], arr[minmaxIndex]);
        }
    }
}
