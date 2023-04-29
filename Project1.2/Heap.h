#pragma once
#include <stdlib.h>
#include <string>
#include <fstream>


class Heap {
private:
	static const int maxHeapSize = 500000;
	int* heap;
	int size;
	/// <summary>
	/// gets index of the left child
	/// </summary>
	/// <param name="parentIndex"></param>
	/// <returns></returns>
	int getLeftChild(int parentIndex);

	/// <summary>
	/// get index of the right child
	/// </summary>
	/// <param name="parentIndex"></param>
	/// <returns></returns>
	int getRightChild(int parentIndex);
	/// <summary>
	/// gets index of the parent
	/// </summary>
	/// <param name="childIndex"></param>
	/// <returns></returns>
	int getParent(int childIndex);

	/// <summary>
	/// recuresivle calls itself in order to create string wchich represents heap as tree
	/// </summary>
	/// <param name="prefix"></param>
	/// <param name="index"></param>
	/// <param name="isRight"></param>
	/// <param name="con"></param>
	void getTreeAsString(std::string prefix, int index, bool isRight, std::string& con);

	/// <summary>
	/// this funciton will repare heap going from bottom to top
	/// </summary>
	/// <param name="index"></param>
	void fixUp(int index);

	/// <summary>
	/// this function will repare heap from top to bottom
	/// </summary>
	/// <param name="index"></param>
	void fixDown(int index);

public:
	Heap();
	~Heap();

	/// <summary>
	/// this function adds element to the heap
	/// </summary>
	/// <param name="value"></param>
	void addElement(int value);

	/// <summary>
	/// this function removes element from the heap 
	/// </summary>
	/// <param name="index"></param>
	void removeElement(int index);

	/// <summary>
	/// this function removes root from heap
	/// </summary>
	void popRoot();

	/// <summary>
	/// this function finds element in the heap
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool findElement(int value);

	/// <summary>
	/// this function adds random element to the heap
	/// </summary>
	void addRandomElement();

	/// <summary>
	/// this function removes all elements from the heap
	/// </summary>
	void removeAll();

	/// <summary>
	/// this function will return string which represents heap
	/// </summary>
	/// <returns></returns>
	std::string toString();

	/// <summary>
	/// this function prints elements of the heap
	/// </summary>
	/// <returns></returns>
	std::string toStringText();

	/// <summary>
	/// this function adds elements to the heap by Floyd method
	/// </summary>
	/// <param name="array"></param>
	/// <param name="length"></param>
	void addAllFloyd(int* array, int length);

	/// <summary>
	/// this function reads data from file and build the heap
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns></returns>
	bool readDataFromFile(std::string fileName);
};
