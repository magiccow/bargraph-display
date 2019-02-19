
/* To drive a bargraph LED display. All anodes are connected to digital inputs 2..11
 *  each with a 2k resistor to common ground.
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=2; i<12; i++)
    pinMode(i, OUTPUT);
}

void dot(int x){
  static int last=0;

  if(last!=0)
    digitalWrite(last, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(x+2, HIGH);   // turn the LED on (HIGH is the voltage level)
  last = x+2;
  
}


void bar(int x){
  static int last=0;

  if (x<last)
    digitalWrite(last+2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(x+2, HIGH);   // turn the LED on (HIGH is the voltage level)
  last = x;
  
}




// the loop function runs over and over again forever
void loop() {
  static int counter=0;
  static int up=false;
  static int iteration=0;

  if(up){
    counter = counter + 1;
    if(counter==10){
      up = false;
      delay(200);
    }
  }else{
    counter = counter - 1;
    if(counter==-1){
      up = true;
      ++iteration;      
      delay(200);
    }
  }
  
  if(iteration%2)
    dot(counter);
  else
    bar(counter);
  
  delay(75);                       
}
