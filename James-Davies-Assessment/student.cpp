#include "student.h"
#include <string>
#include <iostream>
using namespace std;

student::student(string ID, string fName, string lName, string email, int _age, int days[], DegreeProgram deg) :
	studentID(ID), firstName(fName), lastName(lName), emailAddress(email), age(_age), degree(deg)
{
	for (int i = 0; i < 3; i++)
	{
		daysToComplete[i] = days[i];
	}
}

void student::Print() const
{
	cout << this->studentID << '\t';
	cout << "First Name: " << this->firstName << '\t';
	cout << "Last Name: " << this->lastName << '\t';
	cout << "Email: " << this->emailAddress << '\t';
	cout << "Age: " << this->age << '\t';
	cout << "Days in Course: " << daysToComplete[0] << ',' << daysToComplete[1] << ',' << daysToComplete[2] << '\t' << '\t';
	cout << "Degree Program: ";
	switch (this->degree)
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
	cout << endl;
}

string student::GetStudentID() const
{
	return this->studentID;
}
void student::SetStudentID(string value)
{
	this->studentID = value;
}

string student::GetFirstName() const
{
	return this->firstName;
}
void student::SetFirstName(string value)
{
	this->firstName = value;
}

string student::GetLastName() const
{
	return this->lastName;
}
void student::SetLastName(string value)
{
	this->lastName = value;
}

string student::GetEmail() const
{
	return this->emailAddress;
}
void student::SetEmail(string value)
{
	this->emailAddress = value;
}

int student::GetAge() const
{
	return this->age;
}
void student::SetAge(int value)
{
	this->age = value;
}

int student::GetDaysToComplete(int index) const
{
	return this->daysToComplete[index];
}
void student::SetDaysToComplete(int index, int value)
{
	this->daysToComplete[index] = value;
}

DegreeProgram student::GetDegree() const
{
	return this->degree;
}
void student::SetDegree(DegreeProgram value)
{
	this->degree = value;
}

double student::GetAverageDays() 
{
	auto sum = daysToComplete[0] + daysToComplete[1] + daysToComplete[2];
	return sum / 3.0;
}
