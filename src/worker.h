#include <string>
#include <vector>
#include <queue>

#include "task.h"

// typedef std::pair<std::string, uint64_t> IdCount;

class Worker {
    private:
	const std::string name;
	const int MAX_SEARCH_LEN = 10;
	//TODO use priority queue
	//std::list<std::shared_ptr<Task>> tasks;
  struct TaskCompare {
    bool operator()(Task const& a, Task const& b) {
      // TODO what's the type should be here??
      return b.getPriority() < a.getPriority();
    }
  };
  std::priority_queue<Task, std::vector<Task>, TaskCompare> tasks;
    public:
	const Task* nextTask();
	Worker(): name("default") {};
	Worker(std::string name): name(name) {};
	~Worker() = default;
	const std::string& getName() {return name;};
	bool work(const Task* task);
	// Add a new task for worker and return the current
	// task queue size
	int addTask(Task task);
};
