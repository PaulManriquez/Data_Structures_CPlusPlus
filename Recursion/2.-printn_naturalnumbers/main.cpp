//Printing natural numbers using recursion 
//Programmer: Paul Manriquez 
//This is a good exercise to know how the stack works
#include <iostream>
using namespace std;

void printNatural(int N){
    if(N==1){
        cout<<N<<" ";
    }else{
        printNatural(N-1);
        cout<<N<<" ";
    }
}

int main(){
    
    printNatural(17);
    
    
    return 0;
}