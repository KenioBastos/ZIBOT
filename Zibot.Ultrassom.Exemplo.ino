/*
  Zibot.Ultrassom.h - Biblioteca para pinagem, leitura e avaliação de sensores ultrassônicos.
  Criada por Kênio Bastos, dia 23 de setembro de 2017.
  Lançada para domínio público.
*/

// ATENÇÃO! PARA PLENO ENTENDIMENTO DO CÓDIGO, CONSIDERE LER NOSSO MANUAL DE INSTRUÇÕES!

#include <Zibot.Ultrassom.h>

// Declaração do sensor ultrassônico, assim como pinagem.

Ultrassom SensorUltrassom(9, 10, 11, 12);

// Declaração da variável responsável pela escolha de qual dos dois comandos é executado.

char Comando;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // 'Comando' recebe um sinal do monitor serial.

  Serial.println ("Escolha qual comando quer executar. Checagem ou Leitura?");
  Serial.println ("Pressione 'l' para Leitura, e 'c' para Checagem.");

  Comando = Serial.read();

  // Leitura;

  if (Comando = 'l')
  {
    SensorUltrassom.LeituraUltrassom();
  } 

  // Checagem;
  
  else if (Comando = 'c')
  {
    SensorInfravermelho.ChecagemUltrassom();
  }
}
