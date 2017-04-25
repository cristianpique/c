#include<stdio.h>
#include<string.h>

#define MAX_ARTISTA 30
#define MAX_NOM 30
#define MAX_DISC 3
#define MAX_BUSQUEDA 30
#define MAX_ESBORRAT 30

struct disc{
	char artista[MAX_ARTISTA];
	char nom[MAX_NOM];
	int any;
	int cansons;
};

struct coleccio{
	struct disc d[MAX_DISC];
	int elements;
};

void netejarCol(struct coleccio *c){
	int i;
	
	for(i=0;i<c->elements;i++){
	  strcpy(c->d[c->elements].artista,"");
	  strcpy(c->d[c->elements].nom,"");
	  c->d[c->elements].any=0;
	  c->d[c->elements].cansons=0;
  }
}

void introduirDisc(struct coleccio *c){
	if(c->elements<MAX_DISC){
	 printf("\n\t Introdueix artista: ");
	 scanf("%s",c->d[c->elements].artista);
	 printf("\n\t Introdueix disc: ");
	 scanf("%s",c->d[c->elements].nom);
	 printf("\n\t Introdueix any: ");
	 scanf("%i",&c->d[c->elements].any);
	 printf("\n\t Introdueix cançons: ");
	 scanf("%i",&c->d[c->elements].cansons);
	 c->elements++;
	}
	else{
		printf("\n\t ¡¡¡ Llista Plena !!! \n");
	}
}

void llistarDisc(struct coleccio *c){
	int i;
	if(c->elements>0){
	 for(i=0;i<c->elements;i++){
	  printf("\n\t Artista: %s Nom: %s Any: %i Cançons: %i \n",c->d[i].artista,c->d[i].nom,c->d[i].any,c->d[i].cansons);
     }
	}
	else{
		printf("\n\t ¡¡¡ No Hi Ha Contactes !!!\n");
	}
}

void cercarDisc(struct coleccio *c){
	int i;
	char bd[MAX_BUSQUEDA];
	
	printf("\n\t Introdueix artista a cercar: ");
	scanf("%s",bd);
	for(i=0;i<c->elements;i++){
	 if(strcmp(bd,c->d[i].artista)==0){
	  printf("\n\t Artista: %s Nom: %s Any: %i Cançons: %i \n",c->d[i].artista,c->d[i].nom,c->d[i].any,c->d[i].cansons);
	 }
	 else{
		 printf("\n\t ¡¡¡ Artista Inexistent !!! \n");
	 }
  }
}

void esborrarDisc(struct coleccio *c){
	int i;
	char ed[MAX_ESBORRAT];
	
	printf("\n\t Introdueix artista a esborrar: ");
	scanf("%s",ed);
	for(i=0;i<c->elements;i++){
	 if(strcmp(ed,c->d[i].artista)==0){
	  strcpy(c->d[c->elements].artista,"");
	  strcpy(c->d[c->elements].nom,"");
	  c->d[c->elements].any=0;
	  c->d[c->elements].cansons=0;
	  c->d[i]=c->d[c->elements-1];
	  c->elements--;
	  i--;
	  printf("\n\t ¡¡¡ Contacte Esborrat !!! \n");
	 }
	else{
		printf("\n\t ¡¡¡ Contacte No Esborrat !!! \n");
	}
  }
}

void main(){
	 struct coleccio c;
	 char opcio;
	 c.elements=0;
	
	netejarCol(&c);
	
	while(1){
		printf("\n\t a)Introduir");
		printf("\n\t b)Llistar");
		printf("\n\t c)Cercar");
		printf("\n\t d)Esborrar");
		printf("\n\t e)Sortir\n\n");
		printf("\n\t Introdueix opcio: ");
		scanf("%c",&opcio);
		switch(opcio){
			case 'a': introduirDisc(&c);
				      break;
			case 'b': llistarDisc(&c);
				      break;
			case 'c': cercarDisc(&c);
				      break;
			case 'd': esborrarDisc(&c);
				      break;
			
			case 'e': printf("\n");return;
		}
	}
}