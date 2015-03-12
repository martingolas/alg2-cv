#pragma once

class DynamicStack{

	public:
		DynamicStack();
		~DynamicStack();
		void Push(const int value);
		int Pop();
		void Clear();
		bool IsEmpty();
		int Count();
	
	private:

		struct StackItem {
			int value;
			StackItem *next;
		};
		
		StackItem *stackPointer;
};

