#include <iostream>
#include <string>
using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

string GetNextItem(string& text)
{
	string delimeter = ",";
	auto item = text.substr(0, text.find(delimeter));
	text.erase(0, text.find(delimeter) + 1);
	return item;
}

void PopulateRoster(roster& classRoster)
{
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,James,Davies,daviesjamesp@gmail.com,26,20,30,40,SOFTWARE" };

	for (int i = 0; i < 5; i++)
	{
		auto lineItem = studentData[i];
		auto newID = GetNextItem(lineItem);
		auto newFName = GetNextItem(lineItem);
		auto newLName = GetNextItem(lineItem);
		auto newEmail = GetNextItem(lineItem);
		auto newAge = std::stoi(GetNextItem(lineItem));
		int newDays[3];
		for (int j = 0; j < 3; j++)
		{
			newDays[j] = std::stoi(GetNextItem(lineItem));
		}
		auto degreeText = GetNextItem(lineItem);
		DegreeProgram newDegree = DegreeProgram::NONE;
		if (degreeText == "SECURITY") { newDegree = DegreeProgram::SECURITY; }
		if (degreeText == "NETWORK") { newDegree = DegreeProgram::NETWORK; }
		if (degreeText == "SOFTWARE") { newDegree = DegreeProgram::SOFTWARE; }
		classRoster.Add(newID, newFName, newLName, newEmail, newAge, newDays, newDegree);
	}
}

int main()
{
	roster* classRoster = new roster();
	PopulateRoster(*classRoster);

	cout << "Scripting and Programming - Applications C867, C++. 002072436 James Davies" << endl << endl;

	classRoster->PrintAll();

	classRoster->PrintInvalidEmails();

	classRoster->PrintAllAvgDays();

	classRoster->PrintByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << "Removing student A3..." << endl;
	classRoster->Remove("A3");
	cout << endl;

	classRoster->PrintAll();

	cout << "Removing student A3 (again!)" << endl;
	classRoster->Remove("A3");

	delete classRoster;

	return 0;
}

