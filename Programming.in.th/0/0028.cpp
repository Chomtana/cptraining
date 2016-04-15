/* 
 * File:   0028.cpp
 * Author: Pin
 *
 * Created on March 31, 2015, 6:07 PM
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct team {
	string name;
	int score;
	int totalgoal;
	int goalwin; //ประตูที่ยิงได้ - ประตูที่เสีย
	int matchgoal[4];
};

bool comparescore(team a, team b) {
	if (a.score > b.score) return true;
	if (a.score < b.score) return false;
	
	if (a.goalwin > b.goalwin) return true;
	if (a.goalwin < b.goalwin) return false;
	
	if (a.totalgoal > b.totalgoal) return true;
	if (a.totalgoal < b.totalgoal) return false;
}

/*
 * 
 */
int main(int argc, char** argv) {
	team t[4];
	cin >> t[0].name >> t[1].name >> t[2].name >> t[3].name;
	t[0].score = 0;t[1].score = 0;t[2].score = 0;t[3].score = 0;
	t[0].totalgoal = 0;t[1].totalgoal = 0;t[2].totalgoal = 0;t[3].totalgoal = 0;
	t[0].goalwin = 0;t[1].goalwin = 0;t[2].goalwin = 0;t[3].goalwin = 0;
	for (int i = 0;i<4;i++) {
		for (int i2 = 0;i2<4;i2++) {
			cin >> t[i].matchgoal[i2];
			t[i].totalgoal += t[i].matchgoal[i2];
			t[i].goalwin += t[i].matchgoal[i2];
			t[i2].goalwin -= t[i].matchgoal[i2];
		}
	}
	
	//Use combination loop (1 vs 2 = 2 vs 1)
	for (int i = 0;i<4;i++) {
		for (int i2 = i+1;i2<4;i2++) {
			if (t[i].matchgoal[i2] > t[i2].matchgoal[i]) { //win
				t[i].score += 3;
			} else if (t[i].matchgoal[i2] == t[i2].matchgoal[i]) { //draw
				t[i].score += 1;
				t[i2].score += 1;
			} else {
				t[i2].score += 3;
			}
		}
	}
	
	sort(t,t+4,comparescore);
	
	for (int i = 0;i<4;i++) {
		cout << t[i].name << " " << t[i].score << "\n";
	}
	return 0;
}

