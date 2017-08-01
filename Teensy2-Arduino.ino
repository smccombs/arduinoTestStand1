/*
  Board: Teensy 2.0

  AirOnTestStand V1.1
  This is the MCU control programming to operate 12 unit test rack for small air purifier devices using LDR light sensors to detect how many times a test unit has turned on and off, then turns on fans to exhaust the air inside the cabinet.

  CMDs
    dump (displays all units current count and light levels)
    clear 0 (clears the counter for unit 0-12)
  
  1.1 - created 7-28-17 - By Shawn McCombs
 */

const int lightInHigh = 700;
const int lightInLow = 250;

String SerialInString;
int SerialInInt;
int Unit;

const int light0InPin = A0;
const int light1InPin = A1;
const int light2InPin = A2;
const int light3InPin = A3;
const int light4InPin = A4;
const int light5InPin = A5;
const int light6InPin = A6;
const int light7InPin = A7;
const int light8InPin = A8;
const int light9InPin = A9;
const int light10InPin = A10;
const int light11InPin = A11;

const int fan0OutPin = 0;
const int fan1OutPin = 1;
const int fan2OutPin = 2;
const int fan3OutPin = 3;
const int fan4OutPin = 4;
const int fan5OutPin = 5;
const int fan6OutPin = 6;
const int fan7OutPin = 7;
const int fan8OutPin = 8;
const int fan9OutPin = 9;
const int fan10OutPin = 10;
const int fan11OutPin = 23;

int light0In = 0;
int light1In = 0;
int light2In = 0;
int light3In = 0;
int light4In = 0;
int light5In = 0;
int light6In = 0;
int light7In = 0;
int light8In = 0;
int light9In = 0;
int light10In = 0;
int light11In = 0;

int fan0Out = LOW;
int fan1Out = LOW;
int fan2Out = LOW;
int fan3Out = LOW;
int fan4Out = LOW;
int fan5Out = LOW;
int fan6Out = LOW;
int fan7Out = LOW;
int fan8Out = LOW;
int fan9Out = LOW;
int fan10Out = LOW;
int fan11Out = LOW;

int light0Count = 0;
int light1Count = 0;
int light2Count = 0;
int light3Count = 0;
int light4Count = 0;
int light5Count = 0;
int light6Count = 0;
int light7Count = 0;
int light8Count = 0;
int light9Count = 0;
int light10Count = 0;
int light11Count = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(light0InPin, INPUT_PULLUP ); 
  pinMode(light1InPin, INPUT_PULLUP ); 
  pinMode(light2InPin, INPUT_PULLUP ); 
  pinMode(light3InPin, INPUT_PULLUP ); 
  pinMode(light4InPin, INPUT_PULLUP ); 
  pinMode(light5InPin, INPUT_PULLUP ); 
  pinMode(light6InPin, INPUT_PULLUP ); 
  pinMode(light7InPin, INPUT_PULLUP ); 
  pinMode(light8InPin, INPUT_PULLUP ); 
  pinMode(light9InPin, INPUT_PULLUP ); 
  pinMode(light10InPin, INPUT_PULLUP ); 
  pinMode(light11InPin, INPUT_PULLUP );
  
  pinMode(fan0OutPin, OUTPUT);
  pinMode(fan1OutPin, OUTPUT);
  pinMode(fan2OutPin, OUTPUT);
  pinMode(fan3OutPin, OUTPUT);
  pinMode(fan4OutPin, OUTPUT);
  pinMode(fan5OutPin, OUTPUT);
  pinMode(fan6OutPin, OUTPUT);
  pinMode(fan7OutPin, OUTPUT);
  pinMode(fan8OutPin, OUTPUT);
  pinMode(fan9OutPin, OUTPUT);
  pinMode(fan10OutPin, OUTPUT);
  pinMode(fan11OutPin, OUTPUT);
}

