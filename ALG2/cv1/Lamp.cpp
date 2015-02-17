#include "Lamp.h"

Lamp::Lamp(int lifecycles)
{
	SwitchedOn = false;
	Lifecycles = lifecycles;
}

void Lamp::SwitchOn()
{	
	if (IsGood())
	{
		SwitchedOn = true;
		Lifecycles--;
	}
}

void Lamp::SwitchOff()
{
	SwitchedOn = false;
}

bool Lamp::IsGood()
{
	return Lifecycles > 0;
}

int Lamp::RemainingCycles()
{
	return Lifecycles;
}

bool Lamp::GetStatus()
{
	return SwitchedOn;
}

