//Sum of N even or Odd numbers
//Programmer: Paul Manriquez 

#include <stdio.h>
#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

int sumEven(int start, int end) {
    // Base case: if start exceeds end, return 0
    if (start > end) {
        return 0;
    }
    
    // Recursive case: add start to the sum if it's even, then move to the next number
    if (start % 2 == 0) {
        return start + sumEven(start + 2, end); // Skip odd numbers, move to next even number using +2 
    } else {
        return sumEven(start + 1, end); // Skip odd numbers, move to next number using +1 
    }
}

int sumOdd(int start, int end) {
    // Base case: if start exceeds end, return 0
    if (start > end) {
        return 0;
    }
    
    // Recursive case: add start to the sum if it's odd, then move to the next number
    if (start % 2 == 1) {
        return start + sumOdd(start + 1, end); // Skip even numbers, move to next even number using +1 
    } else {
        return sumOdd(start + 1, end); // Skip even numbers, move to next number using +1 
    }
}


int main() {
    int start = 1, end = 5; 
    cout <<sumEven(start, end)<<endl;
    
    cout<<sumOdd(2,5);
    
    
    return 0;
}
