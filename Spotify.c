#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COD 5
#define MAX 100 //MAXIMO LINEA

typedef struct cancion{//CANCIONES

	int codigo[COD];
	char nombre[MAX];
	char artista[MAX];
	char  duracion[COD];
	
	struct cancion*sig;

}CANCION;

void CFichero(){//CREA ARCHIVOS.TXT Y LOS GUARDA EN LISTAS.TXT

	FILE*nueva;
	
	char Nom[20];
	char ext[]=".txt";
	
	system("cls");
	printf("Nombre de la nueva playlist: ");
	fflush(stdin);
	gets(Nom);
	
	strcat(Nom,ext);
	nueva=fopen(Nom,"w");
	fclose(nueva);
	FILE*arch;
	arch=fopen("listas.txt","a+");
	putc('\n',arch);	
	fputs(Nom,arch);

	system("pause");
	close(arch);
}

void MenuAd(){//MENU ADMINISTRADOR

	int op=0,opc=0;//opcion
	char linea[MAX];
	char user[10],password[10];
		
	system("cls");
	printf("\t Usuario: ");
	scanf("%s",&user);
	printf("\t Clave: ");
	scanf("%s",&password);

	if(strcmp("admin",user)==0 && strcmp("admin",password)==0){
	
		do{
			
			system("cls");
			printf("\tMENU ADMINISTRADOR\n\n");
			printf("Que desea hacer?\n\n");
			printf("1- Ver el catalogo\n");
			printf("2- Ver reportes\n");
			printf("3- Cambiar de usuario\n");
			printf("opcion>>> ");
			fflush(stdin);
			scanf("%d",&op);
				
			switch(op){
				
				case 1:

					do{					
						system("cls");
						FILE*p;
						p=fopen("catalogo.txt","r");
						
						if(p==NULL){//VERIFICA QUE EL FICHERO EXISTA
							printf("El fichero no existe");	
							system("pause");
							exit(-1);
							
						}else{
									
							while(fgets(linea,MAX,p)!=NULL){
								printf("%s\n",linea);
								
							}
							
						}	
						
						printf("Desea salir?\n1-si\n2-no\n");	
						printf("\nOpcion>>>");
						scanf("%d",&op);
						
					}while(op!=1);

				break;
					
				case 2:
					
					system("cls");
					do{
						printf("\tMENU Reportes\n\n");
						printf("Que desea ver?\n\n");
						printf("1- Cantidad de listas creadas\n");
						printf("2- Top 5 listas con mas canciones\n");
						printf("3- Canciones mas usadas\n");
						printf("4- Salir\n");
						printf("opcion>>> ");
						scanf("%d",&opc);
						
						switch(op){
							
							case 1:
								system("cls");
							break;
							
							case 2:
								system("cls");
							break;
							
							case 3:
								system("cls");
							break;
							
							case 4:
								
							break;
							
							default:
								system("cls");
								printf("la opcion que ingreso no existe\n");
								system("pause");								
						break;
							
						}
						
					}while(opc!=4);

					break;
					
				case 3:
					system("cls");
					
				break;
				
				default:
					
					system("cls");
					printf("la opcion que ingreso no existe\n");
					system("pause");
					
				break;
			}	
			
		}while(op!=3);
		
	}else{
		
		printf("usuario o clave incorrectos\n");
		system("pause");
		
	}		
}

void MenuUser(){//MENU USUARIO

	char user[10],password[10];
	char linea[MAX];
	int opc,op;//opcion principal y secundaria
	
	system("cls");

	printf("\t Usuario: ");
	scanf("%s",&user);
	printf("\t Clave: ");
	scanf("%s",&password);
	
	if(strcmp("user",user)==0 && strcmp("user123",password)==0){
		do{
			system("cls");
			printf("\tMENU USUARIO\n\n");
			printf("Que desea hacer?\n\n");
			printf("1- Crear una playlist\n");
			printf("2- Eliminar una playlist\n");
			printf("3- Gestionar una playlist\n");
			printf("4- Cambiar de usuario\n");			
			printf("opcion>>> ");
			fflush(stdin);
			scanf("%d",&opc);
			
			switch(opc){
				
				case 1:
					
					do{
						system("cls");
						CFichero();	
						printf("Quiere agregar otra Playlist?:\n1-Si\n2-No\n");
						printf("opcion>>>");
						scanf("%d",&op);
						
					}while(op!=2);
					
				break;
					
				case 2:
					
					do{
						system("cls");
						FILE*Arch;
						Arch=fopen("listas.txt","r");
						
						if(Arch==NULL){//VERIFICA QUE EL FICHERO EXISTA
						
							printf("El fichero no existe");	
							system("pause");
							exit(-1);
							
						}else{
									
							while(fgets(linea,MAX,Arch)!=NULL){
								printf("%s\n",linea);
								
							}
							
						}	
						fclose(Arch);
						printf("Quiere eliminar otra Playlist?:\n1-Si\n2-No\n");
						printf("opcion>>>");
						scanf("%d",&op);
						
					}while(op!=2);
	
				break;
						
				case 3:
					system("cls");					
					do{
						opc==0;				
						printf("Que desea hacer?\n\n");
						printf("1- Agregar cancion\n");
						printf("2- Mover cancion\n");
						printf("3- Eliminar cancion\n");
						printf("4- Salir\n");
						printf("opcion>>> ");
						scanf("%d",&op);
	
						switch(opc){
							case 1:
								system("cls");
								
							break;
									
							case 2:
								system("cls");
								
							break;
									
							case 3:
								system("cls");
								
							break;
								
							case 4:
								
							break;
									
							default:
								
								system("cls");
								printf("la opcion que ingreso no existe\n");
								system("pause");
								
							break;
									
						}
							
					}while(op!=4);
						
				break;
					
				case 4:
						
				break;
						
				default:
					
					system("cls");
					printf("la opcion que ingreso no existe\n");
					system("pause");
					
				break;
				
			}	
			
		}while(opc!=4);	
		
	}else{
		
		printf("usuario o clave incorrectos\n");
		system("pause");
		
	}
	
}	

void MenuP(){//MENU PRINCIPAL

	int opcion=0;

	do{	
		system("cls");
		
		printf("*************************************\n");
		printf("*          BIENVENIDO               *\n");
		printf("*************************************\n");
		printf("*		Como desea ingresar:        *\n");
		printf("*1- Administrador                   *\n");
		printf("*2- Usuario                         *\n");
		printf("*3- Salir                           *\n");
		printf("*************************************\n");
		printf("opcion>>> ");
		
		fflush(stdin);
		scanf("%d",&opcion);
		
		switch(opcion){
		
			case 1:
				MenuAd();
			break;
				
			case 2:
				MenuUser();
			break;
				
			case 3:
				system("cls");
				printf("Gracias por preferirnos..");
				exit(EXIT_SUCCESS);
			break;
				
			default:
				system("cls");
				printf("la opcion que ingreso no existe\n");
				system("pause");
			break;
		}
	}while(opcion!=3);
}

main(){
	
	CANCION*lista=NULL;
	MenuP();
	
}
