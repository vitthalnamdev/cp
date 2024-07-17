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

void solve( A<int,double>a /*this invokes the copy constructor but not the default constructor.*/){
     
}
int main(){
 A<int , double>a;
 // invokes the copy constructor.
 solve(a);
  
}