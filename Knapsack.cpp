#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Item{ 
	int value;
	int weight;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionKP(int W, struct Item t[], int n){ 
	sort(t, t+n, cmp); // sort item on basis of density
	int curWeight = 0; // current weight in knapsack
	double finalval = 0.0; // result
	for(int i=0; i<n; i++){ 
		if(curWeight + t[i].weight <= W){ // if we can add item 
			curWeight += t[i].weight;
			finalval += t[i].value;
		}else{ // if we can’t add current item
 			int remain = W - curWeight;
			finalval += t[i].value*((double)remain/t[i].weight);
			break;
		}
	}
	return finalval;
}

int main(int argc, char** argv){
	int W; // Weight of knapsack
	Item arr[] = { { 25, 18 },
				   { 24, 15 },
				   { 15, 10},
				   { 8, 5} };
				   
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Input Weigh if knapsack ";
	cin >> W;
	cout << endl;
	// Function Call
	cout << "Maximum profit earned = " << fractionKP(W, arr, size); 
	return 0;
}
