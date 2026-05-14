#include<iostream>
#include<string>
using namespace std;

class Personel { // main class
protected:
	string ad;
	string soyad;
	int id;
	float maas;
public:
	void setBilgiler(string a , string s , int i , float m) {
		ad = a;
		soyad = s;
		id = i;
		maas = m;
	}

	void tanit() const {
		cout << " Ad: " << ad << ", Soyad: " << soyad << ", ID: " << id << ", Maas: " << maas << endl;
	}
};


class Sofor : public Personel {
private:
	string ehliyetSinifi;
public:
	void setEhliyet(string sinifehliyet) {
		ehliyetSinifi = sinifehliyet;
	}
	void tanit() const {
		cout << "---------[Sofor Bilgisi]---------" << endl;
		Personel::tanit();
		cout << "Ehliyet Sinifi: " << ehliyetSinifi << endl;
	}
	void aracKullan() {
		cout << ad << " isimli sofor arac kullaniyor!" << endl;
	}
};

class KargoPersoneli : public Personel {
private:
	string dagitimBolgesi;
public:
	void setBolge(string db) {
		dagitimBolgesi = db;
	}
	void tanit() const {
		cout << "---------[Kargo Personeli Bilgisi]---------" << endl;
		Personel::tanit();
		cout << "Dagitim Bolgesi: " << dagitimBolgesi << endl;
	}
	void paketTeslimEt() const {
		cout << ad << " genel bir paket teslimi yapti" << endl;
	}
	void paketTeslimEt (string musteriAdi) const {
		cout << ad << " isimli kargo personeli " << musteriAdi << "icin kargoyu teslim etti." << endl;
	}
};

class Yonetici : public Personel {
private:
	string departman;
public:
	void setDepartman(string d) {
		departman = d;
	}
	void tanit() const {
		cout << "---------[Yonetici Bilgisi]---------" << endl;
		Personel::tanit();
		cout << " Departman:  " << departman << endl;
	}

	void toplantiYap() {
		cout << ad << " isimli yonetici bir toplanti duzenledi." << endl;
	}
	
};

int main() {
	string choice;
	cout << "---------Kargo Takip Sistemine Hos Geldiniz---------" << endl;
	cout << "|?| Sofor |?| KargoPersoneli |?| Yonetici |?|" << endl;
	cout << "Lutfen bir secim yapiniz" << endl;
	cin >> choice;

	if (choice != "Sofor" && choice != "KargoPersoneli" && choice != "Yonetici") {
		cout << "Gecersiz Personel Girisi Yaptiniz!" << endl;
		cout << "Lutfen Uc Personel Turunden Birini Seciniz!" << endl;
		return 1;
	}
	string ad, soyad;
	int id;
	float maas;

	cout << " Adiniz: ";
	cin >> ad;
	cout << " Soyadiniz: ";
	cin >> soyad;
	cout << " ID Numaraniz: ";
	cin >> id;
	cout << " Maas Bilginiz: ";
	cin >> maas;


	if (choice == "Sofor") {
		Sofor s;
		string ehliyetsinifi1;
		cout << " Soforun Ehliyet Sinifini Giriniz: ";
		cin >> ehliyetsinifi1;
		s.setBilgiler(ad, soyad, id, maas);
		s.setEhliyet(ehliyetsinifi1);
		s.tanit();
		s.aracKullan();
	}
	else if (choice == "KargoPersoneli") {
		KargoPersoneli k;
		string gorevbolgesi;
		cout << " Kargo Personelinin Gorev Bolgesini Giriniz: ";
		cin >> gorevbolgesi;
		k.setBilgiler(ad, soyad, id, maas);
		k.setBolge(gorevbolgesi);
		k.tanit();
		k.paketTeslimEt();
		string teslimAlan;
		cout << " Kargoyu Teslim Alacak Olan Kisinin Ismini Giriniz: ";
		cin >> teslimAlan;
		k.paketTeslimEt(teslimAlan);
	}
	else if (choice == "Yonetici") {
		Yonetici y;
		string departman;
		cout << " Yoneticinin departmanini giriniz: ";
		cin >> departman;
		y.setBilgiler(ad, soyad, id, maas);
		y.setDepartman(departman);
		y.tanit();
		y.toplantiYap();
	}
	
	return 0;
	
}