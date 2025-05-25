#pragma once

#include "Pracownik.h"

class Kierownik : public Pracownik {
    Napis m_NazwaDzialu;
    int m_nliczbaPracownikow; 

public:
    Kierownik();
    Kierownik(const Kierownik& wzor);

    void Wpisz();

    Kierownik& operator=(const Kierownik& wzor);
    bool operator==(const Kierownik & wzor) const;

    virtual void WypiszDane() const;
    virtual Pracownik* KopiaObiektu()const;

    friend std::ostream& operator<<(std::ostream& wy, const Kierownik& s); 
    friend std::istream & operator>>(std::istream& we, Kierownik& s); 
};

