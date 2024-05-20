#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_

using namespace std;

template <typename T> class Node{//-------------------------Node class structure
    public:
        T Data;
        Node<T> *Next;
        Node(T _Data):Data(_Data),Next(nullptr){}
};//----------------------------------------------------------------------------

template <typename T> class CircularLinkedList{
    private:
        Node<T> *Root=nullptr;
        Node<T> *Tail=nullptr;
        int     N_Nodes=0;
    public:
        CircularLinkedList():Root(nullptr),Tail(nullptr),N_Nodes(0){}//Constructor
        ~CircularLinkedList(){
            Node<T> *P=Root;
            Node<T> *ToDelete=nullptr;
            
            Tail->Next=nullptr;//break the CircularLinkedList, traverse it directly
            while(P!=nullptr){
                ToDelete=P;
                P=P->Next;
                delete(ToDelete);
            }
        }
    //---Getters---
    int GetN_Nodes(){return N_Nodes;}
    //---Methods---
    void Insert(const T &data);
    void Display();
    void DeleteByIdx();
    void Reverse();
};

template <typename T> void CircularLinkedList<T>::Insert(const T &data){
    if(Root==nullptr){//Is the first node 
        Root = new Node<T>(data);
        Tail = Root;
        Root->Next=Root;//Points to himself mading it circular 
        N_Nodes++;
    }else{
        Tail->Next= new Node<T>(data);
        Tail=Tail->Next;
        Tail->Next=Root;
        N_Nodes++;
    }
}//-----------------------------------------------------------------------------

template <typename T> void CircularLinkedList<T>::Display(){//------------------
    Node<T> *P=Root;
    cout<<"\nDisplaying CircularLinkedList:";
    do{
        cout<<P->Data<<" ";
        P=P->Next;    
    }while(P!=Root);
}//-----------------------------------------------------------------------------

template <typename T> void CircularLinkedList<T>::DeleteByIdx(){//--------------
    int idx=0;
    cout<<"\nInsert the index to delete from 0 to "<<GetN_Nodes()-1<<":";
    cin>>idx;
    if(idx>=0 && idx<=GetN_Nodes()-1){//If is in range you can delete 
        //Set where to delete 
        Node <T> *P=Root;
        Node <T> *Pb=nullptr;
        for(int i=0;i<idx;i++){
            Pb=P;
            P=P->Next;
        }
        if(P==Root){//special case when is the root
            Tail->Next=nullptr;//
            Root=Root->Next; //Re connect the Tail    
            Tail->Next=Root;//
            
            delete(P);
        }else{//General case, check if the last was equal to the tail 
            Pb->Next=P->Next;//Jump and join
            delete(P);
            if(P==Tail){//If what you delete was the Tail case 
                Tail=Pb;
            }//------------------------------------------
        }
         
        N_Nodes--;
    }
}//-----------------------------------------------------------------------------

template <typename T> void CircularLinkedList <T>::Reverse(){
    Node <T> *Pb=Root,*P=Root->Next,*Pa=Root->Next->Next;
    Node <T> *Temp=nullptr;
    
    if(N_Nodes>2){//General Case
        //Temporary desconect
        Tail->Next=nullptr;
        while(P!=nullptr){
            P->Next=Pb;
            Pb=P;
            P=Pa;
            if(Pa!=nullptr){//If is diferent to nullptr you can do another step 
                Pa=Pa->Next;
            }
        }
        Temp=Root;
        
        Root->Next=Tail;
        Root=Tail;
        Tail=Temp;    
    }else if (N_Nodes==2){//When are only 2 nodes
        Temp=Root;
        Tail->Next=nullptr;
        Root=Tail;
        Tail=Temp;
        Root->Next=Tail;
    }else{
        cerr<<"\nNo enough numbers to reverse";
    }
    
}
#endif