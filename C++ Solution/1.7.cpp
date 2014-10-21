#include<iostream>
#include<cstring>
using namespace std;

void set(int *arr, int row, int col){
	
	int r[row];
	int c[col];
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	for(int i=0; i<row*col; i++){
		if(*(arr+i)==0){
			r[int(i/col)] = 1;
			c[i%col] = 1;
		}
	}
	for(int i=0; i<row; i++){
		if(r[i]==0)
			continue;
		for(int j=0; j<col; j++){
			*(arr+i*col+j) = 0;
			cout<<i*col+j<<'\n';
		}
	}
	for(int i=0; i<col; i++){
		if(c[i]==0)
			continue;
		for(int j=0; j<row; j++){
			*(arr+j*col+i) = 0;
		}
	}
	return;
}

int main(){
	int a[4][5] ={{0, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 0, 0, 20}};
	set(*a, 4, 5);
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			cout<<*(*a+i*5+j)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
