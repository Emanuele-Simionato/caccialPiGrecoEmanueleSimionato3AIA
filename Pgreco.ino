#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Bi1 = 10;
int B2 = 9;
int B3 = 8;
int B4 = 7;
int tempo = 5000;
int tI = 0;
int tN = 0;
int turni = 0;
int pM = 0;
byte Cuore[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte PiGreco[8] = {
  B00000,
  B11111,
  B01010,
  B01010,
  B01010,
  B01010,
  B10010,
  B00000
};
byte Radice[8] = {
  B00000,
  B00111,
  B00100,
  B00100,
  B10100,
  B11000,
  B10000,
  B00000

};
void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, Cuore);
  lcd.createChar(1, PiGreco);
  lcd.createChar(2, Radice);
  lcd.begin(16, 2);
  pinMode(Bi1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
bool caso1() {
  lcd.setCursor(4, 1);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  tI = millis();
  while(digitalRead(Bi1) == LOW && digitalRead(B2) == LOW && digitalRead(B3) == LOW && digitalRead(B4) == LOW){}
  tN = millis();
  if (digitalRead(B2) == HIGH || digitalRead(B3) == HIGH || digitalRead(B4) == HIGH) {
    delay(200);
    return false;
  }
  else {
    if(tN - tI > tempo){
      delay(200);
      return false;
    }
    else{
      delay(200);
    return true;
    }
    
  }
}
bool caso2() {
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(1));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  tI = millis();
  while(digitalRead(Bi1) == LOW && digitalRead(B2) == LOW && digitalRead(B3) == LOW && digitalRead(B4) == LOW){}
  tN = millis();
  if (digitalRead(Bi1) == HIGH || digitalRead(B3) == HIGH || digitalRead(B4) == HIGH) {
    delay(200);
    return false;
  }
  else {
    if(tN - tI > tempo){
      delay(200);
      return false;
    }
    else{
      delay(200);
    return true;
    }
  }
}
bool caso3() {
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(1));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  tI = millis();
  while(digitalRead(Bi1) == LOW && digitalRead(B2) == LOW && digitalRead(B3) == LOW && digitalRead(B4) == LOW){}
  tN = millis();
  if (digitalRead(Bi1) == HIGH || digitalRead(B2) == HIGH || digitalRead(B4) == HIGH) {
    delay(200);
    return false;
  }
  else {
    if(tN - tI > tempo){
      delay(200);
      return false;
    }
    else{
      delay(200);
    return true;
    }
  }
}
bool caso4() {
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(10, 1);
  lcd.write(byte(1));
  tI = millis();
  while(digitalRead(Bi1) == LOW && digitalRead(B2) == LOW && digitalRead(B3) == LOW && digitalRead(B4) == LOW){}
  tN = millis();
  if (digitalRead(Bi1) == HIGH || digitalRead(B2) == HIGH || digitalRead(B3) == HIGH) {
    delay(200);
    return false;
  }
  else {
    if(tN - tI > tempo){
      delay(200);
      return false;
    }
    else{
          delay(200);
    return true;
    }
  }
}
void istruzioni(){
  lcd.clear();
  lcd.print("Per vincere");
  delay(1000);
  lcd.clear();
  lcd.print("devi prendere il");
  delay(1000);
  lcd.clear();
  lcd.write(byte(1));
  delay(1000);
  lcd.clear();
  lcd.print("Evita la");
  delay(1000);
  lcd.clear();
  lcd.write(byte(2));
  delay(1000);
  lcd.clear();
  lcd.print("Hai 3 vite");
  delay(1000);
  lcd.clear();
  lcd.write(byte(0));
  delay(1000);
  lcd.clear();
  lcd.print("Buona fortuna");
  delay(1000);
  lcd.clear();
}
void start() {
  lcd.print("CACCIA AL");
  lcd.setCursor(10, 0);
  lcd.write(byte(1));
  while (digitalRead(Bi1) == LOW) {}
}
void loop() {
  // put your main code here, to run repeatedly:
  start();
  istruzioni();
  delay(1000);
  lcd.clear();
  int vite = 3;
  lcd.setCursor(15, 0);
  lcd.write(byte(0));
  lcd.setCursor(14, 0);
  lcd.write(byte(0));
  lcd.setCursor(13, 0);
  lcd.write(byte(0));
  while (vite != 0)
  {
    if (vite == 2) {
      lcd.setCursor(13, 0);
      lcd.write(" ");
    }
    if (vite == 1) {
      lcd.setCursor(14, 0);

      lcd.write(" ");
    }
    int r = random(1, 5);
    if (r == 1)
    {
      if (caso1() == false) {
        vite--;
      }
      else{
        tempo = tempo - 100;
      }

    }
    else if (r == 2)
    {
      if (caso2() == false) {
        vite--;
      }
      else{
        tempo = tempo - 100;
      }
    }
    else if (r == 3)
    {
      if (caso3() == false) {
        vite--;
      }
      else{
        tempo = tempo - 100;
      }
    }
    else if (r == 4)
    {
      if (caso4() == false) {
        vite--;
      }
      else{
        tempo = tempo - 100;
      }
    }
    turni++;
  }
  turni--;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HAI PERSO!");
  delay(1500);
  lcd.clear();
  lcd.print("Sei resistito");
  lcd.setCursor(0,1);
  lcd.print(turni);
  lcd.setCursor(5,1);
  lcd.print("turni");
  delay(1500);
  lcd.clear();
  if( turni > pM){
    lcd.print("Nuovo record");
    lcd.setCursor(0,1);
    lcd.print(turni);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
  }
  else{
    lcd.print("Riprova un'altra");
    lcd.setCursor(0,1);
    lcd.print("volta");
    delay(1000);
    lcd.print(pM);
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0,0);
}
