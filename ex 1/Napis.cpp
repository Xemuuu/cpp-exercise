#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"
#include "string.h"
#include <iostream>


Napis::Napis(const char* nap)
{
    m_nDl = strlen(nap);

    m_pszNapis = new char[m_nDl + 1];
    strcpy(m_pszNapis, nap);
}

Napis::Napis(const Napis& wzor)
{
    m_nDl = wzor.m_nDl;
    m_pszNapis = new char[m_nDl + 1];
    strcpy(m_pszNapis, wzor.m_pszNapis);
}

Napis::~Napis()
{
    delete[] m_pszNapis;
}

Napis& Napis::operator=(const Napis& wzor)
{
    if (this == &wzor) {
        return *this;
    }

    delete[] m_pszNapis;

    m_nDl = wzor.m_nDl;
    m_pszNapis = new char[m_nDl + 1];
    strcpy(m_pszNapis, wzor.m_pszNapis);

    return *this;
}

bool Napis::operator==(const Napis& wzor) const
{
    if (m_nDl != wzor.m_nDl) {
        return false;
    }
    return strcmp(m_pszNapis, wzor.m_pszNapis) == 0;
}

const char* Napis::Zwroc() const
{
    return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis)
{
    strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
    std::cout << m_pszNapis;
}

void Napis::Wpisz()
{
    std::cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char* por_napis) const
{
    return strcmp(m_pszNapis, por_napis);
}

std::ostream& operator<<(std::ostream& wy, const Napis& p)
{
    wy << p.Zwroc();
    return wy;
}

std::istream& operator>>(std::istream& we, Napis& p)
{
    char buffer[1000];
    we >> buffer;
    p.Ustaw(buffer);
    return we;
}
