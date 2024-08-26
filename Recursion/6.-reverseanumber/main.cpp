//Find reverse of a number 
//Programmer: Paul Manriquez 

#include <iostream>
using namespace std;

void ReverseNumber(int n){//Display a number reversed  
    if(n==0){
        return;
    }else{
        int NewNumber = n/10;
        cout<<n%10<<" ";
        ReverseNumber(NewNumber);
    }
}//--------------------------------------------------

/*---------------------Reverse a number----------------------------------------- 
int getX(int n){
    int x=1;
    while(n/10!=0){
        x*=10;
        n/=10;
    }
    return x;
}


int reverseNumber(int n, int flag){
    
    static int ans;
    if(flag==0){
      ans=0;
    }
    if(n==0){
        //printf
        return 0;    
    }else{
        //printf("%d",n%10); 7 5 2
        ans+= (n%10) * getX(n);  
        reverseNumber(n/10,1);
        
        return ans;
         
    }
}
main 
                         //Number | flag to reset     
   printf("%d ",reverseNumber(257,0));
  
   printf("%d ",reverseNumber(239,0)); 

*/

//ChatGPT proposal
int reverseNumber(int n, int ans = 0) {
    if (n == 0) {
        return ans; // Base case: when n becomes 0, return the reversed number
    } else {
        return reverseNumber(n / 10, ans * 10 + n % 10); // Recur with the remaining digits and updated ans
    }
}


int main(){
    
    ReverseNumber(12345);
    
    return 0;
}