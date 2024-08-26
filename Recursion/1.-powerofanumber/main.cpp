//Find power of a number using recursion 
//Programmer: Paul Manriquez 

#include <iostream>
using namespace std;

float Power(float base,int Pow){
    if(Pow==0){
        return 1;
    }else{
        return base * Power(base,Pow-1);
    }
}

int main(){
    
    cout<<Power(2.3,3);

    return 0;
}