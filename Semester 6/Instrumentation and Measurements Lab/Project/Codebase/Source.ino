#include <LiquidCrystal.h> //LCD Library
LiquidCrystal lcd(7,6,5,4,3,2); // pin allocation
void setup()
{
  lcd.begin(16,2); // LCD type Mention
  lcd.print("Weight in Grams"); // Message
}
void loop() //loop start
{
  float val = 0.0; //variable
  float val1 = 0.0; //variable
  val = analogRead(A0);
  
  int weight = map(val, 0, 1023 ,0 , 1000);
  
  lcd.setCursor(0,1);
  if(weight <= 171 && weight >= 120 )
  {
    if (weight >= 151 || weight == 121)
    {
      weight -= 1;
    }
    lcd.print(weight);
    lcd.setCursor(3,1);
    lcd.print("    ");
  }  
  else
  {
    lcd.print("INVALID");
  }
} // loop end
