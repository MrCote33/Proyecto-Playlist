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

void Borrar(CANCION *L, int n){
	CANCION aux= *L; //PUNTERO AUXILIAR
	*L= *L -> sig; // L APUNTA AL SIGUIENTE NODO
	//free(aux); //ELIMININA EL PRIMER NODO DE LA MEMORIA
}

void CFichero(){//CREARA UN FICHERO
	FILE*nueva;
	char Nom[20];
	char ext[]=".txt";
	system("cls");
	printf("Nombre de la nueva playlist: ");
	gets(Nom);
	strcat(Nom,ext);
	nueva=fopen(Nom,"w");
	fclose(nueva);
}

void MenuAdmin(){//MENU ADMINISTRADOR

	int op=0,opc=0;//opcion
	int error;
	char linea[MAX];
	char user[10],password[10];

	system("cls");
	printf("\t usuario: ");
	scanf("%s",&user);
	printf("\t clave: ");
	scanf("%s",&password);

	if(strcmp("admin",user)==0 && strcmp("admin",password)==0){

		do{
			op=0;
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
					system("cls");

					do{
						FILE*p;
						p=fopen("catalogo.txt","r");
						if(p==NULL){        //VERIFICA QUE EL FICHERO EXISTA
							printf("El fichero no existe");
							system("pause");
							exit(-1);

						}else{

							while(fgets(linea,MAX,p)!=NULL){
								printf("%s\n",linea);
							}
						}

						printf("¿Desea salir?\n1-si\n2-no\n");
						printf("\nOpcion>>>");
						scanf("%d",&op);

					}while(op!=1);

					break;

				case 2:

					system("cls");
					do{
						char caracteres[MAX];
						printf("\t MENU REPORTES\n\n");
						printf("Que desea ver?\n\n");
						printf("1- Cantidad de listas creadas\n");
						printf("2- Top 5 listas con mas canciones\n");
						printf("3- Canciones mas usadas\n");
						printf("4- Salir\n");
						printf("opcion>>> ");
						scanf("%d",&opc);

						switch(op){

							case 1:
								FILE *Listas;
								Listas= fopen("Listas.txt", "r");
								
								while(fgets(caracteres,MAX,Listas) != NULL){
									printf("%s",caracteres);
								}
								system ("pause");

							break;

							case 2:

							break;

							case 3:

							break;

							case 4:

							break;

							default:
								system("cls");
								printf("La opcion que ingreso no existe\n");
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
					printf("La opcion que ingreso no existe\n");
					system("pause");

				break;
			}

		}while(op!=3);

	}else{

		printf("Usuario o clave incorrectos\n");
		system("pause");

	}
}

void MenuUser(){//MENU USUARIO
	char user[10],password[10];
	char linea[MAX];
	int opc,op;//opcion principal y secundaria

	system("cls");

	printf("\t usuario: ");
	scanf("%s",&user);
	printf("\t clave: ");
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
					//CreaPlaylist();

					system("cls");

				break;

				case 2:
					//EliminaPlaylist();

					system("cls");

				break;

				case 3:
					//Gestionar();
					system("cls");
					do{
						Lista= NULL;
						opc==0;
						printf("¿Que desea hacer?\n\n");
						printf("1- Agregar cancion\n");
						printf("2- Mover cancion\n");
						printf("3- Eliminar cancion\n");
						printf("4- Salir\n");
						printf("opcion>>> ");
						scanf("%d",&op);

						switch(opc){
							case 1:

							break;

							case 2:
								system("cls");
							break;

							case 3:
								int n; //VARIABLE DONDE SE ALMACENA EL NUMERO A BORRAR
								system("cls"); //BORRA LA PANTALLA
								printf("Ingrese el numero de la cancion a borrar: \n");
								scanf("%d", &n);
								system("cls");
								Borrar(&Lista,n);//LLAMA LA FUNCION BORRAR
								getch();
								
								break;

							case 4:
								MenuUser();
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
		printf("*           BIENVENIDO              *\n");
		printf("* Como desea ingresar:              *\n");
		printf("* 1- Administrador.                 *\n");
		printf("* 2- Usuario.                       *\n");
		printf("* 3- Salir.                         *\n");
		printf("*************************************\n");
		printf("opcion>>> ");

		fflush(stdin);
		scanf("%d",&opcion);

		switch(opcion){

			case 1:
				MenuAdmin();
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
				printf("La opcion que ingreso no existe\n");
				system("pause");
			break;
		}
	}while(opcion!=3);
}

main(){
	CANCION*lista=NULL;
	MenuP();
}



