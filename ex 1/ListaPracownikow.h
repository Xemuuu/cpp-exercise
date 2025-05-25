#pragma once

#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

class ListaPracownikow
{
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	ListaPracownikow();
	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	void ZapiszDoPliku(const char* nazwaPliku) const;
	void OdczytajZPliku(const char* nazwaPliku);
	~ListaPracownikow();
};

