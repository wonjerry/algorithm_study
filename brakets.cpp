#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Stack {
    private:
        int top = -1;
        char *storage;
    public:
        Stack(int size) {
            this->storage = new char[size];
        }

        void push(char bracket) {
            this->storage[++this->top] = bracket;
        }

        char pop(){
            return this->storage[this->top--];
        }

        bool isEmpty() {
            return this->top == -1;
        }
};

bool isVPS(string brackets) {
    Stack s = Stack(brackets.size());
    for(int i = 0, len = brackets.size(); i < len; i++) {
        if(brackets[i] == '(') {
            s.push('(');
        }else {
            if(s.isEmpty()) {
                return false;
            }
            
            s.pop();
        }
    }

    return s.isEmpty();
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        string brackets;
        cin >> brackets;

        printf("%s\n", isVPS(brackets) ? "YES" : "NO");
    }

    return 0;
}