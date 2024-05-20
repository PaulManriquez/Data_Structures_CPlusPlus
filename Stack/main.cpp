//Stack class using template
//Programmer Paul Manriquez november 2023 
#include <iostream>
#include <vector>

using namespace std;


template <typename T> class Stack{//--------------------------------------------
    private:
        vector<T> Elements;//Since the Elements are being stored in the vector, we don't have to explicity create a destructor to Stack class
                          //Only if in the class "Stack" in this case, we use the key new, we need to deallocate this memory with its destructor
    public:
        Stack() = default;//default constructor
        Stack(const vector<T> &initialElements) : Elements(initialElements){}//Parameterized constructor
    
    //---Methods---
                     //Since the value only needs to be read, we pass by reference 
    void push(const T &value){
        Elements.push_back(value);
    }
    //----
    void pop(){
        if(!Elements.empty()){
            Elements.pop_back();
        }else{
            cerr<<"Stack is empty, cannot pop"<<endl;
        }
    }
    //---
    T top(){
        if(!Elements.empty()){
            return Elements.back();//Is like peak function, just return the number, but it don't be deleted in the Stack
        }else{
            cerr<<"Stack is empty"<<endl;
            return T();
        }
    }
    //---
    bool isEmpty(){
        return Elements.empty();//Return a 0 if is not empty
    }
    //---
};//----------------------------------------------------------------------------

int main(){
    
    Stack <int> StackI;
    
    StackI.push(10);
    StackI.push(20);
    StackI.push(30);
    
    //--------------------
    
    Stack <string> StackS;//----------------------------------------------------
    StackS.push("hi");
    StackS.push("My");
    StackS.push("Friends");
    
    while(!StackS.isEmpty()){
        cout<<StackS.top()<<" ";
        StackS.pop();
    }//-------------------------------------------------------------------------
        
    
    return 0;
}


