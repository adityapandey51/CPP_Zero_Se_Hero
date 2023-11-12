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
            swap(arr[ans_ind ],arr[i]);
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

//merge sort
//time complexity=O(nlogn)
//auxilary space=O(n)
void merge(int arr[],int s,int e){
    int mid=s+((e-s)/2);
    int len1=mid-s+1;
    int len2=e-mid;

    int *arr1=new int[len1];
    int *arr2=new int[len2];
    int mainIndex=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainIndex++];
    }
    mainIndex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainIndex++];
    }

    int i=0;
    int j=0;
    mainIndex=s;
    while(i<len1 &&j<len2){
        if (arr1[i]<arr2[j]){
            arr[mainIndex++]=arr1[i++];
        }else{
             arr[mainIndex++]=arr2[j++];
        }
    }
    while(i<len1){
         arr[mainIndex++]=arr1[i++];
    }
    while(j<len2){
        arr[mainIndex++]=arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}

void mergeSort(int arr[],int s,int e){
    if(s>=e) return;
    int mid=s+((e-s)/2);
    mergeSort(arr,s,mid) ;
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

//worst case TC=O(n2)
//best case TC=O(nlogn)
//avg case TC=O(nlogn)
//auxilary space=O(n)
//Quick Sort
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for (int i=s+1;i<e+1;i++){
        if (arr[i]<pivot){
            count++;
        }
    }
    int indexOfPivot=s+count;
    swap(arr[s],arr[indexOfPivot]);
    int i=s;
    int j=e;
    while(i<j){
        // if (arr[s]>pivot && arr[e]<pivot){
        //     swap(arr[s],arr[e]);
        //     s++;
        //     e--;
        // }else if(arr[s]>pivot){
        //     e--;
        // }else if(arr[e]<pivot){
        //     s++;
        // }else{
        //     s++;
        //     e--;
        // }
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if (i<indexOfPivot && j>indexOfPivot){
            swap(arr[i],arr[j]);
        }
    }
    return indexOfPivot;
}

void QuickSort(int arr[],int s,int e){
    if (s>=e) return;

    int p=partition(arr,s,e);

    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);

}


