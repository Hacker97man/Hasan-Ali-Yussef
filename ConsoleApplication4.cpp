#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Company {
private:
	class Employee {
	public:
		Employee() {
			this->name = "";
			this->salaries = 0.0;
		}
		double getSalaries() {
			return this->salaries;
		}
		void setSalaries(double sa) {
			salaries = sa;
		}
		void setName(string name) {
			this->name=name;
		}
		string  getName() {
			return this->name;
		}
	private:
		double salaries;
		string name;
	};
public :
	Company() {
		 em = new Employee[10];
	}
	void addEmployee(string name, double sa,int id) {
		em[id].setName(name);
		em[id].setSalaries(sa);
	}
	void setBouns() {
		for (int i = 0;i < 10;i++) 
			em[i].setSalaries(em[i].getSalaries() * 15 / 100);
	}
	double getAvarage() {
		setBouns();
		double sum = 0;
		for (int i = 0;i < 10;i++)
			sum += em[i].getSalaries();
		return sum / 10;
	}
private :
	Employee *em;
};
int main()
{
	Company *com = new Company();
	for(int i = 0;i < 10;i++) {
		double temp;
		string name;
		cout << "Enter The Name of The Em : " << (i + 1)<<" ";
		cin >> name;
		cout << "Enter The Salarie of " << name<<" : ";
		cin >> temp;
		com->addEmployee(name, temp,i);
	}
	cout <<"The Average is : "<< com->getAvarage() << endl;
    return 0;
}

