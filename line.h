/*
 * line.h
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */

#ifndef LINE_H_
#define LINE_H_

typedef struct fila{
	int limiteInferior;
	int inicioFila;
	int finalFila;
	int limiteSuperior;
	int* elementos;
}Fila;

Fila* InicializarFilaArr(int LI);
bool InserirFilaArr(Fila* fila, int LI, int LS, int IF, int FF, int info);
bool RemoverFilaArr(Fila* fila, int LI, int LS, int IF, int FF);
bool ConsultarFilaArr(Fila* fila, int LI, int IF, int* info);
void LiberarFilaArr(Fila* fila);

#endif /* LINE_H_ */
