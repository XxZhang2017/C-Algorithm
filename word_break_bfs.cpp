/*word break problem using BFS*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	queue<int> q;
    	q.push(0);
    	
    	while(!q.empty()){
		
    	int i=q.front();
    	q.pop();
    	if(i==s.length()){
    		return true;
		}
   
    		for(int j=1;j+i<=s.length();j++){
    			vector<string>::iterator it;
    //		cout<<"the string is "<<s<<endl;
    //		cout<<"the range of substring is "<<i<<" "<<j+i<<endl;
    //		cout<<"we are finding "<<s.substr(i,j)<<" "<<"*********";
    		if(find(wordDict.begin(),wordDict.end(),s.substr(i,j))!=wordDict.end()){
    //			cout<<"got it"<<endl;
    			q.push(j+i);
    			//break;
			}
	//		else{
	//			cout<<"no"<<endl;
	//		}
            }
	
	}
    return false;
}	
};
int main(){
	vector<string> vec;
	Solution s;
	vec.push_back("leet");
	vec.push_back("code");
	cout<<s.wordBreak("leetcode",vec);
	return 0;
}
