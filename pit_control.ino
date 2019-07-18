#include <SPI.h>
#include <SD.h>
#include <Wire.h>

#define dynlist 8
#define audio 8
#define door 2
#define light 3

int audioval = 0;
int dynstate = 0;
int mcprestate = 0;
int activate = 0;
int actcount = 0;

void setup() {
  Serial.begin(9600);
  pinMode (light, OUTPUT);
pinMode (door, OUTPUT);
pinMode (audio, OUTPUT);
//pinMode (mclist, INPUT);
pinMode (dynlist, INPUT);
  // put your setup code here, to run once:
digitalWrite (light, HIGH);
digitalWrite (door, LOW);
digitalWrite (audio, LOW);

delay(100);
}


void loop() {

  // put your main code here, to run repeatedly:
int mcstate = analogRead(A0); 
//Serial.println(mcstate);
delay(100);
  
if (mcstate >= 500){
  activate = 1;
}
if (activate == 1 && actcount == 0){
     changeTrack();
   

activate = 2;
actcount ++;

}

dynstate = analogRead(dynlist); 

if (dynstate >= 700){
  activate = 2;
}
if (activate == 2  && actcount == 1){
     changeTrack();
     delay (5000);
     digitalWrite (light, LOW);

activate = 3;
actcount ++;
delay (1000);
     digitalWrite (light, HIGH);
digitalWrite (door, HIGH);
     
    
  }
 Serial.println(mcstate);
}


void changeTrack(){
  digitalWrite (audio,LOW);
  delay (100);
   digitalWrite (audio, HIGH);
}
