//Binary search tree (BST) template
//Programer Paul Manriquez November 2023

#include <iostream>
#include "BST_Class_Template.h"
using namespace std;
//      This program allows you to execute any operation with any data type
/*                          Functions of this BST- 
//---Getters---
    TreeNode <T> *GetRoot(){return Root;}; //Get the address of the Root node
    T GetRootData(){return Root->Data;};  //Get the Data of the Root node
    int GetN_Nodes(){return N_Nodes;};   //Return the actual quantity of nodes in the Tree
    int GetHeightTree(TreeNode <T> *P); //Return the height of the Tree
    //---Methods---
    TreeNode <T> *Insert(const T &data,TreeNode <T> *P); //Insert an element in the Tree
    void InOrder(TreeNode <T> *P);                      //Display in InOrder
    void PreOrder(TreeNode <T> *P);                    //Display in PreOrder    
    void PostOrder(TreeNode <T> *P);                  //Display in PostOrder
    void DeleteTree(TreeNode <T> *P);                //Delete the whole Tree
    TreeNode <T> *DeleteNodeTree(const T &key,TreeNode <T> *P); //Search and delte the node Tree
    TreeNode <T> *FindMin(TreeNode <T> *P);                    //Find the minimum node data, from the node address you execute
    int MaxOf2Nodes(int n1 , int n2){return n1>n2? n1:n2;}    //Get the max of two numbers
    void SearchElement(TreeNode<T> *P, const T &key);        //Search for an element in the Tree
*/



int main(){
    
    //BST<string> MyBST;
    //MyBST.Insert("hi",MyBST.GetRoot());
    //MyBST.Insert("to",MyBST.GetRoot());
    //MyBST.Insert("every one",MyBST.GetRoot());
    //MyBST.SearchElement(MyBST.GetRoot(),"every one");
    
    /
    BST<int> MyBST;
    MyBST.Insert(15,MyBST.GetRoot());
    MyBST.Insert(10,MyBST.GetRoot());
    MyBST.Insert(20,MyBST.GetRoot());
    //MyBST.Insert(8,MyBST.GetRoot());
    //MyBST.Insert(12,MyBST.GetRoot());
    //MyBST.Insert(17,MyBST.GetRoot());
    //MyBST.Insert(25,MyBST.GetRoot());
    //MyBST.InOrder(MyBST.GetRoot());putchar('\n');
    cout<<"\nHeigh:"<<MyBST.GetHeightTree(MyBST.GetRoot());
    //MyBST.PreOrder(MyBST.GetRoot());putchar('\n');
    //MyBST.PostOrder(MyBST.GetRoot());
    
    //MyBST.DeleteNodeTree(15,MyBST.GetRoot());
    //MyBST.InOrder(MyBST.GetRoot());putchar('\n');
    //cout<<"\n"<<MyBST.GetN_Nodes();
    //putchar('\n');
    //MyBST.PostOrder(MyBST.GetRoot());
    */
    
    /*
    BST<char> MyBST;
    MyBST.Insert('a',MyBST.GetRoot());
    MyBST.Insert('g',MyBST.GetRoot());
    MyBST.Insert('z',MyBST.GetRoot());
    MyBST.PostOrder(MyBST.GetRoot());
    
    BST<string> MyBST;
    MyBST.Insert("hi",MyBST.GetRoot());
    MyBST.Insert("to",MyBST.GetRoot());
    MyBST.Insert("every one",MyBST.GetRoot());
    MyBST.PostOrder(MyBST.GetRoot());
    cout<<"\nHeigh:"<<MyBST.GetHeightTree(MyBST.GetRoot());
    
    BST<int> MyBST;
    MyBST.Insert(15,MyBST.GetRoot());
    MyBST.Insert(10,MyBST.GetRoot());
    MyBST.Insert(20,MyBST.GetRoot());
    MyBST.Insert(8,MyBST.GetRoot());
    MyBST.Insert(12,MyBST.GetRoot());
    MyBST.Insert(17,MyBST.GetRoot());
    MyBST.Insert(25,MyBST.GetRoot());
    MyBST.SearchElement(MyBST.GetRoot(),95);
    MyBST.InOrder(MyBST.GetRoot());putchar('\n');
    cout<<"\nHeigh:"<<MyBST.GetHeightTree(MyBST.GetRoot());
    
    */
    
    return 0;
}
