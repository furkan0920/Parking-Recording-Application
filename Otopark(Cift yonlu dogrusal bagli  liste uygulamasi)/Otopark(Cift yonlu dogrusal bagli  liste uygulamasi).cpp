#include<iostream>
#include<fstream>   //dosya işlemi yapan kutuphane
#include <locale.h>
#include <string.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

struct node {
	string plaka;
	string aracTipi;
	int ucret;
	node* next;
	node* prev;
};
node* head = NULL;

void ekle(string plaka1, string aracTipi1, int ucret1)
{
	system("cls");
	node* arac = new node;
	arac->plaka = plaka1;
	arac->aracTipi = aracTipi1;
	arac->ucret = ucret1;

	if (head == NULL) {
		head = arac;
		head->next = NULL;
		head->prev = NULL;
		cout << plaka1 << " plakali ilk arac otoparka alindi" << endl;
	}
	else {
		arac->next = head;
		head->prev = arac;

		head = arac;
		head->prev = NULL;
		cout << plaka1 << " plakali arac otopark alindi" << endl;
	}

}

void cikar(string plaka1) {
	system("cls");
	bool sonuc = false;
	if (head == NULL) {
		cout << " otopark bos, cikartilacak arac yok" << endl;
		sonuc = true;
	}
	else {
		if (head->next == NULL && head->plaka == plaka1) {
			node* temp = head->next;
			delete head;
			head = temp;
			head->prev = NULL;
			sonuc = true;
		}
		else if (head->next != NULL && head->plaka == plaka1) {
			node* temp = head->next;
			delete head;
			head = temp;
			head->prev = NULL;
			sonuc = true;
		}
		else {
			node* temp = head;
			while (temp->next != NULL)
			{
				if (temp->plaka == plaka1) {
					node* temp2 = temp->prev;
					node* temp3 = temp->next;
					delete temp;

					temp2->next = temp3;
					temp3->prev = temp2;
					cout << plaka1 << " plakali arac otoparktan cikartildi" << endl;
					sonuc = true;
					break;
				}
				temp = temp->next;
			}
			if (temp->plaka == plaka1) {
				node* temp2 = temp->prev;
				delete temp;
				temp2->next = NULL;
				cout << plaka1 << " plakali arac otoparkdan cikarildi" << endl;
				sonuc = true;
			}
		}
	}
	if (!sonuc) {
		cout << plaka1 << " plakali arac otoparkta yoktur" << endl;
	}

}

void yazdir() {
	system("cls");
	if (head == NULL) {
		cout << "otoparkta arac yoktur" << endl;
	}
	else {
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
			temp = temp->next;
		}
	}
}

void adet() {
	system("cls");
	int adet = 0;
	if (head == NULL) {
		cout << "otoparkta arac yoktur" << endl;
	}
	else {
		node* temp = head;
		while (temp != NULL)
		{
			adet++;
			temp = temp->next;
		}
		cout << " otoparkta bulunan arac sayisi: " << adet << endl;
	}
}

void ucretToplami() {
	system("cls");
	int toplam = 0;
	if (head == NULL) {
		cout << "otoparkta arac yoktur" << endl;
	}
	else {
		node* temp = head;
		while (temp != NULL)
		{
			toplam += temp->ucret;
			temp = temp->next;
		}
		cout << " otoparkta bulunan araclarin toplam ucreti: " << toplam << endl;
	}
}

void dosyaYaz() {
	ofstream yaz("otopark.txt", ios::app);
	if (head == NULL) {
		cout << "dosyaya aktarilacak otoparkta arac yoktur" << endl;
	}
	else {
		node* temp = head;
		while (temp->next != NULL)
		{
			yaz << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
			temp = temp->next;
		}
		yaz << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
		yaz.close();
		cout << "otoparkta bulunan aracalar 'otopark.txt' isimli dosyaya kaydedildi" << endl;
	}
}

void dosyadanOku() {
	system("cls");
	ifstream oku("otopark.txt");
	string satir = "";
	while (getline(oku, satir))
	{
		cout << satir << endl;
	}
	oku.close();
}

int main() {
	int ucret, secim;
	string plaka, aracTipi;
	while (1)
	{
		cout << endl;
		cout << "Otopark Uygulamasi " << endl;
		cout << "1-- arac ekle" << endl;
		cout << "2-- arac cikar" << endl;
		cout << "3-- otoparktaki araclarin listesini getir " << endl;
		cout << "4-- otoparktaki arac sayisi " << endl;
		cout << "5-- otoparktaki araclarin toplam ucreti " << endl;
		cout << "6-- otoparktaki araclari dosyaya kaydet" << endl;
		cout << "7-- dosyada kayitli araclari getir" << endl;
		cout << "0-- CIKIS" << endl;
		cin >> secim;
		switch (secim) {
		case 1: cout << " otoparka alinacak arac bilgilerini giriniz ... " << endl;
			cout << " plaka :"; cin >> plaka;
			cout << " arac tipi :"; cin >> aracTipi;
			cout << " ucret : "; cin >> ucret;
			ekle(plaka, aracTipi, ucret);
			break;
		case 2: cout << " otoparktan cikartilacak aracın plakasi: "; cin >> plaka;
			cikar(plaka);
			break;
		case 3: yazdir();
			break;
		case 4: adet();
			break;
		case 5: ucretToplami();
			break;
		case 6: dosyaYaz();
			break;
		case 7: dosyadanOku();
			break;
		case 0: cout << "programdan cikildi ..." << endl;
			return 0;
			break;
		default: cout << "hatali secim yaptiniz " << endl;
			break;
		}
	}
}