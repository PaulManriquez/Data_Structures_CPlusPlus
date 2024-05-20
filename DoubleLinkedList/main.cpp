//Programmer Paul Manriquez November 2023
//DoublyLinkedList Class

#include <stdio.h>
#include <iostream>
#include "DoublyLinkedListClass.h"
using namespace std;

int main(){
    
    DoublyLinkedList DLL1;
    
    DLL1.Insert(3);
    DLL1.Insert(2);
    DLL1.Insert(8);
    DLL1.ReverseDoubleList();
    DLL1.Display();
    
    
    return 0;
}
