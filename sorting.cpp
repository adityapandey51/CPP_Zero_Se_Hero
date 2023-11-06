#include<iostream>
using namespace std;

// SELECTION SORT 
// BEST CASE TIME COMPLEXITY-O(N2)
// WORST CASE-O(N2)
// SPACE COMP.-O(1)
void selection_sort(int arr[],int size){
    for (int i=0;i<size;i++){
        int ans_ind=i;
        for(int j=i+1;j<size;j++){
            if (arr[j]<arr[ans_ind]){
                ans_ind=j;
            }
        }
        if(ans_ind!=i){
            swap(arr[j],arr[i]);
        }
    }
}


// BUBBLE SORT
// BEST CASE TIME COMPLEXITY-O(n)
// WORST CASE-O(N2)
// SPACE COMP.-O(1)

void bubble_sort(int arr[],int size){
    for (int i=0;i<size-1;i++){
        bool change=false;
        for (int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                change=true;
            }
        }
        if (!change){
            break;
        }
    }
}

//  INSERTION SORT
// BEST CASE TIME COMPLEXITY-O(n)
// WORST CASE-O(N2)
// SPACE COMP.-O(1)

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


