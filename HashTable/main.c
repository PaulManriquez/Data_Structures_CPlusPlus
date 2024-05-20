//Hashing Technique chaining
//Programmer Paul Manriquez November 2023
//------------------How the programm works--------------------------------------
//1)Create a linked list acording to an array
//2)Sort each node of the linked list and puts in the HashTable
//3)Principal functions: *Search for a number in HashTable
//                       *Insert a number in HashTable
//                       *Display HashTable    
/*                       *Delete a node in HashTable
    SearchByKey(HashTable);
    InsertNodeInHashTable(HashTable);
    DisplayHashTable(HashTable);
    DeleteNodeHashTable(HashTable);
*/
#include <stdio.h>
#include <stdlib.h>

//----Node of the list---
typedef struct NodeList{
    int Data;
    struct NodeList *Next;
}NodeList;
NodeList *Root=NULL;
NodeList *Rear=NULL;
//-----------------------

NodeList *NewNode(int data){//---------------Create space for a new node element
    NodeList *T=(NodeList *)malloc(sizeof(NodeList));
    if(T==NULL){perror("Error Creating space for the node"); exit(1);}
    T->Data=data;
    T->Next=NULL;
    return T;
}//-----------------------------------------------------------------------------

void InsertInList(int data){//--------------------Insert in linked list function
    if(Root==NULL){//Means it is the first element
        Root=NewNode(data);
        Rear=Root;//Actual node
    }else{
        Rear->Next=NewNode(data);
        Rear=Rear->Next;
    }
}//-----------------------------------------------------------------------------

void DisplayLinkedList(void){//------------------------------Display Linked list
    NodeList *P=Root;
    while(P){
        printf("%d ",P->Data);
        P=P->Next;
    }
}//-----------------------------------------------------------------------------

NodeList *GetNode(void){//------------------------------Get the node in the list
    NodeList *P=Root;
    if(Root!=NULL){//Means that exist the Node to return
        Root=Root->Next;
    }
    P->Next=NULL;
    return P;
}//-----------------------------------------------------------------------------

//Create The linked list function
void CreateLinkedList(int *A,int SizeArrayA){
    for(int i=0;i<SizeArrayA;i++){//----------------------Create the linked list
        InsertInList(A[i]);
    }
}//-----------------------------------------------------------------------------

//Search where to place in the hash table the node
void PlaceNode(NodeList **HashTable,NodeList *P,NodeList *T){
    NodeList *PtrNull=NULL;
    //Case one : the number is minor than the first node in the sublist
            if(P->Data<=T->Data){//Is the first occurrence of the node
                P->Next=T;
                *HashTable=NULL;
                *HashTable=P;
                //HashTable[h]=PtrNull;//***************Mistakes**************** 
                //HashTable[h]=P;//*********************************************
            }else{//Case 2: General case - Search where to put it 
                NodeList *TB=NULL;//TB TBefore
                do{
                    
                    if(P->Data > T->Data){//Move
                        TB=T;
                        T=T->Next;
                    }else{break;}//You fund where to place it 
                }while(T!=NULL);
                P->Next=T;
                TB->Next=P;
            }
}//-----------------------------------------------------------------------------

void DisplayHashTable(NodeList **HashTable){//----------------Display Hash table
    printf("Displaying HashTable:");
    for(int i=0;i<10;i++){
        if(HashTable[i]!=NULL){
            NodeList *CurrentNodePrint=HashTable[i];
            printf("\n[%d] ->",i);
            do{
                printf("%d ",CurrentNodePrint->Data);
                CurrentNodePrint=CurrentNodePrint->Next;
            }while(CurrentNodePrint!=NULL);
        }else{
            printf("\n[%d] -> NULL",i);
        }
    }
}//-----------------------------------------------------------------------------

void StoreNodesInHashTable(NodeList **HashTable,int SizeArrayA){//--------------
    int h=0;//Index to store in the HashTable
    NodeList *P=NULL;
    for(int i=0;i<SizeArrayA;i++){
        P=GetNode();//Retrieve the current node in the list
        h=(P->Data%10);
        if(HashTable[h]==NULL){//Is the first node
            HashTable[h]=P;    
        }else{//**********************INSERT THE NODE IN ORDER******************
            //Position on the adress  where is the list of subNodes
            NodeList *T=HashTable[h];
            //Function to search where to place the new node 
            //if already exist a node in the hash table
            PlaceNode(&HashTable[h],P,T);//-------------------------------------
        }
    }
}//-----------------------------------------------------------------------------

