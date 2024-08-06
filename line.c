/*
 * line.c
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"

Fila* InicializarFilaArr(int elementos){
	Fila* fila = (Fila*) malloc(sizeof(Fila));

	if(fila != NULL){
		fila->inicioFila = 0;
		fila->finalFila = fila->inicioFila;
		fila->limiteInferior = 0;
		fila->limiteSuperior = elementos;
		fila->elementos = (int*) malloc(elementos * sizeof(int));

		if(fila->elementos == NULL){
			free(fila);
			return NULL;
		}
	}

	return fila;
}

bool InserirFilaArr(Fila* fila, int limiteInferior, int limiteSuperior, int inicioFila, int finalFila, int info){
	if((finalFila != inicioFila - 1) && ((inicioFila != limiteInferior) || (finalFila != limiteSuperior))){
		if(inicioFila == limiteInferior - 1){
			fila->inicioFila = fila->limiteInferior;
			fila->finalFila = fila->limiteInferior;
		}else if(finalFila == limiteSuperior){
			fila->finalFila = fila->limiteInferior;
		}else{
			fila->finalFila = fila->finalFila + 1;
		}

		fila->elementos[finalFila] = info;

		return true;
	}else{
		return false;
	}
}

bool RemoverFilaArr(Fila* fila, int limiteInferior, int limiteSuperior, int inicioFila, int finalFila){
	if(inicioFila != limiteInferior - 1){
		if(inicioFila == finalFila){
			fila->inicioFila = fila->limiteInferior - 1;
			fila->finalFila = fila->limiteInferior - 1;
		}else if(inicioFila == limiteSuperior){
			fila->inicioFila = fila->limiteInferior;
		}else{
			fila->inicioFila = fila->inicioFila + 1;
		}

		return true;
	}else{
		return false;
	}
}

bool ConsultarFilaArr(Fila* fila, int limiteInferior, int inicioFila, int* info){
	if(inicioFila != limiteInferior - 1){
		*info = fila->elementos[inicioFila];

		return true;
	}else{
		return false;
	}
}

void LiberarFilaArr(Fila* fila){
	free(fila);
}
