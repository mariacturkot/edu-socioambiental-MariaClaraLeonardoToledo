#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Botões e saídas
const int botaoMedio = 6;    // Nível médio
const int botaoAlto = 7;     // Nível alto
const int buzzer = 8;
const int led = 9;

void setup() {
  pinMode(botaoMedio, INPUT);
  pinMode(botaoAlto, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Nivel da Agua:");

  Serial.begin(9600); // Inicia a comunicação com o Monitor Serial
  Serial.println("Monitor Serial iniciado.");
}

void loop() {
  // Leitura dos botões
  bool nivelMedio = digitalRead(botaoMedio);
  bool nivelAlto = digitalRead(botaoAlto);

  lcd.setCursor(0, 1); // Linha 2 do LCD

  if (!nivelMedio && !nivelAlto) {
    lcd.print("CAIXA VAZIA! ");
    Serial.println("CAIXA VAZIA!");
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

  } else if (nivelMedio && !nivelAlto) {
    lcd.print("Nivel: MEDIO      ");
    Serial.println("Nivel: MEDIO");
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);

  } else if (nivelAlto && !nivelMedio) {
    lcd.print("Nivel: ALTO       ");
    Serial.println("Nivel: ALTO");
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);

  } else if (nivelMedio && nivelAlto) {
    lcd.print("Nivel: CHEIO      ");
    Serial.println("Nivel: CHEIO");
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  delay(300);
}
