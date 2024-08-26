//Factorial of a number
//Programmer: Paul Manriquez 
#include <iostream>
using namespace std;

int Fact(int n){
    if(n==1){
        return n;
    }else{
        return n * Fact(n-1);
    }
    
}

int main(){
    
    cout<<Fact(3);
    
    return 0;
}