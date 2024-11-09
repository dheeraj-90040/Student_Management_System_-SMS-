# Student Management System (SMS)

## Overview

The **Student Management System (SMS)** is a console-based C++ application designed to manage student records, including adding students, updating details (name and SGPA), deleting records, and displaying student information. The system can handle multiple students and their SGPA for different semesters, and calculate their CGPA based on the entered SGPAs.

### Key Features

- **Add New Student:** Add a new student with a name and roll number.
- **Add SGPA:** Add SGPA for one or multiple semesters for a student.
- **Update Student Details:** Update student information such as name and SGPA for specific semesters.
- **Delete Student:** Remove a student record based on the roll number.
- **Display Details:** View the details of a specific student.
- **Display All Students:** View the details of all registered students.

### Technology Stack

- **C++**: The application is implemented in C++ and uses Object-Oriented Programming principles to manage student records efficiently.

## Features Walkthrough

### 1. Add New Student
- Allows you to add a new student by entering the student's name and roll number.
- The system validates the input for the roll number to ensure it is a valid positive number.

### 2. Add SGPA for a Student
- Allows you to add SGPA (Semester Grade Point Average) for a student.
- SGPAs are stored for each semester and can be used to calculate the CGPA (Cumulative Grade Point Average).

### 3. Update Student Details
- Allows you to update the details of a student, including:
  - Updating the name.
  - Updating SGPA for all semesters or a specific semester.
- It prompts for confirmation before making any changes.

### 4. Delete Student
- Allows you to delete a student's record based on their roll number.
- Confirms before deletion to prevent accidental removals.

### 5. Display Student Details
- Displays detailed information for a specific student, including:
  - Name
  - Roll number
  - Number of semesters
  - SGPAs for each semester
  - CGPA (calculated as the average of all entered SGPAs)

### 6. Display All Students
- Displays the details of all students currently stored in the system.
- Displays information such as the name, roll number, number of semesters, SGPAs, and CGPA for all students.

---

## Project Structure

- **Student Class**: 
  - Represents a student and encapsulates all student-related data such as name, roll number, and SGPAs.
  - Provides methods to add SGPA, update student details, and calculate CGPA.

- **Functions**:
  - `addStudent`: Adds a new student to the system.
  - `addSGPAToStudent`: Adds SGPA values for a student.
  - `updateDetails`: Updates student details like name or SGPA.
  - `deleteStudent`: Deletes a student's record.
  - `displayDetails`: Displays the details of a specific student.
  - `displayAllStudents`: Displays the details of all students.
  
## Compilation and Running the Program

To compile and run this program:

1. **Compile**:
   ```bash
   g++ -o student_management student_management.cpp
   ```

2. **Run**:
   ```bash
   ./student_management
   ```

## Example Usage

### Add a New Student
```txt
Enter Name: John Doe
Enter Roll Number: 101
Student Added Successfully!
```

### Add SGPA for a Student
```txt
Enter Roll Number to add SGPAs: 101
Enter number of semesters: 2
Enter SGPA for Semester 1: 8.5
Enter SGPA for Semester 2: 9.0
SGPAs added successfully for John Doe!
```

### Update SGPA for a Student
```txt
Enter Roll Number to Update Record: 101
Current Name: John Doe
Enter New Name to Update: [Leave empty to avoid change]: Jane Doe
Successfully Updated Record [Name]
```

### Display Details of a Student
```txt
Enter Roll Number To Display Details: 101
Name: Jane Doe
Roll Number: 101
Number of Semesters: 2
SGPAs: 8.5 9.0
CGPA: 8.75
```

### Delete a Student
```txt
Enter Roll Number to delete: 101
Are you sure you want to delete this student? [Y/N]: Y
Student Deleted Successfully!
```

---

## Future Enhancements

1. **Database Integration:** Implement database support to store and retrieve student records persistently.
2. **GUI Support:** Implement a graphical user interface (GUI) for easier interaction.
3. **Advanced Search and Filtering:** Allow searching and filtering students based on various criteria such as CGPA or name.

---

## License

This project is open source. Feel free to modify, distribute, or use it for educational and personal purposes.
