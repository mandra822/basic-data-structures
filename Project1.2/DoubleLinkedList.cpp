#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>


DoubleLinkedList::DoubleLinkedList() {
	DoubleLinkedList::first = NULL;
	DoubleLinkedList::last = NULL;
	DoubleLinkedList::size = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
	DoubleLinkedList::deleteAll();
}

void DoubleLinkedList::addFirstIndex(int value) {
	DoubleLinkedList::size++;
	ListElement* element = new ListElement();
	(*element).val = value;
	
	if (first == NULL) {
		DoubleLinkedList::first = element;
		DoubleLinkedList::last = element;
	}
	else {
		element->next = DoubleLinkedList::first;
		DoubleLinkedList::first->prev = element;
		DoubleLinkedList::first = element;
	}
}

void DoubleLinkedList::addLastIndex(int value) {
	size++;
	ListElement* element = new ListElement();
	element->val = value;
	if (first == NULL && last == NULL) {
		first = element;
		last = element;
	}
	else {
		element->prev = last;
		last->next = element;
		last = element;
	}

}

void DoubleLinkedList::addAtIndex(int index, int value) {
	
	if (index < 0 || index > size) {
		return;
	}
	if (index == 0) {
		DoubleLinkedList::addFirstIndex(value);
		return;
	}
	if (index == size) {
		DoubleLinkedList::addLastIndex(value);
		return;
	}

	size++;
	ListElement* element = new ListElement();
	element->val = value;

	 
	ListElement* tmp = first;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	
	ListElement* tempPrev = tmp->prev;
	
	tempPrev->next = element;
	element->prev = tempPrev;

	element->next = tmp;
	tmp->prev = element;

}

ListElement* DoubleLinkedList::findElement(int value) {
	
	ListElement* element = last;

	while (element!=NULL) {

		if (element->val == value) {
			return element;
		}
		element = element->prev;
	}
	return NULL;
}

void DoubleLinkedList::deleteFirstIndex() {
	if (size == 0) {
		return;
	}

	if (size == 1) {
		delete DoubleLinkedList::first; 
		first = NULL;
		last = NULL;
	}
	else {
		ListElement* tmp = first;
		DoubleLinkedList::first = first->next;
		DoubleLinkedList::first->prev = NULL;
		delete tmp;
	}
	size--;
}


void DoubleLinkedList::deleteAtIndex(int index) {
	
	
	if (size <= index || index <0) {
		return;
	}

	if (index == 0) {
		deleteFirstIndex();
		return;
	}

	if (index == size-1) {
		deleteLastIndex();
		return;
	}

	ListElement* tmp = DoubleLinkedList::first;
	ListElement* tmpPrev, * tmpNext;

	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
		
	tmpPrev = tmp->prev;
	tmpNext = tmp->next;

	tmpPrev -> next = tmpNext;
	tmpNext -> prev = tmpPrev;

	delete tmp;

	size--;
}

void DoubleLinkedList::deleteNumber(int number) {

	ListElement* elementToRemove = findElement(number);
	
	if (elementToRemove == NULL) {
		return;
	}

	ListElement* tmpPrev = elementToRemove->prev;
	ListElement* tmpNext = elementToRemove->next;

	if (elementToRemove == first) {
		deleteFirstIndex();
		return;
	}

	if (elementToRemove == last) {
		deleteLastIndex();
		return;
	}


	tmpPrev->next = tmpNext;
	tmpNext->prev = tmpPrev;

	delete elementToRemove;

	size--;
}

void DoubleLinkedList::deleteLastIndex() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete DoubleLinkedList::first;
		first = NULL;
		last = NULL;
	}
	else {
		ListElement* tmp = last;
		last = last->prev;
		last->next = NULL;
		delete tmp;
	}
	size--;
}

void DoubleLinkedList::addRandomElement() {

	srand(time(NULL));
	int random = std::rand();

	addLastIndex(random);
}

void DoubleLinkedList::deleteAll() {
	int size = DoubleLinkedList::size;
	for (int i = 0; i < size; i++ ) {
		DoubleLinkedList::deleteFirstIndex();
	}
}

std::string DoubleLinkedList::toStringFromFirstToLast() {

	std::string list = "";
	ListElement* element = first;

	while (element != NULL) {
		list += std::to_string(element->val) + ", ";
		element = element->next;
	}
	return list;
}

std::string DoubleLinkedList::toStringFromLastToFirst() {
	std::string list = "";
	ListElement* element = last;

	while (element != NULL) {
		list += std::to_string(element->val) + ", ";
		element = element->prev;
	}

	return list;
}

ListElement::ListElement()
{
	ListElement::prev = NULL;
	ListElement::next = NULL;
	ListElement::val = 0;
}

bool DoubleLinkedList::readDataFromFile(std::string fileName)
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

	DoubleLinkedList::deleteAll();

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
			DoubleLinkedList::addLastIndex(val);
	}
	file.close();
	return true;
}
