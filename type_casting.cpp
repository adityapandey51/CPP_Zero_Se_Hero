// Example of how typecasting works

#include<iostream>
using namespace std;

int main(){
    char ch ;
    cout<< "Enter the character\n";
    cin>>ch;

    if (ch>96&&ch<123){
        cout<<"character is lower case";
    }
    else if (ch>64 && ch <91){
        cout<<"character is uppercase";
    
    }
    else if (ch >47 && ch <58){
        cout<<"character is numeric";
    }
    else{cout<<"charater is some other symbol";}
}