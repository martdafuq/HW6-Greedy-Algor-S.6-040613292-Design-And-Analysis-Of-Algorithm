#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sort(int D[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(D[j]>D[i])
			swap(D[i],D[j]);
		}
	}
}

int coinchange (int D[], int n, int W){ 
	int num = 0;
	int i=0;
	sort(D, n);
	while ((W > 0) && (i < n)){
		int coin = W/D[i];
		num += coin;
		W = W-coin*D[i++];
	}
	return num;
}

int main(int argc, char** argv) {
	int D[] = {1, 5, 2, 10};
	int value = 15;
	int size = sizeof(D)/sizeof(D[0]);
	int MinCount = coinchange(D, size, value);
	cout << "Total Coins Needed = " << MinCount << endl;
	cout << "Coin are: ";
	for(int i=0; i<MinCount; i++)
		cout << " " << D[i];
	cout << endl;
	return 0;
}
