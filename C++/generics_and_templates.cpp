#include<iostream>
using namespace std;
template<class V , class T>class A{
 public:
 
 A(){
    cout<<"Constructor Called"<<endl;
 }
 ~A(){
    cout<<"HELLO WORLD"<<endl;
 }
};
class B{
    public:
 B(){
    cout<<"HELLO"<<endl;
 }
};
void solve(){
    cout<<"SOLVE"<<endl;
}
int main(){
 A<int , double>a;
 solve();
 cout<<"VITTHAL"<<endl;
}