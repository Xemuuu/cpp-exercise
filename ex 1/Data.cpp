#include "Data.h"
#include <iostream>

void Data::Koryguj()
{
    if (m_nMiesiac > 12)
        m_nMiesiac = 12;
    else if (m_nMiesiac < 1)
        m_nMiesiac = 1;

    if (m_nMiesiac == 2) {
        if (m_nRok % 4 == 0 && m_nRok % 100 != 0){
            if (m_nDzien > 29)
                m_nDzien = 29;
            else if (m_nDzien < 1)
                m_nDzien = 1;
        }
        else {
            if (m_nDzien > 28)
                m_nDzien = 28;
            else if (m_nDzien < 1)
                m_nDzien = 1;
        }
    }
    else if (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12) {
        if (m_nDzien > 31)
            m_nDzien = 31;
        else if (m_nDzien < 1)
            m_nDzien = 1;
    }
    else {
        if (m_nDzien > 30)
            m_nDzien = 30;
        else if (m_nDzien < 1)
            m_nDzien = 1;
    }
}

Data::Data(int d, int m, int r)
{
    this->m_nDzien = d;
    this->m_nMiesiac = m;
    this->m_nRok = r;
    Koryguj();
}

Data::Data() : m_nDzien(1), m_nMiesiac(1), m_nRok(2000)
{
    Koryguj();
}

void Data::Ustaw(int d, int m, int r)
{
    m_nDzien = d;
    m_nMiesiac = m;
    m_nRok = r;

    Koryguj();
}


int Data::Dzien() const
{
    return m_nDzien;
}


int Data::Miesiac() const 
{
    return m_nMiesiac;
}


int Data::Rok() const
{
    return m_nRok;
}

void Data::Wypisz() const
{
    std::cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}

void Data::Wpisz()
{
    std::cout << "Podaj dzien: ";
    std::cin >> m_nDzien;
    std::cout << std::endl;

    std::cout << "Podaj miesiac: ";
    std::cin >> m_nMiesiac;
    std::cout << std::endl;

    std::cout << "Podaj Rok: ";
    std::cin >> m_nRok;
    std::cout << std::endl;

    Koryguj();
}

int Data::Porownaj(const Data& wzor) const
{
    if (wzor.m_nRok > this->m_nRok)
        return 1;
    else if (wzor.m_nRok < this->m_nRok)
        return -1;
    else {
        if (wzor.m_nMiesiac > this->m_nMiesiac)
            return 1;
        else if (wzor.m_nMiesiac < this->m_nMiesiac)
            return -1;
        else {
            if (wzor.m_nDzien > this->m_nDzien)
                return 1;
            else if (wzor.m_nDzien < this->m_nDzien)
                return -1;
        }
    }

    return 0;
}

std::ostream& operator<<(std::ostream& wy, const Data& d)
{
    wy << d.m_nDzien << "-" << d.m_nMiesiac << "-" << d.m_nRok;
    return wy;
}

std::istream& operator>>(std::istream& we, Data& d)
{
    we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
    d.Koryguj();
    return we;
}
