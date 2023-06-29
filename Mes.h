#ifndef MES
#define MES

#include <iostream>
#include <vector>

#include "Dia.h"

using namespace std;

class Dia{
    private:
        vector<Dia*> mesDoAno;

    protected:
        Dia(vector<Dia*> = vector<Dia*>());

        void setMesDoAno(vector<Dia*>);
        vector<Dia*> getMesDoAno() const;
};