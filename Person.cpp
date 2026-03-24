#include "Person.h"
Person::Person() {
	m_name = "Unknown";
}

Person::Person(string name) {
	m_name = name;
}
string Person::getName() const {
	return m_name;
}