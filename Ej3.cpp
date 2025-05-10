/*3) Agregar validación de datos de manera que no se repitan cuando sea necesario.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int main()
{
    FILE *datos;
    char nombre[20], apellido[20], buscarNombre[20], buscarApellido[20], nombreIngresado[30], apellidoIngresado[30];
    int op, DNI, buscarDni;    
    bool dniRepetido = false, proceder = true;
	
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
            dniRepetido = false;

            printf("Ingrese nombre: ");
            scanf("%s", nombreIngresado);
            printf("Ingrese apellido: ");
            scanf("%s", apellidoIngresado);            
            printf("Ingrese DNI: ");   
            scanf("%d", &buscarDni);

            datos = fopen("datos.txt", "r");

            if (datos != NULL) {
                char nomTemp[30], apeTemp[30];
                int dniTemp;

                while(fscanf(datos, "%s %s %d", nomTemp, apeTemp, &dniTemp) != EOF){
                    if(dniTemp == buscarDni){
                        printf("ESTE DNI YA EXISTE.\n");
                        dniRepetido = true;
                        break;
                    }
                }
                fclose(datos);
            }

            if (!dniRepetido) {
                datos = fopen("datos.txt", "a");
                if(datos == NULL){
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }

                strcpy(nombre, nombreIngresado);
                strcpy(apellido, apellidoIngresado);
                DNI = buscarDni;

                fprintf(datos, "%s %s %d\n", nombre, apellido, DNI);
                printf("Datos guardados correctamente.\n");
                fclose(datos);
            }
        

            if(datos == NULL){
                printf("No se pudo abrir el archivo\n");
                return 1;
            }

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
