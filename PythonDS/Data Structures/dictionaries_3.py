#Programmer Paul Manriquez 
#Date: august 2024 
#Simulating a data base implementation

class StudentDataBase:
    def __init__(self):
        self.data_base = {} 
        self.id = 0

    def add_student(self,name,age,courses):
        #Add to the dictionary the new student data 
        self.data_base[self.id] = {
                                'name':name,
                                'age': age,
                                'courses': courses
                            }
        self.id +=1
        print('Student added')

    def display_db(self):
        if self.data_base != {}: #If the dictionary is not empty
            for id, student_data in self.data_base.items():
                print(f'ID[{id}]: ',end='')
                for key,inf in student_data.items():
                    print(f' {key}:{inf} |',end='')
                print()#\n
        else:
            print('The data base is empty')
    
    def get_student_by_id(self,id):
        return self.data_base.get(id,'Student do not exist')#<-- Returns a default value if the id do not exist          

    def remove_by_id(self,id):
        if id in self.data_base:
            print(f'{self.data_base[id]['name']} was deleted')
            del self.data_base[id]
        else:
            print('The student doesnt exist')    

    def update_student(self, student_id, name=None, age=None, courses=None):
        student = self.data_base.get(student_id)
        if student:
            if name is not None:
                student['name'] = name
            if age is not None:
                student['age'] = age
            if courses is not None:
                student['courses'] = courses
            return "Student updated successfully"
        else:
            return "Student not found"        

DB_S_1 = StudentDataBase() 
DB_S_1.add_student(name='Paul',age=26,courses=['chemestry','physics'])
DB_S_1.add_student(name='Alfredo',age=22,courses=['chemestry2','physics2'])

DB_S_1.remove_by_id(1)