/* Copy right for personal use only and alterations for the public good
 *  Higher Order Thinkers
 *  
 *  Please copy this header with alterations and publish on our site.
 *  
 *  This is dedicated to a war hero missing in action: Edward Snowden
 */
 
#define LIGHT 5

int delaylength = 20;

void setup() {

  Serial.begin(9600);
  //establish motor direction toggle pins
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B

  // PWM
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  
  randomSeed(analogRead(4));  
  pinMode(5, OUTPUT);
  
}

// This turns the rev 3 stepper motor shield counter clockwise with the delays specified
   
void turnLeft(int steps){
  int randDelayMotor = random(30, 300);
   delaylength = randDelayMotor;
   int adc;
   int i;
   
  adc = map(randDelayMotor, 30, 300, 210, 254);
  analogWrite(LIGHT, adc);

  for (i=0;i<steps;i++) {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A
  
  
  delay(delaylength);
  
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylength);
  
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A
  
  delay(delaylength);
    
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylength);
  }
}

void turnRight(int steps)
{
  int i;
  int adc;
  int randDelayMotor = random(30, 300);
  adc = map(randDelayMotor, 30, 300, 210, 254); // maps to the light sequence voltages
  analogWrite(LIGHT, adc);
  delaylength = randDelayMotor;
  
  for (i=0;i<steps;i++) {
  digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A
  
  delay(delaylength);

    digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylength);

 digitalWrite(9, LOW);  //ENABLE CH A
  digitalWrite(8, HIGH); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A
  
  delay(delaylength);

  
  digitalWrite(9, HIGH);  //DISABLE CH A
  digitalWrite(8, LOW); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylength);
  
  }
}

void loop() {

  int randDelayBetween = random (500,5000);
  int randSteps = random(400,1000);

  Serial.println("Left");
  turnLeft(randSteps);
  delay(randDelayBetween);

  Serial.println("Right");
  randSteps = random(400,1000);
  randDelayBetween = random (500,5000);

   turnRight(randSteps);
   delay(randDelayBetween);

}

