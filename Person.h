#ifndef Person_H
#define Person_H

#include <string>
using namespace std;


class Person {

protected:
	string m_name;

public:
	Person();
	Person(string name);
	string getName() const;
};

#endif

