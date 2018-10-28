CC=g++ -std=c++11
clean:
	rm -rf bin/*
build: clean print_line
	$(CC) -o bin/worker src/worker.cpp src/Task.cpp
test: clean
	$(CC)  test/test_worker.cpp test/test_main.cpp src/worker.cpp src/task.cpp -lgtest -lpthread -o bin/test_worker
run: test_worker
	bin/test_worker
build_task: clean
	$(CC) -o bin/task  src/task.cpp
task: build_task
	bin/task
build_order_task: clean
	g+ -std=c++11 -o bin/order_task src/order_task.cpp
order_task: build_order_task
	bin/order_task
print_line:
	echo "========================================================"
	date
