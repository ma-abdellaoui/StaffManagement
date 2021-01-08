#include <iostream>
using namespace std;


int currentYear;                            // needed to calculate age !
class Date{                                 // Class Date for date of birth and for holiday dates
public:
    // Date variables
    short day;
    short month;
    unsigned int year;
    //member functions
    void enterDate()
    {
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    }
    void enterDate(int d, int m, int y)
    {
    day= d;
    month=m;
    year=y;
    }

    void showData()
    {
    cout << day << "." << month << "." << year << endl;
    }
};

int returnDatesDiff(Date date1, Date date2) // takes two dates as input and returns the number of days between them
{
    //calculate the diffrence between two dates and return the number of days.
    //variable for day count for each month
    const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
    // start count with year and day
    long int num1 = date1.year * 365 + date1.day;
    // Add days for of each months in date
    for (int i = 0; i < date1.month - 1; i++)
        num1 += monthDays[i];
    // Add one day for every leap year
    if (date1.month <= 2){date1.year--;};
    num1 += date1.year / 4 - date1.year / 100+ date1.year / 400;
    //we do the same with the second date
    long int num2 = date2.year * 365 + date2.day;
    for (int i = 0; i < date2.month - 1; i++)
        num2 += monthDays[i];
    if (date2.month <= 2){date2.year--;};
    num2 += date2.year / 4 - date2.year / 100+ date2.year / 400;
    // return the difference between the two different counts.
    return abs(num2 - num1);
}

class Employee                              // base class: Employee
{
protected:
    string surname;
    string firstname;
    Date dateofbirth;
    int Days_of_holiday_taken =0;           // initiate with 0 as new employee
    int Days_of_holiday_allowed;
    string type = "E";                      // type E stands for empty. it can either be H for hourly, S for Salary or M for manager.
public:
    Employee(): surname(),firstname(),dateofbirth(), type(){}               // Constructor
    string get_type() {return type;}                                        // get type of employee when looping through database
    string get_name() {return surname;}                                     // get surname of employee when looping through database
    int get_num_holidays_taken() {return Days_of_holiday_taken;}            // get number of haliday days already taken
    int get_num_holidays_allowed() {return Days_of_holiday_allowed;}        // get number of holiday days allowed

    //virtual functions to get display data for each subclass
    virtual void get_hourlyE_data(){}
    virtual void get_salaryE_data(){}
    virtual void get_manager_data(){}

    // other base class member functions
    void calc_num_holiday_days()            // calculate the number of holiday days allowed based on age
    {
        Date refrence;                      // reference date to calculate the age of the employee/manager.
        refrence.enterDate(2,1,currentYear);    // here the day 02.01 of the current calender year is specified
        int num_days = returnDatesDiff(dateofbirth,refrence); //calc number of days between birthday and current year
        if ((num_days/365)<= 50)                // if younger than 50 then 30 days of holiday, else 32 days .
        {
            Days_of_holiday_allowed = 30;
        }
        else
        {
            Days_of_holiday_allowed = 32;
        }
    }
    void add_holiday_days_taken(int numH)   //increment the total number of days taken by employee.
    {
        Days_of_holiday_taken += numH;
    }
};
class HourlyEmployee : public Employee      // Hourly employee class, inherits from base class
{
private:
    float hourly_wage;
    float hours_worked;
public:
    HourlyEmployee():Employee(), hourly_wage(),hours_worked()        //Constructor
   {
        // constructor is responsible for interface with user to input data
        cout << "Enter Surname:";
        cin >>surname;
        cout << "Enter Firstname:";
        cin >>firstname;
        cout << "Enter Date of Birth:" << endl;
        dateofbirth.enterDate();
        cout << "Enter Hourly Wage:";
        cin >> hourly_wage;
        cout << "Enter Hours Worked:";
        cin >> hours_worked;
        type = "H";
        calc_num_holiday_days();
        cout << "employee created successfully!" << endl;
   }
    void get_hourlyE_data()                 // display all data for hourly employee
    {
        cout << "=====================" << endl;
        cout << "Surname: " <<surname << endl;
        cout << "Firstname: " << firstname<< endl;
        cout << "Date of birth: ";
        dateofbirth.showData();
        cout << endl;
        cout << "Hourly wage: " << hourly_wage<< endl;
        cout << "Hours worked: " << hours_worked<< endl;
        cout << "Holiday days taken: " << Days_of_holiday_taken<< endl;
        cout << "Holiday days allowed: " << Days_of_holiday_allowed << endl;
        cout << "=====================" << endl;
    }

};
class SalariedEmployee : public Employee    // Salaried employee class, inherits from base class
{
private:
    float annual_salary;
public:
    SalariedEmployee():Employee(), annual_salary()       //Constructor
   {

        cout << "Enter Surname:";
        cin >>surname;
        cout << "Enter Firstname:";
        cin >>firstname;
        cout << "Enter Date of Birth:" << endl;
        dateofbirth.enterDate();
        cout << "Enter annual Salary:";
        cin >> annual_salary;
        type = "S";
        calc_num_holiday_days();
        cout << "Employee created successfully!" << endl;
   }
    void get_salaryE_data()
    {
        cout << "=====================" << endl;
        cout << "Surname: " <<surname << endl;
        cout << "Firstname: " << firstname<< endl;
        cout << "Date of birth: ";
        dateofbirth.showData();
        cout << endl;
        cout << "Annual salary: " << annual_salary<< endl;
        cout << "Holiday days taken: " << Days_of_holiday_taken<< endl;
        cout << "Holiday days allowed: " << Days_of_holiday_allowed << endl;
        cout << "=====================" << endl;
    }
};

