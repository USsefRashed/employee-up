#include<string>
using namespace std;
class employee
{
private:
	int  m_empno;
	char m_fname[20];
	char m_lname[20];
	char m_email[20];
	double m_salary;
public:
	employee(int =0,string ="",string="",string="",double=0.0);
	int empno()const;
	void setEmpno(int empno);
	string fname() const;
	void setFname(const string &fname);
	string lname()const;
	void setLname(const string &lname);
	string email()const;
	void setEmail(const string &email);
	double salary()const;
	void setSalary(double salary);
};

