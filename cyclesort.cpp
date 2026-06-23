#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void cyclic(vector<int>& arr) {
    int i = 0;
    while (i < arr.size()) {
        int correct = arr[i] - 1;   // value ko index bana rahe hain
        if (arr[i] != arr[correct]) {
            swap(arr, i, correct);
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3, 5, 2, 1, 4};

    cyclic(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}