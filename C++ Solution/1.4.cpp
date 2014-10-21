#include<iostream>
#include<string>
using namespace std;

void replaceSpace(string *s, int len){
	int count = 0;
	for(int i=0; i<len; i++){
		if((*s)[i]==' ')
			count++;
	}
	count *=2;
	for(int i=len-1; i>=0; i--){
		(*s)[i+count] = (*s)[i];
		if((*s)[i]==' '){
			count -=2;
			(*s)[i+count] = '%';
			(*s)[i+count+1] = '2';
			(*s)[i+count+2] = '0';
		}
	}
}

int main(){
	
	string str;
	int len;
	getline(cin, str);
	cin>>len;
	replaceSpace(&str, len);
	cout<<str<<'\n';	
	return 0;
}

