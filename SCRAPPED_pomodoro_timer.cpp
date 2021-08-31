#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
using namespace std;

void timer();

int main() {
  timer();
  return 0;  
}

void timer() {
  int duration;
  cout << "Enter duration of study session (in minutes): ";
  cin >> duration;
  int break_duration;
  cout << "\nEnter duration of break (in minutes): ";
  cin >> break_duration;
  
  duration--;
  break_duration--;
  
  int duration_copy = duration; //Used to reset

  int seconds = 59; 
  
  int interval_count = 0;

  while (true) {
    
    cout << duration << ": ";
    cout << seconds << "\n";

    sleep(1);

    seconds--;

    if (seconds == -1 && duration >= 0) { 
      duration--;
      seconds = 59;
    }
     
//    if (duration == 0 && seconds == 0 && interval_count % 2 != 0) {
//      cout << "Beginning break section" << "\n";
//      duration = break_duration; 
//    }
    if (duration == 0 && seconds == -1) {
      if (interval_count % 2 != 0) {
        duration = duration_copy;
      }
      else {
        duration = break_duration;
      }
    }
    interval_count++;
  }
}
