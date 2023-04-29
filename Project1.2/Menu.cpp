#include "Menu.h"
#include "Tests.h"
#include <string>
#include <iostream> 
#include "Table.h"
#include "DoubleLinkedList.h"
#include "Heap.h"

void tableTests() {
	char option;
	
	std::cout << std::endl;
	std::cout << "      MENU" << std::endl;
	std::cout << "1.Dodaj na poczatek" << std::endl;
	std::cout << "2.Dodaj na wybrany indeks" << std::endl;
	std::cout << "3.Dodaj na koniec" << std::endl;
	std::cout << "4.Usun na poczatku" << std::endl;
	std::cout << "5.Usun wybrany element" << std::endl;
	std::cout << "6.Usun ostatni element" << std::endl;
	std::cout << "7. Znajdz element" << std::endl;
	std::cout << "0.Powrot do menu" << std::endl;
	std::cout << "Podaj opcje: ";
	std::cin >> option;

	switch (option)
	{
	case '1': {
		testAddFirstToTheTable();
		break;
	}
	case '2': {
		testAddAtIndexToTheTable();
		break;
	}
	case '3': {
		testAddAtLastToTheTable();
		break;
	}
	case '4': {
		testDeleteFirstToTheTable();
		break;
	}
	case '5': {
		testDeleteAtIndexToTheTable();
		break;
	}
	case '6': {
		testDeleteAtLastToTheTable();
		break;
	}
	case '7': {

	}
	default:
		break;
	}
}

void listTests() {
	char option;

	std::cout << std::endl;
	std::cout << "      MENU" << std::endl;
	std::cout << "1.Dodaj na poczatek" << std::endl;
	std::cout << "2.Dodaj na wybrany indeks" << std::endl;
	std::cout << "3.Dodaj na koniec" << std::endl;
	std::cout << "4.Usun na poczatku" << std::endl;
	std::cout << "5.Usun wybrany element" << std::endl;
	std::cout << "6.Usun ostatni element" << std::endl;
	std::cout << "7. Znajdz element" << std::endl;
	std::cout << "0.Powrot do menu" << std::endl;
	std::cout << "Podaj opcje: ";
	std::cin >> option;

	switch (option)
	{
	case '1': {
		testAddFirstToTheList();
		break;
	}
	case '2': {
		testAddAtIndexToTheList();
		break;
	}
	case '3': {
		testAddAtLastToTheList();
		break;
	}
	case '4': {
		testDeleteFirstToTheList();
		break;
	}
	case '5': {
		testDeleteAtIndexToTheList();
		break;
	}
	case '6': {
		testDeleteAtLastToTheList();
		break;
	}
	case '7': {

	}
	default:
		break;
	}

}

void menuTable()
{
	char option;
	Table table = Table();
	int index, wartosc;
	
	do {

		std::cout << std::endl;
		std::cout << "      MENU" << std::endl;
		std::cout << "1.Wczytaj z pliku" << std::endl;
		std::cout << "2.Usun" << std::endl;
		std::cout << "3.Dodaj" << std::endl;
		std::cout << "4.Znajdz" << std::endl;
		std::cout << "5.Utworz losowo" << std::endl;
		std::cout << "6.Wyswietl" << std::endl;
		std::cout << "7.Test (pomiary)" << std::endl;
		std::cout << "0.Powrot do menu" << std::endl;
		std::cout << "Podaj opcje: ";
		std::cin >> option;

		switch (option) {
		case '1': {
			std::cout << "Podaj nazwe pliku: ";
			std::string path = "";
			std::cin >> path;

			table.readDataFromFile(path);
			break;
		}
		case '2': {
			std::cout << "Podaj, index elementu tablicy ktory usunac: ";
			std::cin >> index;
			table.deleteAtIndex(index);
			break;
		}

		case '3': {
			std::cout << "Wprowadz wartosc, ktora chcesz dodac do tablicy oraz indeks na ktorym ma sie znalezc: ";
			std::cin >> wartosc;
			std::cin >> index;
			table.addAtIndex(index, wartosc);
			break;
		}

		case '4': {
			std::cout << "Podaj wartosc szukanego elementu: ";
			std::cin >> wartosc;
			int resIndex = table.findElement(wartosc);
			std::cout << "Dany element znajduje sie na indeksie: " << resIndex<<std::endl;
			break;
		}
		case '5': {
			table.addRandomElement();
			break;
		}

		case '7': {
			tableTests();
			break;
		}
		default: 
			break;
		}
		printf("\nTablica:\n");
		std::cout << table.toString();
		printf("\n");

	} while (option != '0');
}

