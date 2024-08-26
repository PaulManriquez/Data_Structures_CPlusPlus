//Print N even or Odd numbers 
//Programmer: Paul Manriquez 

#include <iostream>
using namespace std; 

void PrintEvenN(int N){//Print even numbers 
    if(N==-1){
        return;
    }else{
        PrintEvenN(N-1);
        if(N%2==0) 
            cout<<N<<" ";
    }
}

void PrintOddN(int N){//Print odd numbers 
    if(N==-1){
        return;
    }else{
        PrintOddN(N-1);
        if(N%2==1) 
            cout<<N<<" ";
    }
}


int main(){
    
    PrintEvenN(10);
    cout<<endl;
    PrintOddN(10);
    
    return 0;
}
