<<<<<<< Updated upstream
#ifndef HORA_H
#define HORA_H

class Tempo{
    private:
        int hora, minuto;
    public:
        Tempo(int, int);
};

=======
#ifndef HORA
#define HORA

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Hora {
    private:
        // int mes;
        // int dia;
        int horas;
        int minutos;
    public:
        Hora(const int = 0, const int = 0);
        // virtual ~Hora();

        void setHoras(int);
        int getHoras() const;

        void setMinutos(int);
        int getMinutos() const;
};

>>>>>>> Stashed changes
#endif