/*
  Zibot.Ultrassom.h - Biblioteca para pinagem e leitura de sensores ultrassônicos.
  Criada por Kênio Bastos, dia 23 de setembro de 2017.
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
  unsigned long MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 2);

  digitalWrite(_Trig, HIGH);
  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 10);

  digitalWrite(_Trig, LOW);

  long Duracao = pulseIn(_Echo, HIGH);
  float Distancia = Duracao * 0.034 / 2;

  Serial.print("O seu sensor esta lendo... ");
  Serial.print(Distancia);
  Serial.println(" cm");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM;

void Ultrassom::ChecagemUltrassom()
{
  Serial.println("Sera feita uma analise de qualidade do seu sensor.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 5000);

  Serial.println();

  //--------------------------------------------------------------------------------------->  LEITURA DE TESTE;

  Serial.println("Posicione seu sensor a 10cm de algum objeto.") ;
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("Lembre-se que a trajetória das ondas afeta a leitura.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("A leitura de teste sera feita apos 10 segundos.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  Serial.println("Dez...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Nove...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Oito...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Sete...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
  Serial.println("Seis...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 1000);
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
  unsigned long MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 2);

  digitalWrite(_Trig, HIGH);
  MicrosAnterior = micros();
  do {} while (micros() - MicrosAnterior <= 10);
  
  digitalWrite(_Trig, LOW);

  long Duracao = pulseIn(_Echo, HIGH);
  float Distancia = Duracao * 0.034 / 2;

  float DistanciaTeste = Distancia;
  Serial.println("Leitura de teste feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);


  //--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  if (DistanciaTeste >= 10 && DistanciaTeste < 11)
  {
    Serial.println("Seu sensor esta funcionando corretamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.println("Continue usando-o a vontade.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  } else if (DistanciaTeste < 10 && DistanciaTeste >= 11 && DistanciaTeste >= 9 && DistanciaTeste < 12)
  {
    Serial.println("Seu sensor esta funcionando, porem de maneira nao ideal.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.println("Considere ler nosso manual de instruções.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  } else
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor, a uma distancia de 10cm, le...");
    Serial.println(DistanciaTeste);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.println("Troque-o imediatamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  }
}
