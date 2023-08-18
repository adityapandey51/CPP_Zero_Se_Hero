#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    while (n<54){
        cout<<n<<"\n";
        n=n+1;
    }
}

// SUM OF EVEN NO'S PRESENT IN BETWEEN 1 TO N INTEGERS

int main(){
    int n;
    int sum=0;
    int i=1;
    cout<<"Enter the number";
    cin>>n;
    while (i<=n){
        if (i%2==0){
            sum=sum+i;
        }
        i++;
    }
    cout<<sum;
}

// PRIME NO'S
int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int count=0;
    int i=2;
    while (i<n)
    {
        if (n%i==0){
           count++;
        }
        i++;
    }
    if (count>=1){
        cout<<"it is not a prime";
    }else if (count<1 && n==1){
        cout<<"it is a  1";
    }else{
        cout<<"it is prime";
    }
}




