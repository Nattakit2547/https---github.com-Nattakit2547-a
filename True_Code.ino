#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

#define button1 15
#define button2 16
#define button3 17
#define button4 18
#define button5 19

 
Servo myservo1; //////////กำหนดตัวแปร servo
Servo myservo2; //////////กำหนดตัวแปร servo
Servo myservo3; //////////กำหนดตัวแปร servo
Servo myservo4;

Servo myservo5;

LiquidCrystal_I2C lcd(0x3F, 20, 4);



int sensor = 2; // ตัวแปรของเครื่องรับเหรียญทำงานที่ขา 2
int i = 0;
int k = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int kc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int s = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้
int sc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้
int j = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้
int jc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้
int a = 0; // ตัวแปรสำหรับเก็บผลรวมจำนวนเงินทั้งหมด สามารถเปลี่ยนได้
int i10 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int i5 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้  
int i1 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้

int z = 0; /////// ให้ตัวแปร i = 0 จะไปใช้ใน loop for
int pen = 1; /////// ให้ตัวแปร pen = 1 จะไปใช้ใน loop for


void setup() {
  pinMode(sensor, INPUT);

  
  attachInterrupt(0, doCounter, FALLING);
  Serial.begin(9600);
  lcd.backlight();
  lcd.begin();
  lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");

pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);


  myservo1.attach(5); //////กำหนดขา servo 1
myservo1.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo2.attach(9); //////กำหนดขาservo 2
myservo2.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo3.attach(7); //////กำหนดขาservo 3
myservo3.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo4.attach(8); //////กำหนดขาservo 4
myservo4.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo5.attach(13); //////กำหนดขาservo 5







}
boolean isCounter = false;
int count = 0;
void loop() {
  if (isCounter == true) {
    isCounter = false;
    //Serial.println(count);
    delay(500);
  }
  if (i != 1000 && count != 0 ) {
    i = i + 1;
  }
  if (i == 1000) {
    i = 0;
    if (count == 10) {
      i10 = i10 + 1;
      k = i10 * 10; // มูลค่าเหรียญ
      kc = 10; // ขนิดเหรียญ
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(kc);Serial.println(" บาท");
      Serial.println();
    }
    if (count == 5) {
      i5 = i5 + 1;
      j = i5 * 5;
      jc = 5;
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(jc);Serial.println(" บาท");
      Serial.println();
    }
    if (count == 1) {
      i1 = i1 + 1;
      s = i1 * 1;
      sc = 1;
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(sc);Serial.println(" บาท");
      Serial.println();
    }
    Serial.print("   รวมชนิดเหรียญ 10 บาท: ");
    Serial.print(i10);Serial.println(" เหรียญ");
    Serial.print("   รวมชนิดเหรียญ  5 บาท: ");
    Serial.print(i5);Serial.println(" เหรียญ");
    Serial.print("   รวมชนิดเหรียญ  1 บาท: ");
    Serial.print(i1);Serial.println(" เหรียญ");
    Serial.println();
    a = s + k + j;
    Serial.print("         ยอดเงินรวมทั้งหมด: ");
    lcd.clear();  
    lcd.setCursor(1,1);
    Serial.print(a);Serial.println(" บาท");
    lcd.print(a);  lcd.print("     BATH");
    Serial.println();
    count  = 0;
  }

  if(digitalRead(button1) == LOW){
    Serial.println("button1 is pressed");
    delay(300);
}
  if(digitalRead(button2) == LOW){
    Serial.println("button2 is pressed");
    delay(300);
}
 if(digitalRead(button3) == LOW){
    Serial.println("button3 is pressed");
    delay(300);
}

if(digitalRead(button4) == LOW){
    Serial.println("button4 is pressed");
    delay(300);
}

if(digitalRead(button5) == LOW){
    Serial.println("button5 is pressed");
    delay(300);
}


Sw_1();
Sw_2();
Sw_3();
Sw_4();
Sw_5();
}




void doCounter() {
  isCounter = true;
  count++;
}