void menuDoubleLinkedList() {

	char option;
	int wartosc, index;
	DoubleLinkedList list = DoubleLinkedList();
	do {
		std::cout << std::endl;
		std::cout << "      MENU" << std::endl;
		std::cout << "1.Wczytaj z pliku" << std::endl;
		std::cout << "2.Usun" << std::endl;
		std::cout << "3.Dodaj" << std::endl;
		std::cout << "4.Znajdz" << std::endl;
		std::cout << "5.Utworz losowo" << std::endl;
		std::cout << "6.Wyswietl" << std::endl;
		std::cout << "7.Test (pomiary)" << std::endl;
		std::cout << "0.Powrot do menu" << std::endl;
		std::cout << "Podaj opcje: ";
		std::cin >> option;

		switch (option) {
		case '1': {
			std::cout << "Podaj nazwe pliku: ";
			std::string path = "";
			std::cin >> path;

			list.readDataFromFile(path);
			break;
		}
		case '2':
			std::cout << "Podaj element, który chcesz usunac: ";
			std::cin >> wartosc;
			list.deleteNumber(wartosc);
			break;
		case '3':
			std::cout << "Podaj wartosc elementu oraz indeks, na ktory chcesz go dodac: ";
			std::cin >> wartosc;
			std::cin >> index;
			list.addAtIndex(index, wartosc);
			break;
		case '4': {
			std::cout << "Wprowadz wartosc elementu: ";
			std::cin >> wartosc;
			ListElement* findRes = list.findElement(wartosc);
			if (findRes == NULL)
				printf("Nie ma takiego elementu w liscie\n");
			else
				printf("Jest taki element w liscie\n");
			break;
		}
		case '5':
			list.addRandomElement();
			break;
		case '6':
			list.toStringFromFirstToLast();
			break;
		case '7': {
			listTests();
			break;
		}
		default:
			break;
		}


		std::cout << list.toStringFromFirstToLast();
		printf("\n");
		std::cout << list.toStringFromLastToFirst();
		printf("\n");
	} while (option != '0');
	
}

void menuHeap(){

	char option;
	int wartosc, index;
	Heap heap = Heap();
	do {
		std::cout << std::endl;
		std::cout << "      MENU" << std::endl;
		std::cout << "1.Wczytaj z pliku" << std::endl;
		std::cout << "2.Usun" << std::endl;
		std::cout << "3.Dodaj" << std::endl;
		std::cout << "4.Znajdz" << std::endl;
		std::cout << "5.Utworz losowo" << std::endl;
		std::cout << "6.Wyswietl" << std::endl;
		std::cout << "7.Test (pomiary)" << std::endl;
		std::cout << "0.Powrot do menu" << std::endl;
		std::cout << "Podaj opcje: ";
		std::cin >> option;

		switch (option) {
		case '1': {
			std::cout << "Podaj nazwe pliku: ";
			std::string path = "";
			std::cin >> path;
			
			heap.readDataFromFile(path);
			break;
		}
		case '2':
			std::cout << "Podaj indeks, który chcesz usunac: ";
			std::cin >> index;
			heap.removeElement(index);
			break;
		case '3':
			std::cout << "Podaj wartosc elementu, który chcesz dodac: ";
			std::cin >> wartosc;
			heap.addElement(wartosc);
			break;
		case '4': {
			std::cout << "Wprowadz wartosc elementu: ";
			std::cin >> wartosc;
			bool element = heap.findElement(wartosc);
			if (element == false)
				printf("Nie ma takiego elementu w kopcu\n");
			else
				printf("Jest taki element w kopcu\n");
			break;
		}
		case '5':
			heap.addRandomElement();
			break;
		case '6':

			heap.toString();
			break;
		case '7': {
			listTests();
			break;
		}
		default:
			break;
		}

		std::cout << heap.toStringText();
		printf("\n");
		std::cout << heap.toString();
	} while (option != '0');

}

void menu() {
	char option;
	do {
		std::cout << std::endl;
		std::cout << "==== MENU GLOWNE ===" << std::endl;
		std::cout << "1.Tablica" << std::endl;
		std::cout << "2.Lista" << std::endl;
		std::cout << "3. Heap" << std::endl;
		std::cout << "0.Wyjscie" << std::endl;
		std::cout << "Podaj opcje:";
		std::cin >> option;
		std::cout << std::endl;

		switch (option) {
		case '1':
			menuTable();
			break;
		case '2':
			menuDoubleLinkedList();
			break;
		case '3':
			menuHeap();

		default:
			break;
		}
	} while (option != '0');
}


