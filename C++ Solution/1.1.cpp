#include<iostream>
#include<string>
using namespace std;

int main(){
	bool check[256] = {0};			
	string str = "qwertyuopdhflnczb";
	if(str.length()<=256){
		for (int i=0; i<str.length(); i++){
			if(check[int(str[i])]==1){
				cout<<"FALSE"<<i<<'\n';
				return 0;
			}
			else
				check[int(str[i])] = 1;
		}
	}
	else{
		cout<<"FALSE";
	}
	return 0;
}
