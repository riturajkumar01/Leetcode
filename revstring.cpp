#include<iostream>
using namespace std;
void bubblesort(int arr[] , int n){
    for(int i =0; i<n-1; i++){
        bool swapped = false; // Flag to check if any swapping occurred
        for(int j =0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
        break;
    }
}
int main(){
    int n;
    int arr[100];
    cout << "Enter the number of elements: ";
    cin>>n;
    cout << "Enter the elements: ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout << "Bubble sorted Array: ";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}