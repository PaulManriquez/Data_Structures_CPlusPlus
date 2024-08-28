# Creating a dictionary
student = {
    "name": "John",
    "age": 21,
    "courses": ["Math", "Physics"],
    "graduated": False
}

# Accessing values
print(student["name"])  # Output: John
print(student.get("age"))  # Output: 21

# Adding or updating key-value pairs
student["age"] = 22  # Update age
student["university"] = "MIT"  # Add new key-value pair

# Removing key-value pairs
del student["graduated"]

# Iterating over dictionary
for key, value in student.items():
    print(f"{key}: {value}")

# Output:
# name: John
# age: 22
# courses: ['Math', 'Physics']
# university: MIT

print(student.items())