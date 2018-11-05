#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/order_task.h"

namespace {
  TEST(TaskTest, Process) {
    std::cout << "Test Order Task" << std::endl;
    Task *t = new Task(10);
    t->process();
    EXPECT_EQ(t->getPriority(), 10);
    OrderTask *order_task = new OrderTask(11);
    // TODO extends doesn't extends Task function getPriority
    EXPECT_EQ(order_task->getPriority(), 11);
  }
}
