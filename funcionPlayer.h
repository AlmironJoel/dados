#pragma once
#include "funcionDados.h"
#include "player.h"
#include "rlutil.h"
#include <cstdlib>  // Necesario para rand() y srand()
#include <ctime>    // Necesario para time()

void pedirNombres (jugador Player[2]);
int primerTurno(jugador Player[2]);
int pedirPoliedros(jugador Player[2],int ban);
void ponerEnCero(jugador Player[2],int ban,int VcontenedorIndices[12]);
void transferirDados(jugador Player[2],int origenIndex,int destinoIndex,int cantidad);
