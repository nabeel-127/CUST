
unsigned long startTime = 0, currentTime = 0, sampleTime = 1000;
int lastState = LOW, currentState;
int count = 0;
int RPS = 0, RPM = 0, freq = 0;
int Vref, Vo, E;
int int_E = 0, diff_E = 0, duty;
int kp = 0, ki = 0, kd = 0;

void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(A0, INPUT);   //Vref
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
      lastState = 1;
    }
    currentTime = millis() - startTime;
  }

  
  RPS = count / 4;
  RPM = (count * 60) / 4;
  freq = RPS;

  Serial.print("MaxRpm:");
  Serial.println(RPM);
  
  /*
  Vref = analogRead(A0);
  Vo = map(freq, 0, 2400, 0, 5);
  
  E = Vref - Vo;

  Serial.print("E:");
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
  if (duty > 1000)
  {
    duty = 120;
  }
  else if (duty < 30)
  {
    duty = 30;
  }
  
  analogWrite(3, duty);
  */
  
}
