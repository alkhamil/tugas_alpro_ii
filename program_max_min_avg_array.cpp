/* Author : Nazmudin/181011450118 */
#include <iostream>

using namespace std;

int main(){
	int n , nilai;
	int max = 0 , min = 2147483647;
	float avg, hasil = 0;
	cout<<"Masukan banyaknya nilai : ";
	cin>>n;
	int data[n];
	for(int i=0; i<n; i++){
		cout<<"Masukan nilai ke-"<<i+1<<" : ";
		cin>>nilai;
		data[i] = nilai;
		hasil = hasil + data[i];
		if(nilai > max){
			max = nilai;
		}
		if(nilai < min){
			min = nilai;
		}
		if(i == n-1){
			cout<<"\n";
			cout<<"Data : [";
			/* Menampilkan kumpulan data yg di input menjadi larik atau array */
			for(int j=0; j<n; j++){
				if(j != n-1){
					cout<<data[j]<<",";
				}else {
					cout<<data[j];	
				}
			}
			cout<<"]";
		}
	}
	avg = hasil/n;
	cout<<"\n";
	cout<<"=====================================\n";
	cout<<"Hasil semua nilai	: "<<hasil<<"\n";
	cout<<"Nilai rata-rata		: "<<avg<<"\n";
	cout<<"Nilai maximum		: "<<max<<"\n";
	cout<<"Nilai minimum		: "<<min;
}

