#include <unistd.h>
#include <iostream>
#ifndef __TASK_H_
#define __TASK_H_
#include "task.h"
#endif

class OrderTask : public Task {
public:
  void process() {
    std::cout << "processing a order..." << std::endl;
    Task::process();
  }
};
