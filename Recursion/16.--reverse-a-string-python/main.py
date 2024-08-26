#reverse a string in python  my first approach
'''
MyString = 'This is my original string'
MyString = list(MyString)

def reverseString(MyString:list,pLeft:int,pRight:int):
    if pLeft >=pRight:
        return
    else:
        #swap
        temp = MyString[pLeft]
        MyString[pLeft] = MyString[pRight]
        MyString[pRight] = temp
        #Recursive call to continue swapping elements 
        reverseString(MyString,pLeft+1,pRight-1)


reverseString(MyString,0,len(list(MyString))-1)
print(''.join(MyString))
'''

#Another approach
def reverse_string(s):
    # Base case: if the string is empty or has only one character,
    # it is already reversed
    if len(s) <= 1:
        return s
    # Recursive case: reverse the substring from the second character
    # onwards and concatenate the first character at the end
    return reverse_string(s[1:]) + s[0]
#Quote by Paul
#Returns every single element of the original string by each portion
#stored in the stack, making a new string and returning it  
    

# Example usage
original_string = "hello"
reversed_string = reverse_string(original_string)
print("Original string:", original_string)
print("Reversed string:", reversed_string)


