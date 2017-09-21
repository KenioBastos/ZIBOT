/*
  Zibot.Infravermelho.h - Biblioteca para pinagem e leitura de sensores infravermelhos.
  Criada por Kênio Bastos, dia 21 de setembro de 2017.
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

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA LEITURA DIGITAL;

void Infravermelho::LeituraDigital()
{
  Serial.print("O seu sensor esta lendo... ");
  Serial.println(digitalRead(_DO));

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 750);
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM ANALOGICA; 

void Infravermelho::ChecagemAnalogica()
{
  Serial.println("Sera feita uma analise de qualidade do seu sensor, em relacao a leitura analogica.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

//--------------------------------------------------------------------------------------->  LEITURA DO BRANCO;

  Serial.println("Posicione seu sensor em alguma superficie branca.") ;
  Serial.println("Lembre-se que a altura em relaçao ao chao afeta a leitura.");
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

  Branco = analogRead(_AO);
  Serial.println("Leitura do branco feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

//--------------------------------------------------------------------------------------->  LEITURA DO PRETO;

  Serial.println("Posicione seu sensor em alguma superficie preta.") ;
  Serial.println("Lembre-se que a altura em relaçao ao chao afeta a leitura.");
  Serial.println("A leitura do preto sera feita apos 5 segundos.");

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

  Preto = analogRead(_AO);
  Serial.println("Leitura do preto feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

//--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");
  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

  if (Preto >= 800 && Branco < 100)
  {
    Serial.println("Seu sensor esta funcionando perfeitamente.");

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);

    Serial.println("Continue usando-o a vontade.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);

  } else if (Preto < 800 && Preto > 600 && Branco >= 100 && Branco < 300)
  {
    Serial.println("Seu sensor esta funcionando, porem de maneira nao ideal.");

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);

    Serial.println("Uma calibracao e recomendada. Considere problemas de iluminacao.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);

  } else if (Preto < 600 && Branco >= 300);
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");

    Serial.print("O sensor le branco num valor de...");
    Serial.println(Branco);
    Serial.print("E o preto, num valor de...");
    Serial.println(Preto);

    Serial.println("Troque-o imediatamente.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);
  }
}

//--------------------------------------------------------------------------------------->  COMANDO PARA CHECAGEM DIGITAL;

void Infravermelho::ChecagemDigital()
{
  Serial.println("Sera feita uma analise de qualidade do seu sensor, em relacao a leitura digital.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

//--------------------------------------------------------------------------------------->  LEITURA DO OBJETO;

  Serial.println("Posicione seu sensor em frente a um objeto.");
  Serial.println("Lembre-se que a distancia pode afetar a leitura.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

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

  Objeto = digitalRead(_DO);
  Serial.println("Leitura do objeto feita e armazenada!");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

//--------------------------------------------------------------------------------------->  LEITURA SEM OBJETO;

  Serial.println("Posicione seu sensor sem objeto nenhum em sua frente.");
  Serial.println("Lembre-se que a distancia pode afetar a leitura.");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

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

  SemObjeto = digitalRead(_DO);
  Serial.println("Leitura sem objeto feita e armazenada!");

//--------------------------------------------------------------------------------------->  RESULTADOS;

  Serial.println("Hora dos resultados...");

  MillisAnterior = millis();
  do {} while (millis() - MillisAnterior <= 500);

  if (Objeto = 1 && SemObjeto = 0)
  {
    Serial.println("Seu sensor esta funcionando perfeitamente.");

    Serial.print("Quando ha objeto, o sensor le...");
    Serial.println(Objeto);
    Serial.print("E quando nao ha, o sensor le...");
    Serial.println(SemObjeto);

    Serial.println("Continue usando-o a vontade.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);

  } else
  {
    Serial.println("Seu sensor nao esta funcionando corretamente.");

    Serial.print("Quando ha objeto, o sensor le...");
    Serial.println(Objeto);
    Serial.print("E quando nao ha, o sensor le...");
    Serial.println(SemObjeto);

    Serial.println("Troque-o imediatamente, adapte a programacao, ou considere problemas de distancia.");

    MillisAnterior = millis();
    do {} while (millis() - MillisAnterior <= 1000);
  }
}

