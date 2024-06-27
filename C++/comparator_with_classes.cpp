#include<bits/stdc++.h>
using namespace std;
class a{
 public:
 // this is called call operator.
 bool operator()(int a, int b){
     return a>b;
 }
};

int main(){
set<int , a>s;
s.insert(4);s.insert(2);s.insert(4);
for(auto i:s)cout<<i<<" ";cout<<endl;
}