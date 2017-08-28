/*
  Zibot.IR.h - Biblioteca para pinagem e leitura de sensores infravermelhos.
  Criada por Kênio Bastos, dia 28 de agosto de 2017.
  Lançada para domínio público.
*/

#include "Arduino.h"
#include "Zibot.IR.h"

Infravermelho::Infravermelho(int AO, int DO, int VCC, int GND);
{

  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);

  digitalWrite(GND, LOW);
  digitalWrite(VCC, HIGH);

  _AO = AO;
  _DO = DO;
  _GND = GND;
  _VCC = VCC;

}

void Infravermelho::LeituraAnalogica()
{
  Serial.print("O seu sensor está lendo... ");
  Serial.println(analogRead(_AO));
  
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

void Infravermelho::LeituraDigital()
{
  Serial.print("O seu sensor está lendo... ");
  Serial.println(digitalRead(_DO));
  
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}
