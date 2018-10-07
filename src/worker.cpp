#include <iostream>
#include "worker.h"
using namespace std;


int Worker::addTask(Task& task) {
    // TODO replace with logging
    cout << "adding task" << endl;
    auto _task = std::shared_ptr<Task>(&task);
    this->tasks.push_back(_task);
    cout << "now tasks size is " << this->tasks.size() << endl;
    return tasks.size();
}
 
Task& Worker::nextTask() {
    std::shared_ptr<Task> next_task = nullptr;
	list<shared_ptr<Task>> tasks;
    for (list<shared_ptr<Task>>::iterator it = this->tasks.begin(); it != this->tasks.end(); ++it) {
	if (next_task == nullptr || next_task->getPriority() < (*it)->getPriority()) {
	    next_task = *it;
	}
    }
    return *next_task;
}

bool Worker::work(Task& task) {
    auto it = std::find(tasks.begin(), tasks.end(), std::shared_ptr<Task>(&task));
    // TODO acquire a Lock here
    task.process();
    // TODO How to erase it here????
    tasks.erase(it);
    // Release here
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
