#pragma once
class Lamp
{
	private:
		bool SwitchedOn;
		int Lifecycles;

	public:
		void SwitchOn();
		void SwitchOff();
		bool IsGood();
		int RemainingCycles();
		bool GetStatus();

		Lamp(int lifecycles);
};

