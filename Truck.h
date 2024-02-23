#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include "MotorVehicle.h"

namespace sdds 
{
	class Truck : public MotorVehicle
	{
		double Capacity;
		double Cargo;
	public:
		Truck(const char* Plate, int year, double m_capacity, const char* address);
		bool addCargo(double cargo);

		bool unloadCargo();

		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, Truck& Truck);
	std::istream& operator>>(std::istream& is, Truck& Truck);
}
#endif // !SDDS_TRUCK_H
