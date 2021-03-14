#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("test3.in");

void bubble(int v[], int n){

bool ok;
do{
    ok = 0;
    for(int i = 1;i<n;++i){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
            ok = 1;
        }
    }
}
while(ok);

}

void countSort(int v[], int n){

int w[10000] = {0};
for(int i = 1;i<=n;++i){
    w[v[i]]++;
}

for(int i = 2;i<=10000;++i){
    w[i] = w[i-1] + w[i];
}


int v1[n+1];
for(int i = 1;i<=n;++i){
    v1[w[v[i]]--] = v[i];
}


for(int i = 1;i<=n;++i){
    v[i] = v1[i];
}

}

void cntForRadix(int v[], int n, int e){

int v1[n];
int w[10000] = {0};

for(int i = 1;i<=n;++i){
    ++w[(v[i]/e)%10];
}

for(int i = 2;i<10000;i++){
    w[i] = w[i] + w[i-1];
}

for(int i = n;i>=1;--i){
    v1[w[(v[i]/e)%10]] = v[i];
    w[(v[i]/e)%10]--;
}

for(int i = 1;i<=n;++i){
    v[i] = v1[i];
}

}

void radix(int v[], int n){

int m = -1;
for(int i = 1;i<=n;++i){
    if(v[i] > m){
        m = v[i];
    }
}
for(int i = 1;m/i > 0;i*=10){
    cntForRadix(v, n, i);
}

}

void merge_s(int st , int m , int dr, int v[]){

int i = st;
int j = m+1;
int k=0;
int w[10000];
while(i<= m && j<=dr){

    if(v[i]<v[j]){w[++k] = v[i++];}
    else {w[++k] = v[j++];}

}

while(i<=m){w[++k] = v[i];++i;}
while(j<=dr){w[++k] = v[j];++j;}

for(int i = st , j=1;j<=k;++i , ++j)v[i] = w[j];
}

void divide(int st , int dr, int v[]){

if(st<dr){
    int m = (st+dr)/2;
    divide(st,m, v);
    divide(m+1,dr, v);
    merge_s(st,m,dr, v);
}

}

int pivot(int st , int dr, int v[]){

int x = v[st];
while(st<dr){
    while(st < dr && v[dr] >= x) --dr;
    v[st] = v[dr];
    while(st<dr && v[st] <= x) ++st;
    v[dr] = v[st];
}

v[st] = x;
return st;

}


void quick(int st , int dr, int v[]){

if(st < dr){

    int m = pivot(st,dr, v);
    quick(st,m, v);
    quick(m+1 , dr, v);

}

}

int main()
{
    int n, v[10001];
    fin>>n;
    for(int i = 1;i<=n;++i){
        fin>>v[i];
    }
    return 0;
    quick(1, n, v);
    return 0;
}
