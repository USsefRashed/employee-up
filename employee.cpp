#include "employee.h"
using namespace std;
int employee::empno() const{ return m_empno; }
void employee::setEmpno(int empno){ m_empno = empno; }
string employee::fname()const{ return m_fname; }
void employee::setFname(const string &fname)
{
	int sz = fname.size();
	sz = (sz<20? sz:19);
	fname.copy(m_fname, sz); m_fname[sz] ='\0';
}
string employee::lname()const{ return m_lname; }
void employee::setLname(const string &lname)
{
	int sz = lname.size();
	sz = (sz < 20 ? sz : 19);
	lname.copy(m_lname, sz); m_lname[sz] = '\0';
}
string employee::email()const{ return m_email; }
void employee::setEmail(const string &email)
{
	int sz = email.size();
	sz = (sz < 20 ? sz : 19);
	email.copy(m_email, sz); m_email[sz] = '\0';
}
double employee::salary()const{ return m_salary; }
void employee::setSalary(double salary){ m_salary = salary; }
employee::employee(int eno, string fn, string ln, string em, double sa)
{
	setEmpno(eno);
	setFname(fn);
	setLname(ln);
	setEmail(em);
	setSalary(sa);
}