void loop() {

  // Serial interface
  if (Serial.available() > 0) {
    SerialInString = Serial.readStringUntil(' ');
  
    // Program interface
    if (SerialInString == "clear") {
      SerialInInt = Serial.parseInt();
      Unit = SerialInInt;
      
      switch (Unit) {
        case 0:
          light0Count = 0;
          break;
        case 1:
          light1Count = 0;
          break;
        case 2:
          light2Count = 0;
          break;
        case 3:
          light3Count = 0;
          break;
        case 4:
          light4Count = 0;
          break;
        case 5:
          light5Count = 0;
          break;
        case 6:
          light6Count = 0;
          break;
        case 7:
          light7Count = 0;
          break;
        case 8:
          light8Count = 0;
          break;
        case 9:
          light9Count = 0;
          break;
        case 10:
          light10Count = 0;
          break;
        case 11:
          light11Count = 0;
          break;
      }
    }
    
    // Display system variables
    if (SerialInString == "dump") {
      Serial.println("Unit: 0 \t Count: " + String(light0Count) + "\t LightSensor: " + String(light0In)  + "\t Fan: " + fan0Out);
      Serial.println("Unit: 1 \t Count: " + String(light1Count) + "\t LightSensor: " + String(light1In)  + "\t Fan: " + fan1Out);
      Serial.println("Unit: 2 \t Count: " + String(light2Count) + "\t LightSensor: " + String(light2In)  + "\t Fan: " + fan2Out);
      Serial.println("Unit: 3 \t Count: " + String(light3Count) + "\t LightSensor: " + String(light3In)  + "\t Fan: " + fan3Out);
      Serial.println("Unit: 4 \t Count: " + String(light4Count) + "\t LightSensor: " + String(light4In)  + "\t Fan: " + fan4Out);
      Serial.println("Unit: 5 \t Count: " + String(light5Count) + "\t LightSensor: " + String(light5In)  + "\t Fan: " + fan5Out);
      Serial.println("Unit: 6 \t Count: " + String(light6Count) + "\t LightSensor: " + String(light6In)  + "\t Fan: " + fan6Out);
      Serial.println("Unit: 7 \t Count: " + String(light7Count) + "\t LightSensor: " + String(light7In)  + "\t Fan: " + fan7Out);
      Serial.println("Unit: 8 \t Count: " + String(light8Count) + "\t LightSensor: " + String(light8In)  + "\t Fan: " + fan8Out);
      Serial.println("Unit: 9 \t Count: " + String(light9Count) + "\t LightSensor: " + String(light9In)  + "\t Fan: " + fan9Out);
      Serial.println("Unit: 10 \t Count: " + String(light10Count) + "\t LightSensor: " + String(light10In)  + "\t Fan: " + fan10Out);
      Serial.println("Unit: 11 \t Count: " + String(light11Count) + "\t LightSensor: " + String(light11In)  + "\t Fan: " + fan11Out);
    }
  }
  
  light0In = analogRead(light0InPin);
  light1In = analogRead(light1InPin);
  light2In = analogRead(light2InPin);
  light3In = analogRead(light3InPin);
  light4In = analogRead(light4InPin);
  light5In = analogRead(light5InPin);
  light6In = analogRead(light6InPin);
  light7In = analogRead(light7InPin);
  light8In = analogRead(light8InPin);
  light9In = analogRead(light9InPin);
  light10In = analogRead(light10InPin);
  light11In = analogRead(light11InPin);
  
  // Unit 0
    
    if (light0In >= lightInHigh && fan0Out == LOW) {
      fan0Out = HIGH;
      light0Count++;
      
      Serial.print("0");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light0Count);
      Serial.print("\t ");
      Serial.println(light0In);
    }
    
    if (light0In <= lightInLow && fan0Out == HIGH) {
      fan0Out = LOW;
      light0Count++;
      
      Serial.print("0");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light0Count);
      Serial.print("\t ");
      Serial.println(light0In);
    }
  
  // Unit 1
    
    if (light1In >= lightInHigh && fan1Out == LOW) {
      fan1Out = HIGH;
      light1Count++;
      
      Serial.print("1");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light1Count);
      Serial.print("\t ");
      Serial.println(light1In);
    }
    
    if (light1In <= lightInLow && fan1Out == HIGH) {
      fan1Out = LOW;
      light1Count++;
      
      Serial.print("1");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light1Count);
      Serial.print("\t ");
      Serial.println(light1In);
    }
  
  // Unit 2
    
    if (light2In >= lightInHigh && fan2Out == LOW) {
      fan2Out = HIGH;
      light2Count++;
      
      Serial.print("2");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light2Count);
      Serial.print("\t ");
      Serial.println(light2In);
    }
    
    if (light2In <= lightInLow && fan2Out == HIGH) {
      fan2Out = LOW;
      light2Count++;
      
      Serial.print("2");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light2Count);
      Serial.print("\t ");
      Serial.println(light2In);
    }
  
  // Unit 3
    
    if (light3In >= lightInHigh && fan3Out == LOW) {
      fan3Out = HIGH;
      light3Count++;
      
      Serial.print("3");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light3Count);
      Serial.print("\t ");
      Serial.println(light3In);
    }
    
    if (light3In <= lightInLow && fan3Out == HIGH) {
      fan3Out = LOW;
      light3Count++;
      
      Serial.print("3");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light3Count);
      Serial.print("\t ");
      Serial.println(light3In);
    }
  
  // Unit 4
    
    if (light4In >= lightInHigh && fan4Out == LOW) {
      fan4Out = HIGH;
      light4Count++;
      
      Serial.print("4");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light4Count);
      Serial.print("\t ");
      Serial.println(light4In);
    }
    
    if (light4In <= lightInLow && fan4Out == HIGH) {
      fan4Out = LOW;
      light4Count++;
      
      Serial.print("4");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light4Count);
      Serial.print("\t ");
      Serial.println(light4In);
    }
  
  // Unit 5
    
    if (light5In >= lightInHigh && fan5Out == LOW) {
      fan5Out = HIGH;
      light5Count++;
      
      Serial.print("5");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light5Count);
      Serial.print("\t ");
      Serial.println(light5In);
    }
    
    if (light5In <= lightInLow && fan5Out == HIGH) {
      fan5Out = LOW;
      light5Count++;
      
      Serial.print("5");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light5Count);
      Serial.print("\t ");
      Serial.println(light5In);
    }
  
  // Unit 6
    
    if (light6In >= lightInHigh && fan6Out == LOW) {
      fan6Out = HIGH;
      light6Count++;
      
      Serial.print("6");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light6Count);
      Serial.print("\t ");
      Serial.println(light6In);
    }
    
    if (light6In <= lightInLow && fan6Out == HIGH) {
      fan6Out = LOW;
      light6Count++;
      
      Serial.print("6");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light6Count);
      Serial.print("\t ");
      Serial.println(light6In);
    }
  
  // Unit 7
    
    if (light7In >= lightInHigh && fan7Out == LOW) {
      fan7Out = HIGH;
      light7Count++;
      
      Serial.print("7");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light7Count);
      Serial.print("\t ");
      Serial.println(light7In);
    }
    
    if (light7In <= lightInLow && fan7Out == HIGH) {
      fan7Out = LOW;
      light7Count++;
      
      Serial.print("7");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light7Count);
      Serial.print("\t ");
      Serial.println(light7In);
    }
  
  // Unit 8
    
    if (light8In >= lightInHigh && fan8Out == LOW) {
      fan8Out = HIGH;
      light8Count++;
      
      Serial.print("8");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light8Count);
      Serial.print("\t ");
      Serial.println(light8In);
    }
    
    if (light8In <= lightInLow && fan8Out == HIGH) {
      fan8Out = LOW;
      light8Count++;
      
      Serial.print("8");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light8Count);
      Serial.print("\t ");
      Serial.println(light8In);
    }
  
  // Unit 9
    
    if (light9In >= lightInHigh && fan9Out == LOW) {
      fan9Out = HIGH;
      light9Count++;
      
      Serial.print("9");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light9Count);
      Serial.print("\t ");
      Serial.println(light9In);
    }
    
    if (light9In <= lightInLow && fan9Out == HIGH) {
      fan9Out = LOW;
      light9Count++;
      
      Serial.print("9");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light9Count);
      Serial.print("\t ");
      Serial.println(light9In);
    }
  
  // Unit 10
    
    if (light10In >= lightInHigh && fan10Out == LOW) {
      fan10Out = HIGH;
      light10Count++;
      
      Serial.print("11");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light10Count);
      Serial.print("\t ");
      Serial.println(light10In);
    }
    
    if (light10In <= lightInLow && fan10Out == HIGH) {
      fan10Out = LOW;
      light10Count++;
      
      Serial.print("11");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light10Count);
      Serial.print("\t ");
      Serial.println(light10In);
    }
  
  // Unit 11
    
    if (light11In >= lightInHigh && fan11Out == LOW) {
      fan11Out = HIGH;
      light11Count++;
      
      Serial.print("11");
      Serial.print("\t ");
      Serial.print("Off");
      Serial.print("\t ");
      Serial.print(light11Count);
      Serial.print("\t ");
      Serial.println(light11In);
    }
    
    if (light11In <= lightInLow && fan11Out == HIGH) {
      fan11Out = LOW;
      light11Count++;
      
      Serial.print("11");
      Serial.print("\t ");
      Serial.print("On");
      Serial.print("\t ");
      Serial.print(light11Count);
      Serial.print("\t ");
      Serial.println(light11In);
    }

  digitalWrite(fan0OutPin, fan0Out);
  digitalWrite(fan1OutPin, fan1Out);
  digitalWrite(fan2OutPin, fan2Out);
  digitalWrite(fan3OutPin, fan3Out);
  digitalWrite(fan4OutPin, fan4Out);
  digitalWrite(fan5OutPin, fan5Out);
  digitalWrite(fan6OutPin, fan6Out);
  digitalWrite(fan7OutPin, fan7Out);
  digitalWrite(fan8OutPin, fan8Out);
  digitalWrite(fan9OutPin, fan9Out);
  digitalWrite(fan10OutPin, fan10Out);
  digitalWrite(fan11OutPin, fan11Out);

  delay(2);
}
