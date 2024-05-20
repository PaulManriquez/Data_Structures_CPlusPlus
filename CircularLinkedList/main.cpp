//Circular linked list 
//Programmer Paul Manriquez November 2023 
#include <iostream>
#include "CircularLinkedListClass.h"
using namespace std;

/*----Functions---
    //---Getters---
    int GetN_Nodes(){return N_Nodes;}
    //---Methods---
    void Insert(const T &data);
    void Display();
    void DeleteByIdx();
    void Reverse();
*/
int main(){
    
    //Int
    CircularLinkedList<int> CL1;
    CL1.Insert(7);
    CL1.Insert(2);
    CL1.Insert(9);
    CL1.Reverse();
    CL1.Display();
    
    
    //Char
    CircularLinkedList<char> CL2;
    CL2.Insert('a');
    CL2.Insert('e');
    CL2.Insert('i');
    CL2.Reverse();
    CL2.Display();
    
    
    //String
    CircularLinkedList<string> CL3;
    CL3.Insert("AEI");
    CL3.Insert("OU");
    CL3.Insert("YOU");
    CL2.Reverse();
    CL3.Display();
    
    return 0;
}

