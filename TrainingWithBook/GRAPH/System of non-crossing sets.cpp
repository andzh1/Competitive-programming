#include <bits/stdc++.h>
using namespace std; 

int find(int x, int link[]){
    while(x != link[x]) x = link[x];
    return x;
}

//find2() is faster, than find()
int find2(int x, int link[]){
    if(x == link[x]) return x;
    return link[x] = find(link[x]);
}

bool same(int a, int b, int link[]){
    return find(a, link) == find(b, link);
}

int getSize(int a, int n, int link[], int size[]){
    if(size[a] > 0) return size[a];
    int ans = 1;
    for(int i = 0; i < n; i++) if(link[i] == a && i != a) {
        ans += getSize(i, n, link, size);
    }
    size[a] = ans;
    return ans;
}

void unite(int a, int b, int link[], int size[]){
    a = find(a, link);
    b = find(b, link);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int main(){
    int n;
    cin >> n;
    int link[n], size[n];
    for(int i = 0; i < n; i++) {
        cin >> link[i];
        link[i] --;
    }
    for(int i = 0; i < n; i++) size[i] = -1;
    for(int i = 0; i < n; i++) getSize(i, n, link, size);
    // for(int i = 0; i < n; i++) cout << size[i] << " ";

}