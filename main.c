/*
 * main.c
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "line.h"

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	setlocale(LC_ALL,"Portuguese");

	Fila *fila;

	fila = InicializarFilaArr(9);
	bool sucesso;
	int valorConsultado;

	for(int i = 9; i > 0; i--){
		sucesso = InserirFilaArr(fila, fila->limiteInferior, fila->limiteSuperior, fila->inicioFila, fila->finalFila, i);
	}

	if(sucesso){
		printf("Fila adicionada!\n");
	}else{
		printf("Falha ao adicionar fila\n");
	}

	sucesso = ConsultarFilaArr(fila, fila->limiteInferior, fila->inicioFila, &valorConsultado);

	if(sucesso){
		printf("O valor no início da fila é: %d\n", valorConsultado);
	}else{
		printf("Não foi possível consultar a fila.\n");
	}

	sucesso = RemoverFilaArr(fila, fila->limiteInferior, fila->limiteSuperior, fila->inicioFila, fila->finalFila);

	if(sucesso){
		printf("Valor inicial da fila removido!\n");
	}else{
		printf("Falha ao remover valor inicial da fila.\n");
	}

	sucesso = ConsultarFilaArr(fila, fila->limiteInferior, fila->inicioFila, &valorConsultado);

	if(sucesso){
		printf("O valor no início da fila é: %d\n", valorConsultado);
	}else{
		printf("Não foi possível consultar a fila.\n");
	}

	LiberarFilaArr(fila);

	return 0;
}
