/*
Get the first x elements in an array of size n using the Heapsort algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;
void fixHeap(int arr[],int size, int i);
void k_Sort(int arr,int size);
void print_k(int arr[],int k);
void fixHeap(int arr[],int size, int i){
	int root=i;
	int left=2*i;
	int right=2*i+1;
	
	if(right<size){
       if(arr[right]>arr[left]) {
	    root=right;
	}
	   else {
	   root=left;
    }
}
    else{
     	if(left<size&&arr[left]>arr[root])
     	root=left;
	 }
	 
	if(arr[root]>arr[i]){
		
		cout<<"we change the"<<" "<<root<<" "<<"element "<<arr[root]<<" "<<"with the"<<" "<<i<<" "<<"element"<<" "<<arr[i]<<endl;
   	swap(arr[root],arr[i]);
   	fixHeap(arr,size,root);
   }
}
void k_Sort(int arr[],int k,int size){
	assert(k<size);
	for(int j=size/2-1;j>=0;j--){
		cout<<"fix the"<<" "<<j<<" "<<"interial node"<<" ";
		fixHeap(arr,size,j);
	}
	int i=k;
	int index=size-1;
	cout<<"==================="<<endl;
	cout<<size<<endl;
	for(int p=0;p<size;p++){
		cout<<arr[p]<<endl;
	}
	cout<<"======================="<<endl;
	while(i>0){
		cout<<arr[index]<<" "<<arr[0]<<endl;
	
		swap(arr[0],arr[index]);
		index--;
		fixHeap(arr,index,0);	
		i--;
	}
}


int main(){
	

	int* a;
	int size;
	int k;
	cout<<"enter size of array:"<<endl;
	cin>>size;
	if(size>0){
		a=new int [size];
	    int m=0;
	    cout<<"enter the elements:"<<endl;
		while(m<size){
			cin>>a[m];
			m++;
		}		
	cout<<"enter the first k elements that you want: "<<endl;
    cin>>k;
    if(k>0&&k<=size){
         k_Sort(a,k,size);
    	int j=size-1;
	while(k>0){
		cout<<a[j]<<endl;
		k--;
		return 0;
	}
    }else{
	
	cout<<"invaild k,error";
    exit(1);  	
	}
	}else{	
	cout<<"size should be positive";
    exit(1);
    }
}
