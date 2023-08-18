#include<iostream>
using namespace std;


// PATTERN 1

int main(){
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while (j<=n){
            cout<<j;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 2

int main(){
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while (j<=n){
            cout<<n-j+1;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 3

int main(){
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    int i=1;
    int count=1;
    while(i<=n){
        int j=1;
        while (j<=n){
            cout<<count;
            count++;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 4

int main(){
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    int i=1;
   
    while(i<=n){
        int j=1;
        while (j<=i){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 5

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
   
    while(i<=n){
        int j=1;
        while (j<=i){
            cout<<i;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 6

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
    int count =1;
   
    while(i<=n){
        int j=1;
        while (j<=i){
            cout<<count;
            count++;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 7

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
   
    while(i<=n){
        int j=1;
        while (j<=i){
            cout<<i+j-1;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}


// PATTERN 8

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
   
    while(i<=n){
        int j=1;
        while (j<=i){
            cout<<i-j+1;
            j=j+1;
        }
        cout<<endl;
        i++;
    }

}

// PATTERN 9

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
    char ch=97;
   
    while(i<=n){
        int j=1;
        while (j<=n){
            cout<<ch;
            j=j+1;
        }
        cout<<endl;
        ch++;
        i++;
    }

}

// PATTERN 10

int main(){
    int i;
    int n;
    cout<<"NO.of rows"<<endl;
    cin>>n;
    i=1;
   
   
    while(i<=n){
         char ch=97;
        int j=1;
        while (j<=n){
            cout<<ch;
             ch++;
            j=j+1;
        }
        cout<<endl;
       
        i++;
    }

}

// PATTERN 11

 int main(){
    cout<<"No.of rows";
    int n;
    cin>>n;
    int i =1;
    char ch=97;
    while (i<=n){
        int j=1;
        while(j<=n){
            char a=ch+i+j-2;
            cout<<a;
            j++;
        }
        cout<<endl;
        i++;

            
        
    }
 }

// PATTERN 12

int main(){
    int i=1;
    int n;
    cout<<"Enter the No. of rows\n";
    cin>>n;
    char ch='A';
    while (i<=n){
        int j=1;
        while(j<=i){
            cout<<ch;
            j++;
        }
        cout<<endl;
        ch++;
        i++;
    }

}

// PATTERN 13

int main(){
    int i=1;
    int n;
    cout<<"Enter the No. of rows\n";
    cin>>n;
    char ch='A';
    while (i<=n){
        int j=1;
        while(j<=i){
           char a=ch+i+j-2;
            cout<<a;
            j++;
        }
        cout<<endl;
        i++;
    }

}


// PATTERN 14

int main(){
    int i=1;
    int n;
    cout<<"Enter the No. of rows\n";
    cin>>n;
    char ch='A';
    while (i<=n){
        int j=1;
        while(j<=i){
           char a=ch-i+j-1+n;
            cout<<a;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// PATTERN 15

int main(){
    int i=1;
    int n;
    cout<<"Enter the no. of rows\n";
    cin>>n;
    while(i<=n){
        int j=1;
        while (j<=n-i){
            cout<<" ";
            j++;
        }
        int k=1;
        while (k<=i){
            cout<<"*";
            k++;
        }
        cout<<endl;
        i++;
    }
    
}

// PATTERN 16

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows\n";
    cin>>n;
    while(i<=n){
        int j=1;
        while (j<=n-i+1){
            cout<<"*";
            j++;
        }
        int k=1;
        while (k<=i){
            cout<<" ";
            k++;
        }
        cout<<endl;
        i++;
    }
}

// PATTERN 17

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows";
    cin>>n;
    while (i<=n){
        int j=1;
        while (j<i){
           cout<<" ";
           j++;
        }
        int k=1;
        while(k<=n-i+1){
           cout<<"*";
           k++;
        }
        cout<<endl;
        i++;
    }
}


// PATTERN 18

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows";
    cin>>n;
    while (i<=n){
        int j=1;
        while (j<i){
           cout<<" ";
           j++;
        }
        int k=1;
        while(k<=n-i+1){
           cout<<i;
           k++;
        }
        cout<<endl;
        i++;
    }
}

// PATTERN 19

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows";
    cin>>n;
    while (i<=n){
        int j=1;
        while (j<=n-i){
           cout<<" ";
           j++;
        }
        int k=1;
        while(k<=i){
           cout<<i;
           k++;
        }
        cout<<endl;
        i++;
    }
}

// PATTERN 20

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows";
    cin>>n;
    while (i<=n){
        int j=1;
        while (j<i){
           cout<<" ";
           j++;
        }
        int k=1;
        while(k<=n-i+1){
           cout<<i+k-1;
           k++;
        }
        cout<<endl;
        i++;
    }
}


// FINAL PATTERN

int main(){
    int i=1;
    int n;
    cout<<"enter the no. of rows";
    cin>>n;
    while(i<=n){
        int j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }
        int k=1;
        while (k<=i){
            cout<<k;
            k++;
        }
        int l=1;
        while(l<i){
            cout<<i-l;
            l++;
        }
        cout<<endl;
        i++;
    }
}