class Manager : public Employee             // Manager class, inherits from base class
{
private:
    float profit_sharing;

public:
   Manager():Employee(), profit_sharing()       //Constructor
   {

        cout << "Enter Surname:";
        cin >>surname;
        cout << "Enter Firstname:";
        cin >>firstname;
        cout << "Enter Date of Birth:" << endl;
        dateofbirth.enterDate();
        cout << "Enter profit sharing:";
        cin >> profit_sharing;
        type = "M";
        calc_num_holiday_days();
        cout << "Manager created successfully!" << endl;
   }

    void get_manager_data()
    {
        cout << "=====================" << endl;
        cout << "Surname: " <<surname << endl;
        cout << "Firstname: " << firstname<< endl;
        cout << "Date of birth: ";
        dateofbirth.showData();
        cout << endl;
        cout << "Profit sharing: " << profit_sharing<< endl;
        cout << "Holiday days taken: " << Days_of_holiday_taken<< endl;
        cout << "Holiday days allowed: " << Days_of_holiday_allowed << endl;
        cout << "=====================" << endl;
    }
};

// ============== Declare database and related variables ============
    const int max_num_employees = 500;                     // max size of database, can be changed to any value
    Employee **base = new Employee*[max_num_employees];    // create array of pointers to base class that can also contain derived classes
    int num_employees = 0;                                 // dynamic variable that contains the current number of employees in the database

// ============== End Database declaration ==========================

// needed functions
bool isDatabaseEmpty()                      // Check if database is empty
{
    //Check if database is empty:
    if (num_employees == 0)
    {
        cout << "Database is empty, please fill in data and try again !" << endl;
        return 1;
    }
    return 0;
}

void addEmployee()                          // Add new employee to database
{
    //Declare needed variables
    int select;

    //Display Menu
    cout << "ADD NEW EMPLOYEE:"<< endl;
    cout << "please select one of the options below:" << endl;
    cout << "--MENU--" << endl;
    cout << "[1] Hourly Employee" << endl;
    cout << "[2] Salaried Employee" << endl;
    cout << "[3] Manager" << endl;
    cout << endl << "Please select: ";
    cin >> select;
    switch(select)
    {
    case 1:
        {
            base[num_employees] = new HourlyEmployee();
            num_employees++;   //increment the number of employees by 1
            break;
        }
    case 2:
        {
            base[num_employees] = new SalariedEmployee();
            num_employees++;
            break;
        }
    case 3:
        {
            base[num_employees] = new Manager();
            num_employees++;
            break;
        }
    default:
        {
            cout << endl << "Incorrect input!" << endl;
            system("pause");
            system("cls");
        }
    }
}

