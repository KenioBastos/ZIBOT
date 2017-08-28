/*
  Zibot.IR.h - Biblioteca para pinagem e leitura de sensores infravermelhos.
  Criada por Kênio Bastos, dia 28 de agosto de 2017.
  Lançada para domínio público.

  Essa biblioteca foi baseada no módulo do Arduino, modelo TRCT 5000, um sensor ótico reflexivo;
  Dessa maneira, é aconselhável o uso com este equipamento, em específico!
*/

#include <Zibot.IR.h>

/*
  Com o comando "Infravermelho", você define as portas utilizadas por seu sensor;
  A estrutura do comando consiste em "Infravermelho VARIAVEL_DO_SEU_SENSOR_AQUI(AQUI_VOCÊ_DEFINE_AS_PORTAS)";
  Na definição das portas, primeiro vem a porta analógica, em seguida, a porta digital, a alimentação positiva (VCC) e por fim a alimentação negativa (GND);
  Faremos a pinagem de dois sensores, para exemplificar.
*/

/*
  Para o primeiro sensor, faremos uma leitura digital, portanto utilizamos a porta 8 como porta digital de sinal.
  A porta 9 foi usada como alimentação negativa (GND) e a porta 10 como alimentação positiva (VCC);
  Colocamos a porta analógica como 0 (zero), pois não a utilizaremos.
*/

Infravermelho SensorIR_Digital(0, 8, 9, 10);

/*
  Para o segundo sensor, utilizamos a porta A5 como nossa porta analógica de sinal do sensor;
  A porta 11 foi usada como alimentação negativa (GND) e a porta 12 como alimentação positiva (VCC);
  Colocamos a porta digital como 0 (zero), pois não a utilizaremos.
*/

Infravermelho SensorIR_Analog(A5, 0, 11, 12);

void setup()
{}

void loop()
{

  /*
    Com o comando LeituraAnalogica(), os valores lidos pelo seu sensor serão exibidos no monitor serial do Arduino (canto superior direito);
    A estrutura do comando consiste em "VARIAVEL_DO_SEU_SENSOR_AQUI.LeituraAnalogica";
    Como o nome explica, esta leitura lida com sinal analógico, numa faixa de 0 a 1023.
  */

  SensorIR_Analog.LeituraAnalogica();

  /*
    Com o comando LeituraDigital(), os valores lidos pelo seu sensor serão exibidos no monitor serial do Arduino (canto superior direito);
    A estrutura do comando consiste em "VARIAVEL_DO_SEU_SENSOR_AQUI.LeituraDigital";
    Como o nome explica, esta leitura lida com sinal digital, podendo exibir apenas 0 (zero) ou 1 (um).
  */

  SensorIR_Digital.LeituraDigital();

}

