#include "MenuManager.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <limits>

//===============================
// ADD STUDENT
//===============================
void MenuManager::addStudent() {
	int id;
	string name;
	double gpa;

	//Validate the ID Input
	while (true) {
		cout << "\nEnter Student ID: ";
		cin >> id;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
		} else if (Students.find(id) != Students.end()) {
			cout << "ID Already Exists, Enter a unique ID";
		} else {
			//Clean the input buffer from the residual "\n" from the previous incorrect input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	} 

	//Validate the Name Input
	cout << "Enter Student Name: ";
	getline(cin, name);
	while (name.empty()) {
		cout << "\nName cannot be empty. Enter Student Name: ";
		getline(cin, name);
	}

	//Validate the GPA Input
	while (true) {
		cout << "Enter Student GPA: ";
		cin >> gpa;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number\n";
		} else if (gpa < 0.0 || gpa > 4.0) {
			cout << "\nGPA must be between 0.0 and 4.0\n";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	Students[id] = Student(id, gpa, name);
	cout << "\nStudent added successfully.\n";
}

//===============================
// REMOVE STUDENT
//===============================
void MenuManager::removeStudent(){
	int id;
	
	while (true) {
		cout << "\nEnter Student ID: ";
		cin >> id;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
		} else {
			//Clean the input buffer from the residual "\n" from the previous incorrect input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	
	if (Students.erase(id)) {
		cout << "\nStudent Removed Successfully \n";
	}
	else {
		cout << "\nStudent ID not valid. No students Found \n";

	}
}

//===============================
// SEARCH STUDENT
//===============================
void MenuManager::searchStudent(){
	int id;

	while (true) {
		cout << "\nEnter Student ID: ";
		cin >> id;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
		} else {
			//Clean the input buffer from the residual "\n" from the previous incorrect input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	

	if (Students.find(id) != Students.end()) {
		cout << "\nID: " << Students[id].getId() << "\n"
			<< "Name: " << Students[id].getName() << "\n"
			<< "GPA: " << Students[id].getGpa() << "\n";
				Students[id].displayCourses();
				cout << "\n";
	}
	else {
		cout << "\nStudent ID not valid. No students Found \n";
	}
}

//===============================
// DISPLAY ALL STUDENTS
//===============================
void MenuManager::displayAllStudents(){
	if (Students.size() == 0) {
		cout << "\nNo Students Registered yet\n";
	}
	else {
		for (const auto& student: Students) {
			cout << "\nID: " << student.second.getId()
				<< "\nName: " << student.second.getName()
				<< "\nGPA: " << student.second.getGpa()
				<< "\n";
					student.second.displayCourses();
					cout << "\n";
		}
	}
}

//===============================
// ENROLL A STUDENT TO A COURSE
//===============================
void MenuManager::enrollCourse(){
	string c_name;
	int id;

	while (true) {
	cout << "\nEnter Student ID to enroll: ";
	cin >> id;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
		}
		else {
			//Clean the input buffer from the residual "\n" from the previous incorrect input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	cout << "Enter Course Name: ";
	getline(cin,c_name);

	while (c_name.empty()) {
		cout << "\nCourse name can not be empty. Enter Course Name: ";
		getline(cin,c_name);
	}

	if (Students.find(id) != Students.end()) {
		Students[id].enrollCourse(c_name);
	}
	else {
		cout << "\nStudent ID not valid. No students Found \n";

	}

}

//======================================================
// SHOW ALL THE STUDENT'S COURSES THAT HE IS ENROLLED IN
//======================================================
void MenuManager::showStudentCourses(){
	int id;

	while (true) {
		cout << "\nEnter Student ID: ";
		cin >> id;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
		}
		else {
			//Clean the input buffer from the residual "\n" from the previous incorrect input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	if (Students.find(id) != Students.end()) {
		Students[id].displayCourses();
		cout << "\n";
	}
	else {
		cout << "\nStudent ID not valid. No students Found \n";

	}
}
//===============================
// SORT STUDENTS BY GPA
//===============================
void MenuManager::sortByGPA(){

	//Created a copy of the map as it can't be sorted due to its default sorting
	vector<Student> copiedStudents;
	for (auto& copiedMapElement : Students) { // Call by reference to get the original coppied pair element from the map without creating a new copy of it ( Less Memory Consmption and better Performance )
		copiedStudents.push_back(copiedMapElement.second);
	}
	//Sort(intial range value, final range value), Comparison Function --> in this case Lambda Function 
	sort(copiedStudents.begin(), copiedStudents.end(),
		//empty [] --> we are not using any external variables from outer scoop
		[](const Student& s1, const Student& s2) {
			return s1.getGpa() > s2.getGpa();
		}
	);
	
	for (const auto& stud : copiedStudents) {
		cout << "\nID: " << stud.getId()
			<< "\nName: " << stud.getName()
			<< "\nGPA: " << stud.getGpa() << "\n";
	}
}

//===============================
// DISPLAY CONSOLE APP MENU
//===============================
void MenuManager::run(){
	int command;
	do {
		cout << "\n--- Student Management System ---\n"
			 << "1. Add Student\n"
			 << "2. Remove Student\n"
			 << "3. Search Student\n"
			 << "4. Display All Students\n"
			 << "5. Enroll Student in Course\n"
			 << "6. Show Student Courses\n"
			 << "7. Sort Students by GPA\n"
			 << "8. Exit\n"
			 << "Enter Command Number: ";

		cin >> command;
		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a number.\n";
			continue;
		}

		switch (command) {
		case 1: 
			addStudent(); 
			break;
		case 2: 
			removeStudent(); 
			break;
		case 3: 
			searchStudent(); 
			break;
		case 4: 
			displayAllStudents(); 
			break;
		case 5: 
			enrollCourse(); 
			break;
		case 6: 
			showStudentCourses(); 
			break;
		case 7: 
			sortByGPA(); 
			break;
		case 8: 
			cout << "\n Exiting program.\n"; 
			break;
		default: 
			cout << "\nInvalid choice, try again.\n";
		}
	} while (command != 8);

}