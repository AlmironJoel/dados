#pragma once

struct jugador {
    char nombre[50];
    int vNumTirada[12];
    int vDadosObjetivos[2];
    int puntos = 0;
    int puntosPoliedro[12];
    int dadoInicial;
    int dadosStock = 6;
};

struct point{
    char name[50]="vacio";
    int score=0;
};
