#ifndef BST_CLASS_TEMPLATE_H_
#define BST_CLASS_TEMPLATE_H_

using namespace std;

template <typename T> class TreeNode{//--------------------------Class Tree node
    public:
        TreeNode <T> *Lchild;
        T Data;
        TreeNode <T> *Rchild;
    TreeNode(T _Data): Lchild(nullptr),Data(_Data),Rchild(nullptr){}
};//-----------------------------------------------------------------------------

template <typename T> class BST{
    private:
        TreeNode<T> *Root=nullptr;
        int N_Nodes=0;
    
    public:
        BST(): Root(nullptr),N_Nodes(0){}
        ~BST(){ DeleteTree(Root); } 
    
    //---Getters---
    TreeNode <T> *GetRoot(){return Root;};
    T GetRootData(){return Root->Data;};
    int GetN_Nodes(){return N_Nodes;};
    int GetHeightTree(TreeNode <T> *P);
    //---Methods---
    TreeNode <T> *Insert(const T &data,TreeNode <T> *P);
    void InOrder(TreeNode <T> *P);
    void PreOrder(TreeNode <T> *P);
    void PostOrder(TreeNode <T> *P);
    void DeleteTree(TreeNode <T> *P);
    TreeNode <T> *DeleteNodeTree(const T &key,TreeNode <T> *P);
    TreeNode <T> *FindMin(TreeNode <T> *P);
    int MaxOf2Nodes(int n1 , int n2){return n1>n2? n1:n2;}
    void SearchElement(TreeNode<T> *P, const T &key);
};
//----------------------------INSERT--------------------------------------------
                   //|what returns  |Class|       
template <typename T> TreeNode <T>* BST<T>::Insert(const T &data ,TreeNode <T> *P){
    
    if(Root==nullptr){//The first node 
        P=new TreeNode<T>(data);
        Root=P;
        N_Nodes++;
    }else{
        if(P==nullptr){
            P=new TreeNode<T>(data);
            N_Nodes++;
            return P;
        }else if( (data) < P->Data ){//Go to left
            P->Lchild=Insert(data,P->Lchild);
        }else if ( (data) > P->Data ){
            P->Rchild=Insert(data,P->Rchild);
        }
    }
    return P;
}//-----------------------------------------------------------------------------

//---------------------------------InOrder------------------------------------
template <typename T> void BST <T>::InOrder(TreeNode <T> *P){
    if(P!=nullptr){
        InOrder(P->Lchild);
        cout<<P->Data<<" ";
        InOrder(P->Rchild);
    }
}//-----------------------------------------------------------------------------

//--------------------------------PreOrder--------------------------------------
template <typename T> void BST <T>::PreOrder(TreeNode <T> *P){
    if(P!=nullptr){
        cout<<P->Data<<" ";
        PreOrder(P->Lchild);
        PreOrder(P->Rchild);
    }
}//-----------------------------------------------------------------------------

//---------------------------------PostOrder------------------------------------
template <typename T> void BST <T>::PostOrder(TreeNode <T> *P){
    if(P!=nullptr){
        PostOrder(P->Lchild);
        PostOrder(P->Rchild);
        cout<<P->Data<<" ";
    }
}//-----------------------------------------------------------------------------

//------------------------------Delete Tree-------------------------------------
template <typename T> void BST <T>::DeleteTree(TreeNode <T> *P){
    if(P!=nullptr){
        DeleteTree(P->Lchild);
        DeleteTree(P->Rchild);
        delete(P);
    }
}//-----------------------------------------------------------------------------

//-------------------Delete Node Tree - insert the node to delete---------------
template <typename T> TreeNode <T> *BST<T>::DeleteNodeTree(const T &key ,TreeNode <T> *P){
    
    if(P==nullptr){ return P;}
    else if(key<P->Data){ P->Lchild=DeleteNodeTree(key,P->Lchild);}
    else if(key>P->Data){ P->Rchild=DeleteNodeTree(key,P->Rchild);}
    else{
        
        if( (P->Lchild==nullptr) && (P->Rchild==nullptr)  ){//Case 1: leaft node 
            delete P; P=nullptr; N_Nodes--;
        }
        else if((P->Lchild==nullptr) && (P->Rchild)){//Case 2: one child
            TreeNode<T> *Temp=P;
            P=P->Rchild;
            delete Temp; N_Nodes--;
        }
        else if((P->Rchild==nullptr) && (P->Lchild)){//Case 2: one child
            TreeNode<T> *Temp=P;
            P=P->Lchild;
            delete Temp; N_Nodes--;
        }else{//Case 3: Parent node
            TreeNode<T> *Temp=FindMin(P->Rchild);
            P->Data=Temp->Data;
            //From the place where was replaced the value of the right side of the
            //Current node , search that node and delete it 
            P->Rchild=DeleteNodeTree(Temp->Data,P->Rchild);
        }
    }
    return P;
}
//------------------------------------------------------------------------------

//From the direction that you are pointing to- search the minimum value
template <typename T> TreeNode <T> *BST<T>::FindMin(TreeNode <T> *P){//---------
    while(P->Lchild!=nullptr){
        P=P->Lchild;
    }
    return P;
}//-----------------------------------------------------------------------------

//------------------------Get Height of Tree------------------------------------
template <typename T> int BST<T>::GetHeightTree(TreeNode <T> *P){
    if(P==nullptr){
        return -1;
    }else{
        return 1 + MaxOf2Nodes(GetHeightTree(P->Lchild),GetHeightTree(P->Rchild));
    }
}//-----------------------------------------------------------------------------

//--------------------Search Element in the Tree--------------------------------
template <typename T> void BST<T>::SearchElement(TreeNode <T> *P, const T &key){
    
    if(P==nullptr){//You reach to the last element, thus , the element doesn't exist 
        cout<<"\nThe element "<<key<< " doesnt exist\n";
        return;
    }
    if(P->Data==key){
        cout<<"\nElement Found:"<<P->Data<<endl;
        return;
    }else if(key<P->Data){
        SearchElement(P->Lchild,key);
    }else if(key>P->Data){
        SearchElement(P->Rchild,key);
    }
}//-----------------------------------------------------------------------------


#endif