// nth term of 3n+7 ap
#include <iostream>
using namespace std;

// int nth_term_of_ap(int n){
//     return ((3*(n-1))+7);
// }

// int main(){
//     int n;
//     cout<<"enter the value of n\n";
//     cin>>n;
//     cout<<"the nth term is"<<nth_term_of_ap(n)<<endl;
// }

// No. of set bits in a &b

int no_of_set_bits(int a,int b){
    int count =0;
    while (a!=0){
        if (a&1){
            count++;
        }
        a=a>>1;
    }
    int count1=0;
    while(b!=0){
        if (b&1){
            count1++;
        }
        b=b>>1;
    }
    return count+count1;
}

int main(){
    int a,b;
    cout<<"Enter first no.\n";
    cin>>a;
     cout<<"Enter second no.\n";
    cin>>b;
    cout<<no_of_set_bits(a,b);
    
}