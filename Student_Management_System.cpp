#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Student class representing a single student's data
class Student {
private:
	string name;
	int rollNumber;
	vector<double> sgpas;  // List of SGPAs

public:
	// Constructor to initialize student details
	Student(string name, int rollNumber) {
		this->name = name;
		this->rollNumber = rollNumber;
	}

	// Method to add SGPA for a student
	void addSGPA(double sgpa) {
		sgpas.push_back(sgpa);
	}

	// setName

	void setName(string name) {
		this->name = name;
	}

	// Set rollNumber

	void setRollNumber(int roll) {
		rollNumber = roll;
	}
	// Method to set multiple SGPAs
	void setSgpas(const vector<double>& newSgpas) {
		sgpas = newSgpas;  // Update the sgpas member variable
	}

	// Method to calculate CGPA based on the SGPAs
	double calculateCGPA() const {
		if (sgpas.empty()) return 0;
		double totalSGPA = accumulate(sgpas.begin(), sgpas.end(), 0.0);
		return totalSGPA / sgpas.size();
	}

	// Getters
	int getRollNumber() const {
		return rollNumber;
	}

	string getName() const {
		return name;
	}

	vector<double> getSgpa() const {
		return sgpas;
	}

	// Method to display student information
	void displayInfo() const {
		cout << "\n\t\t { Student Details }" << endl;
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << rollNumber << endl;
		cout << "Number of Semesters: " << sgpas.size() << endl;
		cout << "SGPAs: ";
		for (double sgpa : sgpas) {
			cout << sgpa << " ";
		}
		cout << "\nCGPA: " << calculateCGPA() << endl;
	}
};

// Other functions remain the same as in your code...

// Function Prototypes
void addStudent(vector<Student>& students);
void displayDetails(vector<Student>& students);
void addSGPAToStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void deleteStudent(vector<Student>& students);
void updateDetails(vector<Student>& students);
bool UpdateConformation();
bool DeleteConformation();



int main() {
	vector<Student> students;  // List to store students
	int choice;
	char continueChoice;

	do {
		cout << "\n\t\t Student Dashboard " << endl;
		cout << "\n1. Add New Student\n";
		cout << "2. Add SGPA for a Student\n";
		cout << "3. updateDetails\n";
		cout << "4. Details of Student\n";
		cout << "5. Display All Students\n";
		cout << "6. Delete Student\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.clear();               // Clear the fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input - when it encountered \n


		switch (choice) {
		case 1:
			addStudent(students);
			break;
		case 2:
			addSGPAToStudent(students);
			break;
		case 3:
			updateDetails(students);
			break;
		case 4:
			displayDetails(students);
			break;
		case 5:
			displayAllStudents(students);
			break;
		case 6:
			deleteStudent(students);
			break;
		case 7:
			cout << "Exiting the system...\n";
			return 0;
		default:
			cout << "\n\t\tInvalid choice! Please try again.\n";
		}

		cout << "\n\t\tDo you want to continue? [Y/N]: ";
		cin >> continueChoice;
	} while (continueChoice == 'Y' || continueChoice == 'y');

	return 0;
}

// Function to add a new student
void addStudent(vector<Student>& students) {
	string studentName;
	// Handling RollNumber
	int rollNumber;


	cout << "\nEnter Name: ";
	cin >> studentName;
	cout << "\nEnter Roll Number: ";
	cin >> rollNumber;
	while (!(cin >> rollNumber) || rollNumber < 0) {
		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
		cout << "Invalid input. Please enter a valid Roll Number: ";
	}

	students.push_back(Student(studentName, rollNumber));
	cout << "\n\t\tStudent Added Successfully!\n";
}

void updateSgpas(vector<Student>& students, int rollNumber) {
	for (auto& student : students) {
		if (student.getRollNumber() == rollNumber) {
			// Assuming getSgpas() returns a vector of double
			vector<double> updatedSgpas = student.getSgpa();  // Use correct method to get SGPA
			double newSgpa;

			// Prompt user to enter new SGPA values for all semesters
			cout << "Enter updated SGPA values for all semesters: " << endl;
			for (size_t i = 0; i < updatedSgpas.size(); ++i) {
				cout << "Semester " << (i + 1) << " current SGPA: " << updatedSgpas[i] << endl;
				cout << "Enter new SGPA for Semester " << (i + 1) << " (or -1 to keep current): ";
				cin >> newSgpa;

				// Update only if the user provides a valid value
				if (newSgpa != -1) {
					updatedSgpas[i] = newSgpa;
				}
			}
			student.setSgpas(updatedSgpas);
			cout << "\nSuccessfully updated SGPA for Roll Number: " << rollNumber << endl;
			return;  // Exit after updating
		}
	}
	cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
}

