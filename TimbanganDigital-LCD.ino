//library 
#include <HX711.h>
#include <LiquidCrystal_I2C.h>

//pin
const int id_cel = 2;
const int id_sck = 4;
HX711 scale;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  //start lcd
  lcd.print("Timbangan");
  lcd.setCursor(4,1);
  lcd.print("Digital");
  delay(2000);
  //start hx711
  scale.begin(id_cel,id_sck);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);

  if(scale.is_ready()){
    scale.set_scale();
    lcd.print("Remove weights");
    Serial.println("tare remove weights...");
    delay(3000);

    lcd.clear();
    scale.tare();
    lcd.print("Tare done");
    Serial.println("tare done...");
    delay(2000);

    lcd.clear();
    lcd.print("Now put weight");
    Serial.println("now put weight..");
    delay(2000);

    lcd.clear();
    long reading = scale.get_units(10);
    lcd.setCursor(0,0);
    lcd.print("Berat terukur :");
    lcd.setCursor(0,1);
    lcd.print(reading/419.8);
    Serial.println(reading/419.8);
  }
  delay(5000);
}
