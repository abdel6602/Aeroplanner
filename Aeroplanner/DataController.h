#pragma once
#include <string>
#include <vector>
#include "Aircraft.h"
#include "Airport.h"

using namespace std;

const string airplane_fileName = "allAirplanes.json";
const string waypoint_fileName = "waypoints.json";

class DataController{
public:
	//query aircrafts
	vector<Aircraft>& getAllAircrafts();
	Aircraft& getAircraft_by_name(string name);
	Aircraft& getAircraft_by_brand(string brand);
	//query Airports
	Airport& getAirportByCode(string IcaoCode);
	//get waypoints between 2 airports
	vector<Waypoint>& getWaypointsBetween(Airport& Departure, Airport& Arrival);
	//get certain vector by ICAO code
	Waypoint& getWaypointByCode(string IcaoCode);
};

