#include <string>
#include <vector>
#include <queue>

#include "task.h"


class Worker {
    private:
	const std::string name;
	const int MAX_SEARCH_LEN = 10;
  struct TaskCompare {
    bool operator()(Task const& a, Task const& b) {
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
