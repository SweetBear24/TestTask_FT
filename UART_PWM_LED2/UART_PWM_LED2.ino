const int LED2 = 13; // Пин для управления встроенным светодиодом
const int fadeDelay = 10; // Задержка в миллисекундах между изменениями яркости
bool led2State = false; // Переменная для хранения состояния светодиода

void setup() {
    Serial.begin(115200); // Инициализация UART с baud rate 115200
    pinMode(LED2, OUTPUT); // Настройка встроенного светодиода на вывод
}

void loop() {
    if (Serial.available() > 0) { // Если есть данные для чтения
        String command = Serial.readStringUntil('\n'); // Считываем строку до символа '\n'

        if (command.equals("led2 on")) {
          
          led2State = true; // Устанавливаем состояние светодиода в ВКЛ
          for (int brightness = 0; brightness <= 255; brightness++) {
            softwarePWM(LED2, brightness); // Устанавливаем яркость светодиода
            delay(fadeDelay); // Задержка
          }; // Включаем светодиод
          Serial.println("LED2 ON"); // Отправляем подтверждение обратно по UART
        
        } else if (command.equals("led2 off")) {

            led2State = false; // Устанавливаем состояние светодиода в ВЫКЛ
            for (int brightness = 255; brightness >= 0; brightness--) {
              softwarePWM(LED2, brightness); // Устанавливаем яркость светодиода
              delay(fadeDelay); // Задержка
            }
            Serial.println("LED2 OFF"); // Отправляем подтверждение обратно по UART
  
        } else {
            Serial.println("Unknown command"); // Отправляем сообщение об ошибке, если команда не распознана
        }
    }
        // Поддерживаем текущее состояние светодиода
    if (led2State) {
        softwarePWM(LED2, 255); // Светодиод включен на максимальную яркость
    } else {
        softwarePWM(LED2, 0); // Светодиод выключен
    }
}

void softwarePWM(int pin, int brightness) {
  int onTime = map(brightness, 0, 255, 0, 255); // Время включения
  int offTime = 255 - onTime; // Время выключения

  digitalWrite(pin, HIGH); // Включаем светодиод
  delayMicroseconds(onTime); // Ждем время включения

  digitalWrite(pin, LOW); // Выключаем светодиод
  delayMicroseconds(offTime); // Ждем время выключения
}
