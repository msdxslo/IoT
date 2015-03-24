int i = 0;

int ledPin = 3;
int buttonPin = 4;

int tempPin = 0; 

int tempRaw;
float tempC;

void setup() {
  
  // set-up serial port
  Serial.begin(9600);
  
  // initialize pins
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  analogReference(INTERNAL);
}

void loop() {

  tempRaw = analogRead(tempPin);
  tempC = tempRaw / 9.31;
   
  if (tempC >= 30) {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  String jsonValue = "";
  jsonValue += "{" ;
  jsonValue += "\"deviceID\":\"";
  jsonValue.concat(0);
  jsonValue += "\",";
  jsonValue += "\"timestamp\":\"";
  jsonValue.concat(i++);
  jsonValue += "\",";
  jsonValue += "\"valueFloat\":\"";
  jsonValue.concat(tempC);
  jsonValue += "\",";
  jsonValue += "\"valueInt\":\"";
  jsonValue.concat(0);
  jsonValue += "\",";
  jsonValue += "\"valueString\":\"";
  jsonValue += "\"";
  jsonValue += "}";
  
  Serial.println(jsonValue);
  
  // Serial.print("Temp RAW:   ");
  // Serial.println(tempRaw);
  // Serial.print("Temp Value: ");
  // Serial.println(tempC);
  
  delay(500);
}
