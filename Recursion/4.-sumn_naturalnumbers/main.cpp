//Sum of N Natural numbers
//Programmer: Paul Manriquez
#include <iostream>
using namespace std;

int SumNNatural(int N){
    if(N==1){
        return N;
    }else{
        return N + SumNNatural(N-1);
    }
}

int main(){
    
    cout<<SumNNatural(5);
    
    return 0;
}