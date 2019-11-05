#include <bits/stdc++.h>

using namespace std;

namespace CP {
    template<typename T>
    class vector {
    protected:
        T* mData;
        size_t mSize;
        size_t mCap;

    public:
        vector() {
            mSize = 0;
            mCap = 1;
            mData = new T[mCap];
        }

        vector(vector<T>& v) {
            mSize = v.size();
            mCap = v.size();
            mData = new T[mCap];

            for(int i = 0;i<mSize;i++) {
                mData[i] = v[i];
            }
        }

        size() {
            return mSize;
        }

        empty() {
            return mSize == 0;
        }

        expand(size_t s) {
            T* x = new T[s];
            for(int i = 0;i<mSize;i++) {
                x[i] = mData[i];
            }

            mCap = s;
        }

        ensureCapacity(size_t s) {
            if (s>mCap) {
                expand(s>2*mCap ? s : 2*mCap);
            }
        }

        resize(size_t s) {
            //TO DO
            ensureCapacity(s);
            for(int i = mSize;i<s;i++) {
                mData[i] = T();
            }

            mSize = s;
        }

        push_back(T x) {
            ensureCapacity(mSize+1);
            mData[mSize] = x;
            mSize++;
        }

        T& operator [](int i) {
            return mData[i];
        }

        T& at(int i) {
            if (i>=mSize) {
                throw new out_of_range("IndexOutOfBound");
            }

            return mData[i];
        }
    };
}

int main() {
    CP::vector<int> v;
    v.push_back(5);
    v.push_back(8);
    v.resize(10);
    v[4] = 10;
    v.push_back(20);
    for(int i = 0;i<v.size();i++) {
        cout<<v[i]<<endl;
    }
}
