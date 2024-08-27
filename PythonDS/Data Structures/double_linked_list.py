#Programmer Paul Manriquez
#Date August 2024

#Node class structure 
class Node:
    def __init__(self,data):
        self.data = data 
        self.next = None 
        self.prev = None  

class Double_Linked_list:
    def __init__(self):
        self.head = None 
        self.last = None 
        self.n_nodes = 0 

    #Add an element at the end of the list 
    def append(self,data):
        if self.head == None: #If is the first node in the list 
            self.head = Node(data)
            self.last = self.head
        else:
            self.last.next = Node(data) #Create a node being pointed by the last.next
            self.last.next.prev = self.last #link the node beside the new node 
            self.last = self.last.next #Update last 
        
        self.n_nodes += 1 #Update the node counter 

    #Appends to the front a new node 
    def prepend(self,data):  
        if self.head == None:#If is the first node 
            self.head = Node(data)
            self.last = self.head
        else:
            temp = Node(data) #Store temporarly the new node 
            temp.next = self.head #Link ahead the node 
            self.head.prev = temp #Link beside the node 
            self.head = temp #Update the new node 

        self.n_nodes += 1 #Update the new quantity of nodes in the list 

    #Delete the first occurrence of the data 
    def delete(self,data):
        if self.head: #If at least exist one node in what to search
            current = self.head #Pointers 
            previous = None
            while current and (current.data != data):#While exist a node and the data is not being found
                previous = current
                current = current.next
            
            if current: #if the node with the data was found
                print('old list:')
                self.display_list()

                if current is self.head:  # Case 0: delete the head 
                    print('Delete case 0')
                    self.head = self.head.next  # Point to the next element
                    if self.head:  # If there's a new head
                        self.head.prev = None  # Clear the prev reference
                    else:  # If the list becomes empty
                        self.last = None  # Reset the last node reference
    
                    
                elif current is self.last: # Case 1: delete last node    
                    print('Delete case 1')
                    previous.next = None 
                    self.last = previous #New last node 
                
                else: # Case 2: delete a middle node 
                    print('Case 2')
                    previous.next = current.next #Prev jumps the current node 
                    if current.next.prev: #If the node was pointing previously
                        current.next.prev = previous #New previous to point 

                #Handle if the head becomes in none  
                if self.head == None: #if there is no more nodes
                    self.head = None
                    self.last = None  
                
                self.n_nodes -= 1 #Update the new quantity of nodes in the list 
                print('\nNew list')
                self.display_list()          



    def display_list(self):
        if self.head:
            print('Displaying list')
            current = self.head #Points to the head 
            while current:
                print(f'--> {current.data} ',end='')
                current = current.next #Move the current pointer to the next element 
        else:
            print('No elements in the list, 0')  

    def display_backwards(self):
        if self.last:
            print('Displaying backwards:')
            current = self.last
            while current:
                print(f'--> {current.data} ',end='')
                current = current.prev  
        else: 
            print('There is no elements in the list')   
    
    def nodes_information(self):
        if self.head:
            current = self.head 
            while current:
                if current.prev:
                    print(f'prev:{current.prev.data} ',end='')
                print(f'Current:{current.data} ',end='')
                if current.next:
                    print(f'Next:{current.next.data}')   

                current = current.next                              


My_2_LL = Double_Linked_list() #<-- Make an instance of the double linked list 

My_2_LL.append(78)
My_2_LL.append(7)
My_2_LL.append(8)
My_2_LL.nodes_information()
        