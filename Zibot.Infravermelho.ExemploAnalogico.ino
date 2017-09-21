/*
  Zibot.IR.h - Biblioteca para pinagem, leitura e avaliação de sensores infravermelhos.
  Criada por Kênio Bastos, dia 28 de agosto de 2017.
  Lançada para domínio público.
*/

#include <Zibot.Infravermelho.h>

// Declaração do sensor infravermelho, assim como pinagem. Porta de sinal: A5, alimentação positiva (VCC): 10 e alimentação negativa (GND): 11.

Infravermelho SensorIR_Analog(A5, 0, 10, 11);

// Declaração da variável responsável pela escolha de qual dos dois comandos é executado.

char Comando;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  // 'Comando' recebe um sinal do monitor serial.

  Comando = Serial.read();

  /*
    LeituraAnalogica  -> (1);
    ChecagemAnalogica -> (2);
    Comandos para (1) exibir os valores lidos pelo sensor e (2) para fazer uma avaliação da leitura.
    Digitando "p" no monitor serial, o comando (1) para e o (2) começa.
  */

  do {
    SensorIR_Analog.LeituraAnalogica();
  } while (Comando != 'p');

  SensorIR_Analog.ChecagemAnalogica();

}

