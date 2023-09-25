//library 
#include "HX711.h"

//pin
#define Dout 2
#define CLK 4

HX711 berat;

void timbangUlang(){
  //mengscale ulang
  berat.set_scale(); 
  delay(5000);
  //mulai dari 0
  berat.tare();
  Serial.println("Masukan berat benda");
  delay(5000);
}

void setup() {
  Serial.begin(115200);
  berat.begin(Dout, CLK);
  Serial.println("---Tekan R untuk reset---");
  Serial.println();
}

void loop() {
  timbangUlang();

  long baca = berat.get_units(10);
  Serial.print("Berat: ");
  Serial.print(baca/419.8);
  Serial.println(" kg");
  delay(3000);

  Serial.println("Kosongkan timbangan");
  delay(2000);

  if(Serial.available()){
    char charReset = Serial.read();
    if(charReset == 'R'){
      timbangUlang();
      Serial.println("Berhasil reset");
    }
  }
  delay(1000);
}
