//AVL Tree class 
//Programmer Paul Manriquez January 2024
#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

template <typename T> class NodeTree{//--------------------------------Node Tree
    public:
        NodeTree <T> *Lchild;
        T Data;
        NodeTree <T> *Rchild;
        int Height;
    NodeTree(T _Data):Lchild(nullptr),Data(_Data),Rchild(nullptr),Height(1){}    
};//----------------------------------------------------------------------------


template <typename T> class AVL_T{
    private:
        NodeTree <T> *Root=nullptr;
        int N_nodes=0;
    //----------SubRoutine-----------------
    int NodeHeight(NodeTree<T> *P);
    int BalanceFactor(NodeTree<T> *P);
    NodeTree<T>*LLRotation(NodeTree<T> *P);
    NodeTree<T>*RRotation(NodeTree<T> *P);
    NodeTree<T>*LRRotation(NodeTree<T> *P);
    NodeTree<T>*RLRotation(NodeTree<T> *P);
    //--
    NodeTree<T>*FindMin(NodeTree<T> *P);
    //--
    void DeleteAVLT(NodeTree<T> *P);
    //-------------------------------------
    public:
        AVL_T():Root(nullptr),N_nodes(0){}
        ~AVL_T(){DeleteAVLT(Root);}
    
    //---Getters---
    NodeTree<T> *GetRoot(){return Root;}
    
    //---Methods---
    NodeTree<T> *InsertIn(const T &data,NodeTree<T> *P);
    void InOrder(NodeTree<T> *P);
    void DisplayTreeByLevel();
    NodeTree<T> *DeleteNodeTree(NodeTree<T>*P,const T &data);
};

template <typename T> NodeTree<T>* AVL_T<T>::InsertIn(const T &data, NodeTree<T> *P){
    if(Root==nullptr){//Is the first case 
        Root = new NodeTree<T>(data);
        N_nodes++;
        return Root;
    }else if(P==nullptr){
        P = new NodeTree<T>(data);
        N_nodes++;
        return P;
    }else{
        if(data < P->Data){
            P->Lchild = InsertIn(data , P->Lchild);
        }else if(data > P->Data){
            P->Rchild = InsertIn(data , P->Rchild);
        }else{
            cout<<"\nData repeated no valid"<<endl;
            return nullptr;
        }
    }
    
    P->Height=NodeHeight(P);//Calculate the current Height
    
    if( (BalanceFactor(P)==2) && (BalanceFactor(P->Lchild)==1)){//LLRotation
        P = LLRotation(P);
    }else if( (BalanceFactor(P)==-2) && (BalanceFactor(P->Rchild)==-1) ){//RRotation
        P = RRotation(P);
    }else if((BalanceFactor(P)==2) && (BalanceFactor(P->Lchild)==-1) ){//LRRotation
        P = LRRotation(P);
    }else if( (BalanceFactor(P)==-2) && (BalanceFactor(P->Rchild)==1) ){//RLRotation
        P = RLRotation(P);
    }
    
    return P;
}

template <typename T> void AVL_T<T>::InOrder(NodeTree <T> *P){
    if(P!=nullptr){
        InOrder(P->Lchild);
        cout<<P->Data<<" ";
        InOrder(P->Rchild);
    }
}

//-----------------------AVL SubRoutines----------------------------------------
template <typename T> int AVL_T<T>::NodeHeight(NodeTree<T> *P){
    int LeftHight=0,RightHeight=0;
    
    LeftHight   = (P && P->Lchild)? P->Lchild->Height:0; //If the child exist assign this value
    RightHeight = (P && P->Rchild)? P->Rchild->Height:0;//If the child exist assign this value 
    
    return (LeftHight > RightHeight)? LeftHight+1:RightHeight+1;//Return the greater value of the two
    //this will update the Height of the Node to be evaluated 
}

template <typename T> int AVL_T<T>::BalanceFactor(NodeTree<T> *P){
    int LeftHight=0,RightHeight=0;
    
    LeftHight   = (P && P->Lchild)? P->Lchild->Height:0; //If the child exist assign this value
    RightHeight = (P && P->Rchild)? P->Rchild->Height:0;//If the child exist assign this value 
    
    return (LeftHight-RightHeight);//Return the subtraction to known what case is 
}

