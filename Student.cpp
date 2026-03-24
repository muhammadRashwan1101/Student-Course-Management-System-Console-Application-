#include "Student.h"
#include <iostream>

Student::Student() {
	m_ID = 0;
	m_GPA = 0;
	m_name = "N/A";
	m_courses.clear(); //Remove any potential garbage data
}

Student::Student(int ID, double GPA, string name) {
	m_ID = ID;
	m_GPA = GPA;
	m_name = name;
}
int Student::getId() const {
	return m_ID;
}
double Student::getGpa() const {
	return m_GPA;
}

void Student::enrollCourse(const string& course_name) {

	//Check if the course is already listed
	if (m_courses.find(course_name) != m_courses.end()) {
		cout << "\nStudent is already enrolled in such course\n";
		return;
	}
	m_courses.insert(course_name);
		cout << "\nStudent is Enrolled Successfully\n";
}
void Student::displayCourses() const {
	if (m_courses.empty()) {
		cout << "Not Enrolled in any courses yet\n";
		return;
	}

	int i = 1;
	cout << "Courses: \n";
	for (const string& course : m_courses)
	{
		cout << "  " << i++ << ". " << course << "\n";
	}
}