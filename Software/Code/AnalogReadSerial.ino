/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int led = 6;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5; 
// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  analogWrite(led, brightness);

  float mv = ( sensorValue/1024.0)*5000; 
  //float mv =(sensorValue - 0.5) / 100.0;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();

  if(cel>=176){
     brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
   }else{
        brightness = 0;
    }

 
  
  delay(500);        // delay in between reads for stability
}
