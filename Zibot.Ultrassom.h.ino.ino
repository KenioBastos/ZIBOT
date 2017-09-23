/*
  Zibot.Ultrassom.h - Biblioteca para pinagem e leitura de sensores ultrassônicos.
  Criada por Kênio Bastos, dia 23 de setembro de 2017.
  Lançada para domínio público.
*/

#ifndef Zibot.Ultrassom_h

#define Zibot.Ultrassom_h
#include "Arduino.h"

class Ultrassom
{
  public:
    Ultrassom(int Trig, int Echo, int VCC.Ultra, int GND.Ultra);

    void LeituraUltrassom();
    void ChecagemUltrassom();

  private:
    int _Trig;
    int _Echo;
    int _VCC.Ultra;
    int _GND.Ultra;

};

#endif

