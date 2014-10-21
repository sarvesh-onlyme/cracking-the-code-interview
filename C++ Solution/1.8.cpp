#include<iostream>

using namespace std;

bool isSubstr(string a, string b){
	size_t found = a.find(b);
	if(found==-1)
		return false;
	else
		return true;
}

bool isRotation(string a, string b){
	if(a.length()==b.length())
		return isSubstr(a+a, b);
	return false;
}

int main(){
	string a, b;
	a = "waterbottle";
	b = "erbottlewat";
	cout<<isRotation(a, b)<<'\n';
	
	return 0;
}

