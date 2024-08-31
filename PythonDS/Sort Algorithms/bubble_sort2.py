class bubble_sort:
    def __init__(self):
        pass

    def sort_asc(self,List):
        if len(List) <= 1:
            return List
        else:
            for i in range(0,len(List)):
                swapped  = False
                for j in range(0,len(List)-i-1):
                    if List[j] > List[j+1]:
                        aux = List[j]
                        List[j] = List[j+1]
                        List[j+1] = aux
                        swapped  = True
                
                print(List)        
                if not swapped : #Nothing more to swaap 
                    break        
                           
            return List     

    def sort_desc(self,List):
        for i in range(0,len(List)):
            swapped  = False
            for j in range(0,len(List)-i-1):
                if List[j] < List[j+1]:
                    aux = List[j]
                    List[j] = List[j+1]
                    List[j+1] = aux
                    swapped  = True
            if not swapped : #Nothing more to swaap 
                break        
                           
        return List            


bbs = bubble_sort()
List = [5,1,3,0,2,1]

print(bbs.sort_asc(List))
#print(bbs.sort_desc(List))