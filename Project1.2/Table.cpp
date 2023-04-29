#include "Table.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>


Table::Table() {
	Table::table = new int[0];
	count = 0;
}

Table::~Table() {
	
}

void Table::addFirstIndex(int element) {
	
	Table::addAtIndex(0, element);

}

void Table::addAtIndex(int index, int element) {
	if (index < 0 || index > Table::count)
		return;

	Table::count++;
	int* newTable = new int[Table::count];

	int indexOld = 0;
	for (int indexNew = 0; indexNew < Table::count; indexNew++)
	{
		if (indexNew == index)
		{
			newTable[indexNew] = element;
			continue;
		}
		newTable[indexNew] = Table::table[indexOld];
		indexOld++;
	}

	delete[] Table::table;
	Table::table = newTable;
		
}

void Table::addLastIndex(int element) {
	
	Table::addAtIndex(Table::count,element);
}

void Table::deleteFirstIndex() {
	Table::deleteAtIndex(0);
}

void Table::deleteAtIndex(int index) {
	if (index < 0 || index >= Table::count) {
		return;
	}

	Table::count--;
	int* newTable = new int[Table::count];

	int indexNew = 0;

	for (int indexOld = 0; indexOld < Table::count + 1; indexOld++)
	{
		if (indexOld == index)
		{
			continue;
		}
		newTable[indexNew] = Table::table[indexOld];
		indexNew++;
	}

	delete[] table;
	table = newTable;


}

void Table::deleteLastIndex() {
	Table::deleteAtIndex(Table::count-1);
}

int Table::findElement(int element) {
	for (int i = 0; i < Table::count; i++) {
		if (element == table[i]) {
			return i;
		}
	}
	return -1;
}

void Table::addRandomElement() {

	srand(time(NULL));
	int random = std::rand();

	addLastIndex(random);
}

void Table::deleteAll() {
	
	Table::count = 0;
	delete[] Table::table;
	Table::table = NULL;
}

std::string Table::toString() {
	std::string tableText = "";
	for (int i = 0; i < Table::count; i++)
	{
		tableText += std::to_string(table[i]) + ", ";
	}

	return tableText;
}

bool Table::readDataFromFile(std::string fileName)
{

	int arrSize;
	std::ifstream file = std::ifstream(fileName);

	if (file.is_open() == false)
	{
		std::cout << "File error - OPEN" << std::endl;
		file.close();
		return false;
	}

	//reads first line
	file >> arrSize;
	if (file.fail()) {
		std::cout << "File error - READ SIZE" << std::endl;
		file.close();
		return false;
	}

	Table::deleteAll();

	int val;
	for (int i = 0; i < arrSize; i++)
	{
		file >> val;
		if (file.fail())
		{
			std::cout << "File error - READ DATA" << std::endl;
			file.close();
			return false;
		}
		else
			Table::addLastIndex(val);
	}
	file.close();
	return true;
}
