#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>

using namespace std;

void timer();
void display_pomodoro_timer(int, int, int);

int main() {
  timer();
  return 0;
}


//TODO Add hours to the timer


void timer() {
  // Initalizes, builds, and displays user pomodoro clock... single function gang

  cout << "Enter Length of Study Session: ";
  int duration; cin >> duration;
  cout << "Enter Length of Break Session: ";
  int break_duration; cin >> break_duration;
  cout << "Enter Amount of Study Sections: ";
  int study_sessions; cin >> study_sessions;
  
  int hours = 0; // ignore this for now just using as place holder for line 92

  int seconds = 60;
  
  duration--; // If duration is 3 minutes we start at 2:59
  break_duration--; // Starts one second below duration so duration must be decreased by one

  int original_duration = duration;

  int pomodoro_count = 1; //if even it is a study session if odd it is a break
  int study_session_count = 0; // Start at 1 since we begin on a study session

  while (study_session_count != study_sessions) {
  
    sleep(1);

    seconds--;
    
    // Here we call a function to show the clock
    display_pomodoro_timer(duration, seconds, hours);

    if (seconds == 0 && duration > 0) {
      duration--;
      seconds = 60;
    }
    else if (seconds == 0 && duration == 0) {
      if (pomodoro_count % 2 == 0) {
        cout << "Break Section Beginning, Enjoy!" << "\n";
        duration = break_duration;
        seconds = 60;
      }
      else {
        if (study_session_count+1 != study_sessions) { // the +1 is to account for it not being added until after this part
          cout << "Study Session Beginning, You Got This!" << "\n";
        }
        duration = original_duration;
        seconds = 60;
        study_session_count++;
      }

      pomodoro_count++;

      if (study_session_count == study_sessions) {
        cout << "Pomodoro Session Over. Good job!" << "\n";
      }
    }
  }
}

void display_pomodoro_timer(int duration, int seconds, int hours) {
  system("clear");

  cout << "\n";
  cout << " --------------------------------------\n";
  cout << "|   Hours   |    Minutes    |  Seconds |\n";
  cout << "| -------------------------------------|\n";
  cout << "|           |               |          |\n";
  cout << "|    " << setfill('0') << setw(2) << hours << "     |       "<< setfill('0') << setw(2) << duration << "      |    "<< setfill('0') << setw(2) << seconds << "    |\n";
  cout << "|           |               |          |\n";
  cout << " --------------------------------------\n"; 
}
