#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds 
{
	class MotorVehicle 
	{
		int Year;

		char plateNUM[9];
		char Address[64];
	public:
		void moveTo(const char* address);
		MotorVehicle(const char* Plate, int year);

		MotorVehicle();

		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& is, MotorVehicle& motor);
	std::ostream& operator<<(std::ostream& os, MotorVehicle motor);
}
#endif // !SDDS_MOTORVEHICLE_H
