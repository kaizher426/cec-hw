#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
int analogPin=0;
int x=0;
float Vout=0;
float R=10000; //Known Resistor value in Ohm
float resistor=0;
float buffer=0;
void setup()
{
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("----OHM METER---");
}
void loop()
{
x=analogRead(analogPin);
buffer=x*5;
Vout=(buffer)/1024.0;
buffer=(5/Vout)-1;
resistor=R*buffer;
lcd.setCursor(0,1);
lcd.print("R = ");
lcd.print(resistor);
lcd.print(" Ohm");
delay(3000);
}
