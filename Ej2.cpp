/*1) Realizar un programa en el cual se ingresen los siguientes datos Nombre, Apellido y DNI
a) Crear un menú donde se ingresen los datos y los guarde en un archivo
b) Otro ítem donde se pueda realizar una búsqueda por DNI y devuelva los datos de
Nombre y apellido
c) Salir del mismo*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int main()
{
    FILE *datos;
    char nombre[20], apellido[20], buscarNombre[20], buscarApellido[20];
    int op, DNI, buscarDni;    
	bool proceder = true;
	
    do
	{
        printf("Ingrese la opcion que quiera \n");
        printf("1. Ingresar nuevos datos\n");
        printf("2. Busqueda mediante nombre y apellido\n");
        printf("3. Salir del programa\n: ");
        scanf("%d", &op);
        switch(op)
		{
            case 1:
            printf("Ingrese nombre: ");
            scanf("%s", nombre);
            printf("Ingrese apellido: ");
            scanf("%s", apellido);
            printf("Ingrese DNI: ");   
            scanf("%d", &DNI);
            datos = fopen("datos.txt", "a+");
            
            if(datos == NULL)
			{
                printf("No se pudo abrir el archivo\n");
                return 1;
            }
            fprintf(datos, "%s %s %d\n", nombre, apellido, DNI);
            fclose(datos);
            break;
            
            case 2:
            printf("Ingrese el apellido que desea buscar: ");
            scanf("%s", buscarApellido);
            printf("Ingrese el nombre que desea buscar: ");
            scanf("%s", buscarNombre);

            datos = fopen("datos.txt", "r");

            if(datos == NULL){
                printf("No se pudo abrir el archivo\n");
                return 1;
            }          

            while(fscanf(datos, "%s %s %d", nombre, apellido, &DNI) != EOF)
			{
                if(strcmp(apellido, buscarApellido) == 0 && strcmp(nombre, buscarNombre) == 0)
				{
                    printf("Nombre: %s\n", nombre);
                    printf("Apellido: %s\n", apellido);
                    printf("DNI: %d\n", DNI);
                }
            }
            fclose(datos);
            break;
            
            case 3:
                proceder = false;
            break;
        }
    }while(proceder);
    return 0;

}
