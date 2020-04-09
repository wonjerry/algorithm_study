import java.util.Stack;

class MyQueue {
  private Stack<Integer> stackIn;
  private Stack<Integer> stackOut;
  private boolean pushed = false;

  /** Initialize your data structure here. */
  public MyQueue() {
    this.stackIn = new Stack<>();
    this.stackOut = new Stack<>();
  }

  /** Push element x to the back of queue. */
  public void push(int x) {
    if (!pushed) {
      this.stackIn.clear();
      while(!this.stackOut.empty()) {
        this.stackIn.push(this.stackOut.pop());
      }
    }
    pushed = true;
    this.stackIn.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  public int pop() {
    if (pushed) {
      this.stackOut.clear();
      while(!this.stackIn.empty()) {
        this.stackOut.push(this.stackIn.pop());
      }
    }
    pushed = false;
    return this.stackOut.pop();
  }

  /** Get the front element. */
  public int peek() {
    if (pushed) {
      this.stackOut.clear();
      while(!this.stackIn.empty()) {
        this.stackOut.push(this.stackIn.pop());
      }
    }
    pushed = false;
    return this.stackOut.peek();
  }

  /** Returns whether the queue is empty. */
  public boolean empty() {
    if (this.pushed) {
      return this.stackIn.empty();
    } else {
      return stackOut.empty();
    }
  }
}
