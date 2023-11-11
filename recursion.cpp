#include <iostream>
using namespace std;


//factorial
int factorial(int n){
    if (n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

//fibonacci series
int fibonacci(int n){
    if (n==1 || n==0){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

//SAY DIGIT
void sayDigit(int n,string arr[]){
    if (n==0) {
        return;
    };

    int digit=n%10;
    n=n/10;

    sayDigit(n,arr);

    cout<<arr[digit]<<" " ;
}

//isSorted
bool isSorted(int arr[],int size){
    if (size==0 || size==1) return true;

    if(arr[0]>arr[1]) return false;
    else{
        return isSorted(arr+1,size-1);
    }
}

// sum of elements in an array
int sum(int arr[],int size){
    if (size==0) return 0;
    if (size==1)return arr[0];
    else{
        return arr[0]+sum(arr+1,size-1);
    }

}

//linear search
bool linearSearch(int arr[],int size,int key){
    if (size==0) return false;
    if (arr[0]==key) return true;
    
    return linearSearch(arr+1,size-1,key);
    
}

//binary search
bool binarySearch(int arr[],int s,int e,int key){
    if (s>e) return false;

    int mid=s+((e-s)/2);
    if (arr[mid]==key)return true;
    else if (arr[mid]> key) return binarySearch(arr,s,mid-1,key);
    else{
        return binarySearch(arr,mid+1,e,key);
    }

}
int main(){
    int arr[5]={1,2,3,4,5};
    string ar[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n=4;
    int fact=fibonacci(n);
    sayDigit(n,ar);
    cout<<endl<<endl;
    bool isSort=isSorted(arr,5);
    cout<<"hello"<<endl;
    int ans=sum(arr,5);

    cout<<"the sum of the array is "<<ans<<endl;
    cout<<endl<<endl;
    cout<<"array is sorted or not "<<isSort<<endl;
    cout<<endl<<endl;
    cout<<"factorial of n is => "<<fact<<endl;
}