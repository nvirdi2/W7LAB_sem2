#include <iostream>
#include <ostream>
//#include <cstring>

#include "cstring.h"
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds 
{
	bool Truck::unloadCargo() 
	{
		bool Load;

		if (Cargo != 0)
		{
			Load = true;
		}

		else
		{
			Load = false;
		}
		Cargo = 0;	
			return Load;
	}

	bool Truck::addCargo(double cargo) 
	{
		bool Load;

		if (cargo == 0 && Capacity == Cargo) 
		{
			Load = false;
		}

		else
		{
			if (Cargo + cargo >= Capacity)
			{
				Cargo = Capacity;
			}
			else
			{
				Cargo += cargo;
			}
			Load = true;
		} return Load;
	}

	ostream& operator<<(ostream& os, Truck& Truck) 
	{
		Truck.write(os);
		return os;
	}

	istream& operator>>(istream& is, Truck& Truck) 
	{
		Truck.read(is);
		return is;
	}

	Truck::Truck(const char* Plate, int year, double m_capacity, const char* address) : MotorVehicle(Plate, year) 
	{
		Cargo = 0;
		Capacity = m_capacity;

		moveTo(address);

	}
	
	ostream& Truck::write(ostream& os)
	{
		MotorVehicle::write(os);
			os << " | " << Cargo << "/" << Capacity;
				return os;
	}

	istream& Truck::read(istream& in) 
	{
		MotorVehicle::read(in);

			cout << "Capacity: ";

		in >> Capacity;

			cout << "Cargo: ";

		in >> Cargo;

			return in;
	}
}