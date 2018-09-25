#include <iostream>
#include "worker.h"
using namespace std;


int Worker::addTask(Task* task) {
    // TODO replace with logging
    cout << "adding task" << endl;
    this->tasks.push_back(*task);
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}
 
Task& Worker::nextTask() {
    Task* next_task = nullptr;
    for (list<Task>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
	if (next_task == nullptr || next_task->getPriority() < it->getPriority()) {
	    next_task = &*it;
	}
    }
    return *next_task;
}

bool Worker::work(Task& task) {
    // TODO (1) process. & release 
    task.process();
    for (list<Task>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
	if (&*it == &task) {
	    tasks.erase(it);
	    return true;
	}
    } 
    return false;
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
