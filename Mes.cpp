#include "Dia.h"

Dia::Dia(
    const vector<Hora*> diaDoMes
): mes(mes) {}

void Hora::setDiaDoMes(int diaDoMes) {
    this->diaDoMes = diaDoMes;
}
int Hora::getDiaDoMes() const {
    return diaDoMes;
}