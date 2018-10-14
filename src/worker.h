#include <string>
#include <vector>
#include <queue>

#include "task.h"

struct TaskCompare {
  bool operator()(const Task* t1, const Task* t2) {
    // TODO what's the type should be here??
    return t1->getPriority() >= t2->getPriority();
  }
};

class Worker {
    private:
	const std::string name;
	const int MAX_SEARCH_LEN = 10;
	//TODO use priority queue
	//std::list<std::shared_ptr<Task>> tasks;
  std::priority_queue<std::shared_ptr<Task>, std::vector<std::shared_ptr<Task>>, TaskCompare> tasks;
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
