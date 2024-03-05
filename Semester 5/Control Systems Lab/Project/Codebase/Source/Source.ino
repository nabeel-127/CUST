
#define pwm;

int sensorvalue;
int state1 = HIGH;
int state2;
float rps;
float rpm;
unsigned long prevMillis = 0;
unsigned long interval = 200;
unsigned long currentTime;
unsigned long prevTime = 1;
unsigned long diffTime;
int sensorthreshold = 100;







int desiredrpm=2000;





// To store time
unsigned long duration; // To store time difference
unsigned long refresh;
boolean currentstate; // Current state of IR input scan
boolean prevstate;

int ENA = 10;
int IN1 = 12;
int IN2 = 13;

int speed=0;


int dutycycle=0;
int dut=50;
float kp=0.05;
float ki=0.09;
float kd=0.05;
double current_mills=0;
double previous_mills=0;
int pre=0;
int sampling_interval=50;
int err=0;
int int_err=0;
int diff_err=0;

void setup() {
  // put your setup code here, to run once:
//pinMode(pwm,OUTPUT);

pinMode(0,INPUT);


pinMode (ENA, OUTPUT);
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT); 
  
  prevstate = LOW;  

 Serial.begin(9600);
 
 
 
}



void measurerpm()
  {
    sensorvalue = analogRead(0);
   //Serial.println(sensorvalue);
   //delay(1000);
   // read from pin 0
  if(sensorvalue < sensorthreshold)
    state1 = HIGH;
   else
    state1 = LOW;
   
   if(state2!=state1){      //counts when the state change, thats from (dark to light) or 
                            //from (light to dark), remember that IR light is invisible to us.
     if (state2>state1){
       currentTime = micros();   // Get the arduino time in microseconds
       diffTime = currentTime - prevTime;  // calculate the time diff from the last meet-up
       rps = 1000000/diffTime;   // calculate how many rev per second, good to know
       rpm = 60000000/diffTime;  // calculate how many rev per minute
       
       unsigned long currentMillis = millis();
       
       // print to serial at every interval - defined at the variables declaration
       if(currentMillis - prevMillis > interval){ // see if now already an interval long
       prevMillis = currentMillis;       
       Serial.print(rps); Serial.print(" rps  "); Serial.print(rpm); Serial.println(" rpm");
     //delay(100); 
     }
       
       prevTime = currentTime;
     }
     state2 = state1;
   }
      // if( ( millis()-refresh ) >= 100 )
    //{
      // Serial.println(rpm);
       //delay(10);  
    //}

}
 
      // Serial.println("measured rpm");
       //Serial.print(',');
       //Serial.println(rpm); 
       //delay(1000); 
    
    
    
    
 // }
  


void motor()
{// Turn on MOTOR A
digitalWrite(IN2, HIGH);
digitalWrite(IN1, LOW);
// Set Speed from 0-55
analogWrite(ENA,dut);
}













void loop() {
  
  

    //speed = map(rpm, 450, 1940, 30,120 );
  // Serial.println(speed);
   
  motor();
  
  
  // put your main code here, to run repeatedly:
  measurerpm();
current_mills=millis();
if((current_mills-previous_mills)>sampling_interval)
{
  //int dis=rpm;
  //rpm =(rpm*gain)+(pre*(1-gain));
 // Serial.print(rpm);
  //Serial.print(',');
  //Serial.println(dis);
  err= desiredrpm - rpm;
  int_err=  err + int_err;
  diff_err = err- diff_err;
  if(int_err<0)
  int_err=0;
  if(int_err>1024)
  int_err=1024;
  if(diff_err<0)
  diff_err=0;
  if(diff_err>1024)
  diff_err=1024;
   dut = (kp*err)+(ki*int_err)+(kd*diff_err);
  if(dut >1024)
  dut=255;
  if(dut < 30)
  dut=30;
  
  
}
 
 

  
  
}
