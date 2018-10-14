#include <string>
#include <list>
#include "task.h"

class Worker {
    private:
	const std::string name;
	const int MAX_SEARCH_LEN = 10;
	//TODO use priority queue
	std::list<std::shared_ptr<Task>> tasks;
    public:
	Task& nextTask();
	Worker(): name("default") {};
	Worker(std::string name): name(name) {};
	~Worker() = default;
	const std::string& getName() {return name;};
	bool work(Task& task);
	// Add a new task for worker and return the current
	// task queue size
	int addTask(Task& task);
};
