#Python lists are essentially dynamic arrays. This means:
#Resizable: The size of a Python list can change dynamically as you add or remove elements.
#Efficient Access: Lists provide efficient access to elements via indexing, just like arrays.
#Flexible Storage: Lists can store elements of different data types, unlike traditional arrays in some languages that require all elements to be of the same type.

#List comprehension 

#A list of comprehension help us to reduce code and be more simple in the coding

# 1.- Squares in a range of numbers 
squares = [ x**2 for x in range(5)]
#print(squares)

#2.- List of even numbers 
even = [x for x in range(10) if x % 2 == 0]
#print(even)

#3.- Convert a list of strings to uppercase
fruits = ['banana','apple','lemon']
upper_list = [ fruit.upper() for fruit in fruits ]
#print(upper_list)

#4.- Cartesian product 
cartesian = [(x,y) for x in range(3) for y in range(2)]
#print(cartesian)

#5.- if else condition 
even_odd = ['even' if x % 2 == 0 else 'odd' for x in range(5)]
#print(even_odd)

#6.- Flat a matrix 
matrix = [[1,2,3],[4,5,6],[7,8,9]]
flat = [item for row in matrix for item in row]
print(matrix)
print(flat)
'''
# Create an initial list of numbers
numbers = [3, 6, 9, 12]

# 1. Append an item to the end of the list
numbers.append(15)
print("After append:", numbers)  # [3, 6, 9, 12, 15]

# 2. Extend the list by adding elements from another list
more_numbers = [18, 21]
numbers.extend(more_numbers)
print("After extend:", numbers)  # [3, 6, 9, 12, 15, 18, 21]

# 3. Insert an item at a specific index
numbers.insert(2, 7)
print("After insert:", numbers)  # [3, 6, 7, 9, 12, 15, 18, 21]

# 4. Remove the first occurrence of a value
numbers.remove(9)
print("After remove:", numbers)  # [3, 6, 7, 12, 15, 18, 21]

# 5. Pop an item from a specific index (or the last item if no index is specified)
popped_item = numbers.pop(4)
print("After pop:", numbers)     # [3, 6, 7, 12, 18, 21]
print("Popped item:", popped_item)  # 15

# 6. Clear the entire list
numbers_copy = numbers.copy()    # Create a copy before clearing
numbers.clear()
print("After clear:", numbers)   # []

# 7. Find the index of the first occurrence of a value
index_of_18 = numbers_copy.index(18)
print("Index of 18:", index_of_18)  # 4

# 8. Count the occurrences of a value
count_of_6 = numbers_copy.count(6)
print("Count of 6:", count_of_6)    # 1

# 9. Sort the list in ascending order
unsorted_list = [10, 2, 8, 6, 4]
unsorted_list.sort()
print("Sorted list:", unsorted_list)  # [2, 4, 6, 8, 10]

# 10. Reverse the order of the list
unsorted_list.reverse()
print("Reversed list:", unsorted_list)  # [10, 8, 6, 4, 2]

# 11. Copy the list
final_copy = unsorted_list.copy()
print("Final copied list:", final_copy)  # [10, 8, 6, 4, 2]
'''

