#include "Tests.h"
#include "Table.h"
#include "DoubleLinkedList.h"
#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>
#include "Timer.h"
#include <fstream>
#include "Heap.h"
#include "RandomGenerator.h"


void testAddFirstToTheTable() {

    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();

    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize,currSize));
            }
            int toAdd = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            table.addFirstIndex(toAdd);
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj poczatek", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}


void testAddAtIndexToTheTable(){
    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toAdd1 = rnd.getRandomNumber(0, currSize - 1);
            int toAdd2 = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            table.addAtIndex(toAdd1, toAdd2);
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj na losowy indeks", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}
void testAddAtLastToTheTable(){

    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }
            int toAdd = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            table.addLastIndex(toAdd);
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj na koniec", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}
void testAddFirstToTheList(){

    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toAdd = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            list.addFirstIndex(toAdd);
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj na poczatek", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }

}
void testAddAtIndexToTheList(){

    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toAdd1 = rnd.getRandomNumber(0, currSize);
            int toAdd2 = rnd.getRandomNumber(-currSize, currSize);

            timer.StartTimer();
            list.addAtIndex(toAdd1, toAdd2);
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj na losowy indeks", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }

}
void testAddAtLastToTheList(){
    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toAdd = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            list.addLastIndex(toAdd);
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj na koniec", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }
}

void testDeleteFirstToTheTable(){
    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            timer.StartTimer();
            table.deleteFirstIndex();
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun poczatek", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }

}
void testDeleteAtIndexToTheTable(){
    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toDelete = rnd.getRandomNumber(0, currSize - 1);
            timer.StartTimer();
            table.deleteAtIndex(toDelete);
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun ze srodka", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}
void testDeleteAtLastToTheTable(){
  Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addRandomElement();
            }

            timer.StartTimer();
            table.deleteLastIndex();
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun z konca", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}



void testDeleteFirstToTheList(){
    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addRandomElement();
            }

            timer.StartTimer();
            list.deleteFirstIndex();
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("usun pierwszy element", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }

}
void testDeleteAtIndexToTheList(){
    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addRandomElement();
            }

            int toDelete = rnd.getRandomNumber(0, currSize - 1);

            timer.StartTimer();
            list.deleteAtIndex(toDelete);
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun z losowego indeksu", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }

}


void testDeleteAtLastToTheList(){
    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addRandomElement();
            }

            timer.StartTimer();
            list.deleteLastIndex();
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun ostatni element", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }

}

void testFindElementInTheTable() {
    Table table = Table();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                table.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }
            int toFind = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            table.findElement(toFind);
            time += timer.TimerStop();
            table.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Znajdz w tablicy", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\tablica_pomiary.csv");
    }
}
void testFindElementInTheList() {
    DoubleLinkedList list = DoubleLinkedList();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                list.addLastIndex(rnd.getRandomNumber(-currSize, currSize));
            }

            int toFind = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            list.findElement(toFind);
            time += timer.TimerStop();
            list.deleteAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Znajdz w liscie", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\lista_pomiary.csv");
    }
}

void testAddElementToTheHeap() {
    Heap heap = Heap();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                int num = rnd.getRandomNumber(-currSize, currSize);
                heap.addElement(num);
            }

            int toAdd = rnd.getRandomNumber(-currSize, currSize);

            timer.StartTimer();
            heap.addElement(toAdd);
            time += timer.TimerStop();

            heap.removeAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Dodaj do kopca", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\kopiec_pomiary3.csv");
    }
}

void testRemoveElementToTheHeap() {
    Heap heap = Heap();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                heap.addElement(rnd.getRandomNumber(-currSize, currSize));
            }

            timer.StartTimer();
            heap.popRoot();
            time += timer.TimerStop();
            heap.removeAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Usun z kopca", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\kopiec_pomiary2.csv");
    }
}

void testFindElementInTheHeap() {
    Heap heap = Heap();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            for (int k = 0; k < currSize; k++)
            {
                heap.addElement(rnd.getRandomNumber(-currSize, currSize));
            }
            int toFind = rnd.getRandomNumber(-currSize, currSize);
            timer.StartTimer();
            heap.findElement(toFind);
            time += timer.TimerStop();
            heap.removeAll();
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("Znajdz w kopcu", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\kopiec_pomiary.csv");
    }
}

void testAddAllFloydToHeap()
{
    Heap heap = Heap();
    Timer timer = Timer();
    RandomGenerator rnd = RandomGenerator();


    int maxElemAmount = 100000;
    int step = 10000;
    int repPerSize = 100;

    double time = 0;

    for (int currSize = step; currSize <= maxElemAmount; currSize += step)
    {
        time = 0;
        for (int j = 0; j < repPerSize; j++)
        {
            int* arr = new int[currSize];
            for (int k = 0; k < currSize; k++)
            {
                arr[k] = rnd.getRandomNumber(-currSize, currSize);
            }

            timer.StartTimer();
            heap.addAllFloyd(arr, currSize);
            time += timer.TimerStop();
            heap.removeAll();
            delete[] arr;
        }

        time = time / repPerSize;
        std::cout << "Ilosc elementow: " << currSize << " | Czas: " << time << std::endl;
        saveToFile("", currSize, time, "C:\\Users\\malan\\Desktop\\studia\\4 sem\\SDiZO\\Testy_Projekt_1\\kopiec_pomiary.csv");
    }
}

void saveToFile(std::string operationType, int elementsAmount, double timeOperation, std::string path) {

    std::fstream file;
    try
    {
        file.open(path, std::ios::out | std::ios::app);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    std::string separator = ";";
    
    std::string elementsAmountString = std::to_string(elementsAmount);
    std::string timeOperationString = std::to_string(timeOperation);

    file << operationType << separator << elementsAmountString << separator << timeOperationString << std::endl;
    file.close();
}