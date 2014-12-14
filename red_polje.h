#include <cstdlib> 
#include <iostream>
using namespace std;
typedef int element;

struct qu {
	osoba polje[10000];
	int front,rear;
};

typedef struct qu queue;
typedef int element;

void InitQ(queue *Q){
	Q->front=0;
	Q->rear=9999;
	return;
}

int AddOne(int n) {
	return((n+1)%10000);
}

int MinusOne(int n) {
	if(n==0) return 9999;
	else return n-1;
}

bool IsEmptyQ(queue *Q){
	return AddOne(Q->rear)==Q->front;
}

void EnQueueQ(osoba x, queue *Q){
	if (AddOne(AddOne(Q->rear)) == Q->front) {
		cout<<"Red je pun!";
		return;
	}
	Q->rear=AddOne(Q->rear);
	Q->polje[Q->rear] = x;
	return;
}
void DeQueueQ(queue *Q){
	if(IsEmptyQ(Q)) {
		cout<<"Lista je prazna nemam sto obrisati!"<<endl;
		return;
	}
	Q->front=AddOne(Q->front);
}

osoba FrontQ(queue *Q){
	return Q->polje[Q->front];
}

void Ispis(queue *Q){
	if(IsEmptyQ(Q)) return;	
	for(int k=Q->front; k<=Q->rear; k++) cout<<Q->polje[k].ime<<" "<<Q->polje[k].prezime<<" "<<Q->polje[k].spol<<" <"<<Q->polje[k].ai<<", "<<Q->polje[k].bi<<", "<<Q->polje[k].ci<<", "<<Q->polje[k].di<<"> datum: "<<Q->polje[k].dan<<"."<<Q->polje[k].mj<<endl;
	return;
}

void mini_sort(osoba polje[], int br_ljudi){
	int i,j, flag=1;
	osoba temp;
	for(i=1; (i<=br_ljudi); i++){
		flag=0;
		for(j=0; j<br_ljudi-1;j++){
			if(polje[j+1].ai > polje[j].ai) {
				temp=polje[j];
				polje[j]=polje[j+1];
				polje[j+1]=temp;
				flag=1;
			}
		}
	}
}
void mini_sort2(osoba polje[], int br_ljudi){
	int i,j, flag=1;
	osoba temp;
	for(i=1; (i<=br_ljudi); i++){
		flag=0;
		for(j=0; j<br_ljudi-1;j++){
			if(polje[j+1].ci < polje[j].ci) {
				temp=polje[j];
				polje[j]=polje[j+1];
				polje[j+1]=temp;
				flag=1;
			}
		}
	}
}

int ArrSize(queue *Q){
	return (Q->rear - Q->front)+1;
}
void sort(queue *Q, int z, int nacin, queue *prvi_salter, queue *drugi_salter, queue *treci_salter, queue *cetvrti_salter, queue *peti_salter){
	osoba prvi[z],drugi[z],treci[z],cetvrti[z],peti[z];
	int size_prvi=0, size_drugi=0, size_treci=0, size_cetvrti=0, size_peti=0;
	int br_ljudi = 0;
	element pom;

	pom= 0;
	do{
		if(Q->polje[pom].di==1){
			prvi[size_prvi]=Q->polje[pom];
			size_prvi++;
		}
		if(Q->polje[pom].di==2){
			drugi[size_drugi]=Q->polje[pom];
			size_drugi++;
		}
		if(Q->polje[pom].di==3){
			treci[size_treci]=Q->polje[pom];
			size_treci++;
		}
		if(Q->polje[pom].di==4){
			cetvrti[size_cetvrti]=Q->polje[pom];
			size_cetvrti++;
		}
		if(Q->polje[pom].di==5){
			peti[size_peti]=Q->polje[pom];
			size_peti++;
		}
		br_ljudi++;
		pom++;
	}while(pom<=Q->rear);
	
	
	mini_sort(prvi,size_prvi);
	mini_sort(drugi,size_drugi);
	mini_sort(treci,size_treci);
	mini_sort(cetvrti,size_cetvrti);
	mini_sort(peti,size_peti);
	
	InitQ(Q);
	
	if(nacin==0){
		InitQ(prvi_salter);
	for(int k=0; k<size_prvi; k++) {
		EnQueueQ(prvi[k], prvi_salter);
		EnQueueQ(prvi[k], Q);
	}
	
	InitQ(drugi_salter);
	for(int k=0; k<size_drugi; k++) {
		EnQueueQ(drugi[k], drugi_salter);
		EnQueueQ(drugi[k], Q);
	}
	
	InitQ(treci_salter);
	for(int k=0; k<size_treci; k++) {
		EnQueueQ(treci[k], treci_salter);
		EnQueueQ(treci[k], Q);
	}
	
	InitQ(cetvrti_salter);
	for(int k=0; k<size_cetvrti; k++) {
		EnQueueQ(cetvrti[k], cetvrti_salter);
		EnQueueQ(cetvrti[k], Q);
	}
	
	InitQ(peti_salter);
	for(int k=0; k<size_peti; k++) {
		EnQueueQ(peti[k], peti_salter);
		EnQueueQ(peti[k], Q);
	}
	}
	
	
	if(nacin==1){

	mini_sort2(prvi,size_prvi);
	mini_sort2(drugi,size_drugi);
	mini_sort2(treci,size_treci);
	mini_sort2(cetvrti,size_cetvrti);
	mini_sort2(peti,size_peti);


	InitQ(peti_salter);
	for(int k=0; k<size_peti; k++) {
		EnQueueQ(peti[k], peti_salter);
		EnQueueQ(peti[k], Q);
	}
	InitQ(cetvrti_salter);
	for(int k=0; k<size_cetvrti; k++) {
		EnQueueQ(cetvrti[k], cetvrti_salter);
		EnQueueQ(cetvrti[k], Q);
	}
	InitQ(treci_salter);
	for(int k=0; k<size_treci; k++) {
		EnQueueQ(treci[k], treci_salter);
		EnQueueQ(treci[k], Q);
	}
	InitQ(drugi_salter);
	for(int k=0; k<size_drugi; k++) {
		EnQueueQ(drugi[k], drugi_salter);
		EnQueueQ(drugi[k], Q);
	}
	InitQ(prvi_salter);
	
	for(int k=0; k<size_prvi; k++) {
		EnQueueQ(prvi[k], prvi_salter);
		EnQueueQ(prvi[k], Q);
	}
	}
	return;
}

