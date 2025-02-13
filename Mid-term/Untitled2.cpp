#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, M;
    cin >> n >> M;
    
    vector<double> value;
    vector<double> weight;
    vector<double> ratio;
    vector<double> select(n);
    vector<double> index;
    
	
	for(int i = 0; i < n; i++){
		double weg = 0;
		cin >> weg;
		weight.push_back(weg);
		index.push_back(i);
	}
	
	for(int i = 0; i < n; i++){
		double val = 0;
		cin >> val;
		value.push_back(val);
	}
	
	for(int i = 0; i < n; i++){
		double rati = value[i] / weight[i];
		ratio.push_back(rati);
	}	
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ratio[j] < ratio[i]){
				swap(ratio[i], ratio[j]);
				swap(weight[i], weight[j]);
				swap(value[i], value[j]);
				swap(index[i], index[j]);
			}
		}
	}
	
	double sum_weg = 0;
	double sum_val = 0;
	double _test = 0;
	
	double total = 0;
	double persen = 0;
	for(int i = 0; i < n; i++){
		_test = sum_weg + weight[i]; 
		
		if(_test <= M){
			sum_weg = sum_weg + weight[i];
			select.insert(select.begin() + i, 1);
			sum_val = sum_val + value[i];
		} else {
			total = M - sum_weg;
			persen = total / weight[i];
			select.insert(select.begin() + i, persen);
			sum_weg = sum_weg + total;
			sum_val = sum_val + (value[i]*persen);
			break;
			
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(index[j] > index[i]){
				swap(index[i], index[j]);
				swap(select[i], select[j]);
			}
		}
	}
	
	cout << endl;
	
	for(int i=0; i<n; i++){
		cout << select[i] << " ";
	}
	cout << endl;
	cout << sum_val;
	
	
    return 0;
}

