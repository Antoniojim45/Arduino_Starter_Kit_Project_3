// Arduino Starter Kit 
// project 3, Love-O-Meter
// Version 2 

const int sensorPin = A0;
const int baseLineTemp = 21.0;

void setup(){
  Serial.begin(9600); // open a serial port

  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    
    }
  }
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
