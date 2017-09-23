/*
  Zibot.Infravermelho.h - Biblioteca para pinagem e leitura de sensores óticos infravermelhos.
  Criada por Kênio Bastos, dia 23 de setembro de 2017.
  Lançada para domínio público.
*/

#include "Arduino.h"
#include "Zibot.Infravermelho.h"

//--------------------------------------------------------------------------------------->  COMANDO PARA PINAGEM;

Infravermelho::Infravermelho(int AO, int DO, int VCC.Infra, int GND.Infra);
{

  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
  pinMode(VCC.Infra, OUTPUT);
  pinMode(GND.Infra, OUTPUT);

  digitalWrite(VCC.Infra, HIGH);
  digitalWrite(GND.Infra, LOW);

  _AO = AO;
  _DO = DO;
  _VCC.Infra = VCC.Infra;
  _GND.Infra = GND.Infra;

}

//--------------------------------------------------------------------------------------->  COMANDO PARA LEITURA ANALÓGICA;

void Infravermelho::LeituraAnalogica()
{
  Serial.print("O seu sensor esta lendo... ");
  Serial.println(analogRead(_AO));

  unsigned long MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA LEITURA DIGITAL;

void Infravermelho::LeituraDigital()
{
  Serial.print("O seu sensor esta lendo... ");
  Serial.println(digitalRead(_DO));

  unsigned long MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM ANALOGICA;

void Infravermelho::ChecagemAnalogica()
{
  Serial.println("Sera feita uma analise de qualidade da leitura analogica do seu sensor.");

  unsigned long MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 5000);

  Serial.println();

  //--------------------------------------------------------------------------------------->  LEITURA DO BRANCO;

  Serial.println("Posicione seu sensor em alguma superficie branca.") ;
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("Lembre-se que a altura em relaçao ao chao afeta a leitura.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("A leitura do branco sera feita apos 5 segundos.");
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

  int Branco = analogRead(_AO);
  Serial.println("Leitura do branco feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  //--------------------------------------------------------------------------------------->  LEITURA DO PRETO;

  Serial.println("Posicione seu sensor em alguma superficie preta.") ;
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("Lembre-se que a altura em relaçao ao chao afeta a leitura.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("A leitura do preta sera feita apos 5 segundos.");
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

  int Preto = analogRead(_AO);
  Serial.println("Leitura do preto feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  //--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  if (Preto >= 800 && Branco < 100)
  {
    Serial.println("Seu sensor esta funcionando perfeitamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 5000);

    Serial.println("Continue usando-o a vontade.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  } else if (Preto < 800 && Preto > 600 && Branco >= 100 && Branco < 300)
  {
    Serial.println("Seu sensor esta funcionando, porem de maneira nao ideal.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 5000);

    Serial.println("Considere ler nosso manual de instruções.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  } else if (Preto < 600 && Branco >= 300);
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 5000);

    Serial.println("Considere ler nosso manual de instruções.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);
  }
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM DIGITAL;

void Infravermelho::ChecagemDigital()
{
  Serial.println("Sera feita uma analise de qualidade da leitura digital do seu sensor.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 5000);

  //--------------------------------------------------------------------------------------->  LEITURA DO OBJETO;

  Serial.println("Posicione seu sensor em frente a um objeto.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("Lembre-se que a distancia pode afetar a leitura.");
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

  int Objeto = digitalRead(_DO);
  Serial.println("Leitura do objeto feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  //--------------------------------------------------------------------------------------->  LEITURA SEM OBJETO;

  Serial.println("Posicione seu sensor sem objeto nenhum em sua frente.");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);
  Serial.println("Lembre-se que a distancia pode afetar a leitura.");
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

  int SemObjeto = digitalRead(_DO);
  Serial.println("Leitura sem objeto feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  //--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 2000);

  if (Objeto = 1 && SemObjeto = 0)
  {
    Serial.println("Seu sensor esta funcionando perfeitamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("Quando ha objeto, o sensor le...");
    Serial.println(Objeto);
    Serial.print("E quando nao ha, o sensor le...");
    Serial.println(SemObjeto);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 5000);

    Serial.println("Continue usando-o a vontade.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

  } else
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);

    Serial.print("Quando ha objeto, o sensor le...");
    Serial.println(Objeto);
    Serial.print("E quando nao ha, o sensor le...");
    Serial.println(SemObjeto);
    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 5000);

    Serial.println("Considere ler nosso manual de instruções.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 2000);
  }
}