void showAllEmployees()                     // Show all employee/managers in the database
{
    /* This functions loops through the database and displays all of the employees based on their type.
    if type = E then entry is empty and will not be shown. */

    //Check if database is empty:
    if (isDatabaseEmpty()) return;

    cout << "Total number of saved employees: " << num_employees << endl;
    for (int i=0;i<max_num_employees;i++)
    {
        if (base[i] ->get_type()=="H")
        {
            // Hourly employee
            base[i] -> get_hourlyE_data();
        }
        else if (base[i] ->get_type()=="S")
        {
            // Salary employee
            base[i] -> get_salaryE_data();
        }
        else if (base[i] ->get_type()=="M")
        {
            // Manager
            base[i] -> get_manager_data();
        }
    }
    cout << "=== END OF LIST ===" << endl;
}
int findEmployeeBySurname()                 // search database by surname and return index of element that matched the search query
{
    // Loop through all database and find employee by surname.
    // if found the index will be returned, else (max size of database+1) will be returned.
    //Declare Variables
    string sname;
    //User input
    cout << "Please enter the surname of employee/manager: "  ;
    cin >> sname;

    //Loop through database
    for (int i=0;i<max_num_employees;i++)
    {
        if (base[i] ->get_type()=="H" || base[i] ->get_type()=="S" ||base[i] ->get_type()=="M") // check object type
        {
            // data entry is not empty, check for name match
            if (base[i] -> get_name() == sname)
                return i;

        }
    }
    cout << endl;
    return max_num_employees+1;
}

void removeEmployee()                       // remove employee/manager from database -- employee/manager is located by his surname
{
    //Check is database is not empty:
    if (isDatabaseEmpty()) return;

    // search for employee in database using his surname
    int id = findEmployeeBySurname();

    //if user is found, a valid id number will be returned
    if (id>=0 && id<max_num_employees)
    {
       //overwrite employee data with empty object of class employee
       base[id] = new Employee();
        cout << "Employee/Manager successfully removed from database!" << endl;
    }

    else
    {
        cout << "Employee/Manager was not found! please try again" << endl;

    }
}

void showEmployeeData()                     // Show all data of one employee/managaer -- employee/manager is located by his surname
{

    //Check is database is not empty:
    if (isDatabaseEmpty()) return;

    // search for employee in database using his surname
    int id = findEmployeeBySurname();

    //if user is found, a valid id number will be returned
    if (id>=0 && id<max_num_employees)
    {

        cout << "Employee/Manager was found!" << endl;
        //get data function of respective class is called based on type of employee
        if (base[id] ->get_type()=="H")
        {
            // Hourly employee
            base[id] -> get_hourlyE_data();
        }
        else if (base[id] ->get_type()=="S")
        {
            // Salary employee
            base[id] -> get_salaryE_data();
        }
        else if (base[id] ->get_type()=="M")
        {
            // Manager
            base[id] -> get_manager_data();
        }
    }
    else
    {
        cout << "Employee/Manager was not found! please try again" << endl;

    }
}


