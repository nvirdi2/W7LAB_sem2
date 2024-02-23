#include <iostream>
#include <ostream>
#include <cstring>

#include "MotorVehicle.h"

using namespace std;

namespace sdds 
{
	ostream& operator<<(ostream& os, MotorVehicle motor)
	{
		motor.write(os);
			return os;
	}

	istream& operator>>(istream& is, MotorVehicle& motor) 
	{
		motor.read(is);
			return is;
	}

	ostream& MotorVehicle::write(ostream& os) 
	{
		os << "| " << Year << " | " << 
				plateNUM << " | " << Address;
					return os;
	}

	MotorVehicle::MotorVehicle() 
	{
		plateNUM[0] = '\0';

		Address[0] = '\0';

		Year = 0;
	}

	istream& MotorVehicle::read(istream& in) 
	{
		cout << "Built year: ";
			in >> Year;
		cout << "License plate: ";
			in >> plateNUM;
		cout << "Current location: ";
			in >> Address;

		return in;
	}

	MotorVehicle::MotorVehicle(const char* Plate, int year) 
	{
		strcpy(plateNUM, Plate);

		Year = year;

		strcpy(Address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) 
	{
		if (strcmp(Address, address) != 0) 
		{
			cout << "|";

				cout.setf(ios::right);
				cout.width(8);
				cout << plateNUM;
				cout.unsetf(ios::right);

			cout << "| |";

				cout.setf(ios::right);
				cout.width(20);
				cout << Address;
				cout.unsetf(ios::right);

			cout << " ---> ";

				cout.setf(ios::left);
				cout.width(20);
				cout << address;
				cout.unsetf(ios::left);

			cout << "|" << endl;

				strcpy(Address, address);
		}
	}
}