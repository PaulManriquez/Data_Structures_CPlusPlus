#Programmer Paul Manriquez 
#Date August 2024
#Simple linked list 

''' Why we dont need to deallocate the memory as in C++ ? 
Garbage Collection:
Python uses an automatic memory management system that includes a garbage collector. 
The garbage collector tracks objects and automatically deallocates memory 
when an object is no longer needed or referenced by the program.
When there are no references to an object (like a Node in a linked list), 
the garbage collector will eventually clean it up, freeing the associated memory.
'''

#========== Node
class Node:
    def __init__(self,data):
        self.data = data #<-- Store the data  
        self.next = None #<-- Pointer to another node 
        

class Simple_Linked_List:
    def __init__(self):
        self.head = None #Pointer initialized to Null 
        self.last = None #Pointer to the last element
        self.n_nodes = 0 #Current n nodes  

    def append(self,data): #Add a new item 
        new_node = Node(data) #Create an instance of the node 

        if self.head == None: #If is the first element to insert in the list 
            self.head = new_node #Head points to the first element
            self.last = new_node #Current last element  
        else:
            self.last.next = new_node #Join the last element with the new last element 
            self.last = new_node #Update the new last element   
        
        self.n_nodes +=1 #Update the current number of nodes     
    
    def prepend(self,data):#Add a new item in the front 
        if self.head == None:#case when head is None
            self.head = Node(data) 
            self.last = self.head
        else:
            temp = self.head #Save where the head was pointing to previously
            self.head = Node(data) #New head
            self.head.next = temp #Join again 

        self.n_nodes +=1 #Update the current number of nodes      



    def display_linked_list(self):
        if self.head != None:
            print('Displaying Simple linked list:')
            current_node = self.head 
            while current_node:
                print(f" --> {current_node.data}",end='')
                current_node = current_node.next #Update the next node to point 
            
            print()#New line    
        else:
            print('The linked list is empty')

    def delete(self,item): #Delete the first occurence of the item if it is found
        if self.head != None:
            current = self.head #Point to the head to start to search
            current_b = None
            counter = 0
            while current and (current.data != item): #While we dont find the element 
                current_b = current #Save the old pointer node 
                current = current.next #Check the next item in the list 
                counter += 1

            if current != None:
                print(f'The item {item}, was found in the place number {counter}\nOld linked list:')
                self.display_linked_list()
                if counter == 0: #head case
                    self.head = self.head.next
                elif counter == self.n_nodes - 1: #Last node case
                    current_b.next = None #Disconnect the last node
                    self.last = current_b #New last node 
                    print(f'-->{current_b.data}')
                else:#between case
                    current_b.next = current.next #Before current node points to the next element that was
                                                  #pointing the current node
                    current.next = None #Disconnect the node 

                #If the list is now an empty list
                if self.head == None: 
                    print('Now is an empty list, reset')
                    self.head = None 
                    self.last = None

                self.n_nodes -=1  #Update the new quantity of nodes in the list
                print(f'Current number nodes in the list: {self.n_nodes}')
                if self.head:
                    print(f'Head {self.head.data} | Last {self.last.data}')
                else:
                    print(f'Head None | Last None')
                self.display_linked_list() #<-- Show to the user the new linked list

            else:
                print('The item was not found')
                return None
                
                   

              


My_SLL = Simple_Linked_List() #<-- Create an instance of the linked list 


My_SLL.append(5)




My_SLL.delete(5)