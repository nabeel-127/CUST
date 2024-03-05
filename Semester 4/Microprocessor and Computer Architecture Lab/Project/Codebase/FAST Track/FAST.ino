/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS1 13      // left sensor_1
#define LS2 12     // left sensor_2
#define RS1 2      // right sensor_1
#define RS2 4      // right sensor_2
#define S_mid 7      // mid sensor

#define LM1 11    // left motor
#define LM2 10    // left motor
#define RM1 9    // right motor
#define RM2 6     // right motor

void setup()
{
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(S_mid, INPUT);
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

}

void loop(){
if((digitalRead(LS2)==LOW) && (digitalRead(LS1)==HIGH) && (digitalRead(S_mid)==HIGH) && (digitalRead(RS1)==HIGH) && (digitalRead(RS2)==LOW))    // Condition_1 Forward
{    
    MoveForward();
  }
  if((digitalRead(LS2)==LOW) && (digitalRead(LS1)==LOW) && (digitalRead(S_mid)==LOW) && (digitalRead(RS1)==LOW) && (digitalRead(RS2)==HIGH))
  {
    TurnRight();
  }
  if((digitalRead(LS2)==LOW) && (digitalRead(LS1)==LOW) && (digitalRead(S_mid)==LOW) && (digitalRead(RS1)==HIGH) && (digitalRead(RS2)==HIGH))
  {
    TurnRight();
  }
    if((digitalRead(LS2)==LOW) && (digitalRead(LS1)==LOW) && (digitalRead(S_mid)==HIGH) && (digitalRead(RS1)==HIGH) && (digitalRead(RS2)==HIGH))
  {
    TurnRight();
  }
 
   if((digitalRead(LS2)==HIGH) && (digitalRead(LS1)==LOW) && (digitalRead(S_mid)==LOW) && (digitalRead(RS1)==LOW) && (digitalRead(RS2)==LOW))  // RIGHT
  {
    TurnLeft();
  }
  if((digitalRead(LS2)==HIGH) && (digitalRead(LS1)==HIGH) && (digitalRead(S_mid)==LOW) && (digitalRead(RS1)==LOW) && (digitalRead(RS2)==LOW))  // RIGHT
  {
    TurnLeft();
  }
    if((digitalRead(LS2)==HIGH) && (digitalRead(LS1)==HIGH) && (digitalRead(S_mid)==HIGH) && (digitalRead(RS1)==LOW) && (digitalRead(RS2)==LOW))  // RIGHT
  {
    TurnLeft();
  }
}


void MoveForward()
{
    analogWrite(LM1, 140);
    analogWrite(LM2, 0);
    analogWrite(RM1, 140);
    analogWrite(RM2, 0);
    delay(20);
}

void TurnRight()
{
    analogWrite(LM1, 130);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 70);
    delay(30);  
}

void TurnLeft()
{
    analogWrite(LM1, 0);
    analogWrite(LM2, 70);
    analogWrite(RM1, 130);  
    analogWrite(RM2, 0);
    delay(30);
}

void Stop()
{
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    delay(20);
}
