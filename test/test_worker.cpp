#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/worker.h"
#include <stdio.h>

namespace {
  TEST(WorkerTest, GetTestByPriority) {
    // Woker constructor
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
          // TODO fix work() here
      		// ASSERT_GE(w->work(prv), true);
  	    }
  	    prv = next;
  	}
  }
}
