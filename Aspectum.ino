const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A5, OUTPUT);
  Serial.begin(9600);
}

void sound(int a)
{
  int i,j;
  for (i=0; i< 10; i++)
  {
    analogWrite(A5, 255);
      delay(1+a/4);
    analogWrite(A5, 0);
      delay(1+a/4);  
  }
}

void citire()
{
  Serial.println("Citim ...");
  analogWrite(A5, 200);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Time: ");
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}

void loop() {
  citire();
  sound(distance/4);
}
