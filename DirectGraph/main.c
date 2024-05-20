//Direct Graph implementation
//Programmer Paul Manriquez November 2023

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define ENABLE_N_CONECTIONS 3
#define N_NODES 5
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
    for(int i=0;i<ENABLE_N_CONECTIONS;i++) 
        T->Next[i]=NULL;
    return T;
}//-----------------------------------------------------------------------------

void DisplayGraph(Node *ArrayNodes[N_NODES]){//---------------------DisplayGraph
    printf("\nDisplayGraph:");
    int Nx=0;
    for(int i=0;i<N_NODES;i++){
        Node *TT=ArrayNodes[i];
        Nx=0;
        printf("\n[%d]->",i);
        if(TT!=NULL){
            //printf("%d",TT->Data);
            while(TT->Next[Nx]!=NULL){//If that node has more childs
                printf(" %d",TT->Next[Nx]->Data);
                Nx++;
            }    
        }else{
            printf("NULL");
        }
    }
}//-----------------------------------------------------------------------------

void BuildGraph(Node *ArrayNodes[N_NODES],int AdjacencyMatrix[5][5]){//---------
     //i = Node that i want to connect       Both starts from 1 
    //j = Conections that i want to perform
    Node *P=NULL; int Nxt=0;
    for(int Node=1;Node<N_NODES;Node++){
        P=ArrayNodes[Node];
        Nxt=0;
        for(int Conect=1;Conect<N_NODES;Conect++){
            if(AdjacencyMatrix[Node][Conect]==1){//If we find a node to Conect
              P->Next[Nxt++]=ArrayNodes[Conect];  
            }
        }
    }
}//-----------------------------------------------------------------------------

//----------------Breadth First Search (BFS)------------------------------------
void BFS(int NodeToVisit,int AdjacencyMatrix[5][5],Node* ArrayNodes[5]){
    
    int Visited[N_NODES]={0};
    Node *P=NULL,*U=NULL;
    
    //------
    P=ArrayNodes[NodeToVisit];
    printf("Breadth First Search from Node:%d ",P->Data);
    Visited[NodeToVisit]=1;
    InQueue(P);
    while(FRONT()!=NULL){//
        U=Dequeue();
        for(int v=1;v<N_NODES;v++){
            if(AdjacencyMatrix[U->Data][v]==1 && Visited[v]==0){
                printf(" %d",v);
                Visited[v]=1;
                InQueue(ArrayNodes[v]);
            }
        }
    }
}//-----------------------------------------------------------------------------



int main(){                                    //1 2 3 4 
    int AdjacencyMatrix[N_NODES][N_NODES]={  {0, 0,0,0,0},
                                        /*1*/{0, 0,1,0,1},
                                        /*2*/{0, 1,0,1,1},
                                        /*3*/{0, 1,0,1,0},
                                        /*4*/{0, 1,0,1,0}};
    
    Node *ArrayNodes[N_NODES]={NULL};//Create N nodes and make each node to the array
    for(int i=1;i<N_NODES;i++){
        ArrayNodes[i]=NewNode(i);
    }//-------------------------------------------------------------------------
     
    BuildGraph(ArrayNodes,AdjacencyMatrix);//Build Graph acording AdjacencyMatrix
    //--------------------------------------------------------------------------
    int NodeToStartVisit=4;
    BFS(NodeToStartVisit,AdjacencyMatrix,ArrayNodes);//Breadth First Search
    //--------------------------------------------------------------------------
        
    DisplayGraph(ArrayNodes);//Display Graph
    return 0;
}
