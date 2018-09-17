#include <stdio.h>
#include "gtest/gtest.h"
#include "../src/worker.h"
#include <stdio.h>

namespace {
    // set up and tier down
    TEST(WorkerTest, addTest) {
	Task t;
	Worker *w = new Worker("123");
	w->work(&t);
	EXPECT_EQ("123", w->getName());
	w->addTask(&t);
	for (int i=0; i<10; i++) {
	   Task *ti = new Task(20 - i);
	    w->addTask(ti);
	}
	Task* prv = nullptr;
	for (int i=0; i<10; i++) {
	    Task* next = w->nextTask();
	    if (prv != nullptr) {
		EXPECT_GE(prv->getPriority(), next->getPriority());
	    }
	}
    }
} 
