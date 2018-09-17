#include "order_task.h"
#include <unistd.h>
#include <iostream>
#include "task.cpp"
using namespace std;

class OrderTask : public Task {
public:
  void process() {
    cout << "processing a order..." << endl;
    //Foo::printStuff();
    Task::process();
  }
};

int main(void) {
  OrderTask t;
  //t.setPiority(3);
  //cout << t.getPiority() << endl;
  t.process();
}
