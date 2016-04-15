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

#define doaddres(a) for1(i,0,tha[a].size()) {if(!added[tha[a][i]]) res+=area[tha[a][i]]; added[tha[a][i]] = true;}

//not complete : need m>=20 final loop

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    int casenum = 1;
    while (true) {
        int n,m; cin>>n>>m;
        if (n==0 && m==0) break;
        ll totalarea[n];
        for1(i,0,n) cin>>totalarea[i];
        int intern; cin>>intern;
        vector<ll> area;
        vector< vector<int> > tha(n); //tower [i] have area {...(index of area)...}
        for1(i,0,intern) {
            int covern; cin>>covern;
            for1(j,0,covern) {
                int in; cin>>in; in--;
                tha[in].push_back(i);
            }
            ll in; cin>>in;
            area.push_back(in);
        }
        for1(i,0,n) {
            ll onearea = totalarea[i];
            for1(j,0,tha[i].size()) {
                onearea -= area[tha[i][j]];
            }
            area.push_back(onearea);
            tha[i].push_back(area.size()-1);
        }
        
        
        ll currmax = 0;
        vector<int> towerres(m);
        for1(i0,0,n) {
            if (m>=2) {
                for1(i1,i0+1,n) {
                    if (m>=3) {
                        for1(i2,i1+1,n) {
                            if (m>=4) {
                                for1(i3,i2+1,n) {
                                    if (m>=5) {
                                        for1(i4,i3+1,n) {
                                            if (m>=6) {
                                                for1(i5,i4+1,n) {
                                                    if (m>=7) {
                                                        for1(i6,i5+1,n) {
                                                            if (m>=8) {
                                                                for1(i7,i6+1,n) {
                                                                    if (m>=9) {
                                                                        for1(i8,i7+1,n) {
                                                                            if (m>=10) {
                                                                                for1(i9,i8+1,n) {
                                                                                    if (m>=11) {
                                                                                        for1(i10,i9+1,n) {
                                                                                            if (m>=12) {
                                                                                                for1(i11,i10+1,n) {
                                                                                                    if (m>=13) {
                                                                                                        for1(i12,i11+1,n) {
                                                                                                            if (m>=14) {
                                                                                                                for1(i13,i12+1,n) {
                                                                                                                    if (m>=15) {
                                                                                                                        for1(i14,i13+1,n) {
                                                                                                                            if (m>=16) {
                                                                                                                                for1(i15,i14+1,n) {
                                                                                                                                    if (m>=17) {
                                                                                                                                        for1(i16,i15+1,n) {
                                                        
                                                                                                                                        }
                                                                                                                                    } else {
                                                                                                                                        vector<bool> added(area.size(),false);
                                                                                                                                        ll res = 0;
                                                                                                                                        doaddres(i0);
                                                                                                                                        doaddres(i1);
                                                                                                                                        doaddres(i2);
                                                                                                                                        doaddres(i3);
                                                                                                                                        doaddres(i4);
                                                                                                                                        doaddres(i5);
                                                                                                                                        doaddres(i6);
                                                                                                                                        doaddres(i7);
                                                                                                                                        doaddres(i8);
                                                                                                                                        doaddres(i9);
                                                                                                                                        doaddres(i10);
                                                                                                                                        doaddres(i11);
                                                                                                                                        doaddres(i12);
                                                                                                                                        doaddres(i13);
                                                                                                                                        doaddres(i14);
                                                                                                                                        doaddres(i15);
                                                                                                                                        if (res>currmax) {
                                                                                                                                            currmax = res;
                                                                                                                                            towerres[0] = i0+1;
                                                                                                                                            towerres[1] = i1+1;
                                                                                                                                            towerres[2] = i2+1;
                                                                                                                                            towerres[3] = i3+1;
                                                                                                                                            towerres[4] = i4+1;
                                                                                                                                            towerres[5] = i5+1;
                                                                                                                                            towerres[6] = i6+1;
                                                                                                                                            towerres[7] = i7+1;
                                                                                                                                            towerres[8] = i8+1;
                                                                                                                                            towerres[9] = i9+1;
                                                                                                                                            towerres[10] = i10+1;
                                                                                                                                            towerres[11] = i11+1;
                                                                                                                                            towerres[12] = i12+1;
                                                                                                                                            towerres[13] = i13+1;
                                                                                                                                            towerres[14] = i14+1;
                                                                                                                                            towerres[15] = i15+1;
                                                                                                                                        }
                                                                                                                                    }              
                                                                                                                                }
                                                                                                                            } else {
                                                                                                                                vector<bool> added(area.size(),false);
                                                                                                                                ll res = 0;
                                                                                                                                doaddres(i0);
                                                                                                                                doaddres(i1);
                                                                                                                                doaddres(i2);
                                                                                                                                doaddres(i3);
                                                                                                                                doaddres(i4);
                                                                                                                                doaddres(i5);
                                                                                                                                doaddres(i6);
                                                                                                                                doaddres(i7);
                                                                                                                                doaddres(i8);
                                                                                                                                doaddres(i9);
                                                                                                                                doaddres(i10);
                                                                                                                                doaddres(i11);
                                                                                                                                doaddres(i12);
                                                                                                                                doaddres(i13);
                                                                                                                                if (res>currmax) {
                                                                                                                                    currmax = res;
                                                                                                                                    towerres[0] = i0+1;
                                                                                                                                    towerres[1] = i1+1;
                                                                                                                                    towerres[2] = i2+1;
                                                                                                                                    towerres[3] = i3+1;
                                                                                                                                    towerres[4] = i4+1;
                                                                                                                                    towerres[5] = i5+1;
                                                                                                                                    towerres[6] = i6+1;
                                                                                                                                    towerres[7] = i7+1;
                                                                                                                                    towerres[8] = i8+1;
                                                                                                                                    towerres[9] = i9+1;
                                                                                                                                    towerres[10] = i10+1;
                                                                                                                                    towerres[11] = i11+1;
                                                                                                                                    towerres[12] = i12+1;
                                                                                                                                    towerres[13] = i13+1;
                                                                                                                                }
                                                                                                                            } 
                                                                                                                                }
                                                                                                                            } else {
                                                                                                                                vector<bool> added(area.size(),false);
                                                                                                                                ll res = 0;
                                                                                                                                doaddres(i0);
                                                                                                                                doaddres(i1);
                                                                                                                                doaddres(i2);
                                                                                                                                doaddres(i3);
                                                                                                                                doaddres(i4);
                                                                                                                                doaddres(i5);
                                                                                                                                doaddres(i6);
                                                                                                                                doaddres(i7);
                                                                                                                                doaddres(i8);
                                                                                                                                doaddres(i9);
                                                                                                                                doaddres(i10);
                                                                                                                                doaddres(i11);
                                                                                                                                doaddres(i12);
                                                                                                                                doaddres(i13);
                                                                                                                                doaddres(i14);
                                                                                                                                if (res>currmax) {
                                                                                                                                    currmax = res;
                                                                                                                                    towerres[0] = i0+1;
                                                                                                                                    towerres[1] = i1+1;
                                                                                                                                    towerres[2] = i2+1;
                                                                                                                                    towerres[3] = i3+1;
                                                                                                                                    towerres[4] = i4+1;
                                                                                                                                    towerres[5] = i5+1;
                                                                                                                                    towerres[6] = i6+1;
                                                                                                                                    towerres[7] = i7+1;
                                                                                                                                    towerres[8] = i8+1;
                                                                                                                                    towerres[9] = i9+1;
                                                                                                                                    towerres[10] = i10+1;
                                                                                                                                    towerres[11] = i11+1;
                                                                                                                                    towerres[12] = i12+1;
                                                                                                                                    towerres[13] = i13+1;
                                                                                                                                    towerres[14] = i14+1;
                                                                                                                                }
                                                                                                                            }              
                                                                                                                        }
                                                                                                                    } else {
                                                                                                                        vector<bool> added(area.size(),false);
                                                                                                                        ll res = 0;
                                                                                                                        doaddres(i0);
                                                                                                                        doaddres(i1);
                                                                                                                        doaddres(i2);
                                                                                                                        doaddres(i3);
                                                                                                                        doaddres(i4);
                                                                                                                        doaddres(i5);
                                                                                                                        doaddres(i6);
                                                                                                                        doaddres(i7);
                                                                                                                        doaddres(i8);
                                                                                                                        doaddres(i9);
                                                                                                                        doaddres(i10);
                                                                                                                        doaddres(i11);
                                                                                                                        doaddres(i12);
                                                                                                                        doaddres(i13);
                                                                                                                        if (res>currmax) {
                                                                                                                            currmax = res;
                                                                                                                            towerres[0] = i0+1;
                                                                                                                            towerres[1] = i1+1;
                                                                                                                            towerres[2] = i2+1;
                                                                                                                            towerres[3] = i3+1;
                                                                                                                            towerres[4] = i4+1;
                                                                                                                            towerres[5] = i5+1;
                                                                                                                            towerres[6] = i6+1;
                                                                                                                            towerres[7] = i7+1;
                                                                                                                            towerres[8] = i8+1;
                                                                                                                            towerres[9] = i9+1;
                                                                                                                            towerres[10] = i10+1;
                                                                                                                            towerres[11] = i11+1;
                                                                                                                            towerres[12] = i12+1;
                                                                                                                            towerres[13] = i13+1;
                                                                                                                        }
                                                                                                                    } 
                                                                                                                }
                                                                                                            } else {
                                                                                                                vector<bool> added(area.size(),false);
                                                                                                                ll res = 0;
                                                                                                                doaddres(i0);
                                                                                                                doaddres(i1);
                                                                                                                doaddres(i2);
                                                                                                                doaddres(i3);
                                                                                                                doaddres(i4);
                                                                                                                doaddres(i5);
                                                                                                                doaddres(i6);
                                                                                                                doaddres(i7);
                                                                                                                doaddres(i8);
                                                                                                                doaddres(i9);
                                                                                                                doaddres(i10);
                                                                                                                doaddres(i11);
                                                                                                                doaddres(i12);
                                                                                                                if (res>currmax) {
                                                                                                                    currmax = res;
                                                                                                                    towerres[0] = i0+1;
                                                                                                                    towerres[1] = i1+1;
                                                                                                                    towerres[2] = i2+1;
                                                                                                                    towerres[3] = i3+1;
                                                                                                                    towerres[4] = i4+1;
                                                                                                                    towerres[5] = i5+1;
                                                                                                                    towerres[6] = i6+1;
                                                                                                                    towerres[7] = i7+1;
                                                                                                                    towerres[8] = i8+1;
                                                                                                                    towerres[9] = i9+1;
                                                                                                                    towerres[10] = i10+1;
                                                                                                                    towerres[11] = i11+1;
                                                                                                                    towerres[12] = i12+1;
                                                                                                                }
                                                                                                            } 
                                                                                                        }
                                                                                                    } else {
                                                                                                        vector<bool> added(area.size(),false);
                                                                                                        ll res = 0;
                                                                                                        doaddres(i0);
                                                                                                        doaddres(i1);
                                                                                                        doaddres(i2);
                                                                                                        doaddres(i3);
                                                                                                        doaddres(i4);
                                                                                                        doaddres(i5);
                                                                                                        doaddres(i6);
                                                                                                        doaddres(i7);
                                                                                                        doaddres(i8);
                                                                                                        doaddres(i9);
                                                                                                        doaddres(i10);
                                                                                                        doaddres(i11);
                                                                                                        if (res>currmax) {
                                                                                                            currmax = res;
                                                                                                            towerres[0] = i0+1;
                                                                                                            towerres[1] = i1+1;
                                                                                                            towerres[2] = i2+1;
                                                                                                            towerres[3] = i3+1;
                                                                                                            towerres[4] = i4+1;
                                                                                                            towerres[5] = i5+1;
                                                                                                            towerres[6] = i6+1;
                                                                                                            towerres[7] = i7+1;
                                                                                                            towerres[8] = i8+1;
                                                                                                            towerres[9] = i9+1;
                                                                                                            towerres[10] = i10+1;
                                                                                                            towerres[11] = i11+1;
                                                                                                        }
                                                                                                    } 
                                                                                                }
                                                                                            } else {
                                                                                                vector<bool> added(area.size(),false);
                                                                                                ll res = 0;
                                                                                                doaddres(i0);
                                                                                                doaddres(i1);
                                                                                                doaddres(i2);
                                                                                                doaddres(i3);
                                                                                                doaddres(i4);
                                                                                                doaddres(i5);
                                                                                                doaddres(i6);
                                                                                                doaddres(i7);
                                                                                                doaddres(i8);
                                                                                                doaddres(i9);
                                                                                                doaddres(i10);
                                                                                                if (res>currmax) {
                                                                                                    currmax = res;
                                                                                                    towerres[0] = i0+1;
                                                                                                    towerres[1] = i1+1;
                                                                                                    towerres[2] = i2+1;
                                                                                                    towerres[3] = i3+1;
                                                                                                    towerres[4] = i4+1;
                                                                                                    towerres[5] = i5+1;
                                                                                                    towerres[6] = i6+1;
                                                                                                    towerres[7] = i7+1;
                                                                                                    towerres[8] = i8+1;
                                                                                                    towerres[9] = i9+1;
                                                                                                    towerres[10] = i10+1;
                                                                                                }
                                                                                            }        
                                                                                        }
                                                                                    } else {
                                                                                        vector<bool> added(area.size(),false);
                                                                                        ll res = 0;
                                                                                        doaddres(i0);
                                                                                        doaddres(i1);
                                                                                        doaddres(i2);
                                                                                        doaddres(i3);
                                                                                        doaddres(i4);
                                                                                        doaddres(i5);
                                                                                        doaddres(i6);
                                                                                        doaddres(i7);
                                                                                        doaddres(i8);
                                                                                        doaddres(i9);
                                                                                        if (res>currmax) {
                                                                                            currmax = res;
                                                                                            towerres[0] = i0+1;
                                                                                            towerres[1] = i1+1;
                                                                                            towerres[2] = i2+1;
                                                                                            towerres[3] = i3+1;
                                                                                            towerres[4] = i4+1;
                                                                                            towerres[5] = i5+1;
                                                                                            towerres[6] = i6+1;
                                                                                            towerres[7] = i7+1;
                                                                                            towerres[8] = i8+1;
                                                                                            towerres[9] = i9+1;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            } else {
                                                                                vector<bool> added(area.size(),false);
                                                                                ll res = 0;
                                                                                doaddres(i0);
                                                                                doaddres(i1);
                                                                                doaddres(i2);
                                                                                doaddres(i3);
                                                                                doaddres(i4);
                                                                                doaddres(i5);
                                                                                doaddres(i6);
                                                                                doaddres(i7);
                                                                                doaddres(i8);
                                                                                if (res>currmax) {
                                                                                    currmax = res;
                                                                                    towerres[0] = i0+1;
                                                                                    towerres[1] = i1+1;
                                                                                    towerres[2] = i2+1;
                                                                                    towerres[3] = i3+1;
                                                                                    towerres[4] = i4+1;
                                                                                    towerres[5] = i5+1;
                                                                                    towerres[6] = i6+1;
                                                                                    towerres[7] = i7+1;
                                                                                    towerres[8] = i8+1;
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        vector<bool> added(area.size(),false);
                                                                        ll res = 0;
                                                                        doaddres(i0);
                                                                        doaddres(i1);
                                                                        doaddres(i2);
                                                                        doaddres(i3);
                                                                        doaddres(i4);
                                                                        doaddres(i5);
                                                                        doaddres(i6);
                                                                        doaddres(i7);
                                                                        if (res>currmax) {
                                                                            currmax = res;
                                                                            towerres[0] = i0+1;
                                                                            towerres[1] = i1+1;
                                                                            towerres[2] = i2+1;
                                                                            towerres[3] = i3+1;
                                                                            towerres[4] = i4+1;
                                                                            towerres[5] = i5+1;
                                                                            towerres[6] = i6+1;
                                                                            towerres[7] = i7+1;
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                vector<bool> added(area.size(),false);
                                                                ll res = 0;
                                                                doaddres(i0);
                                                                doaddres(i1);
                                                                doaddres(i2);
                                                                doaddres(i3);
                                                                doaddres(i4);
                                                                doaddres(i5);
                                                                doaddres(i6);
                                                                if (res>currmax) {
                                                                    currmax = res;
                                                                    towerres[0] = i0+1;
                                                                    towerres[1] = i1+1;
                                                                    towerres[2] = i2+1;
                                                                    towerres[3] = i3+1;
                                                                    towerres[4] = i4+1;
                                                                    towerres[5] = i5+1;
                                                                    towerres[6] = i6+1;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        vector<bool> added(area.size(),false);
                                                        ll res = 0;
                                                        doaddres(i0);
                                                        doaddres(i1);
                                                        doaddres(i2);
                                                        doaddres(i3);
                                                        doaddres(i4);
                                                        doaddres(i5);
                                                        if (res>currmax) {
                                                            currmax = res;
                                                            towerres[0] = i0+1;
                                                            towerres[1] = i1+1;
                                                            towerres[2] = i2+1;
                                                            towerres[3] = i3+1;
                                                            towerres[4] = i4+1;
                                                            towerres[5] = i5+1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                vector<bool> added(area.size(),false);
                                                ll res = 0;
                                                doaddres(i0);
                                                doaddres(i1);
                                                doaddres(i2);
                                                doaddres(i3);
                                                doaddres(i4);
                                                if (res>currmax) {
                                                    currmax = res;
                                                    towerres[0] = i0+1;
                                                    towerres[1] = i1+1;
                                                    towerres[2] = i2+1;
                                                    towerres[3] = i3+1;
                                                    towerres[4] = i4+1;
                                                }
                                            }
                                        }
                                    } else {
                                        vector<bool> added(area.size(),false);
                                        ll res = 0;
                                        doaddres(i0);
                                        doaddres(i1);
                                        doaddres(i2);
                                        doaddres(i3);
                                        if (res>currmax) {
                                            currmax = res;
                                            towerres[0] = i0+1;
                                            towerres[1] = i1+1;
                                            towerres[2] = i2+1;
                                            towerres[3] = i3+1;
                                        }
                                    }
                                }
                            } else {
                                vector<bool> added(area.size(),false);
                                ll res = 0;
                                doaddres(i0);
                                doaddres(i1);
                                doaddres(i2);
                                if (res>currmax) {
                                    currmax = res;
                                    towerres[0] = i0+1;
                                    towerres[1] = i1+1;
                                    towerres[2] = i2+1;
                                }
                            }
                        }
                    } else {
                        vector<bool> added(area.size(),false);
                        ll res = 0;
                        doaddres(i0);
                        doaddres(i1);
                        if (res>currmax) {
                            currmax = res;
                            towerres[0] = i0+1;
                            towerres[1] = i1+1;
                        }
                    }
                }
            } else {
                vector<bool> added(area.size(),false);
                ll res = 0;
                doaddres(i0);
                if (res>currmax) {
                    currmax = res;
                    towerres[0] = i0+1;
                }
            }
        }
        cout<<"Case Number  "<<casenum<<endl;
        cout<<"Number of Customers: "<<currmax<<endl;
        cout<<"Locations recommended:";
        for1(i,0,towerres.size()) cout<<' '<<towerres[i];
        cout<<endl<<endl;
        
        casenum++;
    }
    return 0;
}