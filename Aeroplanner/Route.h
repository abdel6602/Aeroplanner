#pragma once
#include <iostream>
#include "Airport.h"
#include <vector>

using namespace std;

class Route
{
private:
	Airport departure;
	Airport arrival;
	vector<Waypoint> waypoints;
public:
	Route(Airport departure, Airport arrival);

	void addWaypoint(Waypoint w);

	ostream& operator<<(ostream& out);
};

