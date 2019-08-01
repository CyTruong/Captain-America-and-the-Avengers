#pragma once 
#include "CamBound.h"
class Cambounds
{
public:
	Cambounds() {
		CamBound temp = CamBound(0, 14, 0, 96);
		camBounds.push_back(temp);
		temp = CamBound(14, 14, 112, 112);
		camBounds.push_back(temp);
	};

	vector <CamBound  >getCamBounds ()
	{
		return camBounds; 
	}
	int getNumberBounds() { return nBounds;  }
private:
	int nBounds;
	
	vector <CamBound> camBounds; 

};


