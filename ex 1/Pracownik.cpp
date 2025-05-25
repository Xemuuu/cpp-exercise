#include "Pracownik.h"
#include "string.h"
#include <iostream>

int Pracownik::nextID;

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok): m_nIDZatrudnienia(++nextID)
{
    this->Imie(im);
    this->Nazwisko(naz);
    this->DataUrodzenia(dzien, miesiac, rok);
    m_pNastepny = nullptr;
    m_pPoprzedni = nullptr;
    
}

Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia(++nextID)
{
    this->Imie(wzor.Imie());
    this->Nazwisko(wzor.Nazwisko());
    this->DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
    this->m_pNastepny = wzor.m_pNastepny;
    this->m_pPoprzedni = wzor.m_pPoprzedni;
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
    if (this == &wzor)
        return *this;

    this->Imie(wzor.Imie());
    this->Nazwisko(wzor.Nazwisko());
    this->DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
    this->m_pNastepny = wzor.m_pNastepny;
    this->m_pPoprzedni = wzor.m_pPoprzedni;

    return *this;
}

const char* Pracownik::Imie() const
{
    return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
    return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie)
{
    m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
    m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
    m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
    m_Imie.Wypisz();
    std::cout << " ";
    m_Nazwisko.Wypisz();
    std::cout << " ";
    m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
    std::cout << "Podaj imie: ";
    m_Imie.Wpisz();
    std::cout << "Podaj Nazwisko: ";
    m_Nazwisko.Wpisz();
    std::cout << "Podaj Date urodzenia: " << std::endl;
    m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
    return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{

    return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	if (strcmp(this->Nazwisko(), wzorzec.Nazwisko()) == 0)
	{
		if (strcmp(this->Imie(), wzorzec.Imie()) == 0)
		{
			return this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
		}
		else 
		{
			return strcmp(this->Imie(), wzorzec.Imie());
		}

	}
	else 
	{
		return strcmp(this->Nazwisko(), wzorzec.Nazwisko());
	}

    return 0;
}

bool Pracownik::operator==(const Pracownik & wzor) const{
    return this->Porownaj(wzor) == 0;
}

std::ostream& operator<<(std::ostream& wy, const Pracownik& p)
{
    wy << p.Imie() << " " << p.Nazwisko() << " " << p.m_DataUrodzenia;
    return wy;
}

std::istream& operator>>(std::istream& we, Pracownik& p)
{
    p.Wpisz();
    return we;
}

void Pracownik::WypiszDane()
{
    std::cout << "ID: " << m_nIDZatrudnienia << std::endl;
    Wypisz();
    std::cout << std::endl;
    m_DataUrodzenia.Wypisz();
    std::cout << std::endl;
}

Pracownik* Pracownik::KopiaObiektu() const
{
    return new Pracownik(*this);
}