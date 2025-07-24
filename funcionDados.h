#pragma once
#include "funcionDados.h"
#include "rlutil.h"
#include <cstdlib>  // Necesario para rand() y srand()
#include <ctime>    // Necesario para time()

void dibujarCuadrado(int x , int y);
void dibujarPuntos(int num,int posX,int posY);

void dibujarNumero(int num,int x,int y);
void dibujarDadoC(int num,int posX,int posY);
int tirarPoliedro(int posX, int posY);

int tirarDado(int posX,int posY);

void dibujarDado(int num,int x , int y);