void SearchByKey(NodeList **HashTable){//-----Search for a node in the HashTable
    //---------------------Search by key---------------------------------------- 
    int NSearch=0;//Search the number 
    int h=0;
    NodeList *P=NULL;
    printf("\nIntroduce the number to search in HashTable:");
    scanf("%d",&NSearch);
    h=NSearch%10;
    P=HashTable[h];
    
    if(P!=NULL){//Start to seach
        while(P!=NULL){
            if(P->Data==NSearch){
                printf("The number %d was found in %d index",NSearch,h);
                break;
            }
            P=P->Next;
        }
        if(P==NULL){printf("\nThe number %d doesnt exist in the HashTable\n",NSearch);}
    }else{
        printf("\nThe number %d doesnt exist in the HashTable\n",NSearch);
    }
}//-----------------------------------------------------------------------------

void InsertNodeInHashTable(NodeList **HashTable){//Insert a new node in HashTable
    int n=0;
    int h=0;
    printf("Insert the new number to Introduce in HashTable:");
    scanf("%d",&n);
    h=n%10;//index in the HashTable
    NodeList *P=NewNode(n);
    NodeList *T=HashTable[h];
    if(HashTable[h]==NULL){
        HashTable[h]=P;        
    }else{
        PlaceNode(&HashTable[h],P,T);    
    }
}//-----------------------------------------------------------------------------

int Search(NodeList **HashTable,int NSearch){//Return positive index if is found the number to Search
    int h=0;
    NodeList *P=NULL;
    h=NSearch%10;
    P=HashTable[h];
    
    if(P!=NULL){//Start to seach
        while(P!=NULL){
            if(P->Data==NSearch){
                return h;
                break;
            }
            P=P->Next;
        }
    }
    return -1;
}//-----------------------------------------------------------------------------

void DeleteNodeHashTable(NodeList **HashTable){//-Delete a node in the HashTable
    int Ndelete=0;
    int index=0;
    printf("Introduce the number to Delete:");
    scanf("%d",&Ndelete);
    index=Search(HashTable,Ndelete);
    
    if(index!=-1){//If the number to Delete was found 
        NodeList *T=HashTable[index];
        NodeList *TB=NULL;//T before
        if(T->Next==NULL){//Case 1: Unique number in HashTable
            free(T);
            T=NULL;
            HashTable[index]=NULL;
        }else if(T->Data==Ndelete){//Case 2: the node is the first node
            TB=T;//Hold the node
            HashTable[index]=T->Next;//Now The pointer of the HashTable points to the next element 
            TB->Next=NULL;//Disconect
            free(TB);//free memory
            TB=NULL;//Free of pointing to a place the pointer "TB"
        }else{//Case 3: General case
                do{
                    if(Ndelete!=T->Data){//Move
                        TB=T;
                        T=T->Next;
                    }else{break;}//You fund where to place it 
                }while(T!=NULL);
                TB->Next=T->Next;//Linke the possible next node in the HashTable
                
                T->Next=NULL;//Disconect
                free(T);//Deallocate node
                T=NULL;//Point again to nowhere 
        }
    }else{
        printf("\nThe number doesnt exist\n");
    }
}//-----------------------------------------------------------------------------


int main(){
    //The linked list must be sorted
    int A[]={16,12,25,39,6,122,5,68,75};
    //int A[]={27,17,47};
    int SizeArrayA = sizeof(A)/sizeof(int);
    CreateLinkedList(A,SizeArrayA);
    
    //------------Store the elements in the hash table-------------------------- 
    NodeList *HashTable[10]={NULL};
    StoreNodesInHashTable(HashTable,SizeArrayA);
    //--------------------------------------------------------------------------
    
    //----Principal functions-------- 
    //SearchByKey(HashTable);
    //InsertNodeInHashTable(HashTable);
    DeleteNodeHashTable(HashTable);
    DisplayHashTable(HashTable);
    //--------------------------------
    return 0;
}





