#pragma once
#include <vector>
#include "student.h"

class roster
{
private:
	std::vector<student*>	classRosterArray;
public:
	roster();
	~roster();
	void Add(string ID, string fName, string lName, string email, int _age, int days[], DegreeProgram deg);
	void Remove(string ID);
	void PrintAll();
	void PrintAvgDays(string ID);
	void PrintAllAvgDays();
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degree);
};

