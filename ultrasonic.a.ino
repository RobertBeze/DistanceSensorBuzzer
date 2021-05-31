#define TrigPin 8
#define EchoPin 9
#define MaxDistance 400
#define BuzzPin 13
#define rosu 10
#define verde 11
#define dist 100
#define timer 1500

uint16_t distance=0, duration=0;
uint16_t contor = 0;

void setup() {
  pinMode(BuzzPin,OUTPUT);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(rosu,OUTPUT);
  pinMode(verde,OUTPUT);
}

void sonar()
{
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  duration = pulseIn(EchoPin,HIGH);
  distance = (duration / 2)* 0.0343;
}

void loop() {
  digitalWrite(verde,HIGH);
  sonar();
  
  if(distance<dist){
    delay(1000);
    contor += 1;
  }

  if(contor == timer)
  {
    digitalWrite(verde,LOW);
    delay(20);
    digitalWrite(rosu,HIGH);
    while(distance < dist){
      sonar();
      tone(BuzzPin,2000);
      delay(250);
      noTone(BuzzPin);
      delay(250);
    }
    digitalWrite(rosu,LOW);
    delay(20);
    digitalWrite(verde,HIGH);
    contor = 0;
  }
  /*
  Serial.print("Distance = ");
  if(distance >=400 || distance <=2){
    Serial.println("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    delay(1500);
  }
  delay(500);\
  */
  
}
