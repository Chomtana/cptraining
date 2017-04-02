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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n; cin.ignore();
    record data[n];
    for1(i,0,n) {
        string s;
        getline(cin,s);
        int delimpos = 0;
        while (delimpos = s.find("$$$") , delimpos!=string::npos) {
            s.replace(s.find("$$$"),3,"/");
        }
        //cout<<s<<endl;

        stringstream ss(s);

        getline(ss,data[i].name,'/');
        getline(ss,data[i].id,'/');
        string day,month,year,grade;
        getline(ss,day,'/');
        getline(ss,month,'/');
        getline(ss,year,'/');
        getline(ss,grade,'/');
        data[i].bd.day = atoi(day.c_str());
        data[i].bd.month = atoi(month.c_str());
        data[i].bd.year = atoi(year.c_str());
        data[i].grade = atof(grade.c_str());
    }

    /*for1(i,0,n) {
        cout<<data[i].name<<' '<<data[i].id<<' '<<data[i].bd.day<<' '<<data[i].bd.month<<' '<<data[i].bd.year<<' '<<data[i].grade<<endl;
    }*/

    sort(data,data+n,bdcompare);

    printf("\n");

    int bdcount = 1;
    printf("Count of student born in %d : ",data[0].bd.year);
    for1(i,1,n) {
        if (data[i].bd.year != data[i-1].bd.year) {
            printf("%d\nCount of student born in %d : ",bdcount,data[i].bd.year);
            bdcount = 1;
        } else {
            bdcount++;
        }
    }
    printf("%d\n\n",bdcount);

    float grademin = 1E9;
    int grademini;
    float grademax = -1;
    int grademaxi;
    for1(i,0,n) {
        if (data[i].grade<grademin) {
            grademin = data[i].grade;
            grademini = i;
        }
        if (data[i].grade > grademax) {
            grademax = data[i].grade;
            grademaxi = i;

        }
    }
    cout<<"Lowest grade student : "<<data[grademini].name<<" "<<data[grademini].id<<endl;
    cout<<"Highest grade student : "<<data[grademaxi].name<<" "<<data[grademaxi].id<<endl<<endl;

    cout<<"Sort by id :"<<endl;
    sort(data,data+n,idcompare);
    for1(i,0,n) {
        cout<<data[i].name;
        printf(" %.2f\n",data[i].grade);
    }
    printf("\n");

    cout<<"Sort by birthday : "<<endl;
    sort(data,data+n,bdcompare);
    for1(i,0,n) {
        cout<<data[i].name;
        printf(" %.2f\n",data[i].grade);
    }
    printf("\n");

    float gradesum = 0;
    //float grademax = -1;
    //float grademin = 1E9;
    for1(i,0,n) {
        gradesum += data[i].grade;
        //grademax = max(data[i].grade,grademax);
        //grademin = min(data[i].grade,grademin);
    }
    float gradeave = gradesum/n;

    cout<<"Grade lower than average : "<<endl;
    for1(i,0,n) {
        if (data[i].grade < gradeave) {
            cout<<data[i].name;
            printf(" %.2f\n",data[i].grade);
        }
    }
    printf("\n");

    sort(data,data+n,namecompare);
    cout<<"Name start with "<<data[0].name[0]<<" : "<<endl<<data[0].name<<endl;
    for1(i,1,n) {
        if (data[i].name[0] == data[i-1].name[0]) {
            cout<<data[i].name<<endl;
        } else {
            cout<<"Name start with "<<data[i].name[0]<<" : "<<endl<<data[i].name<<endl;
        }

    }
    printf("Max grade : %.2f\n",grademax);
    printf("Min grade : %.2f\n",grademin);
    printf("Average grade : %.2f",gradeave);


	return 0;
}
