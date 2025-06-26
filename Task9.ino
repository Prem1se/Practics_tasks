// Ссылка на WOKWI со схемой https://wokwi.com/projects/434838082468118529

#define PHOTO_PIN A0
#define CLOSED_LED_PIN 9
#define OPENED_LED_PIN 5
#define THRESHOLD 512       // порог освещенности
#define DELAY_TIME 5000     // время delay в мс

void setup() {
  pinMode(CLOSED_LED_PIN, OUTPUT);
  pinMode(OPENED_LED_PIN, OUTPUT);
  Serial.begin(9600);
  
  // дверь закрыта
  digitalWrite(CLOSED_LED_PIN, HIGH);
  digitalWrite(OPENED_LED_PIN, LOW);
  Serial.println("Система запущена. Дверь закрыта.");
}

void loop() {
  int lightValue = analogRead(PHOTO_PIN);
  
  if (lightValue > THRESHOLD) {
    // дверь открыта
    digitalWrite(CLOSED_LED_PIN, LOW);
    digitalWrite(OPENED_LED_PIN, HIGH);
    Serial.println("Дверь открыта!");
    
    delay(DELAY_TIME);
    
    // проверка состояния снова после ожидания
    lightValue = analogRead(PHOTO_PIN);
    if (lightValue > THRESHOLD) {
      Serial.println("Дверь остается открытой");
    } else {
      digitalWrite(CLOSED_LED_PIN, HIGH);
      digitalWrite(OPENED_LED_PIN, LOW);
      Serial.println("Дверь закрылась");
    }
  }
  
  delay(10);
}
