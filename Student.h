#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <set>

class Student : public Person {
	int m_ID;
	double m_GPA;
	set<string> m_courses;

public:
	Student();
	Student(int ID, double GPA, string name);
	//consts to prevent any unplanned alteration for the original object data
	int getId() const;
	double getGpa() const;

	void enrollCourse(const string& course_name); //call by reference to use the direct original name without creating a new string ( less memory consumption )
	void displayCourses() const;
};

#endif