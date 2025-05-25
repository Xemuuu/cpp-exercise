#include "ListaPracownikow.h"

ListaPracownikow::ListaPracownikow()
{
	m_nLiczbaPracownikow = 0;
	m_pPoczatek = nullptr;
}



void ListaPracownikow::Dodaj(const Pracownik& p)
{
	Pracownik* pracownik = new Pracownik(p);
	Pracownik* obecny;
	if (m_nLiczbaPracownikow == 0) {
		m_pPoczatek = pracownik;
		m_nLiczbaPracownikow += 1;
	}
	else {
		obecny = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			if (obecny->Porownaj(*pracownik) == 0) {
				break;
			}
			else if (obecny->Porownaj(*pracownik) < 0) {
				if (i + 1 == m_nLiczbaPracownikow) {
					obecny->m_pNastepny = pracownik;
					pracownik->m_pPoprzedni = obecny;
					pracownik->m_pNastepny = nullptr;
					m_nLiczbaPracownikow += 1;
					break;
				}

			}
			else {
				if (i == 0) {
					pracownik->m_pNastepny = obecny;
					obecny->m_pPoprzedni = pracownik;
					pracownik->m_pPoprzedni = nullptr;
					m_pPoczatek = pracownik;
					m_nLiczbaPracownikow += 1;
					break;
				}
				pracownik->m_pNastepny = obecny;
				pracownik->m_pPoprzedni = obecny->m_pPoprzedni;
				obecny->m_pPoprzedni->m_pNastepny = pracownik;
				obecny->m_pPoprzedni = pracownik;
				m_nLiczbaPracownikow += 1;
				break;
			}
			obecny = obecny->m_pNastepny;
		}
	}
}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	if (!m_pPoczatek) {
		std::cout << "Lista jest pusta\n";
		return;
	}
	Pracownik* obecny = m_pPoczatek;
	while (obecny) {
		if (int wynik = obecny->Porownaj(wzorzec)) {
			if (wynik > 0) {
				std::cout << "Pracownika nie ma na liscie\n";
				return;
			}
			else obecny = obecny->m_pNastepny;
		}
		else {
			if (obecny == m_pPoczatek) {
				m_pPoczatek = obecny->m_pNastepny;
				obecny->m_pNastepny->m_pPoprzedni = nullptr;
				m_nLiczbaPracownikow--;
				delete obecny;
				return;
			}
			if (obecny->m_pNastepny) obecny->m_pNastepny->m_pPoprzedni = obecny->m_pPoprzedni;
			if (obecny->m_pPoprzedni) obecny->m_pPoprzedni->m_pNastepny = obecny->m_pNastepny;
			else obecny = obecny->m_pNastepny;
			m_nLiczbaPracownikow--;
			delete obecny;
			return;
		}
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik* obecny = m_pPoczatek;
	while (obecny != nullptr) {
		obecny->Wypisz();
		std::cout << std::endl;
		obecny = obecny->m_pNastepny;
	}

}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	Pracownik* obecny;
	obecny = m_pPoczatek;
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		
		if (strcmp(obecny->Imie(), imie) == 0 && strcmp(obecny->Nazwisko(), nazwisko) == 0) {
			return obecny;
		}
		obecny = obecny->m_pNastepny;
	}
	return nullptr;
}

void ListaPracownikow::ZapiszDoPliku(const char* nazwaPliku) const
{
	std::ofstream plik(nazwaPliku);
	if (!plik) {
		std::cout << "Nie udalo sie otworzyc pliku\n";
		return;
	}
	Pracownik* obecny = m_pPoczatek;
	while (obecny) {
		plik << *obecny << std::endl;
		obecny = obecny->m_pNastepny;
	}
	plik.close();
}

void ListaPracownikow::OdczytajZPliku(const char* nazwaPliku)
{
	std::ifstream plik(nazwaPliku);
	if (!plik) {
		std::cout << "Nie udalo sie otworzyc pliku\n";
		return;
	}
	Pracownik pracownik;
	Napis napis;
	while (plik >> napis) {
		pracownik.Imie(napis.Zwroc());
		plik >> napis;
		pracownik.Nazwisko(napis.Zwroc());
		plik >> napis;
		    
	    int liczba1, liczba2, liczba3;

	    std::stringstream ss(napis.Zwroc());
    	std::string temp;

		std::getline(ss, temp, '-');
    	liczba1 = std::stoi(temp);
    	std::getline(ss, temp, '-'); 
    	liczba2 = std::stoi(temp);
    	std::getline(ss, temp, '-');
    	liczba3 = std::stoi(temp);

		pracownik.DataUrodzenia(liczba1, liczba2, liczba3);
		Dodaj(pracownik);
	}
}

ListaPracownikow::~ListaPracownikow()
{
	Pracownik* obecny = m_pPoczatek;
	Pracownik* nastepny;
	while (obecny) {
		nastepny = obecny->m_pNastepny;
		delete obecny;
		obecny = nastepny;
	}
}

