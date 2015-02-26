#pragma once

/**
 * Prostor jmen pro projekt Stack in Array.
 */
namespace StackInArray
{

	/**
	 * Maximální velikost zásobníku.
	 */
	const int StackSize = 100;


	/**
	 * Implementace zásobníku v poli.
	 * Implementace v poli znamená, že ukazatel je v tomto pøípadì realizován jako èíslo typu int a ukazatel je de-facto index v poli.
	 *
	 * @author      Jiøí Dvorský <jiri.dvorsky@vsb.cz>
	 */
	struct Stack
	{
		/**
		 * Pole obsahující data uložená do zásobníku.
		 */
		char Data[StackSize];
		/**
		 * Ukazatel zásobníku (stack pointer).
		 */
		int SP;
	};


	/**
	 * Inicializace zásobníku.
	 * 
	 * @param S Inicializovaný zásobník
	 */
	void Init(Stack& S);

	/**
	 * Smazání celého obsahu zásobníku.
	 * 
	 * @param S Zásobník
	 */
	void Clear(Stack& S);

	/**
	 * Vložení prvku do zásobníku.
	 * 
	 * @param S Zásobník
	 * @param X Vkládaný prvek
	 */
	void Push(Stack& S, char X);

	/**
	 * Vyjmutí prvku ze zásobníku.
	 * 
	 * @param S Zásobník
	 * @return Prvek z vrcholu zásobníku
	 */
	char Pop(Stack& S);

	/**
	 * Test je-li zásobník prázdný.
	 * 
	 * @param S Zásobník
	 * @return Funkce vrací true pokud je zásobník prázdný, jinak false.
	 */
	bool IsEmpty(const Stack& S);

}