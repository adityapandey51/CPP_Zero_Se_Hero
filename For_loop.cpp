// Fabonacii series - first n no.s

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int a=0;
    int b=1;
    int sum;
    cout<<a;
    cout<<b;
    for(int i=1;i<=n-2;i++){
        sum=a+b;
        cout<<sum;
        a=b;
        b=sum;
    }
}

// PRIME NO.

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    bool isprime=1;
    for (int i=2;i<n;i++){
        if (n%i==0){
             cout<<"Its not prime "<<i;
             isprime=0;
             break;
        }
    }
    if (isprime){
        cout<<"it is prime";
    }
}