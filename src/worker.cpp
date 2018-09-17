#include <iostream>
#include "worker.h"
using namespace std;

bool Worker::work(Task* task) {
    task->process();
    task->getPriority();
    return true;
}

int Worker::addTask(Task* task) {
    cout << "adding task" << endl;
    this->tasks.push_back(*task);
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}
 
Task* Worker::nextTask() {
    int index = 0;
    Task* next_task = nullptr;
    list<Task>::iterator tmp_it;
    // TODO next_task == null??
    for (list<Task>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
	if (next_task == nullptr || next_task->getPriority() < it->getPriority()) {
	    next_task = &(*it);
	    tmp_it = it;
	}
    }
    if (next_task != nullptr) {
	this->tasks.erase(tmp_it);
    }
    return next_task;
}

/**
int main(void) {
    Task t;
    Worker *w = new Worker("123");
    w->work(&t);
    cout << "Worker's name is " << w->getName() << endl;
    w->addTask(&t);
    for (int i=0; i<10; i++) {
	Task *ti = new Task(20 - i);
	w->addTask(ti);
    }
    for (int i=0; i<10; i++) {
	cout << "Priority: " << w->nextTask()->getPriority() << endl;
    }
}
*/
