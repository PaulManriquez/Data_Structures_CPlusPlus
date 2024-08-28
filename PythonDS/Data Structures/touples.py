#tuples as dictionary keys
# Suppose we want to map coordinates (x, y) to a specific value

# Creating a dictionary with tuple keys
coordinate_map = {
    (0, 0): "Origin",
    (1, 2): "Point A",
    (3, 4): "Point B",
    (5, 6): "Point C"
}

# Accessing values using tuple keys
print(coordinate_map[(0, 0)])  # Output: Origin
print(coordinate_map[(1, 2)])  # Output: Point A

# Adding a new coordinate
coordinate_map[(7, 8)] = "Point D"

# Printing the updated dictionary
print(coordinate_map)
# Output:
# {
#     (0, 0): 'Origin',
#     (1, 2): 'Point A',
#     (3, 4): 'Point B',
#     (5, 6): 'Point C',
#     (7, 8): 'Point D'
# }


# Creating a tuple
my_tuple = (10, 20, 30)

# Accessing elements
print(my_tuple[1])  # Output: 20

# Nested tuple
nested_tuple = (1, (2, 3), 4)
print(nested_tuple[1][1])  # Output: 3

# Tuple unpacking
a, b, c = my_tuple
print(a, b, c)  # Output: 10 20 30

# Immutable nature
try:
    my_tuple[1] = 25  # This will raise a TypeError
except TypeError as e:
    print(e)  # Output: 'tuple' object does not support item assignment



