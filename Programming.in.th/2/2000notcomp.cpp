#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

/*
Input
6
left    right   nodeID
2       3       1
-1      4       2
5       6       3
-1      -1      4
-1      -1      5
-1      -1      6
*/

struct node {
    int id;
    int left;
    int right;
    int level;
    vector<int> finalchildlevelleft;
    vector<int> finalchildlevelright;
    //bool visited = false;
};

map<int,node> data; //data[nodeID] = node
//vector<int> dfs1stack;

/*void printstack(int id) {
    cout << id << ": ";
    for (int i = 0;i<dfs1stack.size();i++) {
        cout << dfs1stack[i] << " ";
    }
    cout << "\n";
}

void dfs1processstack(int id) {
    if (id != 1) {
        for (int i = 0;i<dfs1stack.size()-1;i++) {

        }
    }
}

void dfs1(int id) {
    if (id != -1 && id != 0) {
        //cout << id << " ";
        dfs1processstack(id);

        dfs1stack.push_back(data[id].left); //inject left
        dfs1(data[id].left);
        dfs1stack.erase(dfs1stack.end()-1); //eject

        dfs1stack.push_back(data[id].right); //inject right
        dfs1(data[id].right);
        dfs1stack.erase(dfs1stack.end()-1); //eject
    }
}*/

void vectorUnion(vector<int>* target,vector<int> in) {
    for (int i = 0;i<in.size();i++) {
        target->push_back(in[i]);
    }
}

vector<int> vectorUnion(vector<int> a,vector<int> b) {
    vector<int> result = a;
    for (int i = 0;i<b.size();i++) {
        result.push_back(b[i]);
    }
    return result;
}

vector<int> dfs1(int id,int level) {
    if (id != -1 && id != 0) {
        data[id].level = level;
        if (data[id].left == -1) {
            data[id].finalchildlevelleft.push_back(level+1);
        }
        if (data[id].right == -1) {
            data[id].finalchildlevelright.push_back(level+1);
        }
        //if (data[data[id].right].left == -1 && data[data[id].right].right == -1) data[id].child.push_back(data[id].right);
        vectorUnion(&data[id].finalchildlevelleft,dfs1(data[id].left,level+1));
        vectorUnion(&data[id].finalchildlevelright,dfs1(data[id].right,level+1));
    }

    /*twovectorint result;
    result.left = data[id].finalchildlevelleft;
    result.right = data[id].finalchildlevelright;*/

    //vector<int> result = data[id].finalchildlevelleft;
    //vectorUnion(&result,data[id].finalchildlevelright);

    return vectorUnion(data[id].finalchildlevelleft,data[id].finalchildlevelright);
}

bool b = true;

int levelcompare(vector<int> left,vector<int> right) {
    /*
    return value:
    0 (no solution): cannot compare
    1 (no swap) : =
    2 (swap) : <
    3 (no swap) : >
    */
    int minleft = left[min_element(left.begin(),left.end())-left.begin()];
    int minright = right[min_element(right.begin(),right.end())-right.begin()];
    int maxleft = left[max_element(left.begin(),left.end())-left.begin()];
    int maxright = right[max_element(right.begin(),right.end())-right.begin()];

    /*if (b) {
        cout << minleft << " " << minright << " " << maxleft << " " << maxright << "\n";
    }

    b= false;*/

    if (minleft == maxleft && minright == maxright && minleft == minright && maxleft == maxright) {
        return 1;
    } else if (minleft < minright && maxleft <= maxright) {
        return 2;
    } else if (minleft >= minright && maxleft > maxright) {
        return 3;
    } else {
        return 0;
    }
    return 0;
}

bool running = true;
int result = 0;

void dfs2(int id) {
    if (id != -1 && id != 0 && running) {
        int compareresult = levelcompare(data[id].finalchildlevelleft,data[id].finalchildlevelright);
        /*if (id == 1) {
            cout << compareresult << "\n";
        }*/
        switch (compareresult) {
            case 0: result = -1; running = false; return;
            case 2: result++;
        }

        dfs2(data[id].left);
        dfs2(data[id].right);
    }
}

void printchild(int id) {
    cout << id << ": ";
    for (int i = 0;i<data[id].finalchildlevelleft.size();i++) {
        cout << data[id].finalchildlevelleft[i] << " ";
    }
    cout << " , ";
    for (int i = 0;i<data[id].finalchildlevelright.size();i++) {
        cout << data[id].finalchildlevelright[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    data[1].id = 1; //nodeID 1 = root node
    data[1].level = 0;
    for (int i = 1;i<=n;i++) { //i = node id
        data[i].id = i;
        cin >> data[i].left >> data[i].right;
    }
    dfs1(1,0);
    /*for (int i = 1;i<=n;i++) {
        printchild(i);
        //cout << i << ": " << data[i].finalchildlevel << "\n";
    }*/
    //cout << levelcompare(data[3].finalchildlevelleft,data[3].finalchildlevelright);
    //cout << data[2].left;
    dfs2(1);
    cout << result;
    return 0;
}
