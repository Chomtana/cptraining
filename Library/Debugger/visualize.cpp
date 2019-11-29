#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;
#define until(x) while(!x)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

class Visualizer {
  public:
  ofstream file;
  int rown;
  int coln;
  int cellSize = 40;

  Visualizer(int rown,int coln) {
    this->rown = rown;
    this->coln = coln;
    file.open("./visdata.js");
    file << "var data = [\n";
  }

  Visualizer(): Visualizer(0,0) {}
  
  void line(int r1, int c1, int r2, int c2, string stroke, int strokeWidth) {
    if (max(r1,r2) >= rown) rown = max(r1,r2) + 1;
    if (max(c1,c2) >= coln) coln = max(c1,c2) + 1;
    file << "{ type: 'line', points: [["<<r1<<","<<c1<<"],["<<r2<<","<<c2<<"]], stroke: '"<<stroke<<"', strokeWidth: "<<strokeWidth<<" },\n";
  }

  void line(int r1, int c1, int r2, int c2, string stroke) {
    line(r1, c1, r2, c2, stroke, 2);
  }

  void line(int r1, int c1, int r2, int c2) {
    line(r1, c1, r2, c2, "black", 2);
  }

  void text(int r, int c, string text) {
    if (r >= rown) rown = r + 1;
    if (c >= coln) coln = c + 1;
    file << "{ type: 'text', text: `"<<text<<"`, row:"<<r<<", col:"<<c<<" },\n";
  }

  void finalize() {
    file << "];\n";
    file << "var rown = " << rown << ";\n";
    file << "var coln = " << coln << ";\n";
    file << "var cellSize = " << cellSize << ";\n";

    file.flush();
    file.close();
  }
};

Visualizer vis;

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
  vis.line(0,1,0,3);
  vis.line(2,1,2,2);
  vis.text(1,1, "hella");
  vis.finalize();
	return 0;
}
