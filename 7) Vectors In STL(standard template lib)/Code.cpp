#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	////creating vector
	//vector<int>v;
	//vector<int>v1(5, 1);
	//// size and capacity
	//cout << "size of v: " << v.size() << endl;
	//cout << "capacity of v: " << v.capacity() << endl;
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(2);
	//cout << "size of v: " << v.size() << endl;
	//cout << "capacity of v: " << v.capacity() << endl;

	//cout << "size of v1: " << v1.size() << endl;
	//cout << "capacity of v1: " << v1.capacity() << endl;
	//v1.push_back(2);

	//cout << "capacity of v1: " << v1.capacity() << endl;	
//
//	vector<int>vnew;
//	vnew.push_back(4);
//	vnew.push_back(5);
//	vnew.push_back(7);
//	vnew.push_back(10);
//	vnew.push_back(94);
//	vnew.pop_back();
//	cout << "size of vnew: " << vnew.size() << endl;
//	cout << "capacity of vnew: " << vnew.capacity() << endl;
//
////removing from certain value
//	vnew.erase(vnew.begin() + 1); //1 is the index of the value to be removed
//	cout << "size of vnew: " << vnew.size() << endl;
//	cout << "capacity of vnew: " << vnew.capacity() << endl;
//	for (auto i = 0; i<vnew.size(); i++)
//		cout << vnew[i] << " ";
//	//insertion at an index
//	cout << endl;
//	vnew.insert(vnew.begin() + 1, 50);
//	for (auto i = 0; i< vnew.size(); i++)
//		cout << vnew[i] << " ";
//	//replace value
//	vnew[1] = 37;
//	cout << endl;
//	vnew.insert(vnew.begin() + 1, 50);
//	for (auto i = 0; i < vnew.size(); i++)
//		cout << vnew[i] << " ";
//	//removing all elements
//	vnew.clear();
//	cout << "size of vnew: " << vnew.size() << endl;
//	cout << "capacity of vnew: " << vnew.capacity() << endl;

	//printing front element
	//vector<int>arr;
	//arr.push_back(2);
	//arr.push_back(12);
	//arr.push_back(21);
	//arr.push_back(122);
	//cout << arr[0] << endl;
	//cout << arr.front() << endl;
	//cout << arr[arr.size() - 1] << endl;
	//cout << arr.back() << endl;

	//vector<int>a;
	////copy value of 1 vector to another
	//a = arr;
	//for (auto i : arr)
	//	cout << i << " ";

	vector<int>ans;
	ans.push_back(5);
	ans.push_back(235);
	ans.push_back(15);
	ans.push_back(54);
	ans.push_back(125);

	//sort in inc order
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i<<" ";
	cout << endl;

	////sort in dec order
	//sort(ans.rbegin(), ans.rend());
	//for (auto i : ans)
	//	cout << i << " ";

	//Binary searching
	cout << binary_search(ans.begin(), ans.end(), 55) << endl;
	//gives answer in 0 1 if zero ny hy if 1 to hy

	//finding index
	cout << find(ans.begin(), ans.end(), 54) - ans.begin() << endl;
	//jo value dp gy uska index a jy ga

}
