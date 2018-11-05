#include "task.h"

class OrderTask : public Task {
private:
  unsigned priority;
public:
  // TODO do I need those declareation here?
  // static const int SPEED_X = 100000;
  // static const int TIME_MS = 10;
  OrderTask(): priority(-1) {};
  OrderTask(int priority): priority(priority) {};
  unsigned getPiority();
  void setPiority(unsigned priority);
  void process();
};
