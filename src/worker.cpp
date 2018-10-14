#include <iostream>
#include "worker.h"
using namespace std;


int Worker::addTask(Task& task) {
    // TODO replace with logging
    cout << "adding task" << endl;
    auto _task = std::shared_ptr<Task>(&task);
    this->tasks.push(_task);
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}

Task& Worker::nextTask() {
  // TODO check null
  return this->tasks->pop()
}

bool Worker::work(Task& task) {
    task.process();
    return true;
}
