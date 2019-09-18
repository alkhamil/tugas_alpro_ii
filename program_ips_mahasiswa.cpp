/* Author : Nazmudin/181011450118 */
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

int main(){
	menu :
		system("cls");
	char nilai , yesno;
	int i;
	float 	bobot_nilai, 
			number_sks,
			tampung_sks = 0,
			tampung_nilai = 0,
			ip_mhs;
		
	string 	nama_mhs,
			nim_mhs;
			
	string data[8][2] = {
		{"Kalkulus", "4"},
		{"Fisika Dasar", "3"},
		{"PTI", "2"},
		{"Sistim Digital", "2"},
		{"PSO", "2"},
		{"Logika Matematika", "2"},
		{"Bahasa Inggris", "2"},
		{"Agama", "2"}
	};
	
	map<char,int> grade;
	grade['A'] = 4;
	grade['B'] = 3;
	grade['C'] = 2;
	grade['D'] = 1;
	grade['E'] = 0;
	
	size_t n = sizeof(data)/sizeof(data[0]);
	cout<<"=====================================\n";	
	cout<<"PROGRAM MENGHITUNG NILAI IP MAHASISWA\n";
	cout<<"=====================================\n";
	cout<<"Masukan Nama	: ";
	cin>>nama_mhs;
	cout<<"Masukan NIM 	: ";
	cin>>nim_mhs;
	
	cout<<"\n~ Masukan nilai / grade dengan huruf kapital [A - E] ~'\n";
	
	/* MELAKUKAN INPUT NILAI BERDASARKAN MATAKULIAH */	
	cout<<"\n";
	for(i=0; i<n; i++){
		cout<<"Masukan nilai "<<data[i][0]<<" = ";
		cin>>nilai;
		if(nilai != 'A' && nilai != 'B' && nilai != 'C' && nilai != 'D' && nilai != 'E'){
			cout<<"\n";
			cout<<"Masukan nilai yang benar !\n\n";
			cout<<"Ulangi ? [Y/N]";
			cin>>yesno;
			if(yesno == 'Y' || yesno == 'y'){
				goto menu;
			}else{
				cout<<"Goodbye !";
				exit(0);
			}
			
		}
		number_sks		= atoi(data[i][1].c_str());
		bobot_nilai		= grade[nilai] * number_sks;
		tampung_nilai	= tampung_nilai + bobot_nilai;
		tampung_sks		= tampung_sks + number_sks;
	}
	
	/* MENAMPILKAN DATA DARI VARIABLE DATA */
	cout<<"---------------------------------\n";
	cout<<"|NO |MATKUL \t\t|"<<"SKS\t|\n";
	cout<<"---------------------------------\n";
	for(int index=0; index<n; index++){
		cout<<"|"<<index+1<<"  |";
		cout<<data[index][0];
		if(index == 1 || index == 3 || index == 5 || index == 6){
			cout<<"\t| ";	
		}else if(index == 2 || index == 4 || index == 7){
			cout<<"\t\t| ";
		}else if(index == 0){
			cout<<"\t\t| ";
		}
		cout<<data[index][1]<<"\t|"<<"\n";
	}
	cout<<"---------------------------------\n";
	
	ip_mhs = tampung_nilai/tampung_sks;
	cout<<"---------------------------------\n";
	cout<<"NAMA		= "<<nama_mhs<<"\n";
	cout<<"NIM		= "<<nim_mhs<<"\n";		
	cout<<"TOTAL SKS	= "<<tampung_sks<<"\n";
	cout<<"NILAI IP MHS	= "<<ip_mhs<<"\n";
	cout<<"---------------------------------\n";
}
