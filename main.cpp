#include"TStackList.h"
#include"TQueueList.h"

using namespace std;

int main() {

	TQueueList<int> q;
	TStackList<int> s;

	for (int i = 0; i < 10; i++) {
		q.push(i * 2);
	}
	for (int i = 0; i < 10; i++) {
		cout << q.pop() << " ";
	}cout<<"\n";
	////////////////////////////////////////////////
	for (int i = 60; i < 75; i++) {
		q.push(i * 3);
	}
	for (int i = 60; i < 75; i++) {
		cout << q.pop() << " ";
	}cout<<"\n";
	////////////////////////////////////////////////
	for (int i = 0; i < 10; i++) {
		s.push(i * 2);
	}
	for (int i = 0; i < 10; i++) {
		cout << s.pop() << " ";
	}cout<<"\n";
	///////////////////////////////////////////////
	for (int i = 30; i < 40; i++) {
		s.push(i * 3);
	}
	for (int i = 30; i < 40; i++) {
		cout << s.pop() << " ";
	}cout<<"\n";

	int a=0;
	int fl = 1;
	long double*p =new long double[(int)2e8+4e7];
	while (!s.full()) {
		s.push(a++);
	}
	delete[] p;
	cout << a << "\n";
	
	return 0;
}