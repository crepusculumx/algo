#include <queue>

using namespace std;

class MyQueue {
  queue<int> q1, q2;

 public:
  MyQueue() {

  }

  void push(int x) {
    q1.push(x);
  }

  int pop() {
    auto t = peek();
    q2.pop();
    return t;
  }

  int peek() {
    if (q2.empty()) {
      while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }
    }
    return q2.front();
  }

  bool empty() {
    return q1.empty() && q2.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */