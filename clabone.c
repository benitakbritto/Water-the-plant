//LED through digital pin 13
//moisture sensor through analog pin A1
//val of moisture sensor < 800 , then water
//feed me, thank you ---> write to the serial port

int mSensor = A1;
int ledPin = 13;

void blink(int pin);
bool dry(int pin);
bool borderline(int pin);

void setup()
{
/*
* Initialisation code here
*/

/*
* Tells the arduino to start sending and receiving serial
* data at the speed bits per second. You usually set speed
* to 9600
*/
  Serial.begin(9600);
  /*
  * Tells the arduino whether the digital pin is an input or output,
  * mode can be either INPUT or OUTPUT
  */
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  while(dry(mSensor) || borderline(mSensor))
  {
    /*
    * Prints data to the serial port. val can be any data type
    */
    Serial.println("Water me!");
    /*
    * LED will blink if moisture content
    * is at the border
    */
    if(borderline(mSensor))
    {
        blink(ledPin);
    }
    else
    {
      /*
      * LED will be ON
      */
      digitalWrite(ledPin, HIGH);
    }
  }
  /*
  * Moisture content is high
  */
  Serial.println("Thank you!");
  /*
  * LED will be OFF
  */
  digitalWrite(ledPin, LOW);

}


void blink(int pin)
{
  /*
  * Writes a value to a digital pin, value can be either
  * HIGH or LOW
  */
  digitalWrite(pin, HIGH);
  /*
  * Pauses the program for interval milliseconds
  */
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}


bool dry(int pin)
{
  /*
  * Moisture content is low i.e.
  * Reads the value from an analog pin. The return value is
  * between 0 and 1023
  */
  if(analogRead(pin) < 600)
  {
    return true;
  }
  return false;
}


bool borderline(int pin)
{
  if(analogRead(pin) == 600)
  {
    return true;
  }
  return false;
}
/*
Arduino Functions

void pinMode(int pin, int mode);

int digitalRead(int pin);

void digitalWrite(int pin, int value);

int analogRead(int pin);

void analogWrite(int pin, int value);

void Serial.begin(long speed);

void Serial.println(val);

void delay(long interval);

*/
