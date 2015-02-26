#pragma once

/**
 * Prostor jmen pro projekt Stack in Array.
 */
namespace StackInArray
{

	/**
	 * Maxim�ln� velikost z�sobn�ku.
	 */
	const int StackSize = 100;


	/**
	 * Implementace z�sobn�ku v poli.
	 * Implementace v poli znamen�, �e ukazatel je v tomto p��pad� realizov�n jako ��slo typu int a ukazatel je de-facto index v poli.
	 *
	 * @author      Ji�� Dvorsk� <jiri.dvorsky@vsb.cz>
	 */
	struct Stack
	{
		/**
		 * Pole obsahuj�c� data ulo�en� do z�sobn�ku.
		 */
		char Data[StackSize];
		/**
		 * Ukazatel z�sobn�ku (stack pointer).
		 */
		int SP;
	};


	/**
	 * Inicializace z�sobn�ku.
	 * 
	 * @param S Inicializovan� z�sobn�k
	 */
	void Init(Stack& S);

	/**
	 * Smaz�n� cel�ho obsahu z�sobn�ku.
	 * 
	 * @param S Z�sobn�k
	 */
	void Clear(Stack& S);

	/**
	 * Vlo�en� prvku do z�sobn�ku.
	 * 
	 * @param S Z�sobn�k
	 * @param X Vkl�dan� prvek
	 */
	void Push(Stack& S, char X);

	/**
	 * Vyjmut� prvku ze z�sobn�ku.
	 * 
	 * @param S Z�sobn�k
	 * @return Prvek z vrcholu z�sobn�ku
	 */
	char Pop(Stack& S);

	/**
	 * Test je-li z�sobn�k pr�zdn�.
	 * 
	 * @param S Z�sobn�k
	 * @return Funkce vrac� true pokud je z�sobn�k pr�zdn�, jinak false.
	 */
	bool IsEmpty(const Stack& S);

}