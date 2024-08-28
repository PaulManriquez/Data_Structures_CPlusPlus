from collections import defaultdict

# 1. Definition
my_dict = {
    'name': 'John',
    'age': 30,
    'courses': ['Math', 'Physics']
}

print("1. Definition:")
print(my_dict)
print()

# 2. Syntax
print("2. Syntax:")
print(f"Defined Dictionary: {my_dict}")
print()

# 3. Keys
print("3. Keys:")
print(f"Keys: {list(my_dict.keys())}")
print()

# 4. Values
print("4. Values:")
print(f"Values: {list(my_dict.values())}")
print()

# 5. Accessing Values
print("5. Accessing Values:")
print(f"Name: {my_dict['name']}")
print(f"Age using get(): {my_dict.get('age', 'Not Found')}")
print(f"Unknown Key: {my_dict.get('unknown', 'Default Value')}")
print()

# 6. Adding and Updating
print("6. Adding and Updating:")
my_dict['graduated'] = True  # Adding
my_dict['age'] = 31  # Updating
print(f"Updated Dictionary: {my_dict}")
print()

# 7. Deleting Items
print("7. Deleting Items:")
del my_dict['courses']  # Removing a key
print(f"Dictionary after deleting 'courses': {my_dict}")

# Using pop
removed_value = my_dict.pop('name', 'Key not found')
print(f"Removed value with pop(): {removed_value}")
print(f"Dictionary after pop(): {my_dict}")

# Using popitem
key, value = my_dict.popitem()
print(f"Removed item with popitem(): ({key}, {value})")
print(f"Dictionary after popitem(): {my_dict}")
print()

# 8. Iterating
print("8. Iterating:")
for key in my_dict:
    print(f"Key: {key}, Value: {my_dict[key]}")

print("Values:")
for value in my_dict.values():
    print(f"Value: {value}")

print("Key-Value Pairs:")
for key, value in my_dict.items():
    print(f"Key: {key}, Value: {value}")
print()

# 9. Dictionary Methods
print("9. Dictionary Methods:")
print(f"Keys view: {my_dict.keys()}")
print(f"Values view: {my_dict.values()}")
print(f"Items view: {my_dict.items()}")
print(f"Dictionary copy: {my_dict.copy()}")

# Update method
my_dict.update({'new_key': 'new_value'})
print(f"Dictionary after update(): {my_dict}")
print()

# 10. Dictionary Comprehensions
print("10. Dictionary Comprehensions:")
squares = {x: x**2 for x in range(5)}
print(f"Squares dictionary: {squares}")
print()

# 11. Nested Dictionaries
print("11. Nested Dictionaries:")
nested_dict = {
    'student': {
        'id': 1,
        'name': 'Alice',
        'courses': ['English', 'Biology']
    }
}
print(f"Nested dictionary: {nested_dict}")
print(f"Nested value: {nested_dict['student']['courses']}")
print()

# 12. Default Values
print("12. Default Values:")
default_dict = defaultdict(int)  # Default value is 0
default_dict['existing'] = 1
print(f"Default dict with existing key: {default_dict['existing']}")
print(f"Default dict with missing key: {default_dict['missing']}")
print()

# Display the final state of all dictionaries used
print("Final States:")
print(f"my_dict: {my_dict}")
print(f"squares: {squares}")
print(f"nested_dict: {nested_dict}")
print(f"default_dict: {default_dict}")
