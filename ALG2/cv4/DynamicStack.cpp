#include "DynamicStack.h"
#include <iostream>

DynamicStack::DynamicStack()
{
	stackPointer = NULL;
}

DynamicStack::~DynamicStack()
{
	Clear();
}

void DynamicStack::Push(const int value)
{
	StackItem *node = new StackItem;
	node->value = value;
	node->next = stackPointer;
	stackPointer = node;
}

int DynamicStack::Pop()
{
	if (!IsEmpty())
	{
		StackItem *current = stackPointer;
		stackPointer = current->next;
		const int val = current->value;
		delete current;
		return val;
	}
	return -1;
}

void DynamicStack::Clear()
{
	if (!IsEmpty())
	{
		while (stackPointer != NULL)
		{
			StackItem *current = stackPointer;
			stackPointer = current->next;
			delete current;
		}
		stackPointer = NULL;
	}
}

bool DynamicStack::IsEmpty()
{
	return stackPointer == NULL;
}

int DynamicStack::Count()
{
	int cnt = 0;
	StackItem *current = stackPointer;
	while (current != NULL)
	{
		cnt++;
		current = current->next;
	}
	return cnt;
}




