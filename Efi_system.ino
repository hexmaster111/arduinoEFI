//EFI System
//By trevor Grusyznski, for the bike
//DONT USE THIS, You will die if you run it with your system, my is special



// Tuneagurables
const int idleThresh = 205;
const int lowThresh  = 410;
const int midThresh  = 750;
const int higThresh  = 1024;
// end configurables

// pins n' stuff
  //outputs
const int enjector     =  3;      // Enjector trigger pin
const int pump         =  4;      // pump trigger pin
  //inputs
const int pumpPot      =  1;      // Pot in A1, A config pot for the pump
const int throtalPos   =  0;      // pot in A0, main throtal input



int enjState = LOW;             // enjector state
int pumpState = LOW;            // Pump state
unsigned long enjPreviousMills = 0;        // will store last time enj was updated
unsigned long pumpPreviousMills = 0;
int enjinterval = 0;               //Throtal enjinterval
int pumpinterval = 0;

void setup() {
  // set the digital pin as output:
  pinMode(enjector, OUTPUT);
  pinMode(pump, OUTPUT);
  
  Serial.begin(9600);      // open the serial port at 9600 bps: for output of the pot    
  
}



void loop() {
  enjinterval = analogRead(throtalPos);    //Value that will goto the blink code
 
  fuleManage();
  

 
//  pumpinterval = analogRead(throtalPos); //something to control the pump with the old code
// Old Pump code that wouldent work right 
//  // Code for pump pulse  
//   unsigned long pumpCurrentMillis = millis(); 
//   if (pumpCurrentMillis - pumpPreviousMills >= pumpinterval) {
//    pumpPreviousMills = pumpCurrentMillis;
//    if (pumpState == LOW) {
//      pumpState = HIGH;
//    } else {
//      pumpState = LOW;
//    }
//    digitalWrite(pump, pumpState);
//  }
//  // End code for pump
  
  // Code for enjector pulse
  unsigned long enjcurrentMills = millis();
  if (enjcurrentMills - enjPreviousMills >= enjinterval) {
    enjPreviousMills = enjcurrentMills;
      if (enjState == LOW) {
        enjState = HIGH;
    } else {
        enjState = LOW;
    }
    digitalWrite(enjector, enjState);
  }
  // End enjector code  
  
}








void fuleManage(){
  //Serial.println("I ran");
  if ((analogRead(pumpPot)) >= idleThresh){
  
  }else if ((analogRead(pumpPot)) <= lowThresh){
  
  }else if ((analogRead(pumpPot)) <= midThresh){
    
  }else if ((analogRead(pumpPot)) <= higThresh){
    
  }else{
    //This is an error if we are here
    Serial.println(analogRead(pumpPot)); //Some data
    // Something here to send some led code
  }
  
  
  
}



