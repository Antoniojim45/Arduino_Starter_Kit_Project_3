/** 
 * Arduino Starter Kit
 * project 3:  Love-O-Meter
 * 
 * this project is called Love-o-Meter. this project measures the temprature and turns on specific LED's 
 * depending on the temprature. this is the project where we will introduce analog input, and using 
 * a serial monitor. 
 * @Author Antonio Jimenez
 * @Version 1 (5/3/2020)
 */

// these are constants; THESE DO NOT CHANGE WHILE RUNNING
const int sensorPin = A0;
const int baseLineTemp = 20.0; // change this to that of the room temprature

/**
 * this is the setup of the program which set up the connection of the serial monitor.
 * we then use a for loop to setup the pins and the state that they are in. 
 */
void setup(){
  Serial.begin(9600); // open a serial port

  // this is a smart way to set up the pins. 
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    
    }
  }

  /**
   * this is the loop method of the program. the basic functionallity is that it reads the 
   * sensor pin and returns the analog value it detects. we then place the analog value in a 
   * variable "sensorVal". we then find the voltage using a calculation then find the temprature.
   * then we reach a set of conditional statements where depending on the temprature a series of lights 
   * turn on. 
   */
  void loop(){
    int sensorVal = analogRead(sensorPin);

    Serial.print("Sensor value: ");
    Serial.print(sensorVal);

    // convert the ADC reading to Voltage 
    float voltage = (sensorVal/1024.0)*5.0;
    
    Serial.print(", Volts: ");
    Serial.print(voltage);
    Serial.print(", degrees C: ");
    
    // calculate the temprature
    float temp = (voltage - 0.5)*100; 
    
    Serial.println(temp);

    // this is a set of conditional statments that turn on depending on the temprature. 
    if(temp < baseLineTemp + 2){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      }
     else if(temp >= baseLineTemp + 2 && temp < baseLineTemp + 4){
      digitalWrite(2, HIGH);
      digitalWrite(3,  LOW);
      digitalWrite(4,  LOW);
      }
     else if(temp >= baseLineTemp + 4 && temp < baseLineTemp + 6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4,  LOW);
      }
     else if(temp >= baseLineTemp + 6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      }
     delay(1);
    
    }
