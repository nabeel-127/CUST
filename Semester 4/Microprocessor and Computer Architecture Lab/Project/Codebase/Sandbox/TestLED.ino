void setup() 
{
  // setting DDRB as output
  DDRB = B00100000;
}
 
void loop()
{
  PORTB = B00100000; // Turn on LED
  delay(5000);
  PORTB = B00000000; // Turn off LED
  delay(5000);
}
