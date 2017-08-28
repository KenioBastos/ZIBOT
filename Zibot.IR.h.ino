/*
  Zibot.IR.h - Biblioteca para pinagem e leitura de sensores infravermelhos.
  Criada por Kênio Bastos, dia 28 de agosto de 2017.
  Lançada para domínio público.
*/

#ifndef Zibot.IR_h

#define Zibot.IR_h
#include "Arduino.h"

class Infravermelho
{
  public:
    Infravermelho(int AO, int DO, int VCC, int GND);

    void LeituraAnalogica();
    void LeituraDigital();

  private:
    int _AO;
    int _DO;
    int _GND;
    int _VCC;
    
    unsigned long MillisAnterior;
};

#endif
