#include "Kierownik.h"

Kierownik::Kierownik() : Pracownik("", "", 1, 1, 2000)
{
    m_NazwaDzialu = "";
    m_nliczbaPracownikow = 0;
}

Kierownik::Kierownik(const Kierownik& wzor) : Pracownik(wzor)
{
    m_NazwaDzialu = wzor.m_NazwaDzialu;
    m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
}

Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
    if (this == &wzor)
        return *this;

    Pracownik::operator=(wzor);
    m_NazwaDzialu = wzor.m_NazwaDzialu;
    m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;

    return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
    return Pracownik::operator==(wzor) && m_NazwaDzialu == wzor.m_NazwaDzialu && m_nliczbaPracownikow == wzor.m_nliczbaPracownikow;
}

void Kierownik::WypiszDane() const
{
    Pracownik::Wypisz();
    std::cout << " " << m_NazwaDzialu << " " << m_nliczbaPracownikow;
}

Pracownik* Kierownik::KopiaObiektu() const
{
    return new Kierownik(*this);
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& s)
{
    s.WypiszDane();
    return wy;
}

std::istream& operator>>(std::istream& we, Kierownik& s)
{
    s.Wpisz();
    return we;
}

void Kierownik::Wpisz()
{
    Pracownik::Wpisz();
    std::cout << "Podaj nazwe dzialu: ";
    std::cin >> m_NazwaDzialu;
    std::cout << "Podaj liczbe pracownikow: ";
    std::cin >> m_nliczbaPracownikow;
}