#include <iostream>

using namespace std;
int main() {
    long long n,m,f=-1,kol=0;
    long long ji[200002];
    long long tk[200002];
    long long ot[200002];
    cin >> n >> m;
    for (long long i=0;i<n+m;i++){
        cin >> ji[i];
    }
    for (long long i=0;i<n+m;i++){
        cin >> tk[i];
        if (tk[i]==1&&f==-1) f=i;
    }
    ot[0]=f;
    for (long long i=f , j=f;j<n+m;i=j){
        j++;
        while (j<n+m&&tk[j]!=1) {
            j++;
        }
        if (j<n+m) {
            kol++;
            for(long long k=i+1;k<j;k++){
                if ((ji[k]-ji[i])<=(ji[j]-ji[k])) {
                    ot[kol-1]++;
                } else {
                    ot[kol]++;
                }
            }
        } else {
            for(long long k=i+1;k<n+m;k++){
                ot[kol]++;
            }
        }

    }
    for (int i=0;i<=kol;i++){
        cout << ot[i] << " ";
    }
    return 0;
}