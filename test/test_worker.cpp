#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/worker.h"

namespace {
  TEST(WorkerTest, GetTestByPriority) {
    // Woker constructor
    std::cout << "Test Worker" << std::endl;
  	Worker *w = new Worker("123");
  	EXPECT_EQ("123", w->getName());
    // Add/Get Task
  	for (int i=0; i<10; i++) {
  	   Task *ti = new Task(20 - i);
  	    w->addTask(*ti);
  	}
  	const Task* prv = nullptr;
  	for (int i=0; i<10; i++) {
  	    const Task* next = w->nextTask();
  	    if (prv != nullptr) {
      		ASSERT_GE(prv->getPriority(), next->getPriority());
      		ASSERT_EQ(w->work(prv), true);
  	    }
  	    prv = next;
  	}
  }
}
