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

//class CommissionEmployee
class CommissionEmployee :public Employee
{
public:
	CommissionEmployee(const string &staffname, int staffnumber)
		:Employee(staffname, staffnumber)
	{

	}

	//setting base salary
	void setBaseSalary(float baseSalary)
	{
		BaseSalary = (baseSalary<0.0) ? 0.0 : baseSalary;
	}
	//setting rate
	void setRate(float rate)
	{
		Rate = (rate<0.0) ? 0.0 : rate;
	}

	//setting revenue
	void setRevenue(float revenue)
	{
		Revenue = (revenue<0.0) ? 0.0 : revenue;
	}

	//calculating salary
	float salary()
	{
		Earnings = BaseSalary + (Rate*Revenue);
		return Earnings;
	}

private:
	float Rate, BaseSalary, Revenue, Earnings;
};
//Driver Program
int main()
{
	//declaring pointers to objects
	Employee *salaryEmpPtr, *hourlyEmpPtr, *commEmpPtr;
	string temp;
	//creating objects of each type
	SalaryEmployee salaryEmployee1("Makepeace", 11);
	HourlyEmployee hourlyEmployee1("Busisiwe", 12);
	CommissionEmployee commissionEmployee1("Mukuda", 13);
	//Assigning addresses of each object to base-pointers
	salaryEmpPtr = &salaryEmployee1;
	hourlyEmpPtr = &hourlyEmployee1;
	commEmpPtr = &commissionEmployee1;
	//====================================================================
	//Calculating total wages paid to employees, polymorphically
	//====================================================================

	cout << "***********CALCULATING TOTAL WAGES POLYMORPHICALLY**********\n" << endl;


	//1.Salaried Employee.
	cout << "STAFF NAME:" << salaryEmployee1.name() << '\n';
	cout << "STAFF NUMBER:" << salaryEmployee1.staffNumber() << '\n';
	salaryEmployee1.setSalary(25.0);	//setting salaryEmployee1's salary.
	cout << "TOTAL WAGE: $"
		<< salaryEmpPtr->salary() << '\n' << '\n';	//indirect access of base-class member.

													//2.Hourly Emlployee.
	cout << "STAFF NAME:" << hourlyEmployee1.name() << '\n';
	cout << "STAFF NUMBER:" << hourlyEmployee1.staffNumber() << '\n';
	hourlyEmployee1.setHourlyRate(1.50);	//setting salaryEmployee1's rate/hour.
	hourlyEmployee1.setHoursWorked(10);	//setting salaryEmployee1's hours worked.
	cout << "TOATAL WAGE: $"
		<< hourlyEmpPtr->salary() << '\n' << '\n';	//indirect access of base-class member.

													//3.Commission Employee.
	cout << "STAFF NAME:" << commissionEmployee1.name() << '\n';
	cout << "STAFF NUMBER:" << commissionEmployee1.staffNumber() << '\n';
	commissionEmployee1.setBaseSalary(15.5);	//setting salaryEmployee1's base salary.
	commissionEmployee1.setRate(0.5);	//setting salaryEmployee1's commission %.
	commissionEmployee1.setRevenue(0.5);	//setting salaryEmployee1's revenue
	cout << "TOTAL WAGE: $"
		<< commEmpPtr->salary() << '\n' << '\n';	//indirect access of base-class member.

	return 0;

}
