#Stack implementation 
#Programmer: Paul Manriquez August 2024
# Last in first out LIFO - Recursion 
class Stack():
    def __init__(self) -> None:
        self.MyStack = [] # Constructs the stack based on a list 

    def push(self,item):
        self.MyStack.append(item) #<-- append an item  to the stack 
    
    def pop(self):
        if self.MyStack:
            return self.MyStack.pop() #<-- return the element 
        else:
            return 'Stack empty'

    def peek(self):
        if self.MyStack:
            return self.MyStack[-1] #<-- return the last element but is not removed 
        else:
            return 'Stack empty'  
    
    def size(self):
        return len(self.MyStack) #<-- current len of the stack 

    #===========================
    def recursive_f(self,index):
        
        if  index == -1:#Break
            return 
        else: 
            temp_list = []
            for i in range(0,index): #<-- steps to signal 
                temp_list.append('')
            
            temp_list.append('*')
            print(temp_list)
            print(self.MyStack)#Full stack display

            self.recursive_f(index-1) #Next Element
        
    def display_recursive(self):
        i = self.size()
        self.recursive_f(i)
    #===========================    

    
    def __str__(self):
        return str(self.MyStack) #<-- Returns in string format the stack (list)
    

      
            
        

my_stack = Stack() #<-- constructs the class instance

my_stack.push(5)
my_stack.push(0)
my_stack.push(5)
my_stack.push(9)
my_stack.push(1)

#print(my_stack.pop())
#print(my_stack.pop())
#print(my_stack)

my_stack.display_recursive()

                