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

//class SalaryEmployee
class SalaryEmployee :public Employee
{
public:
	SalaryEmployee(const string &staffname, const int &staffnumber)
		: Employee(staffname, staffnumber)
	{

	}//end of SalaryEmployee constructor

	 //set salary.
	void setSalary(float staffSalary)
	{
		grossSalary = ((staffSalary<0.0) ? 0.0 : staffSalary);
	}
	float salary()
	{
		return grossSalary;
	}
private:
	float grossSalary;
};

//class HourlyEmployee.
class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(const string &staffname, const int &staffnumber)
		: Employee(staffname, staffnumber)
	{

	}
	//setting hourly rate
	void setHourlyRate(float hourlyRate)
	{
		HourlyRate = hourlyRate < 0.0 ? 0.0 : hourlyRate;
	}
	//setting hours worked
	void setHoursWorked(int hoursWorked)
	{
		HoursWorked = ((hoursWorked>0) && (hoursWorked <= 744)) ? hoursWorked : 0;
	}
	//calculating salary
	float salary()
	{
		wage = HoursWorked*HourlyRate;
		return wage;
	}

private:
	float wage;
	int HoursWorked;
	float HourlyRate;
};