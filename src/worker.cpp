#include <iostream>
#include "worker.h"
using namespace std;


int Worker::addTask(Task task) {
    // TODO replace with logging
    cout << "adding task" << endl;
    this->tasks.push(std::move(task));
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}

const Task* Worker::nextTask() {
  // TODO check null
  if (this->tasks.empty()) {
    return nullptr;
  }
  // return nullptr;
  return &(this->tasks.top());
  // typeid(t).name();
  // return t;
}

bool Worker::work(const Task* task) {
    task->process();
    return true;
}