void Sw_1(){ ///// สร้าง functionSw_1
//ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button1) == LOW && (a > 6)) {
Serial.println("button1 is pressed");
delay(300);
Serial.print(a);
for(z = 0 ; z < pen ; z ++){
  myservo1.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(5000); ///ดีเลย์ สองวิ
a = a - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
i = 0;
k = 0; 
kc = 0; 
s = 0; 
sc = 0; 
j = 0; 
jc = 0; 
a = 0; 
i10 = 0; 
i5 = 0; 
i1 = 0; 
myservo1.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_1");
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("THANK YOU");
delay(5000);
lcd.clear();
lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");
}
}//// void Sw_1



void Sw_2(){ ///// สร้าง functionSw_1
//ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button2) == LOW && (a > 6)) {
Serial.println("button2 is pressed");
delay(300);
Serial.print(a);
for(z = 0 ; z < pen ; z ++){
  myservo3.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(5000); ///ดีเลย์ สองวิ
a = a - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
i = 0;
k = 0; 
kc = 0; 
s = 0; 
sc = 0; 
j = 0; 
jc = 0; 
a = 0; 
i10 = 0; 
i5 = 0; 
i1 = 0; 
myservo3.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_2");
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("THANK YOU");
delay(5000);
lcd.clear();
lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");
}
}//// void Sw_2






void Sw_3(){ ///// สร้าง functionSw_1
//ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button3) == LOW && (a > 6)) {
Serial.println("button3 is pressed");
delay(300);
Serial.print(a);
for(z = 0 ; z < pen ; z ++){
  myservo4.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(5000); ///ดีเลย์ สองวิ
a = a - 10 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
i = 0;
k = 0; 
kc = 0; 
s = 0; 
sc = 0; 
j = 0; 
jc = 0; 
a = 0; 
i10 = 0; 
i5 = 0; 
i1 = 0; 
myservo4.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_3");
  
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("THANK YOU");
delay(5000);
lcd.clear();
lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");
}
}//// void Sw_3





void Sw_4(){ ///// สร้าง functionSw_1
//ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button4) == LOW && (a > 6)) {
Serial.println("button4 is pressed");
delay(300);
Serial.print(a);
for(z = 0 ; z < pen ; z ++){
  myservo2.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(5000); ///ดีเลย์ สองวิ
a = a - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
i = 0;
k = 0; 
kc = 0; 
s = 0; 
sc = 0; 
j = 0; 
jc = 0; 
a = 0; 
i10 = 0; 
i5 = 0; 
i1 = 0; 
myservo2.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_4");
  
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("THANK YOU");
delay(5000);
lcd.clear();
lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");
}
}//// void Sw_4



void Sw_5(){ ///// สร้าง functionSw_1
//ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button5) == LOW && (a > 11)) {
Serial.println("button5 is pressed");
delay(300);
Serial.print(a);
for(z = 0 ; z < pen ; z ++){
  myservo5.writeMicroseconds(1300);
delay(500); // หน่วงเวลา 2000ms
myservo5.writeMicroseconds(1450); // สั่งให้ Servo หยุด
delay(2000); // หน่วงเวลา 2000ms

myservo5.writeMicroseconds(2600);
delay(450); // หน่วงเวลา 2000ms
myservo5.writeMicroseconds(1450); // สั่งให้ Servo หยุด
delay(2000); // หน่วงเวลา 2000ms
a = a - 12 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo5 180");

}/// for
i = 0;
k = 0; 
kc = 0; 
s = 0; 
sc = 0; 
j = 0; 
jc = 0; 
a = 0;  
i10 = 0; 
i5 = 0; 
i1 = 0; 


Serial.println("End process Sw_5");

lcd.clear();  
  
lcd.setCursor(0,1);
lcd.print("THANK YOU");
delay(2000);
lcd.clear();
lcd.setCursor(5, 0); // จอ lcd จะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.print("INSERT COIN"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
  lcd.setCursor(0, 1);
  lcd.print("PEN 7 BATH");
  lcd.setCursor(0, 2);
  lcd.print("Book 12 BATH");
  lcd.setCursor(5, 3);
  lcd.print("!<BK.TECH>!");
}
}//// void Sw_5
