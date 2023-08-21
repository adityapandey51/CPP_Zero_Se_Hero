// decimal to binary

#include<iostream>
using namespace std;
#include<math.h>

int decimal_to_binary (int n){
    int ans=0;
    int i=0;
    while (n!=0){
        int a=n&1;
        ans=(a*pow(10,i))+ans;
        i++;
        n=n>>1;
    }
    return ans;

}

int main(){
    int n;
    cout<<"enter the no.";
    cin>>n;
    int ans;
    if (n<0){
        ans=~n+1;
        ans=decimal_to_binary(ans);
    }
    else{
        ans=decimal_to_binary(n);
    }
    cout<<ans;

}


