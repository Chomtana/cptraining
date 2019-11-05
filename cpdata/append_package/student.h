#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        stack<T> thiss = *this;
        stack<T> res;
        while(!thiss.empty()) {
            res.push(thiss.top()); thiss.pop();
        }

        while(!s.empty()) {
            res.push(s.top()); s.pop();
        }

        stack<T> res2;
        while(!res.empty()) res2.push(res.top()), res.pop();
        (*this) = res2;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> thiss = *this;
        stack<T> res;
        while(!thiss.empty()) {
            res.push(thiss.top()); thiss.pop();
        }

        while(!q.empty()) {
            res.push(q.front()); q.pop();
        }
        stack<T> res2;
        while(!res.empty()) res2.push(res.top()), res.pop();
        (*this) = res2;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        queue<T> thiss = *this;
        queue<T> res;
        while(!thiss.empty()) {
            res.push(thiss.front()); thiss.pop();
        }

        while(!s.empty()) {
            res.push(s.top()); s.pop();
        }
        (*this) = res;
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        queue<T> thiss = *this;
        queue<T> res;
        while(!thiss.empty()) {
            res.push(thiss.front()); thiss.pop();
        }

        while(!q.empty()) {
            res.push(q.front()); q.pop();
        }
        (*this) = res;
    }
}
