#include "Stack.h"

namespace StackInArray
{

	void Init(Stack& S)
	{
		S.SP = 0;
	}

	void Clear(Stack& S)
	{
		S.SP = 0;
	}

	void Push(Stack& S, char X)
	{
		S.Data[S.SP] = X;
		S.SP += 1;
	}

	char Pop(Stack& S)
	{
		S.SP -= 1;
		return S.Data[S.SP];
	}

	bool IsEmpty(const Stack& S)
	{
		return S.SP == 0;
	}

}
