class Task {
private:
  unsigned const priority;
public:
  // Larger number indicate longer process time.
  Task(): priority(-1) {}; 
  Task(int priority): priority(priority) {}; 
  static const int SPEED_X = 100000;
  static const int TIME_MS = 10;
  unsigned getPriority() const {return this->priority;};
  void process();
  ~Task() = default;
};
