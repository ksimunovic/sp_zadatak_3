#include <cstdlib> 

struct qu {
	osoba value;
	struct qu *next;
};

struct que {
	struct qu *front,*rear;
};

typedef struct que queue;
typedef struct qu *element;

void InitQ(queue *Q){
	element el = new qu;
	el->next = NULL;
	Q->front = Q->rear = el;
}

bool IsEmptyQ(queue *Q){
	return Q->front==Q->rear;
}

void EnQueueQ(osoba x, queue *Q){
	qu *novi = new qu;
	novi->value = x;
	novi->next = NULL;
	Q->rear->next = novi;
	Q->rear = novi;		
}
void DeQueueQ(queue *Q){
	Q->front = Q->front->next;
}

osoba FrontQ(queue *Q){
	return Q->front->next->value;
}

void Ispis(queue *Q){
	if(IsEmptyQ(Q)==1) return;
	element pom;
	pom= Q->front->next;
	do{
		cout<<pom->value.ime<<" "<<pom->value.prezime<<" "<<pom->value.spol<<" <"<<pom->value.ai<<", "<<pom->value.bi<<", "<<pom->value.ci<<", "<<pom->value.di<<"> datum: "<<pom->value.dan<<"."<<pom->value.mj<<"."<<pom->value.god<<endl;
		pom=pom->next;
	}while(pom!=NULL);
	
}

void ispis_jarci(queue *Q){ 
	element pom;
	pom= Q->front->next;
	do{
		bool jarac = (pom->value.mj==12 && pom->value.dan>22 && pom->value.dan<=31)||(pom->value.mj==1 && pom->value.dan>0 && pom->value.dan<=20); //&& (prvi[k].dan>0&&prvi[k].dan<20); //(out>="1222"&&out<"1232")||
		if(jarac&&pom->value.di==3&&pom->value.god>1974) cout<<pom->value.ime<<" "<<pom->value.prezime<<" "<<pom->value.spol<<" <"<<pom->value.ai<<", "<<pom->value.bi<<", "<<pom->value.ci<<", "<<pom->value.di<<"> datum: "<<pom->value.dan<<"."<<pom->value.mj<<"."<<pom->value.god<<endl;
		pom=pom->next;
	}while(pom!=NULL);
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

void brisi_trudne(queue *Q){
	element pom;
	element pret;
	pret=Q->front;
	pom= Q->front->next;
	do{
		if(pom->value.ci==3&&pom->value.ai>250){
			
			element del;
		    del = pom->next;
		    if(del==NULL) {
		    	pret->next=NULL;
		    	Q->rear=pret;
		    }
		    else {
		    	pom->next = del->next;
		    	pom->value=del->value;
		    }

		    delete del,pom,pret;
		    brisi_trudne(Q);
		    
		}
		pret=pret->next;
		pom=pom->next;
		
	}while(pom!=NULL);
	return;
}
void ubaci_na_vrh(osoba x, queue *Q){
	element pom;
	pom = Q->front->next;
	qu *novi = new qu;
	novi->value = x;
	novi->next = pom;
	Q->front->next = novi;
	if(pom==NULL) Q->rear = pom;
	else
	do{
		pom=pom->next;
		if(pom==NULL) Q->rear = pom;
	}while(pom!=NULL);
	delete pom;
	return;
}
int prvi_limit=0,drugi_limit=0,treci_limit=0,cetvrti_limit=0,peti_limit=0;
void simulator(queue *Q, queue *P){
	element trenutni;
	trenutni= Q->front->next;
	element prethodni;
	prethodni=Q->front;
	element sljedeci;
	
	do{
		if( (trenutni->value.ci==4) || (prvi_limit<2 && trenutni->value.di==1) || (drugi_limit<2 && trenutni->value.di==2) || (treci_limit<2 && trenutni->value.di==3) || (cetvrti_limit<2 && trenutni->value.di==4) || (peti_limit<2 && trenutni->value.di==5) ){//|| (prvi_limit<2 && trenutni->value.di==1)
			
			ubaci_na_vrh(trenutni->value, P);
			
		    sljedeci = trenutni->next;
		    if(sljedeci==NULL) {
		    	prethodni->next=NULL;
		    	Q->rear=prethodni;
		    	return;
		    }
		    else {
		    	trenutni->next = sljedeci->next;
		    	trenutni->value=sljedeci->value;
		    	
		    	if(trenutni->value.di==1) prvi_limit++;
		    	if(trenutni->value.di==2) drugi_limit++;
		    	if(trenutni->value.di==3) treci_limit++;
		    	if(trenutni->value.di==4) cetvrti_limit++;
		    	if(trenutni->value.di==5) peti_limit++;
		    	simulator(Q,P);
		    }
		    delete sljedeci,trenutni,prethodni;
			
		}
		
		trenutni=trenutni->next;
		prethodni=prethodni->next;
	}while(trenutni!=NULL);
	return;
}


void sort(queue *Q, int z, int nacin, queue *prvi_salter, queue *drugi_salter, queue *treci_salter, queue *cetvrti_salter, queue *peti_salter){
	osoba prvi[z],drugi[z],treci[z],cetvrti[z],peti[z];
	int size_prvi=0, size_drugi=0, size_treci=0, size_cetvrti=0, size_peti=0;
	int br_ljudi = 0;
	element pom;
	pom= Q->front->next;
	do{
		if(pom->value.di==1){
			prvi[size_prvi]=pom->value;
			size_prvi++;
		}
		if(pom->value.di==2){
			drugi[size_drugi]=pom->value;
			size_drugi++;
		}
		if(pom->value.di==3){
			treci[size_treci]=pom->value;
			size_treci++;
		}
		if(pom->value.di==4){
			cetvrti[size_cetvrti]=pom->value;
			size_cetvrti++;
		}
		if(pom->value.di==5){
			peti[size_peti]=pom->value;
			size_peti++;
		}
		br_ljudi++;
		pom=pom->next;
	}while(pom!=NULL);
	
	
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


