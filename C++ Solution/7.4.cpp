#include<iostream>
using namespace std;

int negate1(int a){
	int b =a;
	int neg = 0;
	int d = (b<0 ? 1:-1);
	while(b){
		neg += d;
		b += d;
	}
	return neg;
}

int multiply(int a, int b){
	if(b<0){
		a = negate1(a);
		b = negate1(b);
	}
	int res=0;
	for(int i=0; i<b; i++)
		res += a;
	return res;
}

int subtract(int a, int b){
	return a + negate1(b);
}

int divide(int a, int b){
	int tmpA=a, tmpB=b, absB=b;
	bool flag=true;		//positive
	if(a>0 && b>0)
		tmpB = negate1(b);
	else if(a>0 && b<0){
		absB = negate1(b);
		flag = false;
	}
	else if(a<0 && b>0){
		tmpA = negate1(a);
		flag = false;
		tmpB = negate1(b);
	}
	else{
		tmpA = negate1(a);
		absB = negate1(b);
	}
	int res = 0;
	while(tmpA >= absB){
		tmpA += tmpB;
		res += 1;
	}
	return (flag? res: negate1(res));
}

int main(){
	int a = -18, b = -9;
	cout<<multiply(a, b)<<'\n';
	cout<<subtract(a, b)<<'\n';
	cout<<divide(a, b)<<'\n';
	return 0;
}