/*
Given an unsorted array. 
The task is to find all the star and super 
star elements in the array. Star are those 
elements which are strictly greater than all 
the elements on its right side. Super star 
are those elements which are strictly greater
 than all the elements on its left and right side.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "find_star.h"
using namespace std;
star::star(){}
void star::get_input(){
	cout<<"in get_input"<<endl;
  string str;
  char* token;
  char* cstr;
  int cur;
  getline(cin,str);
  cstr=new char[str.length()+1];
  strcpy(cstr,str.c_str());
  
  token=strtok(cstr," ");
  while(token!=NULL){
  	printf("%s",token);
      cur=atoi(token);
  //    cout<<cur<<endl;
      input.push_back(cur);
      token=strtok(NULL," ");

  }
}
void star::find_star(){
	vector<int>::iterator it;
	reverse(input.begin(),input.end());
	it=input.begin();
	candy.push_back(*it);
	advance(it,1);

	for(int i=0;it!=input.end();it++,i++){
	    if(*it>input.at(i-1)){
	    	candy.push_back(*it);  //?
	    	flag_super=true;
	    }
	}
}
void star::find_super(){
	vector<int>::iterator it;
    if(flag_super==true){

	it=candy.end();
    }
    int count=0;
    vector<int>::iterator an;
    for(an=input.end();an!=input.begin();an--){
    	if(*an<=*it){
    		count++;
    	}
}
    if(count==input.size())
    	sup.push_back(*it);

}
void star::showstar(){
	cout<<"the star elements are: "<<" "<<endl;
	vector<int>::iterator it;
	for(it=candy.begin();it!=candy.end();it++){
		cout<<*it<<" ";
	}
}
void star::showsuper(){
    cout<<"the super element is: "<<" "<<endl;
    vector<int>::iterator it;
    for(it=sup.begin();it!=sup.end();it++){
    	cout<<*it<<" ";
    }
}

int main(){

        star my;
        my.get_input();
        my.find_star();
        my.showstar();
        my.find_super();
        my.showsuper();

    return 0;
}



