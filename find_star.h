#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef FIND_STAR_H_
#define FIND_STAR_H_
class star{
private:
	vector<int> input;
	vector<int> candy;
	bool flag_super=false;
	vector<int> sup;
public:
	star();
	void get_input();
	void find_star();
	void find_super();
	void showstar();
	void showsuper();
};




#endif 
