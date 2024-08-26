#N fibonacci sequence 

def fibo(n:int):
    if(n==0):
        return 0
    elif(n==1):
        return 1
    else:
        return fibo(n-2) + fibo(n-1)


def fiboCalculate(n:int):
    for i in range(1,n):
        before = fibo(i-1)
        after  = fibo(i)
        ans = before + after
        print(f"{before} + {after} = {ans}")
    
        
        
        

fiboCalculate(10)


