#include<iostream>
using namespace std;
int main(){
    int a=4;
    int b=6;
    cout<<(a & b) << endl;
    cout<<(a | b) << endl;
    cout<<(~ a) << endl;
    cout<<(a ^ b) << endl;

    // LEFT SHIFT- usually multiplies by 2 
    cout<<(a<<1)<<endl;

    // RIGHT SHIFT - usually divides by 2
    cout<<(a>>1)<<endl;
    
}