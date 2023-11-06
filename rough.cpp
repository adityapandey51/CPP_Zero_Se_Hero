#include<iostream>
using namespace std;


void swapalt(int arr[],int size){
    for (int i=0;i<size-1;i=i+2){
        swap(arr[i],arr[i+1]);
    };
    
}

int main(){
    int arr[4]={1,2,3,4};
    swapalt(arr,4);
    for(int i=0;i<4;i++ ) {
        cout << arr[i];
    }

}