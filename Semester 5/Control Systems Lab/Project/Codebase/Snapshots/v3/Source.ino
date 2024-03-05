
unsigned long startTime = 0, currentTime = 0, sampleTime = 1000;
int lastState = LOW, currentState;
int count = 0;
float RPS = 0, RPM = 0, freq = 0;
float Vref, RPMref, Vo, E;
float int_E = 0, diff_E = 0, duty;

float kp = 1, ki = 0, kd = 0;

float out = 0, percent_duty = 0;

void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(A1, INPUT);   //Vref
  pinMode(4, INPUT);    //Feedback (Interrupt)
  pinMode(3, OUTPUT);   //Controller Output
  Serial.begin(9600);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:

  count = 0;
  currentTime = 0;
  startTime = millis();
  while (currentTime <= sampleTime)
  {
    currentState = digitalRead(4);
    if (!currentState)
    {
      if (lastState)
      {
        count++;
        lastState = LOW;
      }
    }
    else
    {
      lastState = HIGH;
    }
    currentTime = millis() - startTime;
  }

  RPS = (count / 4) * (1000 / sampleTime);
  RPM = RPS * 60;
  freq = RPS;

  Serial.print("RPM: ");
  Serial.println(RPM);
  


  
  

  
  //Vref = analogRead(A1);
  Vref = 511;
  
  Serial.print("Vref: ");
  Serial.println(Vref);  
  Serial.print("A1: ");
  Serial.println(analogRead(A1)); 
  
  //Vo = map(freq, 0, 2100, 0, 5);
  RPMref = map(Vref, 0, 1023, 0, 2100);

  Serial.print("RPMref: ");
  Serial.println(RPMref);
  
  //E = Vref - Vo;
  E = RPMref - RPM;
  
  Serial.print("E: ");
  Serial.println(E);
  
  int_E = E + int_E;
  if (int_E > 1024)
  {
    int_E = 1024;
  }
  else if (int_E < 0)
  {
    int_E = 0;
  }

  diff_E = E - diff_E;
  if (diff_E < 0)
  {
    diff_E = 0;
  }
  else if (diff_E > 1024)
  {
    diff_E = 1024;
  }

  duty = (kp * E) + (ki * int_E) + (kd * diff_E);

  Serial.print("Duty: ");
  Serial.println(duty);
  
  /*
  if (duty > 1000)
  {
    duty = 120;
  }
  else if (duty < 30)
  {
    duty = 30;
  }
  */

  //Serial.print("Duty2: ");
  //Serial.println(duty);


  //out = map(E, 0, 2243, 0, 100);
  percent_duty = map(duty, 0, 2100, 0, 100);
  //percent_duty = (duty / 2100) * 100;

  Serial.print("percent_duty: ");
  Serial.println(percent_duty);
  
  out = out + 2.50 * percent_duty;

  if (out >= 256)
  {
    out = 255;
  }
  if (out < 0)
  {
    out = 0;
  }
  
  /*
  if ((percent_duty > 0) && (out < 255))
  {
    out = out + 10;
  }
  if ((percent_duty < 0) && (out > 0))
  {
    out = out - 10;
  }
  */
  
  Serial.print("Out: ");
  Serial.println(out);
  analogWrite(3, out);
  
  Serial.println();
  Serial.println();
  
}
