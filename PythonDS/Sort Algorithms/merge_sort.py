#Merge Sort

def Merge(left,right):
    sorted_list = [] 
    i = j = 0 

    #Merge the two list by comparing their elements
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            sorted_list.append(left[i])
            i+=1
        else:
            sorted_list.append(right[j])
            j += 1

    #Append any remaining elements
    sorted_list.extend(left[i:])
    sorted_list.extend(right[j:])

    return sorted_list        
                


def Merge_Sort(My_Array):

    #Base case 
    if len(My_Array) <=1:
        return My_Array
    
    #Split the list
    mid = len(My_Array) // 2 #Get integer value division 
    left_array = My_Array[:mid]
    right_array = My_Array[mid:]

    #Recursive call till reach the base case 
    left_sorted = Merge_Sort(left_array)
    right_sorted = Merge_Sort(right_array)

    return Merge(left_sorted,right_sorted)

arr = [5,1,3,0,2,1]
print(Merge_Sort(arr))
