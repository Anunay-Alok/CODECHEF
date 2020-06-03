
#include <bits/stdc++.h>
using namespace std;
#define ull long long
 
vector<ull> parent(100001),size(100001);

ull getMinVal(const string& s1, const string& s2) {
    ull sz1 = s1.size();
    ull sz2 = s2.size();
    ull sz = min(sz1, sz2);
    ull ans = 0;
    for (ull i = 0; i < sz; ++i) {
        if(s1[i] == s2[i] and s1[sz1 - i - 1] == s2[sz2 - i - 1]) ans++;
        else break;
    }
    return (ans * ans);
}

void setParents(ull n) {
    for (ull i = 0; i < n; ++i) {
        parent[i] = i;
        size[i]=1;
    }
}

bool ifPossible(const string& s1, const string& s2) {
    return s1[0] == s2[0] and s1[s1.size() - 1] == s2[s2.size() - 1];
}
  
ull unionFind(ull v) {
    return ((v == parent[v]) ? v : (parent[v] = unionFind(parent[v])));
}
 
void takeUnion(ull a, ull b) {
    a = unionFind(a);
    b = unionFind(b);
    if (a != b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main() {
    ull t; 
    cin>>t;
    while (t--) {
        ull n;
        scanf("%llu", &n);
        char a[100001];
        setParents(n);
        unordered_set<string> ifRepeated;
        string temp_str;
        ull res = 0;
        vector<string> str;
        if(n <= 1e3){
          str.resize(n);
        }
        vector<pair<ull, pair<ull,ull>>> vec;
        for (ull i = 0; i < n; ++i) {
            cin >> temp_str;
            if(n > 1e3){
              if(ifRepeated.find(temp_str) != ifRepeated.end()){
                  res += ((temp_str.length())*(temp_str.length()));
                  ifRepeated.erase(temp_str);
              }
              else{
                  ifRepeated.insert(temp_str);
              }
            }
            else{
             str[i]=temp_str;
            }
        }
        if(n > 1e3){
          for(auto i : ifRepeated){
              str.push_back(i);
          }
        }
        n = str.size();
        sort(str.begin(), str.end());
        for (ull i = 0; i < n - 1; ++i) {
            for (ull j = i + 1; j < n; ++j) {
                if (ifPossible(str[i], str[j])) {
                    ull x = getMinVal(str[i], str[j]);
                    vec.emplace_back(make_pair(-x, make_pair(i, j)));
                }
            }
        }
        sort(vec.begin(), vec.end());
        ull m = vec.size();
        unordered_map<ull, bool> pair_map;
        for (ull i = 0; i < m; ++i) {
            if (pair_map[vec[i].second.first] || pair_map[vec[i].second.second])
            	continue;
            pair_map[vec[i].second.first] = pair_map[vec[i].second.second] = 1;
            ull a = vec[i].second.first, b = vec[i].second.second, l = vec[i].first;
            if (unionFind(a) != unionFind(b)) {
                takeUnion(a, b);
                res += -l;
            }
        }
        printf("%llu\n", res);
    }
    return 0;
}

