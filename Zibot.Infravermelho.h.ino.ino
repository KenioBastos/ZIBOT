/*
  Zibot.Infravermelho.h - Biblioteca para pinagem e leitura de sensores infravermelhos.
  Criada por Kênio Bastos, dia 21 de setembro de 2017.
  Lançada para domínio público.
*/

#ifndef Zibot.Infravermelho_h

#define Zibot.Infravermelho_h
#include "Arduino.h"

class Infravermelho
{
  public:
    Infravermelho(int AO, int DO, int VCC.Infra, int GND.Infra);

    void LeituraAnalogica();
    void LeituraDigital();
    void ChecagemAnalogica();
    void ChecagemDigital();

  private:
    int _AO;
    int _DO;
    int _GND.Infra;
    int _VCC.Infra;
    
};

#endif
