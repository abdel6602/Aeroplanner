#pragma once
#include <string>
using namespace std;
class Aircraft
{
private:
	string name;
	float maxFuelLoad;
	int cruiseSpeed;
	int maxTakeOffWeight, maxLandingWeight, emptyWeight;
	int PassengerCapacity;
	double range_in_km;
public:
	//constructor
	Aircraft(string name, float maxFuelLoad, int CruiseSpeed, int maxTakeOffWeight, int maxLandingWeight,
		int emptyWeight, int PassengerCapacity, double range_in_km);
	
	//getters and setters

};

