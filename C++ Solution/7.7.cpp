#include<iostream>
#include<queue>
using namespace std;

int findKthMagicNo(int k){
	if(k<2){
		if(k<1)
			return 0;
		return 1;
	}
	int no=1, res=0;
	queue<int> Q3,  Q5, Q7;
	Q3.push(3);
	Q5.push(5);
	Q7.push(7);
	for(int i=2; i<=k; i++){
		int a = Q3.front(), b = Q5.front(), c = Q7.front();
		if(a<b && a<c){
			res = a;
			Q3.pop();
			Q3.push(a*3);
			Q5.push(a*5);
			Q7.push(a*7);
		}
		else if(b<c){
			res = b;
			Q5.pop();
			Q5.push(b*5);
			Q5.push(b*7);
		}
		else{
			res = c;
			Q7.pop();
			Q7.push(c*7);
		}
	}
	return res;
}

int main(){
	int k=13;
	cout<<findKthMagicNo(k);
	return 0;
}