#include<bits/stdc++.h>
using namespace std;

int D[] = {1,5,2,10};
int n = 4;
int w = 13;



int coin_change(int w, int D[], int n){
	int cnts = 0;
	
	while(w > 0){
		if(w >= D[n-1]){ //13 > 10
			w = w - D[n-1]; //13-10
			cnts = cnts + 1;
		}else {
			n--;
		}
	}
	
//	int i = n-1;
//	while((w > 0) && (i >= 0)){
//
//		int coin = w / D[i]; //13/10 = .3
//		cout << coin << " ";
//		cnts = cnts + coin;
//		w = w-coin*D[i--];
//	}
	
	
	return cnts;
}


int main(){
	sort(D, D + n);
	
	for(int i = 0; i < n; i++){
		cout << D[i] << " ";
	}
	cout << endl;
	cout << endl << coin_change(w, D, n);
	
	return 0;
}
