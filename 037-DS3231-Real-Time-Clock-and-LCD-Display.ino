#include <DS3231.h>
#include <LiquidCrystal.h>
#include <Servo.h>

Servo my_servo;
DS3231  rtc(SDA, SCL);
bool first_time;
bool second_time;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
void setup() { 
 rtc.begin();
 lcd.begin(16,2);
 
 my_servo.attach(9);
}
void loop() { 
  
 lcd.setCursor(0,0);
 lcd.print("Time:  ");
 lcd.print(rtc.getTimeStr());

  //18：25：02
 first_time = rtc.getTime().hour == 18  && rtc.getTime().min == 36 && rtc.getTime().sec == 2 ;
 //10:36:30
 second_time = rtc.getTime().hour == 10  && rtc.getTime().min == 36 && rtc.getTime().sec == 30;
 
 if(first_time || second_time ){
    my_servo.write(50); // Start turning clockwise
    delay(5000); // Go on turning for the right duration
    my_servo.write(90);  // Stop turning
 }

 
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 
 delay(1000); 
}
