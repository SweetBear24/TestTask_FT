int LED = 13;
void setup() {
    Serial.begin(115200); // Инициализация UART с baud rate 115200
    pinMode(LED, OUTPUT); // Настройка встроенного светодиода на вывод
}

void loop() {
    if (Serial.available() > 0) { // Если есть данные для чтения
        String command = Serial.readStringUntil('\n'); // Считываем строку до символа '\n'

        if (command.equals("led1 on")) {
            digitalWrite(LED, HIGH); // Включаем светодиод
            Serial.println("LED ON"); // Отправляем подтверждение обратно по UART
        } else if (command.equals("led1 off")) {
            digitalWrite(LED, LOW); // Выключаем светодиод
            Serial.println("LED OFF"); // Отправляем подтверждение обратно по UART
        } else {
            Serial.println("Unknown command"); // Отправляем сообщение об ошибке, если команда не распознана
        }
    }
}
