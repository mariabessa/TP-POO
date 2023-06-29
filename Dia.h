#ifndef DIA
#define DIA

#include <iostream>
#include <vector>

#include "Hora.h"

using namespace std;

class Dia{
    private:
        vector<Hora*> diaDoMes;
        // vector<int> mes;
        // vector<int> dia;

    protected:
        Dia(vector<Hora*> = vector<Hora*>());
        // Dia(vector<int*> = vector<int*>(), vector<int*> = vector<int*>());

        void setDiaDoMes(vector<Hora*>);
        vector<Hora*> getDiaDoMes() const;

        // void setDia(vector<int*>);
        // vector<int*> getDia() const;

        // void setMes(vector<int*>);
        // vector<int*> getMes() const;
};