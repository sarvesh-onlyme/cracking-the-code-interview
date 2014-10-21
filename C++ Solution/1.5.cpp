#include<iostream>
#include<string>
using namespace std;

string compress(string *s){
	int len = (*s).length();
	string str="";
	str += (*s)[0];
	char a = (*s)[0];
	int count=0;
	for(int i=0; i<len; i++){
		if((*s)[i]==a){
			count++;
		}
		else{
			str += to_string(count);
			count = 1;
			a = (*s)[i];
			str += a;
		}
	}
	str += to_string(count);
	if(str.length()<len)
		return str;
	return *s;
}

int main(){

	string str;
	cin>>str;
	cout<<compress(&str);
	return 0;
}
