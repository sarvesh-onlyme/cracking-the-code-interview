#include<iostream>
#include<string>
using namespace std;

int anagramcmp(string a, string b){
	int arr[256] = {0}; //ascii
	int len = a.length();
	if(len != b.length())
		return 0;
	for(int i=0; i<len; i++){
		arr[int(a[i])]++;
		arr[int(b[i])]--;
	}
	for(int i=0; i<256; i++){
		if(arr[i] != 0)
			return 0;
	}
	return 1;
}

int main(){
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout<<anagramcmp(a, b)<<'\n';
	return 0;
}
