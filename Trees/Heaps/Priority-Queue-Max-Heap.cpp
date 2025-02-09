#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue<int> pq;
	// Adding elements
	pq.push(10);
	pq.push(5);
	pq.push(20);
	// Display and remove elements in priority order
	cout << "Priority Queue (Max-Heap): ";
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}
