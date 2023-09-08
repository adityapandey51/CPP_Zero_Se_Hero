#include<iostream>
using namespace std;

int main(){
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[3][2]={{1,11},{2,22},{3,33}}
    int arr[3][4];

    // taking input
    int rows;
    int cols;
    for(int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    // same for output

    // SEARCH
    int element;//the element u wanna search
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (arr[i][j]==element)
               return 1;

            return 0;
        }
    }


    // ROW WISE SUM

    int arr1[rows];
    for (int i=0;i<rows;i++){
        int sum=0;
        for(int j=0;j<cols;j++){
            sum+=arr[i][j];
        }
        arr1[i]=sum;
    }

    // Largest row sum
    // just find the index of max value in arr1
    
}