/*quick sort*/

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int parti(vector<int>& vc,int first,int last);
void q_sort(vector<int>& vc, int first, int last);

int parti(vector<int>& vc,int first,int last){
	int temp=vc[first];
	int low=first;
	int high=last;
	
	while(low<high){
		while(vc[high]>temp){
			--high;
		}
		swap(vc[high],vc[low]);
		++low;
	}
	vc[low]=temp;
	return low;
}
void q_sort(vector<int>& vc, int first, int last){
	if(first==last)
	return;
	int mid=parti(vc,first,last);
	cout<<"the mid is"<<mid<<endl;
	q_sort(vc,first,mid);
	q_sort(vc,mid+1,last);
}

int main(){
	vector<int> v;
	v.push_back(42);
	v.push_back(30);
		v.push_back(24);
	v.push_back(3);
		v.push_back(4);
	v.push_back(9);
	q_sort(v,0,5);
	
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}

