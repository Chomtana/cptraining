#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct birthday {
    int day;
    int month;
    int year;
};

typedef struct birthday birthday;

typedef struct {
    string name;
    string id;
    birthday bd;
    float grade;
} record;

bool operator < (birthday a,birthday b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            return a.day < b.day;
        } else {
            return a.month < b.month;
        }
    } else {
        return a.year < b.year;
    }
}

bool bdcompare(record a,record b) {
    return a.bd<b.bd;
}

bool idcompare(record a,record b) {
    return a.id<b.id;
}

bool namecompare(record a,record b) {
    return a.name<b.name;
}

list<record> data;

record processin(string s) {
    int delimpos = 0;
    while (delimpos = s.find("$$$") , delimpos!=string::npos) {
        s.replace(s.find("$$$"),3,"/");
    }
    //cout<<s<<endl;

    stringstream ss(s);

    record r;

    getline(ss,r.name,'/');
    getline(ss,r.id,'/');
    string day,month,year,grade;
    getline(ss,day,'/');
    getline(ss,month,'/');
    getline(ss,year,'/');
    getline(ss,grade,'/');
    r.bd.day = atoi(day.c_str());
    r.bd.month = atoi(month.c_str());
    r.bd.year = atoi(year.c_str());
    r.grade = atof(grade.c_str());

    return r;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n; cin.ignore();

    for1(i,0,n) {
        string s;
        getline(cin,s);

        record r = processin(s);

        data.push_back(r);
    }

    /*for1(i,0,n) {
        cout<<data[i].name<<' '<<data[i].id<<' '<<data[i].bd.day<<' '<<data[i].bd.month<<' '<<data[i].bd.year<<' '<<data[i].grade<<endl;
    }*/

    list<record>::iterator it;

    while (true) {
        string com; cin>>com;
        if(com=="af") {
            string in; cin>>in;
            record r = processin(in);
            data.push_front(r);
        }
        if(com=="al") {
            string in; cin>>in;
            record r = processin(in);
            data.push_back(r);
        }
        if(com=="ac") {
            string in; cin>>in;
            record r = processin(in);
            it = data.insert(it,r);
        }
        if(com=="df") {
            if (data.size()>0) {
                if (it == data.begin()) it++;
                data.pop_front();
            }
        }
        if(com=="dl") {
            if (data.size()>0) {
                if (it == --data.end()) it--;
                data.pop_back();
            }
        }
        if(com=="dc") {
            it = data.erase(it);
        }
        if(com=="tf") it = data.begin();
        if(com=="tl") it = data.end();
        if(com=="tn") it++;
        if(com=="tb") it--;
    }


	return 0;
}
