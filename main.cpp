#include<iostream>
#include<fstream>
#include<iomanip>
#include"employee.h"
using namespace std;
const string FILENAME = "emp.dat";
void print_table();
bool isExsist(int );
void create(employee);
void creat(employee emp)
{
	if (isExsist(emp.empno())){ cout << "cannot record employe no #" << emp.empno() << " is already exsist" << endl; return; }
	ofstream outfile(FILENAME, ios::app | ios::binary); if (!outfile){ cout << "Error opening file\n"; exit(1); }
	outfile.write(reinterpret_cast<char*>(&emp), sizeof(employee)); outfile.close();
}
bool isExsist(int eno)
{
	bool exsist = false;
	ifstream infile(FILENAME, ios::in | ios::binary);
	while (!infile.eof())
	{
		employee ee;
		infile.read(reinterpret_cast<char*>(&ee), sizeof(employee));
		if (ee.empno() == eno){ exsist = true; break; }
	}
	infile.close();
	return exsist;
}
void print_table()
{
	cout << left
		<< setw(10) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << '+' << '+'
		<< endl;
	cout << setfill(' ') << '|' << left
		<< setw(9) << "Emp No." << setfill(' ')
		<< '|' << setw(20) << "First Name" << setfill(' ')
		<< '|' << setw(20) << "Last Name" << setfill(' ')
		<< '|' << setw(20) << "Email" << setfill(' ')
		<< '|' << right << setw(20) << "Balance" << '|'
		<< endl;
	cout << left << setw(10) << setfill('-') << left <<
		setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << left << '+'
		<< setw(21) << setfill('-') << '+' << '+' << endl;
	employee record;
	ifstream infile(FILENAME, ios::in | ios::binary);
	infile.read(reinterpret_cast<char *>
		(&record), sizeof(employee));
	while (!infile.eof()){
		cout << setfill(' ') << '|' << left
			<< setw(9) << record.empno()
			<< setfill(' ') << '|' << setw(20) << record.fname()
			<< setfill(' ') << '|' << setw(20) << record.lname()
			<< setfill(' ') << '|' << setw(20) << record.email()
			<< setfill(' ') << '|' << right << setw(20)
			<< record.salary() << '|' << endl;
		infile.read(reinterpret_cast<char *>(&record), sizeof(employee));
	}
}
int main()
{
	ofstream outfile(FILENAME, ios::out | ios::binary);
	if (!outfile){ cout << "Error openning file" << endl; }
	outfile.close();
	double sal; int empno;
	string fname, lname, email;
	while (true)
	{
		cout << "Enter employer no.(#0 to exit) \n"; cin >> empno;
		if (empno == 0){ break; }
		if (isExsist(empno)){ cout << "Employer #no is exsist\n"; continue; }
		cout << "Enter 1-firstname 2- lastname 3-email 4- salary\n";
		cin >> setw(19) >> fname;
		cin >> setw(19) >> lname;
		cin >> setw(19) >> email;
		cin >> setw(19) >> sal;
		employee emp(empno, fname, lname, email, sal);
		creat(emp);
		print_table();
	}
	return 0;
}