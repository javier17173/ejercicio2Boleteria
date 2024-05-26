#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <locale.h>
#include <string>
#include <stdio.h>

/* 
Javier Santana Rodríguez
Tarea 1.2
Programación 1
Universidad Tecnológica Costarricense
*/

/* 
La Federación Costarricense de Futbol, le ha solicitado a usted como Ingeniero de Sistemas 
desarrolle un Sistema de Control de Ventas para las Entradas del partido a efectuarse el día 5 de Noviembre 2018, 
frente a su similar de Mexico en el Estadio Nacional de Costa Rica
*/

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "spanish"); //Permite utilizar tildes en la consola de C++
	
	const float cargosPorServicio = 1000; 
	
	int numFactura = 0, cedula = 0, localidad = 0, cantEntradas = 0, precioEntrada = 0, opcionMenu;
	int cantLocal1 = 0, cantLocal2 = 0, cantLocal3 = 0;
	float acumuladoLocacalidad1 = 0.0, acumuladoLocacalidad2 = 0.0, acumuladoLocacalidad3 = 0.0; 
	float subTotal = 0.0, totalCargos = 0.0, totalPagar = 0.0;
	char nombre[100];
	string nomLocalidad;
	
	do{
		printf("Ingrese el número de Factura: ");
		scanf("%i", &numFactura);
		
		printf("Digite la cédula del Comprador: ");
		scanf("%i", &cedula);
	
		printf("Digite el nombre del Comprador: ");
		scanf(" %[^\n]", &nombre); 
	
		printf("Digite el tipo de localidad según la siguiente lista: \n");
		printf("1. Sol Norte/Sur \n");
		printf("2. Sombra Este/Oeste \n");
		printf("3. Preferencial \n");
		scanf("%i", &localidad);
		printf("\n");
	
		printf("Digite la cantidad de Entradas: ");
		scanf("%i", &cantEntradas);
	
		if(cantEntradas > 5){
			printf("Usuario solo puede comprar un máximo de 5 entradas \n");
			printf("Digite la cantidad de Entradas: ");
			scanf("%i", &cantEntradas);
		}
	
	//Cálculos de Subtotal, cargos por servicio y Total a pagar
		if(localidad==1){
			precioEntrada = 10500;
			nomLocalidad = "Sol Norte/Sur";
			cantLocal1++;
			subTotal = cantEntradas * precioEntrada;
			totalCargos = cantEntradas * cargosPorServicio;
			totalPagar = subTotal + totalCargos;
		
			acumuladoLocacalidad1 +=totalPagar;
		}else{
			if(localidad==2){
				precioEntrada = 20500;
				nomLocalidad = "Sombra Este/Oeste";
				cantLocal2++;
				subTotal = cantEntradas * precioEntrada;
				totalCargos = cantEntradas * cargosPorServicio;
				totalPagar = subTotal + totalCargos;
			
				acumuladoLocacalidad2 += totalPagar;
			}else{
				if(localidad==3){
					precioEntrada = 25500;
					nomLocalidad = "Preferencial";
					cantLocal3++;
					subTotal = cantEntradas * precioEntrada;
					totalCargos = cantEntradas * cargosPorServicio;
					totalPagar = subTotal + totalCargos;
				
					acumuladoLocacalidad3 += totalPagar;
				}
			}
		}
	
	//Mostrar en pantalla la información solicitada
			printf("\n");
			printf("****************************************************\n");
			printf(" Número de Factura: %i\n", numFactura);
			printf(" Cédula del Comprador: %i\n", cedula);
			printf(" Nombre del Comprador: %s\n", &nombre);
			printf(" Localidad: %s\n", nomLocalidad.c_str()); //se utiliza c_str() para leer los datos de las variables tipo string
			printf(" Cantidad de Entradas: %i\n", cantEntradas);
			printf(" SubTotal: %.0f\n", subTotal);
			printf(" Cargos Por Servicios: %.2f\n", totalCargos);
			printf(" total a Pagar: %.2f\n", totalPagar);
			printf("****************************************************\n");
			
			printf("\n");
			printf("¿Desea calcular otro empleado? \n");
			printf("1. Si \n");
			printf("2. Salir\n");
			scanf("%i", &opcionMenu);
			printf("\n");
	}while(opcionMenu ==1);
	
	printf("\n");
	printf("****************************************************\n");
	printf("Estadísticas \n");
	printf("1. Cantidad Entradas Localidad Sol Norte/Sur: %i\n", cantLocal1);
	printf("2. Acumulado Dinero Localidad Sol Norte/Sur: %.2f\n", acumuladoLocacalidad1);
	printf("\n");
	printf("3. Cantidad Entradas Localidad Sombra Este/Oeste: %i\n", cantLocal2);
	printf("4. Acumulado Dinero Localidad Sombra Este/Oeste: %.2f\n", acumuladoLocacalidad2);
	printf("\n");
	printf("5. Cantidad Entradas Localidad Preferencial: %i\n", cantLocal3);
	printf("6. Acumulado Dinero Localidad Preferencial: %.2f\n", acumuladoLocacalidad3);
	printf("****************************************************\n");
	
	
	return 0;
}
