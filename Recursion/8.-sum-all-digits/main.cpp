//Program to sum all the entire digits of a integrer number 
//Programmer: Paul Manriquez 
#include <iostream>
using namespace std;

int sumAllNumbers(int n){
    if(n/10==0){
        return n%10;
    }else{
        return (n%10) + sumAllNumbers(n/10);
    }
}

int main(){
    
    cout<<sumAllNumbers(532);
    
    return 0;
}