void ispis_jarci(queue *Q){
	element pom;
	pom= 0;
	do{
		bool jarac = (Q->polje[pom].mj==12 && Q->polje[pom].dan>22 && Q->polje[pom].dan<=31)||(Q->polje[pom].mj==1 && Q->polje[pom].dan>0 && Q->polje[pom].dan<=20); //&& (prvi[k].dan>0&&prvi[k].dan<20); //(out>="1222"&&out<"1232")||
		if(jarac&&Q->polje[pom].di==3&&Q->polje[pom].god>1974) cout<<Q->polje[pom].ime<<" "<<Q->polje[pom].prezime<<" "<<Q->polje[pom].spol<<" <"<<Q->polje[pom].ai<<", "<<Q->polje[pom].bi<<", "<<Q->polje[pom].ci<<", "<<Q->polje[pom].di<<"> datum: "<<Q->polje[pom].dan<<"."<<Q->polje[pom].mj<<"."<<Q->polje[pom].god<<endl;
		pom++;
	}while(Q->polje[AddOne(AddOne(pom))].ime!=FrontQ(Q).ime);
	return;
}

void brisi_trudne(queue *Q){
	element pom;
	pom= Q->front;
	do{
		if(Q->polje[pom].ci==3&&Q->polje[pom].ai>250){
			if(pom==Q->rear){
				Q->rear--;
				return;				
			}
			else{
			for (int i = pom; i<Q->rear; i++) 
        		Q->polje[i] = Q->polje[i+1];
			Q->rear--;
			brisi_trudne(Q);
			}

		}
		pom=AddOne(pom);	
	}while(pom<=Q->rear);
	return;
}

void ubaci_na_vrh(osoba x, queue *Q){
	element pom;
	pom = Q->front;
	if(!IsEmptyQ(Q))
		for (int i = Q->rear; i>=Q->front; i--) 
	        			Q->polje[AddOne(i)] = Q->polje[i];
	Q->polje[Q->front]=x;
	Q->rear=AddOne(Q->rear);

	return;
}

int prvi_limit=0,drugi_limit=0,treci_limit=0,cetvrti_limit=0,peti_limit=0;
void simulator(queue *Q, queue *P){
	element trenutni;
	trenutni= Q->front - 1;
	element prethodni;
	prethodni=Q->front - 1;
	element sljedeci;
	
	do{
		if( (Q->polje[trenutni].ci==4) || (prvi_limit<=2 && Q->polje[trenutni].di==1) || (drugi_limit<=2 && Q->polje[trenutni].di==2) || (treci_limit<=2 && Q->polje[trenutni].di==3) || (cetvrti_limit<=2 && Q->polje[trenutni].di==4) || (peti_limit<=2 && Q->polje[trenutni].di==5) ){
			
			ubaci_na_vrh(Q->polje[trenutni], P);

		    sljedeci = AddOne(trenutni);
		    if(trenutni==Q->rear) {

		    	Q->rear--; Q->rear--;
		    	if(Q->rear==-1) InitQ(Q);
		    	return;
		    }
		    else {
		    	Q->rear--; 
		    	for (int i = trenutni; i<=Q->rear; i++) 
        			Q->polje[i] = Q->polje[i+1];

		    	if(Q->polje[trenutni].di==1) prvi_limit++;
		    	if(Q->polje[trenutni].di==2) drugi_limit++;
		    	if(Q->polje[trenutni].di==3) treci_limit++;
		    	if(Q->polje[trenutni].di==4) cetvrti_limit++;
		    	if(Q->polje[trenutni].di==5) peti_limit++;

		    	simulator(Q,P);
		    }

		}
		
		trenutni=AddOne(trenutni);
		prethodni=AddOne(prethodni);
	}while(trenutni<=Q->rear);
	return;
}