// updateDetails of Specific student based on rollNumber
void updateDetails(vector<Student>& students) {
	int rollNumber;
	cout << "\nEnter Roll Number to Update Record: ";

	while (!(cin >> rollNumber) || rollNumber < 0) {
		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
		cout << "Invalid input. Please enter a valid Roll Number: ";
	}

	for (auto& student : students) {  // Use reference to avoid copying
		if (student.getRollNumber() == rollNumber) {
			// Confirm the update
			if (UpdateConformation()) {  // Ensure this function is defined elsewhere
				string newName;
				cout << "Current Name: " << student.getName() << endl;
				cout << "Enter New Name to Update: [Leave empty to avoid change]: ";
				cin.ignore(); // Clear any remaining newline character
				getline(cin, newName); // Get full line input for name

				// Update the name if it's not empty
				if (!newName.empty()) {
					student.setName(newName); // Assuming there's a method to set the name
					cout << "\n\t\t--------- Successfully Updated Record [Name] ---- " << endl;
				}

				while (true) {
					int choice;
					cout << "1. Update SGPA for All Semesters" << endl;
					cout << "2. Update SGPA for Specific Semester" << endl;
					cout << "3. Exit" << endl;
					cout << "\nEnter your Choice: ";
					cin >> choice;

					switch (choice) {
					case 1:
						if (UpdateConformation()) {
							updateSgpas(students, rollNumber);  // Call the SGPA update function
						}
						break;

					case 2: {
						if (UpdateConformation()) {
							int semYear;
							double newSgpa;
							cout << "Enter specific Semester Year [1 - 8]: ";
							cin >> semYear;

							// Check for valid semester year
							if (semYear < 1 || semYear > 8) {
								cout << "Invalid Semester Year!" << endl;
								break;
							}
							vector<double> updatedsgpa = student.getSgpa();
							cout << "\nCurrent SGPA: " << student.updatedsgpa[semYear - 1] << endl;  // Adjust for zero-based index
							cout << "Enter new SGPA for Semester " << semYear << ": ";
							cin >> newSgpa;
							student.updatedsgpa[semYear - 1] = newSgpa; // Update the SGPA
							student.setSgpas(updatedsgpa);
							cout << "\nSuccessfully Updated SGPA for Semester " << semYear << endl;
						}
						break;
					}
					case 3:
						return;

					default:
						cout << "Invalid choice! Please try again." << endl;
					}
				}
			}
			return;  // Exit after updating
		}
	}

	cout << "\n\t\tStudent not found!" << endl;  // If the student is not found
}


// display student detaild based on the Roll No
void displayDetails(vector<Student>& students) {
	int rollNumber;

	cout <<"\nEnter RollNumber To Display Details :: ";
	// Handling RollNumber
	while (!(cin >> rollNumber) || rollNumber < 0) {
		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
		cout << "Invalid input. Please enter a valid Roll Number: ";
	}

	for(const auto& student : students) {
		if(student.getRollNumber() == rollNumber) {
			student.displayInfo(); // display info of specific student
			return;
		}
	}

	cout << "\n\t\tStudent Not found | Make sure that ID is Valid ! " << endl;
}

// Function to display all students
void displayAllStudents(const vector<Student>& students) {
	cout << "\n======================================================" << endl;
	cout << "              STUDENT MANAGEMENT SYSTEM               " << endl;
	cout << "======================================================" << endl;

	if (students.empty()) {
		cout << "\n\t------------ No Student to Display ------------" << endl;
	} else {
		cout << "\n\t\t============ STUDENT DETAILS ============\n" << endl;
		for (const auto& student : students) {
			cout << "------------------------------------------------------" << endl;
			student.displayInfo();
			cout << "------------------------------------------------------\n" << endl;
		}
	}

	cout << "\n======================================================" << endl;
	cout << "              Thank you for using the system!         " << endl;
	cout << "======================================================\n" << endl;
}


// Function to add SGPAs for a student
void addSGPAToStudent(vector<Student>& students) {
	int rollNumber, numSemesters;
	double sgpa;

	cout << "\nEnter Roll Number to add SGPAs: ";
	// Handling RollNumber
	while (!(cin >> rollNumber) || rollNumber < 0) {
		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
		cout << "Invalid input. Please enter a valid Roll Number: ";
	}


	for (auto& student : students) {
		if (student.getRollNumber() == rollNumber) {
			cout << "\nEnter number of semesters: ";
			cin >> numSemesters;

			for (int i = 0; i < numSemesters; i++) {
				cout << "\nEnter SGPA for Semester " << i + 1 << ": ";
				cin >> sgpa;
				student.addSGPA(sgpa);
			}

			cout << "\n\t\tSGPAs added successfully for " << student.getName() << "!\n";
			return;
		}
	}

	cout << "\n\t\tStudent not found!\n";
}

// Function to delete a student
void deleteStudent(vector<Student>& students) {
	int rollNumber;
	cout << "\nEnter Roll Number to delete: ";
	// Handling RollNumber
	while (!(cin >> rollNumber) || rollNumber < 0) {
		cin.clear();  // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
		cout << "Invalid input. Please enter a valid Roll Number: ";
	}

	for (auto it = students.begin(); it != students.end(); ++it) {
		if (it->getRollNumber() == rollNumber) {
			if(DeleteConformation()) {
				students.erase(it);
				cout << "\n\t\tStudent deleted successfully!\n";
				return;
			}
			else {
				cout << "\nRecord Not Deleted !" << endl;
			}

		}
	}

	cout << "Student not found!\n";
}

bool DeleteConformation() {
	cout << "\n\tAre you sure that you want to delete the record !" << endl;
	char choice;
	cout <<"\nEnter your choice : [ Y / N ] :: ";
	cin >> choice;
	if(choice == 'Y' || choice == 'y') return 1;

	return 0;
}

bool UpdateConformation() {
	cout << "\n\tAre you sure that you want to Update the record !" << endl;
	char choice;
	cout <<"\nEnter your choice : [ Y / N ] :: ";
	cin >> choice;
	if(choice == 'Y' || choice == 'y') return 1;

	return 0;
}

