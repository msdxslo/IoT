//
// LED counter - 8-part LED matrix shows numbers from 0 to 9
//

// first and last pins
// don't use pin 0 and 1, as those are tx and rx for serial
int pin0 = 2;
int pin7 = 9;

int number[10][8] = {
// segments: 
// b  a  f  g  e  d  c  dp
  {0, 0, 0, 1, 0, 0, 0, 1}, // 0
  {0, 1, 1, 1, 1, 1, 0, 0}, // 1
  {0, 0, 1, 0, 0, 0, 1, 1}, // 2
  {0, 0, 1, 0, 1, 0, 0, 0}, // 3
  {0, 1, 0, 0, 1, 1, 0, 1}, // 4
  {1, 0, 0, 0, 1, 0, 0, 0}, // 5
  {1, 0, 0, 0, 0, 0, 0, 1}, // 6
  {0, 0, 1, 1, 1, 1, 0, 0}, // 7
  {0, 0, 0, 0, 0, 0, 0, 1}, // 8
  {0, 0, 0, 0, 1, 0, 0, 0}, // 9
};

int num;

// displays number on LED display
void numberShow(int num) {                    
  for (int pin = pin0; pin <= pin7; pin++) {
    digitalWrite(pin, number[num][pin - pin0]);
  }
}

void setup() {
  
  Serial.begin(9600);

  for (int num = pin0; pin <= pin7; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }

  num = 0;
  
}

void loop() {
  
  numberShow(num);

  num++;
  if (num > 9) num = 0;

  Serial.println(num);
  delay(1000); 
  
}
