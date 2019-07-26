#pragma once
#include "ObjectData.h"
class ElevatorData :
	public ObjectData
{
public:
	enum ElevatorArrIndex
	{
		WAITTING,
		RUNNING,
		COUNT
	};		
public:
	ElevatorData();
	~ElevatorData();
};

