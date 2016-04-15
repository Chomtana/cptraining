#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
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

typedef long long ll;

using namespace std;

//(x-k)(y-k)=k^2

void print(ostringstream &oss,ll k,ll x,ll y) {
    oss<<"1/"<<k<<" = 1/"<<x<<" + 1/"<<y<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    ll k;
    while (cin>>k) {
        ll count = 0;
        ll x,y;
        ostringstream oss;
        for(y=1;y<=k/*=sqrt(k^2)*/;y++) {
            if (k*k%y==0) {
                x = k*k/y;
                print(oss,k,x+k,y+k);
                count++;
            }
        }
        cout<<count<<endl<<oss.str();
    }
    return 0;
}

/*
Force answer algorithm:
1. สมมุติสมการที่เป็นคำตอบ (สามารถมีตัวแปรค่าคงที่ที่ยังไม่รู้ค่าได้ไม่จำกัด)
1.1 ตัวแปรที่มีอยุ่ในสมการของจริงถือเป็นตัวแปรสมมุติ
1.2 ตัวแปรค่าคงที่ที่สร้างมาใหม่ถือเป้นตัวแปรจริง
2. หาค่าของตัวแปรค่าคงที่ที่ยังไม่รู้ค่า
2.1 ตัวแปรค่าคงที่สามารถแทนค่าเป็นค่าคงที่ได้
2.1.1 สามารถเพิ่ม / ลดจำนวนตัวแปรค่าคงที่ได้ตลอด โดยการแทนค่าเป็นค่าคงที่ตัวใหม่ (b=a / a=a+b)
2.2 สามารถนำสมการที่ได้จากการคำนวณจริงๆมาแทนค่าลงไปได้ (ตัวแปรจะถูกเปลี่ยนเป็นตัวแปรจริง)
2.3 สมการที่สมมุติมาสามารถเปลี่ยนได้ทุกส่วน
2.4 สามารถเปลี่ยนตัวแปรสมมุติเป็นตัวแปรจริงได้ (แต่เปลี่ยนกลับไม่ได้)
3. สรุปสมการหลังจากเปลี่ยนตัวแปรเสร็จ (ได้สมการที่ถูกต้อง)

1/k = 1/x + 1/y
xy = ky+kx
([x]-a)([y]-b) = [k] (force answer => we want a,b that make (x-a)(y-b) similar to k ... not need to equal to k)
([xy])-[x]b-[y]a+ab = [k] = (ky+kx)-[x]b-[y]a+ab

[k] = ky+kx-[x]a-[y]a+a^2 ; select b=a : make it easier
[k] = k(x+y)-[x]a-[y]a+a^2
[k] = k(x+y)-a([x]+[y])+a^2 ; select a=k and change [x],[y] to real variable : make it similar to what we want
[k] = k^2 ; equation not true => we want to change assume variable (left side) to calculated variable (left side)
if we change [k] to k^2 then
k^2 = k^2 ; equation is true
then correct equation is (x-k)(y-k)=k^2
*/