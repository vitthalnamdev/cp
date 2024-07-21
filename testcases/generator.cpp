#include "bits/stdc++.h"
using namespace std;
 
int main()
{

	srand(time(NULL));
	
	// correct
	int n = rand()%10 + 3;
	int l = rand()%100+1;
    l = n+l;
	int k = rand()%n;
	cout<<n<<" "<<l<<" "<<k<<endl;
	vector<int>numbers(n);
	int last = l , first = 0;   
    numbers[n-1] = l;numbers[0] = 0;
	for (int i = 1; i < n - 1; ++i) {
        numbers[i] = first + rand() % (last - first);
    }

    std::sort(numbers.begin() + 1, numbers.end() - 1);

    // Adjust numbers to be strictly increasing
    for (int i = 1; i < n - 1; ++i) {
        if (numbers[i] <= numbers[i - 1]) {
            numbers[i] = numbers[i - 1] + 1;
        }
    }
   for(int i=0;i<n;i++){
	cout<<numbers[i]<<" ";
   }cout<<endl;
	for(int i=0;i<n;i++){
		int x = rand()%20;
		cout<<x<<" ";
	}cout<<endl;
}