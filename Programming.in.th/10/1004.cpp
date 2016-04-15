#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> queue;
int current = 0;
map<int,int> sturoom; //stu[ID] = room
map<int,int> queueroompos; //queueroompos[room] = pos

int searchpos(int room) {
    int i = 0;
    bool foundstart = false;
    for (i = 0;i<queue.size();i++) {
        if (sturoom[queue[i]] == room && !foundstart) {
            foundstart = true;
        }
        if (sturoom[queue[i]] != room && foundstart) {
            break;
        }
    }
    return i;
}

int main() {
    int nc,ns; cin >> nc >> ns;
    for (int i = 0;i<ns;i++) {
        int c,s; cin >> c >> s;
        sturoom[s] = c;
    }
    char command; cin >> command;
    while (command != 'X') {
        if (command == 'E') {
            int id;
            cin >> id;
            int room = sturoom[id];
            queue.insert(queue.begin()+searchpos(room),id);
        } else if (command == 'D') {
            //if () {
                //cout << "empty\n";
            //} else {
            cout << queue[0] << "\n";
            queue.erase(queue.begin());
                //current++;
            //}
        }
        cin >> command;
    }
    cout << 0;
    return 0;
}