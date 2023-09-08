#include<iostream>
using namespace std;

bool isPrime(int n){
    for (int i=2;i<n;i++){
        if(n%i==0)return false; 
    }
    return true;
}
int main(){
    bool ans=isPrime(6);
    cout<<ans;
}

int gcd(int n,int m){

    while(n>0 && m>0){
        if (n>m){
            n=n-m;
        }else{
            m=m-n;
        }
    } 
    if (n==0) return m;
    if (m==0)return n;
}

// gcd(a,b)=gcd(a-b,b)=gcd(a%b,b)
// gcd(a,b)*lcm(a,b)=a*b

// MODULAR EXPONENTATION

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	int res=1;
	while(n>0){
		if(n&1){
			res=(1LL*(res)*(x)%m)%m;
		}
		x=1LL*(x)%m*(x)%m;
		n=n>>1;
	}
	return res;
}

