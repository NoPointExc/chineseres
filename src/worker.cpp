#include <iostream>
#include "worker.h"
using namespace std;


int Worker::addTask(Task task) {
    cout << "adding task" << endl;
    this->tasks.push(std::move(task));
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}

const Task* Worker::nextTask() {
  if (this->tasks.empty()) {
    return nullptr;
  }
  return &(this->tasks.top());
}

bool Worker::work(const Task* task) {
    task->process();
    return true;
}