void addHolidayEntry()                      // add holiday entry to one employee/manager -- employee/manager is located by his surname
{
    //Check is database is not empty
    if (isDatabaseEmpty()) return;
    //Declare variables
    Date strtdat,enddat;

    // search for employee in database using his surname
    int id = findEmployeeBySurname();

    //if user is found, a valid id number will be returned
    if (id>=0 && id<max_num_employees)
    {
        cout << "Employee/Manager was found!" << endl;
        cout << "Employee/Manager currently has " << base[id] -> get_num_holidays_taken()<< " days of holiday taken."<<  endl;
        cout << "Employee/Manager is allowed " << base[id] -> get_num_holidays_allowed()<< " days of holiday."<<  endl;
        cout << "Please enter start date of vacation:" << endl;
        strtdat.enterDate();
        cout << "Please enter end date of vacation:" << endl;
        enddat.enterDate();
        //Add the number of days requested to the already taken days and chech if they exceed allowed days
        int num_Hday_taken_with_new_entry = returnDatesDiff(strtdat,enddat)+ 1 + base[id] -> get_num_holidays_taken();
        if (num_Hday_taken_with_new_entry <= base[id] -> get_num_holidays_allowed())
        {
            //Employee is allowed to take new holiday
            //Add new days to days taken
            base[id] -> add_holiday_days_taken(returnDatesDiff(strtdat,enddat)+1);
            cout << returnDatesDiff(strtdat,enddat)+1 << " holiday days were successfully added to the employees/manager's account!" << endl;
            cout << "Number of holiday days already taken by employee/manager: "<< base[id] -> get_num_holidays_taken() << endl;
            cout << "Number of holiday days allowed for the employee/manager: "<< base[id] -> get_num_holidays_allowed() << endl;
            cout << "New holiday entry was successfully saved. " << endl;
        }
        else
        {
            //Employee is not allowed to take extra holiday days
            cout << "Employee/Manager has only " << base[id] -> get_num_holidays_allowed() << " holiday days allowed" << endl;
            cout << "Employee/Manager has has already taken " << base[id] -> get_num_holidays_taken() << "days of holiday!" << endl;
            cout << "The requested number of days: " << returnDatesDiff(strtdat,enddat)+1 <<" exceeds the total allowed number of days!" << endl;
            cout << "Please try again with shorter time range or contact your manager." << endl;
        }
    }
    else
    {
        cout << "Employee/Manager was not found! please try again" << endl;
    }

}


void initiateDatabase()                     // initiate database with empty employee objects to avoid runtime errors
{
    //Loop through database
    for (int i=0;i<max_num_employees;i++)
    {
        // create dummy employee objects
        base[i] = new Employee();
    }
}
int main()                                  // main function
{
    //Declare variables
    int select;

    //Input current calender year to calculate the current age of employees
    cout << "Please enter current calender year(example: 2019):" << endl;
    cin >> currentYear;
    system("cls");

    //initiate database
    initiateDatabase();

    //Welcome message
    cout << "Welcome to Abdellaoui's staff holiday management system(ASHMS)" << endl;
    cout << "To start, please select one of the options below:" << endl;

    //Main Menu
    do
    {
        cout << "--MENU--" << endl;
        cout << "[1] Add employees" << endl;
        cout << "[2] Remove employees" << endl;
        cout << "[3] Add a holiday entry for an employee" << endl;
        cout << "[4] Search for employee data" << endl;
        cout << "[5] List all stored employee data" << endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Please select: ";
        cin >> select;
        switch(select)
        {
        case 1: //Add employees
            {
                system("cls");
                if (num_employees ==(max_num_employees-1)){
                    cout << "Database is full, delete employees or expand database!!!" << endl;
                    break;}
                else
                    addEmployee();
                system("pause");
                system("cls");
                break;
            }
        case 2: //Remove employees
            {
                system("cls");
                cout << "REMOVE EMPLOYEE/MANAGER:" << endl;
                removeEmployee();
                system("pause");
                system("cls");
                break;
            }
        case 3: //Add a holiday entry for an employee
            {

                system("cls");
                addHolidayEntry();
                system("pause");
                system("cls");
                break;
            }
        case 4: //Search for employee data"
            {
                system("cls");
                cout << "SHOW EMPLOYEE/MANAGER DATA: " << endl;
                showEmployeeData();
                system("pause");
                system("cls");
                break;
            }
        case 5: //List all stored employee data
            {
                system("cls");
                cout << "LIST OF ALL EMPLOYEES:" << endl;
                showAllEmployees();
                system("pause");
                system("cls");

                break;
            }
        case 0: //Exit
            {
                cout << endl << "Goodbye" << endl;
                return 0;
            }
        default: //All other cases
            {
                cout << endl << "Incorrect input!" << endl;
                system("pause");
                system("cls");
            }
        }
    }while(select!=0);
    return 0;
}
