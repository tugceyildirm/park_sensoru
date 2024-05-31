#define echoPin 12
#define trigPin 13
#define led1 2
#define led2 3
#define buzzer 6

void setup(){
  pinMode(echoPin,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop(){
  int olcum=mesafe();

  if(olcum != 0){
    digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
    if(olcum>20 && olcum<40){
      digitalWrite(led1,HIGH); 
      digitalWrite(led2,LOW);
      digitalWrite(buzzer, HIGH);

    }
     else if(olcum<20){
       digitalWrite(led1,HIGH); 
       digitalWrite(led2,HIGH);
       digitalWrite(buzzer, HIGH);
  
    }else{
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(buzzer,LOW);

    }

  }
}
int mesafe(){
  long sure, uzaklik;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echoPin,HIGH);
  uzaklik=sure/58.2;
  delay(50);
  return(uzaklik);

}