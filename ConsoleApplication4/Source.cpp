#include<iostream>
#include<string>
using namespace std;

//Abstract class Employee
class Employee
{
public:
	Employee(const string &staffname, const int &staffnumber) :staffName(staffname), staffNum(staffnumber)
	{
		//empty constructor
	}

	//member functions.
	//set staff name,The function will be inherited as such.
	void setStaffName(const string &staffname)
	{
		staffName = staffname;
	}

	//set staff number,Function will be inherited as such.
	void setStaffNumber(int &staffnumber)
	{
		staffNum = staffnumber;
	}

	//returns a C++ string.
	string name()
	{
		return staffName;
	}

	//returns staff number.
	int staffNumber()
	{
		return staffNum;
	}

	virtual float salary() { return 0; };
private:
	int staffNum;
	static int numberOfStaff;
	string staffName;
};