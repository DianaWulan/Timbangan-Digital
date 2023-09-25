//esp32, loadcell 5kg, Hx711

//library 
#include "HX711.h"

//pin
#define Dout 2
#define CLK 4

HX711 berat;

void setup() {
  Serial.begin(115200);
  berat.begin(Dout, CLK);
  Serial.println("---Tekan R untuk reset---");
  Serial.println();
}

void loop() {
  //mengscale ulang
  berat.set_scale(); 
  delay(5000);
  //mulai dari 0
  berat.tare();
  Serial.println("Masukan berat benda");
  delay(10000);

  long baca = berat.get_units(10);
  Serial.print("Berat: ");
  Serial.print(baca/419.8);//kalibrasi
  Serial.println(" kg");

  if(Serial.available()){
    char charReset = Serial.read();
    if(charReset == 'R'){
      berat.tare();
      Serial.println("Berhasil reset");
    }
  }
  delay(1000);
}
