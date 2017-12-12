/*
subset sum problem
*/

#include <iostream>
using namespace std;
int main(){
	int size;
	int test;
	cin>>test;

while(test!=0){
    int * p;
	cin>>size;
	int k;
	int sum=0;
	int cur=0;
	bool equalflag=false;
	
    p=new int [size];
    
    for(int i=0;i<size;i++){
    	cin>>p[i];
	}
	cin>>k;
	for(int i=0;i<size;i++){
	      if(equalflag==false){
	      	if(p[i]<k){
	      		++cur;
			  }
			else if(p[i]>k){
				cur=0;
			}
			else if(p[i]==k){
				++cur;
				equalflag=true;
		//		cout<<"we get the equal"<<" ";
		//		cout<<p[i]<<endl;
			}
		  }else{
		  	if(p[i]<=k){
		  		++cur;
			  }
			else{
				equalflag=false;
				sum+=cur;
				cur=0;
		//		cout<<" the length is "<<sum<<endl;
			  }
	        }
	}
	if(equalflag==true){
	sum+=cur;
	cur=0;
	equalflag=false;
}
	cout<<sum<<endl;
	sum=0;
	delete[] p;
	--test;
}	
	return 0;
}
