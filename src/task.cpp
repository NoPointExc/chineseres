#include <iostream>
#include "task.h"
#include <unistd.h>
using namespace std;

/*
- SeatTask
- OrderTask
- CleanTask
- PayTask
**/


void Task::process() {
  std::string class_name  = typeid(this).name();
  int process_time = this->TIME_MS * this->SPEED_X;
  cout << "Begin process " << class_name << " and will process for "<<process_time<<"ms...." << endl;
  cout << "Priority = " << this->getPriority() << endl;
  usleep(process_time);
  cout << "Complete class_name" << endl;
}


 //int main(void) {
 //  Task t;
   //t.setPiority(3);
   //cout << t.getPriority() << endl;
  // t.process();
// }
