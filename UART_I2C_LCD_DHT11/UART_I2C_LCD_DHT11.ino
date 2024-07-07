#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Пин, к которому подключен датчик DHT11
#define DHTPIN 4

// Указываем тип датчика DHT11
#define DHTTYPE DHT11

// Инициализация объекта для работы с LCD дисплеем по I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Адрес 0x27, 16 столбцов, 2 строки

// Инициализация объекта для работы с датчиком DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  lcd.init();  // Инициализация LCD дисплея
  lcd.backlight();  // Включаем подсветку LCD дисплея
  dht.begin();  // Инициализация датчика DHT11
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); 

    if (command.equals("write i2c")) {
      lcd.clear(); // Очистка экрана
      Serial.println("Reading DHT11...");

      float humidity = dht.readHumidity(); // Ситывачем влажность
      float temperature = dht.readTemperature(); // Считываем температуру в градусах Цельсия

      if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Ошибка при считывании данных с датчика DHT!");
        lcd.print("Ошибка DHT11");
        delay(5000); 
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Влажность: ");
        lcd.print(humidity);
        lcd.print("%");

        lcd.setCursor(0, 1);
        lcd.print("Температура: ");
        lcd.print(temperature);
        lcd.print("C");

        Serial.print("Влажность: ");
        Serial.print(humidity);
        Serial.print("%, Температура: ");
        Serial.print(temperature);
        Serial.println("C");

        delay(5000); 
      }

      lcd.clear(); // Очистка экрана после отображения данных
    }
  }
}
