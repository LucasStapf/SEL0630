#include <Wire.h> // Biblioteca para a comunicação I2C

const int LED_PIN = LED_BUILTIN;
const int POTEN_PIN = A0;
const int I2C_ADDRESS = 0x08;
int potenValue = 0;

/* ---------- Código 02 para leitura do potênciometro ---------- */

void setup() {
  // Endereço no barramento I2C
  Wire.begin(I2C_ADDRESS); 
  
  // Taxa de comunicação - 9600 bits / s
  Serial.begin(9600);

  // Define a função que irá receber solicitações da Rasp
  Wire.onRequest(requestEvent);

  // LED inicialmente desligado e definido como saída
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Delay de 100 ms
  delay(100);
}

void requestEvent() {
  // Realiza a leitura do potênciometro.
  potenValue = analogRead(POTEN_PIN);

  // Envia os dados.
  Wire.write(lowByte(potenValue));
  Wire.write(highByte(potenValue));

  // Printa os valores no console.
  Serial.print("Valor enviado: ");
  Serial.println(potenValue);
}

// /* ---------- Fim do código 02 ---------- */
