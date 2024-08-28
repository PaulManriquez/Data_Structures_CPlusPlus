# A program to manage a simple student database using dictionaries

# Step 1: Create an empty dictionary to store student data
students = {}

# Step 2: Function to add a new student
def add_student(student_id, name, age, courses):
    students[student_id] = {
        "name": name,
        "age": age,
        "courses": courses
    }
    print(f"Student {name} added successfully.\n")

# Step 3: Function to update a student's information
def update_student(student_id, name=None, age=None, courses=None):
    if student_id in students:
        if name:
            students[student_id]["name"] = name
        if age:
            students[student_id]["age"] = age
        if courses:
            students[student_id]["courses"] = courses
        print(f"Student {student_id} updated successfully.\n")
    else:
        print(f"Student with ID {student_id} not found.\n")

# Step 4: Function to remove a student
def remove_student(student_id):
    if student_id in students:
        removed_student = students.pop(student_id)
        print(f"Student {removed_student['name']} removed successfully.\n")
    else:
        print(f"Student with ID {student_id} not found.\n")

# Step 5: Function to display all students
def display_students():
    if students:
        print("Current Student Database:")
        for student_id, details in students.items():
            print(f"ID: {student_id}")
            for key, value in details.items():
                print(f"  {key.capitalize()}: {value}")
            print()
    else:
        print("No students in the database.\n")

# Step 6: Demonstrate functionalities

# Add students
add_student(101, "Alice", 20, ["Math", "Physics"])
add_student(102, "Bob", 22, ["English", "History"])

# Update a student's information
update_student(101, age=21, courses=["Math", "Chemistry"])

# Remove a student
remove_student(102)

# Display all students
display_students()
