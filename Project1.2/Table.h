#pragma once
#include <stdlib.h>
#include <string>
#include <fstream>


class Table
{
private:
	int* table;
	int count;
public:
	Table(); 
	~Table();

	/// <summary>
	/// this function adds given element to index number zero
	/// </summary>
	/// <param name="element"></param>
	void addFirstIndex(int element);

	/// <summary>
	/// this function adds given element to given index
	/// </summary>
	/// <param name="index"></param>
	/// <param name="element"></param>
	void addAtIndex(int index, int element);

	/// <summary>
	/// this function adds given element to last index
	/// </summary>
	/// <param name="element"></param>
	void addLastIndex(int element);

	/// <summary>
	/// this function deletes element at index number zero
	/// </summary>
	void deleteFirstIndex();
	
	/// <summary>
	/// this function deletes element at given index
	/// </summary>
	/// <param name="index"></param>
	void deleteAtIndex(int index);

	/// <summary>
	/// this function deletes element at last index
	/// </summary>
	void deleteLastIndex();

	/// <summary>
	/// this function return index of given element 
	/// </summary>
	/// <param name="element"></param>
	/// <returns></returns>
	//int findElement(int element);
	int findElement(int element);

	/// <summary>
	/// this function gives new random element to table
	/// </summary>
	void addRandomElement();

	/// <summary>
	/// this function deletes all elements from the table
	/// </summary>
	void deleteAll();


	bool readDataFromFile(std::string fileName);

	/// <summary>
	/// this function shows whole table
	/// </summary>
	/// <returns></returns>
	std::string toString();

};




