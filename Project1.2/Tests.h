#pragma once
#include<string>


	/// <summary>
	/// this function measures the time of adding firsts elements to the table
	/// </summary>
	void testAddFirstToTheTable();

	/// <summary>
	/// this function measures the time of adding elements to the random indexes to the table
	/// </summary>
	void testAddAtIndexToTheTable();

	/// <summary>
	/// this function measures the time of adding lasts elements to the table
	/// </summary>
	void testAddAtLastToTheTable();

	/// <summary>
	/// this function measures the time of adding firsts elements to the list
	/// </summary>
	void testAddFirstToTheList();

	/// <summary>
	/// this function measures the time of adding elements to the random indexes to the list
	/// </summary>
	void testAddAtIndexToTheList();

	/// <summary>
	/// this function measures the time of adding lasts elements to the list
	/// </summary>
	void testAddAtLastToTheList();

	/// <summary>
	/// this function measures the time of deleting firsts elements from the table
	/// </summary>
	void testDeleteFirstToTheTable();

	/// <summary>
	/// this function measures the time of deleting elements from the random indexes from the table
	/// </summary>
	void testDeleteAtIndexToTheTable();

	/// <summary>
	/// this function measures the time of deleting lasts elements from the table
	/// </summary>
	void testDeleteAtLastToTheTable();

	/// <summary>
	/// this function measures the time of deleting firsts elements from the list
	/// </summary>
	void testDeleteFirstToTheList();

	/// <summary>
	/// this function measures the time of deleting elements from the random indexes from the list
	/// </summary>
	void testDeleteAtIndexToTheList();

	/// <summary>
	/// this function measures the time of deleting lasts elements from the list
	/// </summary>
	void testDeleteAtLastToTheList();

	/// <summary>
	/// this function measures time of finding elements in the table
	/// </summary>
	void testFindElementInTheTable();

	/// <summary>
	/// this function measures time of finding elements in the list
	/// </summary>
	void testFindElementInTheList();
	
	/// <summary>
	/// this function measures time of the adding elements to the heap
	/// </summary>
	void testAddElementToTheHeap();

	/// <summary>
	/// this function measures time of removing elements to the heap
	/// </summary>
	void testRemoveElementToTheHeap();

	/// <summary>
	/// this function measures time of finding elements to the heap
	/// </summary>
	void testFindElementInTheHeap();

	/// <summary>
	/// this finction measures time of addind elements by Floyd method
	/// </summary>
	void testAddAllFloydToHeap();

	/// <summary>
	/// this function saves results of the test to the file
	/// </summary>
	/// <param name="operationType"></param>
	/// <param name="elementsAmount"></param>
	/// <param name="timeOperation"></param>
	/// <param name="path"></param>
	void saveToFile(std::string operationType, int elementsAmount, double timeOperation, std::string path);

