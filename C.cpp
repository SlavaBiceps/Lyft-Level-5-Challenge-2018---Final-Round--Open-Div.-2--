#include <iostream>

using namespace std;
int main() {
    int n,m,kol=0,koll=0;
    int ver[90000];
    int goro[90000];
    int gork[90000];
    int gory[90000];
    int x[80000];
    int y[80000];
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ver[i];
    }
    for (int i=0;i<m;i++){
        cin >> goro[i] >> gork[i] >> gory[i];
    }
    for (int i=0;i<n;i++){
        for (int k=0;k<m;k++){
            if ((goro[k]==1)&&(goro[k]<=ver[i])&&(gork[k]>=ver[i])) {
                kol++;
                x[kol]=ver[i];
                y[kol]=gory[k];
            }
        }
    }
    for (int k=0;k<m;k++){
        if ((goro[k]==1)&&(gork[k]==1000000000)) {
            kol++;
            x[kol]=1000000000;
            y[kol]=gory[k];
        }
    }
    int ch=0;
    while (kol>0) {
        ch++;
        int mix=1000000002;
        int miy=1000000002;
        for (int i=1;i<=kol;i++){
            mix=min(x[i],mix);
            miy=min(y[i],mix);
        }
        int xx = 0;
        int yy = 0;
        if (mix!=1000000000) {
            for (int i = 1; i <= kol; i++) {
                if (x[i] == mix) {
                    xx++;
                }
                if (y[i] == miy) {
                    yy++;
                }
            }
        }
        if (xx>yy) {
            koll=0;
            for (int i=1;i<=kol;i++) {
                if (x[i]!=mix) {
                    koll++;
                    x[koll]=x[i];
                    y[koll]=y[i];
                }
            }
        } else {
            koll = 0;
            for (int i = 1; i <= kol; i++) {
                if (y[i] != miy) {
                    koll++;
                    x[koll] = x[i];
                    y[koll] = y[i];
                }
            }
        }
        kol=koll;
    }
    cout << ch;
    return 0;
}