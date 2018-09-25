#include <string>
#include <list>
#include "task.h"
using namespace std;

class Worker {
    private:
	const string name;
	const int MAX_SEARCH_LEN = 10;
	//TODO use priority queue
	list<Task> tasks;
    public:
	Task& nextTask();
	Worker(): name("default") {};
	Worker(string name): name(name) {}; 
	~Worker() = default;	
	const string& getName() {return name;};
	bool work(Task& task);
	// Add a new task for worker and return the current
	// task queue size
	int addTask(Task* task);
};

