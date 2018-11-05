#include <iostream>
#include "order_task.h"
#include <unistd.h>
using namespace std;

/*
- SeatTask
- OrderTask
- CleanTask
- PayTask
**/


void Task::process() const{
  std::string class_name  = typeid(this).name();
  int process_time = this->TIME_MS * this->SPEED_X;
  std::cout << "Begin process " << class_name << " and will process for "<<process_time<<"ms...." << std::endl;
  std::cout << "Priority = " << this->getPriority() << std::endl;
  usleep(process_time);
  std::cout << "Complete class_name" << std::endl;
}
