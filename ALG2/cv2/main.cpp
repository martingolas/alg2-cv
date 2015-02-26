/**
 * Testovací program pro zásobník implementovaný v poli.
 */
#include <iostream>
#include <iomanip>
#include <string>
#include "Stack.h"

using namespace std;
using namespace StackInArray;

/**
 * Funkce demonstruje testování parity závorek (, [, {, ), ], } pomocí zásobníku
  * 
 * @param Text Øetìzec obsahující výraz se závorkami
 * @return Funkce vrací true, pokud je výraz správnì uzávorkován, jinak vrací false.
 */
bool TestParentheses(string Text)
{
	Stack S;
	Init(S);
	for(unsigned int i = 0; i < Text.length(); i++)
	{
		switch (Text[i])
		{
		case '(':
			Push(S, ')');
			break;
		case '[':
			Push(S, ']');
			break;
		case '{':
			Push(S, '}');
			break;
		case ')':
		case ']':
		case '}':
			if (!IsEmpty(S))
			{
				char ch = Pop(S);
				if (ch != Text[i])
					return false;
			}
			else
			{
				return false;
			}
			break;
		}
	}
	return IsEmpty(S);
}

size_t Precedence(const char op)
{
	switch (op)
	{
	case '-':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '/':
		return 4;
		break;
	case '*':
		return 8;
		break;
	}
}

bool IsOperator(const char op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}

string InfixToPostfix(string input)
{
	// Zasobnik
	Stack st;
	Init(st);

	// Iteracni promenna
	size_t i = 0;

	string output = "";

	while (i < input.length())
	{
		size_t tmp = i;
		if (IsOperator(input[i]))
		{
			if (IsEmpty(st))
			{
				Push(st, input[i]);
			} else if (Precedence(input[i]) > Precedence(st.Data[st.SP - 1]))
			{
				Push(st, input[i]);
			}
			i += (tmp + 1); // Posun na 1. nasledujici znak po mezere
		}
		else
		{
			if (isdigit(input[i]))
			{
				int sp = input.find(" ", i);
				output.append(input.substr(i, ++sp));
			}

			i += 2; // Posun na 1. nasledujici znak po mezere
		}
	}
	return output;
}

int EvalPostfix(string input)
{
	// Zasobnik
	Stack st;
	Init(st);

	// Iteracni promenna
	size_t i = 0;

	while (i < input.length())
	{
		size_t tmp = i;
		if (isalnum(input[i]))
		{
			Push(st, stoi(&input[i], &tmp));
			i += (tmp + 1); // Posun na 1. nasledujici znak po mezere
		}
		else
		{
			switch (input[i])
			{
				case '+':
					// Soucet
					Push(st, Pop(st) + Pop(st));
					break;
				case '*':
					// Soucin
					Push(st, Pop(st) * Pop(st));
					break;
				case '-':
					// Rozdil
					Push(st, Pop(st) - Pop(st));
					break;
				default:
					cerr << "Unknown operator." << endl;
					return;
			}
			i += 2; // Posun na 1. nasledujici znak po mezere
		}
	}
	return (int)Pop(st);
}


/**
 * Hlavní funkce programu
 */
void main()
{
	// Vyhodnoceni postfix vyrazu
	cout << EvalPostfix("2 5 +") << endl;
	cin.get();
}

