#include<iostream>
#include<cstring>
using namespace std;

void reverse(char* s){
	int len = strlen(s);
	char tmp;
	for(int i=0; i<int(len/2); i++){
		tmp = *(s+i);
		*(s+i) = *(s+len-i-1);
		*(s+len-i-1) = tmp;
	}
}

int main(){

	char *s = new char;
	cin>>s;
	reverse(s);
	cout<<s<<'\n';
	return 0;
}
