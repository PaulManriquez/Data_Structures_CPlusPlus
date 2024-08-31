# Function to demonstrate various set operations
'''
Sets in Python are collections of unique items. They are like bags where you can put things in, 
but each thing can only appear once, and the order in which you put them doesn't matter. 
You can use sets to quickly check if something is in the collection, remove duplicates, or 
compare groups of items.
'''
def set_operations():
    # Create two sets
    set1 = {1, 2, 3, 4, 5}
    set2 = {4, 5, 6, 7, 8}

    print("Set 1:", set1)
    print("Set 2:", set2)

    # Union of two sets
    union_set = set1.union(set2)
    print("Union of Set 1 and Set 2:", union_set)

    # Intersection of two sets
    intersection_set = set1.intersection(set2)
    print("Intersection of Set 1 and Set 2:", intersection_set)

    # Difference of two sets (elements in set1 but not in set2)
    difference_set = set1.difference(set2)
    print("Difference of Set 1 and Set 2:", difference_set)

    # Symmetric Difference (elements in either set1 or set2, but not in both)
    symmetric_difference_set = set1.symmetric_difference(set2)
    print("Symmetric Difference of Set 1 and Set 2:", symmetric_difference_set)

    # Add an element to a set
    set1.add(9)
    print("Set 1 after adding 9:", set1)

    # Remove an element from a set
    set1.remove(1)
    print("Set 1 after removing 1:", set1)

    # Discard an element (won't raise an error if the element is not found)
    set1.discard(99)
    print("Set 1 after discarding 99 (no effect if not present):", set1)

    # Check if an element is in a set
    print("Is 2 in Set 1?", 2 in set1)

    # Iterate through a set
    print("Elements in Set 1:")
    for element in set1:
        print(element)

    # Clear all elements in a set
    set1.clear()
    print("Set 1 after clearing all elements:", set1)

    # Check if a set is a subset of another
    print("Is Set 2 a subset of the union set?", set2.issubset(union_set))

    # Check if a set is a superset of another
    print("Is the union set a superset of Set 2?", union_set.issuperset(set2))


# Call the function to execute set operations
set_operations()
