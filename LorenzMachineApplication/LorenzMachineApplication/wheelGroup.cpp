#include "stdafx.h"
#include "wheelGroup.h"

wheelGroup::wheelGroup(wheel wheel1, wheel wheel2, wheel wheel3, wheel wheel4, wheel wheel5)
{
	wheels.push_back(wheel1);
	wheels.push_back(wheel2);
	wheels.push_back(wheel3);
	wheels.push_back(wheel4);
	wheels.push_back(wheel5);
}

void wheelGroup::rotate()
{
	for(int i=0;i<wheels.size();i++)
	{
		wheels[i].rotate();
	}
}

int wheelGroup::getCurrentPins()
{
	int result = 0;
	
	//Bug 2
	for(int i=0;i<wheels.size();i++)
	{
		//Bug 3
		result <<= 1;
		//Bug 4
		result += wheels[i].getCurrentPin();
	}

	return result;
}