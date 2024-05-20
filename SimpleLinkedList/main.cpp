#include <iostream>

using namespace std;

template <typename T> class Node{//----------------------Simple linked list Node
    public:
        T Data;
        Node <T> *Next;
    Node(T _Data):Data(_Data),Next(nullptr){}    
};//----------------------------------------------------------------------------


template <typename T> class SLL{//----------------------------Simple linked list
    private:
        Node<T> *Root=nullptr;
        Node<T> *Tail=nullptr;
        int N_nodes=0;
    //---------------    
    void DeleteSLL();
    //---------------
    public:
        SLL(): Root(nullptr),N_nodes(0){}
        ~SLL(){ DeleteSLL();}
    //---Getters---
    T GetRootData();
    T GetTailData();
    Node <T> *GetRootPointer(){return Root;};
    //---Methods---
    void Insert (const T &data);
    void Display();
    void InsertAtIdx(const T &data,const int idx);
    void DeleteAtIdx(const int idx);
    void ReverseList();
    void ReverseRList(Node <T> *P);//Reverse recursive list 
};

template <typename T> T SLL <T>::GetRootData(){
    return Root->Data;
}

template <typename T> T SLL <T>::GetTailData(){
    return Tail->Data;
}

template <typename T> void SLL<T>::ReverseRList(Node <T>*P){
    if(P==Tail){//When you reach to the end
        Tail=Root;
        Tail->Next=nullptr;
        Root=P;
    }else{
        Node <T> *B=P;
        P=P->Next;
        ReverseRList(P);
        P->Next=B;
    }
}

template <typename T> void SLL<T>::ReverseList(){
    if(N_nodes>=2){//It can be reversed 
        Node <T> *B=Root;//Before
        Node <T> *A=Root->Next;//After
        Node <T> *C=A->Next;//To know where to A will jump
        
        B->Next=nullptr;//Make now root be the tail
        while(C!=nullptr){
            A->Next=B;
            B=A;
            A=C;
            C=C->Next;
        }
        A->Next=B;//Last conection 
        
        Tail=Root;
        Root=A;
    }
}

template <typename T> void SLL<T>::DeleteAtIdx(const int idx){
    Node <T> *B=nullptr;//Before
    Node <T> *A=Root;//After
    if(N_nodes>=1 && idx<=N_nodes && idx>=0){
        if(idx==0){//If is at the root 
            B=Root;
            Root=Root->Next;
            delete (B);
            N_nodes--;
        }else if(idx==N_nodes-1){//If is the last node
            while(A->Next!=Tail){
                A=A->Next;
            }            
            delete (Tail);
            Tail=A;
            Tail->Next=nullptr;
            N_nodes--;
            
        }else{
            
            for(int i=0;i<idx;i++){
                B=A;
                A=A->Next;
            }
            B->Next=A->Next;
            delete (A);
            N_nodes--; 
        }
    }else{
        cout<<"\nError idx not valid"<<endl;
    }
}

template <typename T> void SLL<T>::InsertAtIdx(const T &data,const int idx){//--
    Node <T> *B=nullptr;//Before
    Node <T> *A=Root;//After
    if(N_nodes>1 && idx<=N_nodes && idx>=0){
        if(idx==0){//If is at the root 
            B=new Node<T>(data);
            B->Next=Root;
            Root=B;
            N_nodes++;
        }else if(idx==N_nodes){//Insert in the Tail
            Tail->Next= new Node<T>(data);
            Tail=Tail->Next;
            N_nodes++;
        }else{
            
            for(int i=0;i<idx;i++){
                B=A;
                A=A->Next;
            }
            B->Next = new Node<T>(data);
            B->Next->Next=A;//Connect
            
            N_nodes++;
        }
    }else{
        cout<<"\nError idx not valid"<<endl;
    }
}//-----------------------------------------------------------------------------

template <typename T> void SLL<T>::Insert(const T &data){
    if(Root==nullptr){
        Root=new Node<T>(data);
        Tail=Root;
        N_nodes++;
    }else{
        Tail->Next= new Node<T>(data);
        Tail=Tail->Next;
        N_nodes++;
    }
}

template <typename T> void SLL<T>::Display(){
    Node <T> *P=Root;
    cout<<"\nDisplaying data:";
    while(P!=nullptr){
        cout<<P->Data<<" ";
        P=P->Next;
    }
    cout<<"\nNumber of nodes:"<<N_nodes;
    cout<<"\nRoot:"<<GetRootData()<<" Tail:"<<GetTailData();
    cout<<endl;
}

template <typename T> void SLL<T>::DeleteSLL(){
    Node <T> *P=Root;
    Node <T> *ToDelete=Root;
    while(P!=nullptr){
        P=P->Next;
        delete (ToDelete);
        ToDelete=P;
    }
    N_nodes=0;
}

int main(){
    
    SLL<int> L1;//Simple linked list object
    
    L1.Insert(8);
    L1.Insert(9);
    L1.Insert(3);
    
    //L1.InsertAtIdx(2,3);
    //L1.Display();
    //L1.DeleteAtIdx(3);
    //L1.DeleteAtIdx(3);
    
    //L1.Display();
    
    L1.ReverseList();
    L1.Display();
    
    //L1.ReverseList();
    L1.ReverseRList(L1.GetRootPointer());
    L1.Display();
       
    return 0;
}






