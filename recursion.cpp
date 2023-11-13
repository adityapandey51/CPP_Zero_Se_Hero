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

//check palindrome
bool checkPalindrome(string str , int s,int e){
    if (s>e) return true;
    if (str[s]==str[e]){
        s++;
        e--;
        return checkPalindrome(str,s,e);
    } else{
        return false;
    }   
}

//bubble sort
void bubbleSort(int arr[],int size){
    if (size==0 || size==1) return;
    for (int i=0;i<size-1;i++){
        if (arr[0]>arr[1]){
            swap(arr[0],arr[1]);
        }
        bubbleSort(arr+1,size-1);
    }
   
}
// betterone
// void bubbleSort(int arr[],int size){
//     if (size==0 || size==1) return;
//     for (int i=0;i<size-1;i++){
//         if (arr[i]>arr[i+1]){
//             swap(arr[i],arr[i+1]);
//         }
//     }
//     bubbleSort(arr,size-1);
   
// }

//selection sort

void selectionSort(int arr[],int size){
    if (size==0 || size==1) return;

    
        int ans_ind=0;
        int key=arr[0];
        for (int j=1;j<size;j++){
            if (arr[j]<arr[ans_ind]){
                ans_ind=j;
            }
        }
        if (ans_ind!=0) {swap(arr[0],arr[ans_ind]);}

        selectionSort(arr+1,size-1);
    
}

//insertion sort
void insertion(int arr[],int size){
    if (size=0 ||size==1) return;
    
    insertion(arr,size-1);

    int i=size-1;
    int key=arr[i];
    int j=i-1;
    for (;j>=0;j--){
        if (arr[j]>key){
            arr[j+1]=arr[j];
        }
    }
    arr[j+1]=key;
    
}

//inverting count

int inversionCount(int arr[],int size){
    int count=0;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

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

void quickSort(int arr[],int s,int e){
    if (s>=e) return;

    int p=partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}




int main(){
    int arr[5]={31,22,76,41,234};
    quickSort(arr,0,4);
    for (int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }
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


//Rat in a maze problem

class Solution{
    private:
    bool isSafe(int newx,int newy,int n,vector<vector<int>> visited,vector<vector<int>> m ){
        if ((newx<n && newx>=0) && (newy>=0 && newy<n) && (visited[newx][newy]==0) && (m[newx][newy]==1)){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> m,int x,int y,int n,vector<string> &ans,string path,vector<vector<int>> visited){
        if (x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        int newx=x+1;
        int newy=y;
        if (isSafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,newx,newy,n,ans,path,visited);
            path.pop_back();
        }
        
        newx=x;
        newy=y-1;
        if (isSafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,newx,newy,n,ans,path,visited);
            path.pop_back();
        }
        
        newx=x-1;
        newy=y;
        if (isSafe(newx,newy,n,visited,m)){
            path.push_back('U');
            solve(m,newx,newy,n,ans,path,visited);
            path.pop_back();
        }
        
        newx=x;
        newy=y+1;
        if (isSafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,newx,newy,n,ans,path,visited);
            path.pop_back();
        }
        
        
        visited[x][y]=0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        string path="";
        int srcx=0;
        int srcy=0;
        solve(m,srcx,srcy,n,ans,path,visited);
        return ans;
    }
};
