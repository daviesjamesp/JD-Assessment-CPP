#pragma once
#include <string>
#include "degree.h"

class student
{
private:
	std::string		studentID;
	std::string		firstName;
	std::string		lastName;
	std::string		emailAddress;
	int				age;
	int				daysToComplete[3];
	DegreeProgram	degree;
	
public: 
	student(std::string ID, std::string fName, std::string lName, std::string email, int _age, int days[], DegreeProgram deg);
	void			Print() const;
	std::string		GetStudentID() const;
	void			SetStudentID(std::string value);
	std::string		GetFirstName() const;
	void			SetFirstName(std::string value);
	std::string		GetLastName() const;
	void			SetLastName(std::string value);
	std::string		GetEmail() const;
	void			SetEmail(std::string value);
	int				GetAge() const;
	void			SetAge(int value);
	int				GetDaysToComplete(int index) const;
	void			SetDaysToComplete(int index, int value);
	DegreeProgram	GetDegree() const;
	void			SetDegree(DegreeProgram deg);
	double			GetAverageDays();
};

