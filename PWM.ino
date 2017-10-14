int AHI = 7;
int BHI = 8;
int ALI = 6;
int BLI = 5;
int D = 4;


void setup() {
  // wyjścia
  pinMode(AHI, OUTPUT);
  pinMode(ALI, OUTPUT);
  pinMode(BHI, OUTPUT);
  pinMode(BLI, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  digitalWrite(D, LOW);

}
// przełączanie sygnałów parami według schematu układu
void lewo() {
  digitalWrite(ALI, LOW);
  digitalWrite(BHI, LOW); //brak sygnału podawanego na ALI i BHI
  for (int i=0; i<=255; i++) //PWM na BLI i AHI, przyspieszanie silnika
  {
    analogWrite(AHI, i);
    analogWrite(BLI, i);
    delay(20);
  }
  delay(1000);
  for (int i=255; i>=0; i--) //zwalnianie silnika
  {
    analogWrite(AHI, i);
    analogWrite(BLI, i);
    delay(20);
  }
  delay(1000);
}
void prawo() {
  digitalWrite(AHI, LOW);
  digitalWrite(BLI, LOW); //brak sygnału podawanego na AHI i BLI
  for (int i=0; i<=255; i++) //PWM na BHI i ALI, przyspieszanie silnika
  {
    analogWrite(BHI, i);
    analogWrite(ALI, i);
    delay(20);
  }
  delay(1000);
  for (int i=255; i>=0; i--) //zwalnianie silnika
  {
    analogWrite(BHI, i);
    analogWrite(ALI, i);
    delay(20);
  }
  delay(1000);
}
//przełączanie sygnałów według znalezionej tabeli prawdy
void lewotab() {
  digitalWrite(AHI, HIGH);
  digitalWrite(BHI, LOW);
  digitalWrite(ALI, LOW);
  for (int i=0; i<=255; i++) //PWM na BLI, przyspieszanie silnika
  {
    analogWrite(BLI, i);
    delay(20);
  }
  delay(1000);
  for (int i=255; i>=0; i--) //zwalnianie silnika
  {
    analogWrite(BLI, i);
    delay(20);
  }
  delay(1000);
}
void prawotab() {
  digitalWrite(AHI, LOW);
  digitalWrite(BHI, HIGH);
  digitalWrite(BLI, LOW);
  for (int i=0; i<=255; i++) //PWM na ALI, przyspieszanie silnika
  {
    analogWrite(ALI, i);
    delay(20);
  }
  delay(1000);
  for (int i=255; i>=0; i--) //zwalnianie silnika
  {
    analogWrite(ALI, i);
    delay(20);
  }
  delay(1000);
}

