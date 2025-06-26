// Ссылка на WIKWO со схемой https://wokwi.com/projects/434842772673642497

#include <Servo.h>

#define SERVO_PIN 3       // пин сервопривода
#define BAUD_RATE 9600    // скорость последовательного порта

Servo myServo;
int currentAngle = 90;
int targetAngle = 90;
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

void setup() {
  Serial.begin(BAUD_RATE);
  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    // проверка ввода
    if (isValidNumber(input)) {
      int newAngle = input.toInt();
      
      // проверка диапазона
      if (newAngle >= MIN_ANGLE && newAngle <= MAX_ANGLE) {
        if (newAngle != currentAngle) {
          targetAngle = newAngle;
          Serial.print("Поворот на: ");
          Serial.print(targetAngle);
          Serial.println("°");
        } else {
          Serial.println("Сервопривод уже в этом положении");
        }
      } else {
        Serial.println("Ошибка: угол должен быть от 0 до 180");
      }
    } else {
      Serial.println("Ошибка: введите число от 0 до 180");
    }
  }
  
  // перемещение привода
  if (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) {
      currentAngle++;
    } else {
      currentAngle--;
    }
    myServo.write(currentAngle);
    delay(10);
  }
}

// ввелось ли число
bool isValidNumber(String str) {
  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return str.length() > 0;
}
