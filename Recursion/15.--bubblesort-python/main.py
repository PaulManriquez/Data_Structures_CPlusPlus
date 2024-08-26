#Bubble Sort 
array = [2,4,1,5,2,6]


for i in range(0,len(array)-1):
    for j in range(i+1,len(array)):
        if array[i] > array[j]:
            #--- Swap section --- 
            temp = array[i]
            array[i] = array[j]
            array[j] = temp 
            
            

print(array)            
            
            


