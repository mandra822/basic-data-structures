#pragma once
#include <string>
#include <fstream>

struct ListElement {
	ListElement* prev, * next;
	int val;
	ListElement();
};

class DoubleLinkedList
{
private:
	int size;
	ListElement* first;
	ListElement* last;
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	/// <summary>
	/// this function adda new first element to list
	/// </summary>
	/// <param name="element"></param>
	void addFirstIndex(int element);

	/// <summary>
	/// this function adda new element to given index of the list
	/// </summary>
	/// <param name="index"></param>
	/// <param name="element"></param>
	void addAtIndex(int index, int element);

	/// <summary>
	/// this function adda new last element to list
	/// </summary>
	/// <param name="element"></param>
	void addLastIndex(int element);

	/// <summary>
	/// this function finds given element
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	ListElement* findElement(int value);

	/// <summary>
	/// this function deletes first element of the list
	/// </summary>
	void deleteFirstIndex();

	/// <summary>
	/// this function deletes alement on given index
	/// </summary>
	/// <param name="index"></param>
	void deleteAtIndex(int index);

	/// <summary>
	/// deletes given number from the list
	/// </summary>
	/// <param name="number"></param>
	void deleteNumber(int number);

	/// <summary>
	/// this function deletes last element of the list
	/// </summary>
	void deleteLastIndex();

	/// <summary>
	/// this function adds random element to the last index of the list
	/// </summary>
	void addRandomElement();

	/// <summary>
	/// this function deletes all elements from list
	/// </summary>
	void deleteAll();

	/// <summary>
	/// this function prints whole list from first to last element
	/// </summary>
	/// <returns></returns>
	std::string toStringFromFirstToLast();

	/// <summary>
	/// this function prints whole list from last to first element
	/// </summary>
	/// <returns></returns>
	std::string toStringFromLastToFirst();

	/// <summary>
	/// reads data from file and safe in the list
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns></returns>
	bool readDataFromFile(std::string fileName);
};

