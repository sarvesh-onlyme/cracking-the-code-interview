#include<iostream>
using namespace std;

void transpose(int* arr, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<i; j++){
			int tmp = *(arr+size*i+j);
			*(arr+size*i+j) = *(arr+size*j+i);
			*(arr+size*j+i) = tmp;
		}
	}
}

int main(){
	int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	transpose(*arr, 4);
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<'\n';
	}
}
