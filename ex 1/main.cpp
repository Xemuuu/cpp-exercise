#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include <iostream>
#include "ListaPracownikow.h"




int main() {



	ListaPracownikow lista;
	int opcja;
	do {
		std::cout << std::endl;
		std::cout << "1. Dodaj pracownika do listy." << std::endl;
		std::cout << "2. Usun pracownika z listy." << std::endl;
		std::cout << "3. Wypisz liste pracownikow." << std::endl;
		std::cout << "4. Znajdz pracownika." << std::endl;
		std::cout << "5. Odczytaj pracownikow z pliku." << std::endl;
		std::cout << "6. Zapisz pracownikow do pliku." << std::endl;
		std::cout << "7. Dodaj kierownika do listy." << std::endl;
		std::cout << "0. Wyjscie." << std::endl;
		std::cout << "Wybierz opcje: ";
		std::cin >> opcja;

		switch (opcja) {
		case 1: {
			Pracownik pracownik;
			std::cin >> pracownik;
			lista.Dodaj(pracownik);
			
			break;
		}
		case 2: {
			Pracownik pracownik;
			std::cin >> pracownik;
			lista.Usun(pracownik);
			break;
		}
		case 3: {
			lista.WypiszPracownikow();
			break;
		}
		case 4: {
			Napis nazwisko;
			Napis imie;
			std::cout << "Podaj nazwisko: ";
			std::cin >> nazwisko;
			std::cout << "Podaj imie: ";
			std::cin >> imie;
			const Pracownik* szukany;
			szukany = lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			if (szukany)
				std::cout << *szukany << std::endl;
			else
				std::cout << "Nie znaleziono pracownika" << std::endl;
			break;
		}
		case 5: {
			lista.OdczytajZPliku("pracownicy.txt");
			break;
		}
		case 6: {
			lista.ZapiszDoPliku("pracownicy.txt");
			break;
		}
		case 7: {
			Kierownik kierownik;
			std::cin >> kierownik;
			lista.Dodaj(kierownik);
			break;
		}
		default:
			break;
		}
	} while (opcja != 0);


/*
	//testowanie klasy Data
	Data data1(29, 2, 2026);
	Data data2;
	Data data3;
	std::cout << "Podaj date(d,m,r): " << std::endl;
	std::cin >> data2;
	data3.Ustaw(5, 10, 2023);
	data1.Wypisz();
	std::endl(std::cout);
	if(data2.Porownaj(data3) == 0)
		std::cout << "Data2 i Data3 sa takie same" << std::endl;
	else if (data2.Porownaj(data3) == 1)
		std::cout << "Data3 jest pozniejsza niz Data2" << std::endl;
	else
		std::cout << "Data2 jest pozniejsza niz Data3" << std::endl;
		
	std::cout << "Data2: " << data2 << std::endl;
*/
/*
	//testowanie klasy Lista pracownikow
	ListaPracownikow lista;
	Pracownik pracownik1("Jan", "Kowalski", 1, 1, 2000);
	Pracownik pracownik2("Adam", "Nowak", 1, 1, 2000);
	Pracownik pracownik3("Jan", "Nowak", 1, 1, 2000);
	Pracownik pracownik4("Adam", "Kowalski", 1, 1, 2000);
	lista.Dodaj(pracownik1);
	lista.Dodaj(pracownik2);
	lista.Dodaj(pracownik3);
	lista.Dodaj(pracownik4);
	lista.WypiszPracownikow();
	std::endl(std::cout);
	lista.Usun(pracownik1);
	lista.WypiszPracownikow();
	std::endl(std::cout);
	lista.Usun(pracownik3);
	lista.WypiszPracownikow();
	std::endl(std::cout);

	const Pracownik* szukany;
	szukany = lista.Szukaj("Kowalski", "Adam");
	if (szukany)
		szukany->Wypisz();
	else
		std::cout << "Nie znaleziono pracownika" << std::endl;

*/
/*
	//testowanie klasy Napis
	Napis napis1("Ala ma kota");
	Napis napis2(napis1);
	Napis napis3;
	napis3 = napis1;

	std::cout << "Napis1: " << napis1 << std::endl;
	if (napis2 == napis3)
		std::cout << "Napis2 i Napis3 sa takie same" << std::endl;
	else
		std::cout << "Napis2 i Napis3 nie sa takie same" << std::endl;

	std::cout << "napis3: " << napis3.Zwroc() << std::endl;
	std::cout << "Podaj napis: " << std::endl;
	std::cin >> napis3;
	std::cout << "napis3: " << napis3 << std::endl;
*/
	
	return 0;
}