class bubble_sort:
    def __init__(self):
        pass

    def sort_asc(self,List):
        if len(List) <= 1:
            return List
        else:
            for i in range(0,len(List)):
                for j in range(i+1,len(List)):
                    if List[i] > List[j]:
                        aux = List[i]
                        List[i] = List[j]
                        List[j] = aux   
            return List     

    def sort_desc(self,List):
        if len(List) <= 1:
            return List
        else:
            for i in range(0,len(List)):
                for j in range(i+1,len(List)):
                    if List[i] < List[j]:
                        aux = List[i]
                        List[i] = List[j]
                        List[j] = aux   
            return List               


bbs = bubble_sort()
List = [5,1,3,0,2,1]

print(bbs.sort_asc(List))
print(bbs.sort_desc(List))