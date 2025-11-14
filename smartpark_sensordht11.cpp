#include "DHT.h"

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LDR_PIN A0
#define DHT_PIN 8
#define DHTTYPE DHT11

#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 7
#define BUZZER 5

long duracao;
int distancia;
float temperatura;
int luminosidade;

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
   Serial.begin(9600);

   pinMode(TRIG_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);
   pinMode(LED_VERDE, OUTPUT);
   pinMode(LED_AMARELO, OUTPUT);
   pinMode(LED_VERMELHO, OUTPUT);
   pinMode(LED_AZUL, OUTPUT);
   pinMode(BUZZER, OUTPUT);

   dht.begin();

   Serial.println("Sistema de Estacionamento Inteligente Iniciado");
}

void loop() {

   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);
   duracao = pulseIn(ECHO_PIN, HIGH);
   distancia = duracao * 0.034 / 2;

   luminosidade = analogRead(LDR_PIN);

   if (luminosidade <= 600) {
      digitalWrite(LED_AZUL, HIGH);
   } else {
      digitalWrite(LED_AZUL, LOW);
   }

   temperatura = dht.readTemperature();

   if (isnan(temperatura)) {
      Serial.println("Erro ao ler o sensor DHT11!");
      temperatura = 0;
   }

   Serial.print("Distancia: ");
   Serial.print(distancia);
   Serial.print(" cm | Temperatura: ");
   Serial.print(temperatura);
   Serial.print(" °C | Luminosidade: ");
   Serial.println(luminosidade);

   if (temperatura > 40) {
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AMARELO, LOW);
      digitalWrite(LED_VERMELHO, HIGH);
      tone(BUZZER, 1000);
      Serial.println("ALERTA: Temperatura Alta!");
   } else {
      noTone(BUZZER);

      if (distancia > 30) {
         digitalWrite(LED_VERDE, HIGH);
         digitalWrite(LED_AMARELO, LOW);
         digitalWrite(LED_VERMELHO, LOW);
         noTone(BUZZER);
      } else if (distancia > 15 && distancia <= 30) {
         digitalWrite(LED_VERDE, LOW);
         digitalWrite(LED_AMARELO, HIGH);
         digitalWrite(LED_VERMELHO, LOW);
         tone(BUZZER, 800, 150);
         delay(300);
      } else if (distancia > 5 && distancia <= 15) {
         digitalWrite(LED_VERDE, LOW);
         digitalWrite(LED_AMARELO, LOW);
         digitalWrite(LED_VERMELHO, HIGH);
         tone(BUZZER, 900, 100);
         delay(300);
      } else if (distancia <= 5) {
         digitalWrite(LED_VERDE, LOW);
         digitalWrite(LED_AMARELO, LOW);
         digitalWrite(LED_VERMELHO, HIGH);
         tone(BUZZER, 900);
         delay(300);
      }
   }

   delay(300);
}
