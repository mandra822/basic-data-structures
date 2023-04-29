#include "Heap.h"
#include <time.h>
#include <iostream>

Heap::Heap(){
	Heap::size = 0;
	Heap::heap = new int[maxHeapSize];
}

Heap::~Heap() {
	Heap::size = 0;
	delete[] Heap::heap;
}
int Heap::getLeftChild(int parentIndex){
	int leftChildIndex = 2 * parentIndex + 1;
	if (leftChildIndex < size) {
		return leftChildIndex;
	}
	else {
		return -1;
	}
}
int Heap::getRightChild(int parentIndex){
	int rightChildIndex = 2 * parentIndex + 2;
	if (rightChildIndex < size) {
		return rightChildIndex;
	}
	else {
		return -1;
	}
}
int Heap::getParent(int childIndex){
	int parentIndex = (childIndex - 1) / 2;
	if (childIndex < size && parentIndex >= 0) {
		return parentIndex;
	}
	else
	{
		return -1;
	}
}

void Heap::getTreeAsString(std::string prefix, int index, bool isRight, std::string& con)
{
	if (index >= 0 && index < Heap::size)
	{
		con += prefix;

		con += isRight ? "|--:" : "*--:";

		con += std::to_string(Heap::heap[index]) + "\n";

		Heap::getTreeAsString(prefix + (isRight ? "|  " : "   "), getRightChild(index), true, con);
		Heap::getTreeAsString(prefix + (isRight ? "|  " : "   "), getLeftChild(index), false, con);
	}
}

void Heap::fixUp(int index)
{
	int parentIndex = Heap::getParent(index);
	while (parentIndex >= 0)
	{
		int parVal = Heap::heap[parentIndex];
		int curr = heap[index];
		if (parVal < curr)
		{
			int temp = Heap::heap[parentIndex];
			Heap::heap[parentIndex] = Heap::heap[index];
			Heap::heap[index] = temp;

			index = parentIndex;
			parentIndex = Heap::getParent(index);
		}
		else
		{
			return;
		}
	}
}

 void Heap::fixDown(int index) {
	while (index < size)
	{
		int leftChildIndex = getLeftChild(index);
		int rightChildIndex = getRightChild(index);
		int childToCheckIndex;

		if (rightChildIndex != -1) {
			if (heap[rightChildIndex] > heap[leftChildIndex]) {
				childToCheckIndex = rightChildIndex;
			}
			else {
				childToCheckIndex = leftChildIndex;
			}
		}
		else if (leftChildIndex != -1 && rightChildIndex == -1) {
			childToCheckIndex = leftChildIndex;
		}
		else {
			return;
		}

		if (heap[childToCheckIndex] > heap[index]) {
			int tmp = heap[index];
			heap[index] = heap[childToCheckIndex];
			heap[childToCheckIndex] = tmp;
			index = childToCheckIndex;
		}
		else
		{
			return;
		}


	}

}

void Heap::addElement(int value){
	if (size >= maxHeapSize) {
		return;
	}

	size++;
	int currentIndex = size - 1;
	heap[currentIndex] = value;

	Heap::fixUp(currentIndex);
}


void Heap::removeElement(int index) {

	if (index >= Heap::size && index < 0)
	{
		return;
	}
	else if(index == 0)
	{
		Heap::popRoot();
		return;
	}


	Heap::heap[index] = Heap::heap[0] + 1;
	Heap::fixUp(index);
	Heap::popRoot();
}

void Heap::popRoot(){

	if (size <= 0) {
		return;
	}
	int index = 0;

	Heap::heap[index] = Heap::heap[size - 1];
	Heap::size--;
	
	Heap::fixDown(index);


}
bool Heap::findElement(int value){

	if (size == 0) {
		return false;
	}
	
	if (value > heap[0]) 
	{
		return false;
	}


	for (int i = 0; i < Heap::size - 1; i++)
	{
		if (heap[i] == value) {
			return true;
		}
		
	}

	return false;
	
}

void Heap::addRandomElement() {

	srand(time(NULL));
	int random = std::rand();

	Heap::addElement(random);
	

}

std::string Heap::toString() {

	std::string res = "";
	Heap::getTreeAsString("", 0, false, res);
	if (res == "") {
		return "NONE\n";
	}
	else {
		return res + "\n";
	}
}

std::string Heap::toStringText() {
	std::string tableText = "";
	for (int i = 0; i < Heap::size; i++)
	{
		tableText += std::to_string(heap[i]) + ", ";
	}

	return tableText;
}

void Heap::removeAll() {
	Heap::size = 0;
}

void Heap::addAllFloyd(int* array, int length) {
	Heap::removeAll();
	int i;
	for ( i = 0; i < length && i < Heap::maxHeapSize; i++)
	{
		heap[i] = array[i];
	}

	Heap::size = i;


	int lastParentIndex = getParent(size - 1);

	for (i = lastParentIndex; i >= 0; i--)
	{
		Heap::fixDown(i);
	}
}

bool Heap::readDataFromFile(std::string fileName)
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

	Heap::removeAll();
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
			Heap::addElement(val);
	}
	file.close();
	return true;
}
