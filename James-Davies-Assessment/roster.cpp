#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "roster.h"
#include "degree.h"



roster::roster()
{ 
	classRosterArray.resize(0);
}

roster::~roster()
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		delete classRosterArray.at(i);
	}
	classRosterArray.clear();
}



void roster::Add(string ID, string fName, string lName, string email, int _age, int days[], DegreeProgram deg)
{
	student* newStudent = new student(ID, fName, lName, email, _age, days, deg);
	classRosterArray.push_back(newStudent);
}

void roster::Remove(string ID)
{
	bool isFound = false;
	for (int i = 0; i < classRosterArray.size() && !isFound; i++)
	{
		if (classRosterArray.at(i)->GetStudentID() == ID)
		{
			isFound = true;
			classRosterArray.erase(classRosterArray.begin() + i);
		}
	}
	if (!isFound)
	{
		cout << "Error: Student ID not found!" << endl << endl;
	}
}

void roster::PrintAll()
{
	cout << "List of all students in roster:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray.at(i)->Print();
	}
	cout << endl;
}

void roster::PrintAvgDays(string ID)
{
	bool isFound = false;
	for (int i = 0; i < classRosterArray.size() && !isFound; i++)
	{
		if (classRosterArray.at(i)->GetStudentID() == ID)
		{
			isFound = true;
			cout << classRosterArray.at(i)->GetStudentID() << ": ";
			cout << classRosterArray.at(i)->GetAverageDays() << endl;
		}
	}
	if (!isFound)
	{
		cout << "Error: Student ID not found!" << endl;
	}
}

void roster::PrintAllAvgDays()
{
	cout << "Average Days in Courses:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		PrintAvgDays(classRosterArray.at(i)->GetStudentID());
	}
	cout << endl;
}

void roster::PrintInvalidEmails()
{
	int count = 0;
	cout << "Invalid Emails:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		bool isValid = true;
		auto emailToCheck = classRosterArray.at(i)->GetEmail();
		if (emailToCheck.find('@') == string::npos) { isValid = false; }
		if (emailToCheck.find('.') == string::npos) { isValid = false; }
		if (emailToCheck.find(' ') != string::npos) { isValid = false; }
		if (!isValid)
		{
			count++;
			cout << "Student " << classRosterArray.at(i)->GetStudentID() << ": ";
			cout << emailToCheck << endl;
		}
	}
	if (count == 0) 
	{
		cout << "No invalid emails found." << endl;
	}
	cout << endl;
}

void roster::PrintByDegreeProgram(DegreeProgram degree)
{
	int count = 0;
	cout << "Students in the ";
	switch (degree)
	{
	case DegreeProgram::SECURITY:
		cout << "Security";
		break;
	case DegreeProgram::NETWORK:
		cout << "Network";
		break;
	case DegreeProgram::SOFTWARE:
		cout << "Software";
		break;
	default:
		break;
	}
	cout << " Program:" << endl;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->GetDegree() == degree)
		{
			count++;
			classRosterArray.at(i)->Print();
		}
	}
	if (count == 0)
	{
		cout << "No matching students found." << endl << endl;
	}
	cout << endl;
}