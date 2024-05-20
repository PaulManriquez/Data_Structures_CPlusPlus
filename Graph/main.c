//This program creates a graph according the inputs you introduce in the array of conections
//By default creates N_NODES from 1 to n and create an interconection between graphs
//***This is a diferent aproach to Adjacency Matrix*** 
//Programmer Paul Manriquez November 2023

#include <stdio.h>
#include <stdlib.h>
#define N_NODES 5  
#define ENABLE_N_CONECTIONS 3
//---------Node-----------
typedef struct Node{
    int Data;
    struct Node *Next[ENABLE_N_CONECTIONS];
}Node;
//-----------------------

Node *NewNode(int data){//---------------Create space for a new node element
    Node *T=(Node *)malloc(sizeof(Node));
    if(T==NULL){perror("Error Creating space for the node"); exit(1);}
    T->Data=data;
    T->Next[0]=NULL; T->Next[1]=NULL; T->Next[2]=NULL;
    return T;
}//-----------------------------------------------------------------------------

void CreateGraph(Node *ArrayNodes[N_NODES],int *Conections,int SizeConections){
    int conect=0;  Node *T=NULL; int Nx=0;//Current Next Conection                 
    for(int i=0;i<SizeConections;i++){
        conect=Conections[i]; 
        Nx=0;//Current next to conect
        T=ArrayNodes[i+1];//Currently in what node i need to conect
        do{
            T->Next[Nx]=ArrayNodes[conect%10];//conect with this node
            Nx++;//Update where is pointing Currently
            conect/=10;
        }while(conect!=0);
    }
}//-----------------------------------------------------------------------------

void DisplayGraph(Node *ArrayNodes[N_NODES]){//---------------------DisplayGraph
    int Nx=0;
    for(int i=0;i<N_NODES;i++){
        Node *TT=ArrayNodes[i];
        Nx=0;
        printf("\n[%d]->",i);
        if(TT!=NULL){
            printf("%d",TT->Data);
            while(TT->Next[Nx]!=NULL){//If that node has more childs
                printf(" %d",TT->Next[Nx]->Data);
                Nx++;
            }    
        }else{
            printf("NULL");
        }
    }
}//-----------------------------------------------------------------------------

int main(){
    
    Node *ArrayNodes[N_NODES]={NULL};//Create N nodes and make each node to the array
    for(int i=1;i<N_NODES;i++){
        ArrayNodes[i]=NewNode(i);
    }//-------------------------------------------------------------------------
    
    int Conections[]={24,3,1,3};
    int SizeConections=sizeof(Conections)/sizeof(int);
    /*print 2 and 4 
        1 |-> 2 -> 4 
        2 |-> 3
        3 |-> 1
        4 |-> 3
    */
    CreateGraph(ArrayNodes,Conections,SizeConections);
    DisplayGraph(ArrayNodes);
    
    return 0;
}



