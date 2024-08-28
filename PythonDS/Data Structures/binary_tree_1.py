#Programmer Paul Manriquez
#Date August 2024

#*Pending add a function to display by level 

#Diference between is and == in None
#is refers exactly with the memory section - (is identicall)
#== refers if the value<-- , is the same, but not to the exact element pointing to 

class Node:
    def __init__(self,data):
        self.left = None
        self.data = data
        self.right = None

class Binary_Tree: 
    def __init__(self):
        self.root = None

    def insert(self,data):
        if self.root is None: 
            self.root = Node(data)
        else:
            self._insert(self.root,data)#Recursive function to insert the element in the tree 

    def _insert(self,P,data):
        if data < P.data: #Insert in the lefth path 
            if P.left is None:
                P.left = Node(data) #<-- Since you reach to a base breakpoint in the recursive call, 
                                    #    inserts the data and then returns
            else:
                self._insert(P.left,data)
        
        else:#Insert in the right path 
            if P.right is None:
                P.right = Node(data) #<-- Since you reach to a base breakpoint in the recursive call,
                                     #    inserts the data and then returns
            else:
                self._insert(P.right,data) 

    def Display_InOrder(self):
        if self.root is not None:
            self._InOrder(self.root)
        else:
            print('Tree is empty')    

    def _InOrder(self,P):
        if P is not None:
            self._InOrder(P.left) #<--Go first to the left most side
            if P is self.root:
                print(f' Root:{P.data} ',end='')    
            else:
                print(f' {P.data} ',end='')
            self._InOrder(P.right) #<-- Go to the right most side



My_B_Tree = Binary_Tree() #Instance of the tree 

My_B_Tree.insert(7)
My_B_Tree.insert(3)
My_B_Tree.insert(9)
My_B_Tree.insert(8)
My_B_Tree.Display_InOrder()
                                    
