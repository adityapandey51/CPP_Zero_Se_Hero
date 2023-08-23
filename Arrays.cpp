#include <iostream>
using namespace std;


// Minimum in an array
int get_min(int arr[],int size){
    int mini=INT_MAX;
    for (int i=0;i<size;i++){
      mini=min(mini,arr[i]);
    }
    return mini;
}

// Maximum in an array

int get_max(int arr[],int size){
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

// sum of elements of an array

int sum_of_elements(int arr[],int size){
    int sum =0;
    for (int i=0;i<size;i++){
        sum +=arr[i];
    }
    return sum;

}

// Reverse an  array

void reverse(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
 for (int i=0;i<size;i++){
    cout<<arr[i];
 }
}

// int main(){
//     int arr[6]={1,2,3,4,5,6};
//     reverse(arr,6);
// }

// Reverse aternate elements in an array

void reverse_alternate(int arr[],int size){
    int i=0;
    while(i+1<size){
        swap(arr[i],arr[i+1]);
        i=i+2;
    }
     for (int i=0;i<size;i++){
    cout<<arr[i];
 }
}

// int main(){
//     int arr[6]={1,2,3,4,5,6};
//     reverse_alternate(arr,6);
// }


// you have been given an integer arr of size N; where N =2M+1,
// Now in the given arr 'M' no's are present twice and one number is present only once
// You need to find and return theat no. which is unique in that arr

int unique(int arr[],int size){
    int sol=0;
    for (int i=0;i<size;i++){
        sol=sol^arr[i];
    }
    return sol;
}

// int main(){
//     int arr[9]={1,1,2,2,3,4,4,5,3};
//     int a=unique(arr,9);
//     cout<<a;
// }