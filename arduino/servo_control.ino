#include <Servo.h>

Servo directionServo; 
Servo intensityServo; 

void setup() {
    directionServo.attach(9); 
    intensityServo.attach(10); 
    Serial.begin(9600); 
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n'); 
        if (command.startsWith("D:")) { 
            int angle = command.substring(2).toInt();
            directionServo.write(angle); 
        } else if (command.startsWith("I:")) { 
            int speed = command.substring(2).toInt();
            intensityServo.write(map(speed, 0, 40, 0, 180));
        }
    }
}
