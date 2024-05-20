//Queue class template
//Programmer Paul Manriquez November 2023 
#include <iostream>
#include <queue>
using namespace std;

template <typename T> class Queue{
    private:
        queue<T> Myqueue;
    public:
        Queue() = default;//default constructor
    //---Getter---
    size_t Getqueuesize(){
        return Myqueue.size();
    }
    //---Method---
    void Inqueue(const T &data){
        Myqueue.push(data);
    }
    //
    void Dequeue(){
        if(!Myqueue.empty()){
            Myqueue.pop();
        }else{
            cout<<"\nQueue is empty"<<endl;
        }
    }
    //
    T front(){
        if(!Myqueue.empty()){
            return Myqueue.front();
        }else{
            cerr<<"\nQueue is empty";
            return T();
        }
    }
    //
    bool isEmpty(){
        return Myqueue.empty();
    }
    //
    void Display();
};

template <typename T> void Queue<T>::Display(){
    cout<<"Displaying queue:";
    queue<T> Copy=Myqueue;
    while(!Copy.empty()){
        cout<<Copy.front()<<" ";
        Copy.pop();//since we are using a copy of a queue there is not problem to use pop
    }
}//-----------------------------------------------------------------------------

int main(){
    //Int 
    Queue <int>QueueI;
    QueueI.Inqueue(8);
    QueueI.Inqueue(7);
    QueueI.Inqueue(2);
    //cout<<QueueI.Getqueuesize();
    QueueI.Dequeue();
    //QueueI.Display();
    
    //String 
    Queue <string>QueueS;
    
    QueueS.Inqueue("Hi");
    QueueS.Inqueue("Everyone");
    QueueS.Inqueue("My name is geovany georgo");
    //cout<<QueueS.Getqueuesize();
    //QueueI.Dequeue();
    QueueS.Display();
    
    
    return 0;
}

