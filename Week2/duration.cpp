#include "duration.h"


string Duration::toString() //Must include this for scope resolution
{
	int numHours = mins/60;
	int numMins = mins%60;
	return to_string(numHours) + " hours, " + to_string(numMins) + " min";
};

Duration sumDuration(const Duration &lhs,const Duration &rhs)
{
	Duration total(lhs.mins, rhs.mins);
	return total;
};

Duration operator +(const Duration& lhs, const Duration& rhs) 
{
	Duration total(lhs.mins+rhs.mins);
	return total;
};