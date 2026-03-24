#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include "Student.h"
#include <map>

class MenuManager {
	map<int, Student> Students;
	void addStudent();
	void removeStudent();
	void searchStudent();
	void displayAllStudents();
	void enrollCourse();
	void showStudentCourses();
	void sortByGPA();

public:	
	void run();
};
#endif

