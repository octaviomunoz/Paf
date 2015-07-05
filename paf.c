#include <stdio.h>

int main(){
	int *punteros;
	int arreglo[100];
	int num = 0, num1, i, p, j, suma1, suma2, diferen, diferencia, salida = 0;
	char carac;


	punteros = &arreglo[0];

	FILE *leer, *escribir;

	leer = fopen ("entrada.ent", "r");
	if (leer == NULL){
		printf ("No se a podido leer el archivo");
	}else{
		carac = fgetc(leer);
		while(48<=carac && carac<=57){
			if(num != 0){
				num *= 10;
			}
			switch (carac){
				case 48:
					num += 0;
					break;
				case 49:
					num += 1;
					break;
				case 50:
					num += 2;
					break;
				case 51:
					num += 3;
					break;
				case 52:
					num += 4;
					break;
				case 53:
					num += 5;
					break;
				case 54:
					num += 6;
					break;
				case 55:
					num += 7;
					break;
				case 56:
					num += 8;
					break;
				default:
					num += 9;
			}
			carac = fgetc(leer);			
		}
		for (i=0;i<num;i++){
			num1 = 0;
			carac = fgetc(leer);
			while(48<=carac && carac<=57){
				if (num1 != 0){
					num1 *= 10;
				}
				switch (carac){
				case 48:
					num1 += 0;
					break;
				case 49:
					num1 += 1;
					break;
				case 50:
					num1 += 2;
					break;
				case 51:
					num1 += 3;
					break;
				case 52:
					num1 += 4;
					break;
				case 53:
					num1 += 5;
					break;
				case 54:
					num1 += 6;
					break;
				case 55:
					num1 += 7;
					break;
				case 56:
					num1 += 8;
					break;
				default:
					num1 += 9;
				}
				carac = fgetc(leer);

			}
			*punteros = num1;
			*punteros++;
		}
		fclose(leer);
		diferencia = -1;
		for(p=1;p<num;p++){
			suma1 = 0;
			suma2 = 0;
			i=0;
			punteros = &arreglo[0];
			while(i<num){
				if(i<p){
					suma1 += *punteros;
				}else{
					suma2 += *punteros;
				}
				*punteros++;
				i++;
			}
			diferen = suma1 - suma2;
			if(diferen < 0){
				diferen *= (-1);
			}
			if(diferencia == (-1)){
				diferencia = diferen;
			}
			if(diferencia > diferen){
				diferencia = diferen;
			}

		}
		printf("\n%d\n", diferencia);
		
		escribir = fopen("salida.sal", "w");
		num1 = diferencia;
		j = 1;
		while(num1 >= 10){
			j *= 10;
			num1 /= 10;
		}
		while(salida == 0){
			num1 = diferencia/j;
			switch(num1){
				case 0:
					carac = '0';
					break;
				case 1:
					carac = '1';
					break;
				case 2:
					carac = '2';
					break;
				case 3:
					carac = '3';
					break;
				case 4:
					carac = '4';
					break;
				case 5:
					carac = '5';
					break;
				case 6:
					carac = '6';
					break;
				case 7:
					carac = '7';
					break;
				case 8:
					carac = '8';
					break;
				default:
					carac = '9';	
			}
			diferencia -= num1*j;
			fputc(carac, escribir);
			if (j == 1){
				salida = 1;
			}
			j /= 10;

		}

		fclose(escribir);

	}


	return 0;
}
