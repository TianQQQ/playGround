#include <iostream>
#include <thread>

using namespace std;

void printnums(int start, int n){
	for (int i = 0; i< n ;i++){
		cout <<"["<<start + i << "]" << endl;
	}
}

int main(){
	thread t1(printnums, 0 , 100);
}
