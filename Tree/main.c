//Binary Tree 
//Programmer Paul Manriquez November 2023
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


//---Binary Tree basic structure------------------------------------------------
typedef struct Tree{
    struct Tree *Lchild;
    int Data;
    struct Tree *Rchild;
}Tree;
int TotalNodesInTree=0;
Tree *Root=NULL;
//------------------------------------------------------------------------------

Tree *NewNodeTree(int data){//-------------------Generate a new node of the Tree
    Tree *T=(Tree *)malloc(sizeof(Tree));
    if(T==NULL){perror("\nError generating a new node"); exit(1);}
    T->Lchild=T->Rchild=NULL;
    T->Data=data;
    return T;
}//-----------------------------------------------------------------------------

Tree *CreateTree(void){//------------------------------------CreateTree function
    Tree *P=NULL;//Where whe retrieve from the Queue to known where to create the childs 
    Tree *T=NULL;//Temporal creating a new child
    int Continue=1;//This is to the first time Continue to add a left or right child 
    int data=0;//Variable to store int value of the node
    
    printf("Creating Root node, introduce the value:");
    scanf("%d",&data);
    Root=NewNodeTree(data);//Create the first node, the Root node
    InQueue(Root);//We use this function to now where to point and create a left or rigth child
    TotalNodesInTree++;//Global counter
    
    while(Continue==1){
        P=Dequeue();//Retrieve the actual node to where to create the left and rigth child
        
        printf("\nIntroduce the left child of the node %d:",P->Data);
        printf("\nPress -1 to pass\t?:");
        scanf("%d",&data);
        if(data>-1){
            T=NewNodeTree(data);//Create the left child
            P->Lchild=T;//Conect left child
            InQueue(T);//Introduce the new element in Queue
            TotalNodesInTree++;
        }
        printf("\nIntroduce the rigth child of the node %d:",P->Data);
        printf("\nPress -1 to pass\t?:");
        scanf("%d",&data);
        if(data>-1){
            T=NewNodeTree(data);//Create Right child
            P->Rchild=T;//Conect rigth child
            InQueue(T);//Introduce the new element in Queue
            TotalNodesInTree++;
        }
        
        printf("\nContinue? 1)Yes 0)No:");
        scanf("%d",&Continue);
    }
    
    return Root;
}//-----------------------------------------------------------------------------

void InOrder(Tree *P){//-----------------------------------------Dispay in order
    if(P){
       InOrder(P->Lchild);
       printf("%d ",P->Data);
       InOrder(P->Rchild);
    }
}//-----------------------------------------------------------------------------

void PreOrder(Tree *P){//------------------------------------Display in PreOrder
    if(P){
       printf("%d ",P->Data);
       PreOrder(P->Lchild);
       PreOrder(P->Rchild);
    }
}//-----------------------------------------------------------------------------

void PostOrder(Tree *P){//-------------------------------------Display PostOrder
    if(P){
       PostOrder(P->Lchild);
       PostOrder(P->Rchild);
       printf("%d ",P->Data);
    }
}//-----------------------------------------------------------------------------

void DeleteTree(Tree *P){//--------------------------Function to delete the Tree
    if(P){
       DeleteTree(P->Lchild);
       DeleteTree(P->Rchild);
       free(P);//When we reach to this point we encounter a current leaf node, so we delete it 
       //if(P==Root){ //Enable this to make root point to NULL
        //   Root=NULL;
       //}    
    }
}//-----------------------------------------------------------------------------

int main(){
    
    
    //--Generate tree from convencional way-------------------------------------
    Root=CreateTree();
    //--------------------------------------------------------------------------
    printf("\nInOrder:");
    InOrder(Root);
    printf("\nPreOrder:");
    PreOrder(Root);
    printf("\nPosOrder:");
    PostOrder(Root);
    
    DeleteTree(Root);
    printf("%p",Root);//After deleting root is still pointing to the memory segment
                     //Even when you deallocate correctly , it doesnt mean "Im pointing to NULL"    
    
    return 0;
}