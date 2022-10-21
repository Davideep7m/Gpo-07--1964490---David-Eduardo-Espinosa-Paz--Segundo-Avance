#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>


using namespace std;

struct empresa
{
	//declaracion de variable

	int idarticulo, numoc;
	string proveedor;
	float subtotal, iva, total;
};


int main()
{
	empresa compras[3];
	int opcion, busqueda;

	do
	{
		printf("\t ***MENU OPCIONES*** \n");
		printf(" 1.-Agregar articulo \n 2.-Lista de articulos \n 3.-Eliminar \n 4.-Limpiar \n 5.-Modificar articulo \n 6.-Salir \n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			//capturar y guardar los datos por posicion
			for (int i = 0; i < 3; i++)
			{
				compras[i].idarticulo = 20220000 + i;
				printf("ID Articulo: %d \n", compras[i].idarticulo);
				int salida = 1;
				/*do
				{
					printf("ingrese el num oc \n");
					scanf_s("%d", &compras[i].numoc);
					if (compras[i].numoc == compras[i - 1].numoc || compras[i].numoc == compras[i - 2].numoc)
					{
						printf("el num oc ya existe \n");

					}
					else
					{
						salida = 2;
					}
				} while (salida == 1);
				*/
				do
				{
					printf("ingrese el num oc \n");
					scanf_s("%d", &compras[i].numoc);
				} while (compras[i].numoc == compras[i - 1].numoc || compras[i].numoc == compras[i - 2].numoc);


				//proveedor 
				printf("ingrese el proveedor \n");
				cin.ignore();
				getline(cin, compras[i].proveedor);
				printf("ingrese el subtotal \n");
				scanf_s("%f", &compras[i].subtotal);
				compras[i].iva = compras[i].subtotal * .16;
				compras[i].total = compras[i].subtotal + compras[i].iva;
				//compras[i].total =compras[i].subtotal*1.16;
			}
			break;

		case 2: //lista
			int opc2;
			printf("1.- num OC \n 2.-Listas Vigentes");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
			{
				printf("ingrese el num oc");
				scanf_s("%d", &busqueda);

				//imprimir los datos por posicion 
				for (int i = 0; i < 3; i++)
				{
					if (busqueda == compras[i].numoc)
					{
						printf("ID Articulo: %d \n", compras[i].idarticulo);
						printf("num OC: %d \n", compras[i].numoc);
						//proveedor
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (compras[i].numoc != 0)
					{
						printf("ID Articulo: %d \n", compras[i].idarticulo);
						printf("num OC: %d \n", compras[i].numoc);
						//proveedor
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			break;

		case 3:// no hara nada
			printf("ingrese el num oc");
			scanf_s("%d", &busqueda);

			//imprimir los datos por posicion 
			for (int i = 0; i < 3; i++)
			{
				if (busqueda == compras[i].numoc)
				{
					compras[i].numoc = 0;
				}
			}
			break;

		case 4:
			system("cls");
			break;
		case 5:
			break;
		case 6:
			printf("saliendo... \n");
			break;
		default:
			printf("intente denuevo... \n");
			break;
		}
	} while (opcion != 5);
	system("pause");
}
