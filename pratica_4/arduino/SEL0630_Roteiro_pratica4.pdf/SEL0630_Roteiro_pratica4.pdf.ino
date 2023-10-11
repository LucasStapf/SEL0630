#include <Wire.h> // Biblioteca para a comunicação I2C

const int LED_PIN = LED_BUILTIN;
const int POTEN_PIN = A0;
const int I2C_ADDRESS = 0x8;
int potenValue = 0;

/* ---------- Código 01 para testar a conexão do Arduino com a Rasp ---------- */

void setup() {
  // Endereço no barramento I2C
  Wire.begin(I2c_ADDRESS); 

  // Define a função que irá ser chamada ao receber dados
  Wire.onReceive(receiveEvent);

  // LED inicialmente desligado e definido como saída
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Delay de 100 ms
  delay(100);
}

// Função que é chamada quando o Arduino receber dados
void receiveEvent(int howMany) {
  while (Wire.available()) { // Enquanto houver dados no barramento
    char c = Wire.read();
    digitalWrite(LED_PIN, c);
  }
}

/* ---------- Fim do código 01 ---------- */

/* ---------- Código 02 para leitura do potênciometro ---------- */

void setup() {
  // Endereço no barramento I2C
  Wire.begin(0x8); 
  
  // Taxa de comunicação - 9600 bits / s
  Serial.begin(9600);

  // Define a função que irá ser chamada ao receber dados
  Wire.onReceive(receiveEvent);

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

// Função que é chamada quando o Arduino receber dados
void receiveEvent(int howMany) {
  while (Wire.available()) { // Enquanto houver dados no barramento
    char c = Wire.read();
    digitalWrite(LED_PIN, c);
  }
}

void requestEvent() {
  // Realiza a leitura do potênciometro.
  potenValue = analogRead(POTEN_PIN);

  // Envio da leitura
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(lowByte(potenValue));
  Wire.endTransmission(I2C_ADDRESS);

  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(highByte(potenValue));
  Wire.endTransmission(I2C_ADDRESS);

  Serial.print("Valor do potenciometro (LB): ");
  Serial.println(lowByte(potenValue));

  Serial.print("Valor do potenciometro (HB): ");
  Serial.println(HighByte(potenValue));
}

/* ---------- Fim do código 02 ---------- */
