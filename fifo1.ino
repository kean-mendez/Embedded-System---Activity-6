// C++ code
//FIFO

void setup()
{
  pinMode(13, OUTPUT); //set port 13 to output
  pinMode(12, OUTPUT); //set port 12 to output
  pinMode(11, OUTPUT); //set port 11 to output
  pinMode(10, OUTPUT); //set port 10 to output
  pinMode(9, OUTPUT); //set port 9 to output
  pinMode(8, OUTPUT); //set port 8 to output
}

void loop()
{
  first_come_first_serve(); //calling the function.
}

void first_come_first_serve(){
  int time[6] = {1000, 2000, 4000, 7000, 3000, 5000};
  int count = 0; 
  for (int i=13; i>=8; i--){
  	digitalWrite(i, HIGH); //Turn the LED On
    delay(time[count]); //Delay.
    digitalWrite(i, LOW); //Turn the LED Off
    count++; //Increment count.
  }
}