/*
  Zibot.Ultrassom.h - Biblioteca para pinagem e leitura de sensores ultrassônicos.
  Criada por Kênio Bastos, dia 21 de setembro de 2017.
  Lançada para domínio público.
*/

#include "Arduino.h"
#include "Zibot.Ultrassom.h"

//--------------------------------------------------------------------------------------->  COMANDO PARA PINAGEM;

Ultrassom::Ultrassom(int Trig, int Echo, int VCC.Ultra, int GND.Ultra);
{

  pinMode(Trig, INPUT);
  pinMode(Echo, INPUT);
  pinMode(VCC.Ultra, OUTPUT);
  pinMode(GND.Ultra, OUTPUT);

  digitalWrite(VCC.Ultra, HIGH);
  digitalWrite(GND.Ultra, LOW);

  _Trig = Trig;
  _Echo = Echo;
  _VCC.Ultra = VCC.Ultra;
  _GND.Ultra = GND.Ultra;

}

//--------------------------------------------------------------------------------------->  COMANDO PARA LEITURA;

void Ultrassom::LeituraUltrassom()
{
  digitalWrite(_Trig, LOW);

  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 2);

  digitalWrite(_Trig, HIGH);

  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 10);

  Duracao = pulseIn(_Echo, HIGH);
  Distancia = Duracao * 0.034 / 2;

  Serial.print("O seu sensor ultrassonico esta lendo... ");
  Serial.println(Distancia);

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM;

void Ultrassom::ChecagemUltrassom()
{
  Serial.println("Sera feita uma analise de qualidade do seu sensor.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

  //--------------------------------------------------------------------------------------->  LEITURA DE TESTE;

  Serial.println("Posicione seu sensor a 10cm de algum objeto.") ;
  Serial.println("Lembre-se que superfícies curvas afetam a leitura.");
  Serial.println("A leitura de teste sera feita apos 5 segundos.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  Serial.println("Cinco...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Quatro...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Tres...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Dois...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Um...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);

  //--------------------------------------------------------------------------------------->  CÁLCULO DA DISTÂNCIA;

  digitalWrite(_Trig, LOW);
  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 2);

  digitalWrite(_Trig, HIGH);
  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 10);

  Duracao = pulseIn(_Echo, HIGH);
  Distancia = Duracao * 0.034 / 2;

  DistanciaTeste = Distancia;

  Serial.println("Leitura de teste feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);


  //--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

  if (DistanciaTeste = 10)
  {
    Serial.println("Seu sensor esta funcionando corretamente.");

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);

    Serial.println("Continue usando-o a vontade.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);

  } else if (DistanciaTeste >= 8 && DistanciaTeste <= 12)
  {
    Serial.println("Seu sensor esta funcionando, porem de maneira nao ideal.");

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);

    Serial.println("Considere olhar nosso guia para solucao de problemas.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);

  } else
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);

    Serial.println("Troque-o imediatamente.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);
  }
}

