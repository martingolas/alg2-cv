#include "Lamp.h"
#include <iostream>
#include <string>

using namespace std;

void printLampStatus(Lamp& lamp)
{
	string status = (lamp.GetStatus()) ? "ON" : "OFF";
	cout << "Lamp is " << status << " Remaining " << lamp.RemainingCycles() << " cycles."<< endl;
}

int main()
{
	Lamp l(5);
	while (l.IsGood())
	{
		l.SwitchOn();
		printLampStatus(l);
		l.SwitchOff();
		printLampStatus(l);
	}
	cin.get();
	return 0;
}

