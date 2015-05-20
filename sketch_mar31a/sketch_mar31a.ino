int ledPin = 13;
int delayPeriod = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);
  //delayPeriod = delayPeriod + 100;
  //if (delayPeriod > 3000)
  //{
  //  delayPeriod = 100;
  //}

}
