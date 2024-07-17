#include<bits/stdc++.h>
using namespace std;


 int n=2;
 
/*Difference between structures and classes.*/
/*Read about what is data integrity.*/
class employees{
  public:
  int a,b;
  /* we have to access the data inside any method.*/
  employees(){
   a= 0;b = 0;
  }
  void setdata();

  // when the word nesting appears use function inside the function.
};
void employees ::/*scope resolution operator */ setdata(){
   this->a = 0;this-> b= 0;
}
int main(){
    int arr[n];
    // we can declare classes in main functions or driver functions too/
    class a{
      public:
      int b,c;
    };
    a A;
    A.b = 5;
}



/*
Stack memory allocation vs heap memory allocation.
Stack memory allocation-> it is not dyanamic , its size is fixed .
Heap ..................-> it is dyanamic , it is as big as the virtual memory of our system.
In Heap, we have allocate and deallocate ourself.(to delete an array =>  delete[]p ) 
there is another word , dangling pointer-> i.e. the pointer now is containing the address as previously.
but the container that the pointer is pointing to, is now containing some garbage value. 
, if we don't delete the memory then it may cause memory leake , may cause a serious problems in servers types.

while in stack the system handles the deallocation part itself. 




*/


/*
what is the size of different pointers.
*/