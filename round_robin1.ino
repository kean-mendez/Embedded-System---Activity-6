// C++ code
//Round Robin


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
  round_robin(); 
}

void round_robin(){
  int time_quantum = 2000;
  int burst_time[6] = {8000, 2000, 7000, 3000, 5000, 4000};
  int pin[6] = {13, 12, 11, 10, 9, 8};
  int ready_queue[6];
  int arrival_time[6] = {0, 5000, 1000, 6000, 8000, 5000};
  int time = 0;
  
  int temp;
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (arrival_time[i] < arrival_time[j]){
      	temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  
  for (int i=0; i<6; i++){
  	digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;
  
  }
  
}