#include <iostream>
#include "DynamicStack.h"


void main()
{
	DynamicStack stack;
	for (size_t i = 0; i < 1000000000; i++)
	{
		stack.Push(i);
	}

	std::cout << "On stack is " << stack.Count() << " items." << std::endl;

	while (!stack.IsEmpty())
	{
		//std::cout << "Top of stack: " << stack.Pop() << std::endl;
		stack.Pop();
	}

	std::cin.get();

}