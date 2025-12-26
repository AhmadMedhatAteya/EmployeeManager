#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;


struct stEmployee
{
    string FirstName;
    string LastName;
    double Salary;
};


string readStringFromUser(string Message)
{
    string Input;
    cout << Message << endl;
    getline(cin >> ws, Input);
    return Input;
}

double readDoubleFromUser(string Message)
{
    double number = 0;
    cout << Message << endl;
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}

void FillEmployeesVector(vector<stEmployee>& Employee)
{
    char Choice = 'y';
    int counter = 1;
    stEmployee employeeTemp;

    do
    {
        cout << "----------------------------------------\n";
        cout << "Employee Number " << counter << " Fill Info:\n";
        cout << "----------------------------------------\n";

        employeeTemp.FirstName = readStringFromUser("Please Enter First Name Of Employee: ");
        employeeTemp.LastName = readStringFromUser("Enter Last Name: ");
        employeeTemp.Salary = readDoubleFromUser("Enter Salary: ");

        Employee.push_back(employeeTemp);

        cout << "\nEmployee Number " << counter << " Added Successfully!\n";
        cout << "Do you want to add more employees? (Y/N): ";
        cin >> Choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        counter++;

        system("cls");

    } while (Choice == 'y' || Choice == 'Y');
}

void printEmployeeInfo(const stEmployee& Employee)
{
    cout << "First Name: " << Employee.FirstName << endl;
    cout << "Last Name : " << Employee.LastName << endl;
    cout << "Salary    : " << Employee.Salary << endl;
}

void printVectorOfEmployees(const vector<stEmployee>& vEmployees)
{
    int counter = 1;
    for (const stEmployee& employee : vEmployees)
    {
        cout << "----------------------------------------\n";
        cout << "Employee " << counter << " Info:\n";
        printEmployeeInfo(employee);
        cout << "----------------------------------------\n";
        counter++;
    }
}

int main()
{
    cout << "========================================\n";
    cout << "       WELCOME TO EMPLOYEE MANAGER      \n";
    cout << "========================================\n\n";

    vector<stEmployee> vEmployees;
    FillEmployeesVector(vEmployees);

    system("cls");
    cout << "*********** ALL EMPLOYEES ***********\n\n";
    printVectorOfEmployees(vEmployees);

    return 0;
}
