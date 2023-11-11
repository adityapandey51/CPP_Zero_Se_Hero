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

int main(){
    int n=8;
    int fact=fibonacci(n);
    cout<<"factorial of n is => "<<fact<<endl;
}