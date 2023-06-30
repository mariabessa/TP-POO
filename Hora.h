#ifndef HORA
#define HORA

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Hora {
    private:
        int horas;
        int minutos;
    public:
        Hora(const int = 0, const int = 0);
        
        void setHoras(int);
        int getHoras() const;

        void setMinutos(int);
        int getMinutos() const;
};

#endif