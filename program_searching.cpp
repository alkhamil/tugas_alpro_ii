/* Author : Nazmudin = 181011450118 */
#include <iostream>
#include <string>

using namespace std;

void loading();
void head(string title);
void sequencialSearch(int data[], int n, int x, int *idx);
void seqProses();
void binarySearch(int data[], int n, int x, int *idx);
void binProses();

int main(){
	string title;
	char ulang;
	int pilih;   
	home:
	head("");
	cout<<"1. SQUENCIAL SEARCH\n2. BINARY SEARCH\n\n";
	cout<<"Pilih menu pencarian [1/2] = ";cin>>pilih;
	cout<<"\n";
	switch(pilih){
		case 1:
			loading();
			sequen:
				system("cls");
			title = "SQUENCIAL SEARCH\n";
			head(title);
			seqProses();
			cout<<"Kembali ke menu utama ?[y/n] ";cin>>ulang;
			switch(ulang){
				case 'y':
					goto home;
					break;
				case 'Y':
					goto home;
					break;
				case 'n':
					goto sequen;
					break;
				case 'N':
					goto sequen;
					break;
				default:
					cout<<"GoodBye !";
					exit(0);
			}
			break;
		case 2:
			loading();
			bin:
				system("cls");
			title = "BINARY SEARCH\n";
			head(title);
			binProses();
			cout<<"Kembali ke menu utama ?[y/n] ";cin>>ulang;
			switch(ulang){
				case 'y':
					goto home;
					break;
				case 'Y':
					goto home;
					break;
				case 'n':
					goto bin;
					break;
				case 'N':
					goto bin;
					break;
				default:
					cout<<"GoodBye !";
					exit(0);
			}
			break;
		default:
			cout<<"Menu tidak ada !\n";
			break;
	}
}

void head(string title){
	cout<<"METODE PENCARIAN DATA "<<title<<"\n";
}

void sequencialSearch(int data[], int n, int x, int *idx){
	int i = 0;
	while(i < n-1 && data[i] != x){
		i++;
		if(data[i] == x){
			*idx = i;
		}else{
			*idx = -1;
		}
	}
}

void seqProses(){
	int n=10, idx, x;
	int data[n] = {23,56,10,90,35,45,9,100,200,65};
	cout<<"DATA = [ ";
	for(int i=0; i<n; i++){
		if(i != n-1){
			cout<<data[i]<<", ";
		}else {
			cout<<data[i];	
		}
	}
	cout<<" ]\n";
	cout<<"\nMasukan data yang dicari = ";cin>>x;
	sequencialSearch(data, n, x, &idx);
	if(idx != -1){
		cout<<"Data berada pada index : "<<idx<<"\n";
	}else{
		cout<<"Data tidak ada \n";
	}
}

void binarySearch(int data[], int n, int x, int *idx){
	bool ketemu = false;
	int top = n-1, bottom = 0, mid;
	while(bottom<=top && !ketemu){
		mid = (top+bottom)/2;
		if(data[mid] == x){
			ketemu = true;
		}else{
			if(data[mid] < x){
				top = mid - 1;
			}else{
				bottom = mid + 1;
			}
		}
		
		if(ketemu){
			*idx = mid;
		}else{
			*idx = -1;
		}
	}
}

void binProses(){
	int n = 8;
	int data[n] = {81,76,21,18,16,13,10,5};
	int x, idx, i;
	cout<<"DATA = [ ";
	for(int i=0; i<n; i++){
		if(i != n-1){
			cout<<data[i]<<", ";
		}else {
			cout<<data[i];	
		}
	}
	cout<<" ]\n";
	cout<<"\nMasukan data yang dicari = ";cin>>x;
	binarySearch(data, n, x, &idx);
	if(idx != -1){
		cout<<"Data berada pada index : "<<idx<<"\n";
	}else{
		cout<<"Data tidak ada\n";
	}

}

void loading(){
	for(int i=0; i<100; i+=5){
		cout<<"Loading ("<<i<<") %";
		system("cls");
	}
}
