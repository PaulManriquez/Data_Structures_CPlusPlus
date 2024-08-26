def factorial(n:int):
    if(n==0):
        return 1 
    else:
        return n * factorial(n-1)
        

def GetNFactorials(n:int):
    for i in range(0,n):
        print(f"{i}! = {factorial(i)}")
        
        
        


GetNFactorials(11)        
        
        