template <typename T> NodeTree<T> *AVL_T<T>::LLRotation(NodeTree<T> *P){
    NodeTree<T> *LeftChild = P->Lchild;//LeftChild
    NodeTree<T> *LeftCR    = P->Rchild;//Posible sub childs 
    
    P->Lchild=NULL;
    LeftChild->Rchild=NULL;
    
    LeftChild->Rchild=P;
    P->Lchild=LeftCR;
    
    //Calculate old "root/parent" node first and then the new "parent/root"
    P->Height=NodeHeight(P);
    LeftChild->Height=NodeHeight(LeftChild);
    //---------------------------------------------------------------------
    if(P==Root){//If you move the root, update the new Root
        Root=LeftChild;
    }
    
    return LeftChild;
}

template <typename T> NodeTree<T> *AVL_T<T>::RRotation(NodeTree<T> *P){
    NodeTree<T> *PR=P->Rchild;//Right child of P
    NodeTree<T> *LPR=PR->Lchild;//Possible L child of PR
    
    PR->Lchild=NULL;//Disconnect
    P->Rchild=NULL;
    
    PR->Lchild=P;//Connect 
    P->Rchild=LPR;
    
    //Update Height
    P->Height=NodeHeight(P);
    PR->Height=NodeHeight(PR);
    //-----------------------------------------------------
    if(P==Root){//If you move the root, update the new Root
        Root=PR;
    }
    
    return PR;
}

template <typename T> NodeTree<T> *AVL_T<T>::LRRotation(NodeTree<T> *P){
    NodeTree<T> *NP=P->Lchild->Rchild;//New Parent node
    NodeTree<T> *NPL=NP->Lchild;//NP Childs
    NodeTree<T> *NPR=NP->Rchild;//NP Childs
    NodeTree<T> *PL=P->Lchild;//P left child
    
    //Disconnect
    NP->Lchild=NULL;
    NP->Rchild=NULL;
    PL->Rchild=NULL;
    P->Lchild=NULL;
    
    //Connect
    NP->Rchild=P;
    NP->Lchild=PL;
    P->Lchild=NPR;
    PL->Rchild=NPL;
    
    //Update Height
    P->Height=NodeHeight(P);
    PL->Height=NodeHeight(PL);
    NP->Height=NodeHeight(NP);
    //--------------------------------------------------------------------------
    if(P==Root){//If you moved the root 
        Root=NP;
    }   
    
    return NP;
}


template <typename T> NodeTree<T>* AVL_T<T>::RLRotation(NodeTree<T> *P){
    NodeTree<T> *NP=P->Rchild->Lchild;//New parent node
    NodeTree<T> *LNP=NP->Lchild;//Possible Left child of parent node
    NodeTree<T> *RNP=NP->Rchild;//Possible Right child of parent node
    NodeTree<T> *PR=P->Rchild;
    
    //Disconnect
    NP->Rchild=NULL;
    NP->Lchild=NULL;
    PR->Lchild=NULL;
    P->Rchild=NULL;
    
    //Connect
    NP->Rchild=PR;
    NP->Lchild=P;
    PR->Lchild=RNP;
    P->Rchild=LNP;
    
    //Update Height
    P->Height=NodeHeight(P);
    PR->Height=NodeHeight(PR);
    NP->Height=NodeHeight(NP);
    
    //--------------------------------------------------------------------------
    if(P==Root){//If you moved the root 
        Root=NP;
    }//-------------------------------------------------------------------------   
    
    return NP;
}
//------------------------------------------------------------------------------

//---------------------Display Tree By Level------------------------------------
template <typename T> void AVL_T<T>::DisplayTreeByLevel(){
    NodeTree <T> *P = Root;
    if(P==nullptr){return ;}
    
    queue <NodeTree<T> *>MyQueue;
    NodeTree<T>*Current=nullptr;
    
    cout<<"\nDisplaying by level:"<<endl;
    MyQueue.push(P);
    MyQueue.push(nullptr);
    while(true){
        Current = MyQueue.front();
        MyQueue.pop();
        
        if(Current!=nullptr){
            cout<<Current->Data<<" ";
            if(Current->Lchild) MyQueue.push(Current->Lchild);
            if(Current->Rchild) MyQueue.push(Current->Rchild);
        }else{
            cout<<"\n";
            if(MyQueue.empty()){break;}//If the queue is empty there are not more elements
            MyQueue.push(nullptr);//If there are more elements add a delimeter
        }
    }
}
//------------------------------------------------------------------------------

