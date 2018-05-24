/*
 • The Employee class should throw an exception named InvalidEmployeeNumber
    when it receives an employee number that is less than 0 or greater than 9999.
 • The ProductionWorker class should throw an exception named InvalidShift
    when it receives an invalid shift.
 • The ProductionWorker class should throw an exception named InvalidPayRate
    when it receives a negative number for the hourly pay rate.


    Created by Zeeshan Abidi on 5/22/18.
*/

#include<iostream>
#include<string>
using namespace std;

/*
 Design a class named Employee. The class should keep the following information in
 • Employee name
 • Employee number
 • Hire date
 */

class Employee
{
private:
        string EmployeeName;
        int EmployeeNumber;
        string HireDate;

public:
    Employee()            //default constructor
        {
            EmployeeName = " ";
            EmployeeNumber = 0;
            HireDate= " ";
        }

        Employee(string name, int number, string date)
        {
            EmployeeName = name;
            EmployeeNumber = number;
            HireDate = date;
        }
        //Excaption class for Invalid ID
        class InvalidEmployeeNumber{};
        void setEmpName(string);
        void setEmpNumber(int);
        void setHireDate(string);
        string getEmpName();
        int getEmpNumber();
        string getHireDate();
    };

    //setters
    void Employee::setEmpName(string str)
    {
        EmployeeName = str;
    }
    /************************************************
      throw an exception named InvalidEmployeeNumber
     When it receives an employee number that is
     less than 0 or greater than 9999.
     ******************************************/
    void Employee::setEmpNumber(int num)
    {
        if(num < 0 ||num > 9999)        //if employe number is less than 1 or greater than 999
        throw InvalidEmployeeNumber();
    else
        EmployeeNumber = num;
    }
    void Employee::setHireDate(string date)
    {
        HireDate = date;
    }

    //getters
    string Employee::getEmpName()
    {
        return EmployeeName;
    }
    int Employee::getEmpNumber()
    {
        return EmployeeNumber;
    }
    string Employee::getHireDate()
    {
        return HireDate;
    }

    /*****************************************************************************************
     Next, write a class named ProductionWorker that is derived from the Employee class.
     The ProductionWorker class should have member variables to hold the following information:
     • Shift (an integer)
     • Hourly pay rate (a double)
     **********************************************************************************************/
class ProductionWorker:public Employee
    {
private:
        int Shift;
        double HourlyPayRate;

public:
        ProductionWorker()         //Default constructor
        {
            Shift = 0;
            HourlyPayRate = 0;
        }

        ProductionWorker(int shift,double pay)
        {
            Shift = shift;
            HourlyPayRate = pay;
        }
        //Exception class for Invalid shift
        class InvalidShift{};
        //Exception class for Invalid Pay rate
        class InvalidPayRate{};
        void setShift(int);
        void setHourlyPay(double);
        int getShift();
        double getHourlyPay();
    };

    /*
     The ProductionWorker class should throw an exception named InvalidShift
     when it receives an invalid shift.
     */
    void ProductionWorker::setShift(int shift)
    {
        if(shift < 0||shift > 2)        //if shift is less than 0 or greater than 2, throw
            throw InvalidShift();
        else
            Shift = shift;
    }

    /* The ProductionWorker class should throw an exception named InvalidPayRate
        when it receives a negative number for the hourly pay rate.
     */
    void ProductionWorker::setHourlyPay(double pay)
    {
        if(pay< 1)                  //if pay is less than 0, throw
            throw InvalidPayRate();
        else
            HourlyPayRate = pay;
    }

    int ProductionWorker::getShift()
    {
        return Shift;
    }
    double ProductionWorker::getHourlyPay()
    {
        return HourlyPayRate;
    }

    int main()
    {
        int shift;
        double pay;
        int num;

        cout << "Enter employee number: ";
        cin >> num;
        cout << "Enter shift (DayShift = 1  /  NightShift = 2): ";
        cin >> shift;
        cout << "Enter hourly pay: ";
        cin >> pay;


        //creating ProductionWorker object
        ProductionWorker Employee1(0,0);

        Employee1.setEmpName("Kobe");
        Employee1.setHireDate(" October 24, 2019");

        try
        {
            Employee1.setShift(shift);
            Employee1.setHourlyPay(pay);
        }
        catch(Employee::InvalidEmployeeNumber)
        {
            cout<<"Error invalid employee number entered" << endl;
        }
        catch(ProductionWorker::InvalidShift )
        {
            cout<<"Error invalid shift entered" << endl;
        }
        catch(ProductionWorker ::InvalidPayRate)
        {
            cout<<"Error invalid pay rate entered" << endl;
        }

        cout<< "\nEmployee Details:"<< endl;
        cout<< "-------------------"<< endl;
        cout<< "Employee Name: " << Employee1.getEmpName() << endl;
        cout<<"Employee Number: " << Employee1.getEmpNumber() << endl;
        cout<< "Employee Hire Date: " << Employee1.getHireDate() << endl;
        cout<< "Employee Shift: " << Employee1.getShift() << endl;
        cout<<"Employee Hourly pay: $" << Employee1.getHourlyPay() << endl;

        return 0;
    }
