//Get nth Fibonacci number
//Programmer: Paul Manriquez 

#include <iostream>
using namespace std;

int Fibo(int n){
    if(n<=0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return Fibo(n-2) + Fibo(n-1);
    }
}


int main(){
    
    //Print nth factorial numbers 
    for(int i=0;i<=10;i++){
        cout<<Fibo(i)<<" ";    
    }
    

    return 0;
}