//--------------------------Delete node code------------------------------------
template <typename T> NodeTree<T>* AVL_T<T>::FindMin(NodeTree<T>*P){
    while(P->Lchild != NULL) P = P->Lchild;
	return P;
}

template <typename T> NodeTree<T> *AVL_T<T>::DeleteNodeTree(NodeTree<T>*P, const T &key){
    if(P==NULL){return P;}

    else if(key<P->Data) P->Lchild=DeleteNodeTree(P->Lchild,key);
    else if(key>P->Data) P->Rchild=DeleteNodeTree(P->Rchild,key);
    else if(P->Data==key){
            //Case 1: No child
        if( (P->Lchild==NULL) && (P->Rchild==NULL) ){
            delete(P);
            P=NULL;
            N_nodes--;
        }else if(P->Lchild==NULL){//Case 2: one child
            NodeTree<T> *temp=P;
            P=P->Rchild;
            if(temp==Root){Root=P;}//***If you will delete the root case***
            delete(temp);
            N_nodes--;
        }else if(P->Rchild==NULL){
            NodeTree<T> *temp=P;
            P=P->Lchild;
            if(temp==Root){Root=P;}//***If you will delete the root case***
            delete(temp);
            N_nodes--;
        }else{//Case 3: 2 children
            NodeTree<T> *temp=FindMin(P->Rchild);
            P->Data=temp->Data;
            P->Rchild=DeleteNodeTree(P->Rchild,temp->Data);
        }

    }
    //Before you return you need to be sure that is correctly balanced the Tree
    //A deletion can cause an unbalance Tree
    //Calculate the current Height of the node before return
    if(P!=NULL){//The node if is finded becomes null after deletion, so we need to pass this case and check the others 
    
        P->Height=NodeHeight(P);//Calculate the current Height
    
        if( (BalanceFactor(P)==2) && (BalanceFactor(P->Lchild)==1)){//LLRotation
            P = LLRotation(P);
        }else if( (BalanceFactor(P)==-2) && (BalanceFactor(P->Rchild)==-1) ){//RRotation
            P = RRotation(P);
        }else if((BalanceFactor(P)==2) && (BalanceFactor(P->Lchild)==-1) ){//LRRotation
            P = LRRotation(P);
        }else if( (BalanceFactor(P)==-2) && (BalanceFactor(P->Rchild)==1) ){//RLRotation
            P = RLRotation(P);
        }
    }
    
    return P;
}
//------------------------------------------------------------------------------

//-------------------------Destructor function----------------------------------
template <typename T> void AVL_T<T>::DeleteAVLT(NodeTree<T>*P){
    if(P!=nullptr){
        DeleteAVLT(P->Lchild);
        DeleteAVLT(P->Rchild);
        delete (P);
    }
}
//------------------------------------------------------------------------------

int main(){
    
    AVL_T<int> MyAVL_T;
    NodeTree<int> *P=MyAVL_T.GetRoot();
    
    MyAVL_T.InsertIn(10,MyAVL_T.GetRoot());
    MyAVL_T.InsertIn(30,MyAVL_T.GetRoot());
    MyAVL_T.InsertIn(20,MyAVL_T.GetRoot());
    //MyAVL_T.InsertIn(8,MyAVL_T.GetRoot());
    //MyAVL_T.InsertIn(40,MyAVL_T.GetRoot());
    
    cout<<"Displaying in order:";
    MyAVL_T.InOrder(MyAVL_T.GetRoot());
    
    P=MyAVL_T.GetRoot();
    cout<<"\nRoot:"<<P->Data<<" Heights:"<<P->Lchild->Height<<" "<<P->Height<<" "<<P->Rchild->Height<<endl;
    
    MyAVL_T.DisplayTreeByLevel();
    
    cout<<endl;
    
    MyAVL_T.DeleteNodeTree(MyAVL_T.GetRoot(),5);
    cout<<"Displaying in order:";
    MyAVL_T.InOrder(MyAVL_T.GetRoot());
    MyAVL_T.DisplayTreeByLevel();
    
    //P=MyAVL_T.GetRoot();
    //cout<<"*:"<<P->Lchild->Data;
    
    return 0;
}




