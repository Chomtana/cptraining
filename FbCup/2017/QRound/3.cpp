#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class BigNumber { //unsigned with 6 decimal place
public:
    deque<int> data;

    BigNumber() {

    }

    BigNumber(string s) {
        for1(i,0,s.size()) {
            data.push_back(s[i]-'0');
        }
    }

    BigNumber(ll i) {
        while (i) {
            int digit = i%10;
            data.push_front(digit);
            i/=10;
        }
    }

    int size() {
        return data.size();
    }

    int get(int i) {
        if (i<0 || i>=data.size()) {
            return 0;
        }
        return data[i];
    }

    void del0() {
        while (data[0]==0 && data.size()>1) {
            data.pop_front();
        }
    }

    bool operator == (BigNumber n) {
        if (n.size()!=size()) return false;
        for1(i,0,size()) {
            if (data[i]!=n.data[i]) return false;
        }
        return true;
    }

    bool operator != (BigNumber n) {
        return !(*this==n);
    }

    bool operator > (BigNumber n) {
        if (size()>n.size()) return true;
        if (size()<n.size()) return false;
        for1(i,0,size()) {
            if (data[i]>n.data[i]) return true;
            if (data[i]<n.data[i]) return false;
        }
        return false;
    }

    bool operator >= (BigNumber n) {
        return (*this>n || *this==n);
    }

    bool operator < (BigNumber n) {
        return !(*this>n);
    }

    bool operator <= (BigNumber n) {
        return (*this<n || *this==n);
    }

    BigNumber operator + (BigNumber n) {
        BigNumber res;
        res.data.resize(max(size(),n.size())+1);

        bool add = false;
        for1(i,0,res.size()) {
            int pres = res.size()-1-i;
            int pn = n.size()-1-i;
            int p = size()-1-i;
            int sum = get(p)+n.get(pn)+add;
            add = false;
            if (sum>=10) {
                add = true;
                sum -= 10;
            }
            res.data[pres] = sum;
        }
        res.del0();
        return res;
    }

    BigNumber operator - (BigNumber n) {
        BigNumber res;
        res.data.resize(max(size(),n.size())+1);
        bool add = false;
        for1(i,0,res.size()) {
            int pres = res.size()-1-i;
            int pn = n.size()-1-i;
            int p = size()-1-i;
            int sum = get(p)-n.get(pn)-add;
            add = false;
            if (sum<0) {
                add = true;
                sum += 10;
            }
            res.data[pres] = sum;
        }
        res.del0();
        return res;
    }

    BigNumber operator * (BigNumber n) {
        BigNumber res;
        res.data.resize(size()+n.size()+1);
        if (n==BigNumber(10)) { //base case
            res.data.resize(size()+1);
            for1(i,0,size()) {
                res.data[i] = data[i];
            }
            return res;
        } else if (n.size()==1) { //base case
            int add = 0;
            int use = n.data[0];
            for1(i,0,res.size()) {
                int pres = res.size()-1-i;
                int pn = n.size()-1-i;
                int p = size()-1-i;
                int mul = get(p)*use+add;
                add = mul/10;
                mul %= 10;
                res.data[pres] = mul;
            }
        } else {
            for1(i,0,n.size()) {
                int pn = n.size()-1-i;
                BigNumber add = *this*BigNumber(n.data[pn]);
                for1(j,0,i) {
                    add = add*10;
                }
                //cout<<add.str()<<endl;
                res = res+add;
            }
        }
        res.del0();
        return res;
    }

    BigNumber operator / (BigNumber n) {
        BigNumber curr;
        BigNumber res;
        for1(i,0,this->size()) {
            curr.data.push_back(data[i]);
            for1(j,1,10) {
                BigNumber mul = n*BigNumber(j);

            }
        }
    }

    string str() {
        string s;
        for1(i,0,data.size()) {
            s+=data[i]+'0';
        }
        return s;
    }

    friend ostream& operator << (ostream& os,BigNumber n) {
        os<<n.str();
    }
};

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	BigNumber i1("9999999999999999999999999999999999999999999999999999999999999999998");
	BigNumber i2("9999999999999999999999999999999999999999999999999999999999999999999");
    cout<<(i1<i2);
    int a,b,c;
    scanf("%dd%d%d",&a,&b,&c);
    cout<<a<<' '<<b<<' '<<c;
	return 0;
}
