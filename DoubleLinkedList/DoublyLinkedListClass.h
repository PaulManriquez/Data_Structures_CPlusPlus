#ifndef DOUBLYLINKEDLISCLASS_H_
#define DOUBLYLINKEDLISCLASS_H_
using namespace std;

class Node{//------------------------------------------Since Node is a structure
    public:
        Node(int _Data):Prev(nullptr),Data(_Data),Next(nullptr){}//Constructor
        Node *Prev;
        int Data;
        Node *Next;
};//----------------------------------------------------------------------------

class DoublyLinkedList{
    private:
        Node *Root;//First node
        Node *Tail;//Last node
        int  N_Nodes;//Counter 
    public:
        DoublyLinkedList():Root(nullptr),Tail(nullptr),N_Nodes(0){}//Constructor
        ~DoublyLinkedList(){
            Node *Current=Root,*Delete=nullptr;
            while(Current!=nullptr){
                Delete=Current;
                Current=Current->Next;
                delete(Delete);
            }
        }
    //---Getters---
    int GetN_Nodes(){return N_Nodes;}
    //---Methods---
    void Insert(int data);
    void Display();
    void DisplayBackwards();
    void InsertAtIdx();
    void DeleteAtIdx();
    void ReverseDoubleList();
};

void DoublyLinkedList::Insert(int data){//Insert a new element in the DoublyLinkedList
    
    if(Root==nullptr){//When is the first element 
        Root=new Node(data);
        Tail=Root;
        N_Nodes++;
    }else{
        Tail->Next=new Node(data);
        Tail->Next->Prev=Tail;
        Tail=Tail->Next;
        N_Nodes++;
    }
}//-----------------------------------------------------------------------------

void DoublyLinkedList::Display(){//----------------------Display DoublyLinkedList
    Node *P=Root;
    cout<<"\nDisplaying DoublyLinkedList:";
    while(P!=nullptr){
        cout<<P->Data<<" ";
        P=P->Next;
    }
}//-----------------------------------------------------------------------------

void DoublyLinkedList::InsertAtIdx(){//----------------------------Insert at idx 
    int idx=0,n=0;
    cout<<"\nIntroducre the index to Insert between 0 and "<<GetN_Nodes()-1<<":";
    cin>>idx;
    if(idx>=0 && idx<= (GetN_Nodes()-1) ){//Is in range
        cout<<"\nIntroduce the number to add:";
        cin>>n;
        
        Node *P=Root;
        Node *T=nullptr;
        Node *Pb=nullptr;
        if(idx==0){//insert where is the Root
            T=new Node(n);
            T->Next=Root;
            Root->Prev=T;
            Root=T;
        }else if(idx==GetN_Nodes()-1){
            T=new Node(n);
            T->Prev=Tail;
            Tail->Next=T;
            Tail=T;
        }else{
            for(int i=0;i<idx;i++){
                P=P->Next;
            }
                T=new Node(n);
                Pb=P->Prev;
        
                Pb->Next=T;//Back conection 
                T->Prev=Pb;
        
                T->Next=P;//Front conection
                P->Prev=T;
        }
        N_Nodes++;//Counter
    }else{
        cout<<"\nOut of range";
    }
}//----------------------------------------------------------------------------- 

void DoublyLinkedList::DisplayBackwards(){//---DisplayBackwards DoublyLinkedList
    Node *P=Tail;
    cout<<"\nDisplaying DoublyLinkedList backwards:";
    while(P!=nullptr){
        cout<<P->Data<<" ";
        P=P->Prev;
    }
}//-----------------------------------------------------------------------------

void DoublyLinkedList::DeleteAtIdx(){//--------------------------Delete by index
    int idx=0;
    cout<<"\nIntroducre the index to delete between 0 and "<<GetN_Nodes()-1<<":";
    cin>>idx;
    if(idx>=0 && idx<= (GetN_Nodes()-1) ){//Is in range
        
        Node *ToDelete=Root;
        Node *Pb=nullptr;
        if(idx==0){//Delete where is the Root
            Root=Root->Next;
            Root->Prev=nullptr;
            
            delete(ToDelete);
            ToDelete=nullptr;
        }else if(idx==GetN_Nodes()-1){//When is the Tail
            ToDelete=Tail;
            
            Tail=Tail->Prev;
            Tail->Next=nullptr;
            delete(ToDelete);
            ToDelete=nullptr;
        }else{
            for(int i=0;i<idx;i++){
                ToDelete=ToDelete->Next;
            }
                Pb=ToDelete->Prev;
        
                Pb->Next=ToDelete->Next;//Back conection 
                ToDelete->Next->Prev=Pb;
                
                delete(ToDelete);
                ToDelete=nullptr;
        }
        N_Nodes--;//Counter
    }else{
        cout<<"\nOut of range";
    }
}//-----------------------------------------------------------------------------

void DoublyLinkedList::ReverseDoubleList(){//---------Double linked list reverse
    if(N_Nodes>=2){
        Node *Current=Root;
        Node *T=nullptr;
        
        while(Current!=nullptr){
            T=Current->Next;
            Current->Next=Current->Prev;
            Current->Prev=T;
            Current=Current->Prev;
        }
        T=Root;
        Root=Tail;
        Tail=Root;
    }
}//-----------------------------------------------------------------------------

#endif