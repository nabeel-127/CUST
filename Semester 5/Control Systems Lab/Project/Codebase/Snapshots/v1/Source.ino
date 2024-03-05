

int count = 0;
volatile int counti = 0;
long int RPS = 0, RPM = 0, freq = 0;
int kp, ki, kd;
int Vref, Vo, E, int_E = 0, diff_E = 0, duty;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(A0, INPUT);   //Vref
  pinMode(3, INPUT);    //Feedback (Interrupt)
  pinMode(9, OUTPUT);   //Controller Output
  attachInterrupt(digitalPinToInterrupt(1), myISR, RISING );
  Serial.begin(9600);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  //count = 0;
  counti = 0;
  //sei();
  attachInterrupt(digitalPinToInterrupt(1), myISR, RISING);

  delay(1000);
  
  Serial.println(counti);
  Serial.println();
  
  //count = counti;
  detachInterrupt(digitalPinToInterrupt(1));
  //cli();

  
  //Serial.println(RPS);

  
  /*
  RPS = count / 4;
  RPM = (count * 60) / 4;
  freq = RPS;

  Vref = analogRead(A0);
  Vo = map(freq, 0, 2400, 0, 5);
  
  E = Vref - Vo;
  
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
  
  counti = 0;
  */
}


void myISR()
{
  counti++;
}
