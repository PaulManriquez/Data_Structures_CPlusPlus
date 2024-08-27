#Queue implementation
#Programmer Paul Manriquez 

#First in, First out - FIFO 

class Queue():
    def __init__(self) -> None: #<-- constructor
        self.My_queue = []

    def enqueue(self,item): #<-- Add a element to the queue 
        self.My_queue.append(item)
    
    def dequeue(self):#<-- Pops out the front element 
        if self.My_queue:
            return self.My_queue.pop(0)  
        else:
            return 'Queue is empty'
        
    def peek(self): #<-- Shows the front element 
        if self.My_queue:
            return self.My_queue[0]
        else:
            print('Queue is empty')    

    def is_empty(self):#<-- Is empty?
        return len(self.My_queue) == 0        

    def __str__(self) -> str: #<-- Return the queue in string format  
        return str(self.My_queue)
    
    def size(self):
        return len(self.My_queue)
    
    #===== Recursion ===
    def display_recursive(self):
        index = 0
        self.recursive_d(index)

    def recursive_d(self,index):
        
        if index > self.size():
            return  
        else:
            for i in range(0,index):
                print(f"{self.My_queue[i]},",end='')
            print()

            self.recursive_d(index + 1)  #<-- Recursive function 
                 

My_queue = Queue() #<-- Create an instance of the class 

My_queue.enqueue(7)
My_queue.enqueue(6)
My_queue.enqueue(5)
My_queue.enqueue(4)

My_queue.display_recursive()