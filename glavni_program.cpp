#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <sstream>

using namespace std;

struct osoba{
	string ime;
	string prezime;
	string spol;
	int dan,mj,god;
	int ai, bi, ci, di;
};

string ime(int i){
	stringstream ime;
	if(i<10) ime << "Imena";
	else ime << "Imen";
	ime << i;
	return ime.str();
}

string prezime(int i){
	stringstream prez;
	if(i<10) prez << "Prezimena";
	else prez << "Prezimen";
	prez << i;
	return prez.str();
}
string aSpol[2]={"muski ", "zenski"};


#include "red_polje.h"
//#include "red_pokazivaci.h"


queue ljudi, brza_linija, prvi_salter, drugi_salter, treci_salter, cetvrti_salter, peti_salter;
int main(){
	srand(time(NULL));
	InitQ(&ljudi);
	int p;
	if(ljudi.front==0) p=1;
	int n,i,k=0;
	bool flag = true;
	cout<<"Program radi sljedece! "<<endl;
	cout<<"1. - Generiranje niza od N cetvrokti <ai, bi, ci, di> slucajnih brojeva"<<endl<<"2. - Ispis osoba horoskopa Jarac mladjih od 40"<<endl<<"3. - Odlazak trudnica zbog cekanja vise od 250 jedinica vremena "<<endl<<"4. - Simulira uvodjenje brze linije u poslovnicu poste"<<endl<<endl;
	cout<<"Koliko N cetvorki generiram? (zbog pregleda ne preporucam preko 85)";
	cin>>n;
	int cetvorke[n][4];
		
	for(i=0; i<n; i++){
		osoba nova;
		nova.ai=rand()%491+10; nova.bi=rand()%721+80; nova.ci=rand()%5+1; nova.di=rand()%5+1;
		nova.ime=ime(i+1); nova.prezime=prezime(i+1);
		nova.dan=rand()%31+1; nova.mj=rand()%12+1; nova.god=rand()%45+1970;
		if(nova.ci==3) nova.spol="zenski";
		else nova.spol=aSpol[rand()%2];
		EnQueueQ(nova, &ljudi);
	}

	sort(&ljudi, i, 0, &prvi_salter, &drugi_salter, &treci_salter, &cetvrti_salter, &peti_salter);
	cout<<"2. - Ispis osoba horoskopa Jarac mladjih od 40 na salteru Lutrije!"<<endl<<endl;
	ispis_jarci(&ljudi);
	
	cout<<"\n____________________________________________________________"<<endl;
	cout<<"2.a - Ispis glavnog reda "<<endl<<endl;
	Ispis(&ljudi);
	
	cout<<"\n____________________________________________________________"<<endl;
	cout<<"3. - Bijeg trudnica zbog cekanja vise od 250 jedinica vremena "<<endl<<endl;
	brisi_trudne(&ljudi);
	Ispis(&ljudi);
	InitQ(&brza_linija);
	
	cout<<"\n____________________________________________________________"<<endl;
	cout<<"4. - Uvodjenje brze linije u poslovnicu Hrvatske Poste "<<endl<<endl;
	simulator(&ljudi, &brza_linija);
	
	cout<<"------> brza linija <-----------------------------------------"<<endl;
	Ispis(&brza_linija);

	cout<<"\n------> glavni red <------------------------------------------"<<endl;
	Ispis(&ljudi);
	sort(&ljudi, i, 1, &prvi_salter, &drugi_salter, &treci_salter, &cetvrti_salter, &peti_salter);
	
	cout<<"\n------> 1 - predaja/preuzimanje posiljke <--------------------"<<endl;
	Ispis(&prvi_salter);
	
	cout<<"\n------> 2 - placanje racuna <----------------------------------"<<endl;
	Ispis(&drugi_salter);
	
	cout<<"\n------> 3 - uplata lutrije <----------------------------------"<<endl;
	Ispis(&treci_salter);
	
	cout<<"\n------> 4 - Western Union <-----------------------------------"<<endl;
	Ispis(&cetvrti_salter);
	
	cout<<"\n------> 5 - Evotv <-------------------------------------------"<<endl;
	Ispis(&peti_salter);
	
	return 0;
}



