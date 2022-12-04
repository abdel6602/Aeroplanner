#pragma once
#include <string>
#include "Coordinate.h"
class Waypoint
{
private:
	Coordinate coords;
	string name;
	float Gcost, Hcost, Dcost;
public:
	Waypoint(Coordinate coords, string name);

	void Calc_cost();
};

