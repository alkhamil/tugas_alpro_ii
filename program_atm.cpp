#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Declare function
void loading();
void header();
int getPin();
int getSaldo();

int main(){
	home :
	int saldo_awal = getSaldo(), i = 1, pin_input, tarik, setor, trf, pilihan;
	long int norek;
	do {
		header();
		cout<<"MASUKAN PIN ANDA = ";cin>>pin_input;
		menu :
		if(pin_input == getPin()){
			loading();
			header();
			cout<<"Selamat datang :)\n";
			cout<<"------------------\n";
			cout<<"1. Tarik Tunai \n2. Setor Tunai \n3. Cek Saldo \n4. Transfer \n5. Keluar \n\n";
			cout<<"Masukkan pilihan menu : ";cin>>pilihan;
			switch(pilihan){
				case 1:
					tarik :
					system("cls");
					header();
            		cout<<"Penarikan = ";cin>>tarik;
            		loading();
            		if(tarik%50000!=0 || tarik<0){
            			system("cls");
						header();
                		cout<<"Masukkan total uang dengan pecahan 50000\n";
                		system("pause");
                		system("cls");
                		goto tarik;
            		}else{
                		if(tarik > saldo_awal){
                    		cout<<"Saldo anda tidak cukup \n";
                		}else{
                			saldo_awal -= tarik;
                			system("cls");
							header();
                			cout<<"Total saldo anda sekarang = "<<saldo_awal<<"\n";
                		}
                		system("pause");
                		system("cls");
                		goto menu;
            		}
        			break;
        		case 2:
        			setor :
        			system("cls");
					header();
        			cout<<"Penyetoran = ";cin>>setor;
        			loading();
        			if(setor%50000!=0 || setor<0){
        				system("cls");
						header();
                		cout<<"Masukkan total uang dengan pecahan 50000\n";
                		system("pause");
                		system("cls");
                		goto setor;
            		}else{
            			saldo_awal += setor;
            			system("cls");
						header();
                		cout<<"Total saldo anda sekarang = "<<saldo_awal<<"\n";
                		system("pause");
                		system("cls");
                		goto menu;
					}
					break;
				case 3:
					loading();
					system("cls");
					header();
					cout<<"Saldo anda = "<<saldo_awal<<"\n";
            		system("pause");
            		system("cls");
            		goto menu;
            		break;
            	case 4:
            		trf :
            		system("cls");
					header();
            		cout<<"Masukan no rekening = ";cin>>norek;
            		loading();
            		if(norek != 18101145){
            			system("cls");
						header();
            			cout<<"No rekening tidak sesuai !\n";
            			system("pause");
                		system("cls");
            			goto trf;
					}else{
						system("cls");
						header();
						cout<<"Nama Nasabah = Nazmudin\n";
            			cout<<"No Rekening	= "<<norek<<"\n\n";
            			cout<<"----------------------------\n";
            			cout<<"Masukan jumlah trf = ";cin>>trf;
            			if(trf > saldo_awal){
            				cout<<"Saldo anda tidak cukup \n";
						}else{
							saldo_awal -= trf;
							cout<<"Total saldo anda sekarang = "<<saldo_awal<<"\n";
						}
            			system("pause");
                		system("cls");
                		goto menu;
					}
            	case 5:
            		loading();
            		system("cls");
					header();
           			cout<<"GoodBye !\n";
           			exit(0);
           			break;
           		default :
           			loading();
           			system("cls");
					header();
            		cout<<"\Pilihan yang anda pilih tidak ada ";
            		system("pause");
            		system("cls");
            		goto menu;
        			break;
			}
		}else{
			loading();
			cout<<"Pin yang anda masukan tidak sesuai !\n";
		}
	i++;
	}while(i <= 3);
	system("cls");
	header();
	cout<<"Maaf akun anda terblokir sementara \nsilahkan hubungi CS !\n";
}

void loading(){
	for(int i=0;i<=100;i = i + 10){
    	cout<<endl<<"Loading . . . "<<i<<"%"<<endl;
        system("cls");
    }
}

void header(){
	cout<<"-----------------------------------\n";
	cout<<"\t    ATM PROGRAM\n";
	cout<<"    BY NAZMUDIN | 181011450118\n";
	cout<<"-----------------------------------\n\n";
}

int getSaldo(){
	string line;
	int saldo;
	ifstream data("data.txt");
	getline(data, line);
	saldo = atoi(line.c_str());
	return saldo;
}

int getPin(){
	return 123456;
}


