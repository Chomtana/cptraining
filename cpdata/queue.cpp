#include <bits/stdc++.h>

using namespace std;

namespace CP {
    template<typename T>
    class queue {
        protected:
            T* mData; size_t mFront; size_t mSize; size_t mCap;

        public:
            queue() {
                mFront = 0;
                mSize = 0;
                mCap = 1;
                mData = new T[mCap];
            }

            queue(vector<T>& v) {
                mSize = v.size();
                mCap = v.size();
                mFront = 0;
                mData = new T[mCap];

                for(int i = 0;i<v.size();i++) {
                    mData[i] = v[i];
                }
            }

            front() {
                return mData[mFront];
            }

            pop() {
                mFront++;
                mFront %= mCap;
                mSize--;
            }

            expand(size_t s) {
                T* x = new T[s];
                for(int i = 0;i<mSize;i++) {
                    x[i] = mData[(mFront+i)%mCap];
                }

                mCap = s;
                mFront = 0;
                mData = x;
            }

            ensureCapacity(size_t s) {
                if (s>mCap) {
                    expand(s > mCap*2 ? s : mCap*2);
                }
            }

            push(T x) {
                ensureCapacity(mSize + 1);
                mData[(mFront+mSize)%mCap] = x;
                mSize++;
            }

            size() {
                return mSize;
            }

            empty() {
                return mSize == 0;
            }
    };
}

int main() {
    CP::queue<int> q;
    q.push(3);
    q.push(5);
    q.push(8);
    while (!q.empty()) {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
