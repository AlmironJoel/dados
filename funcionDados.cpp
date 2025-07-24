#include <iostream>
#include "funcionDados.h"
#include "rlutil.h"
#include <cstdlib>  // Necesario para rand() y srand()
#include <ctime>    // Necesario para time()

using namespace std;


void dibujarCuadrado(int posX,int posY){

    rlutil::setColor(rlutil::WHITE);

     for(int i =posX;i<=posX+6;i++){
        for(int j=posY;j<=posY+2;j++){
            rlutil::locate(i,j);
            cout<<(char)219;
        }
      }
}

void dibujarDado(int num,int posX,int posY){
    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    dibujarCuadrado(posX,posY);
    dibujarPuntos(num,posX,posY);

    rlutil::resetColor();
}

void dibujarPuntos(int num,int posX,int posY){
    switch(num){
    case 1 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
            rlutil::locate(posX+3,posY+1);
            cout<<(char)254;
        break;
    case 2 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
            rlutil::locate(posX+1,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY+2);
            cout<<(char)223;
        break;
    case 3 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
            rlutil::locate(posX+1,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+3,posY+1);
            cout<<(char)254;
        break;
    case 4 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
            rlutil::locate(posX+1,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+1,posY+2);
            cout<<(char)223;
        break;
    case 5 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);
            rlutil::locate(posX+1,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+1,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+3,posY+1);
            cout<<(char)254;
        break;
    case 6 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::RED);

            rlutil::locate(posX+1,posY);
            cout<<(char)220;
            rlutil::locate(posX+5,posY);
            cout<<(char)220;
            rlutil::locate(posX+3,posY);
            cout<<(char)220;


            rlutil::locate(posX+5,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+1,posY+2);
            cout<<(char)223;
            rlutil::locate(posX+3,posY+2);
            cout<<(char)223;
        break;
    }
}

int tirarDado(int posX,int posY){
    rlutil::hidecursor();
    int numeroAleatorio;
    for(int i=0;i<10;i++){
    numeroAleatorio=rand()%6+1;
    dibujarDado(numeroAleatorio,posX,posY);
    rlutil::msleep(50);
    }
    return numeroAleatorio;
}


//poliedro
int tirarPoliedro(int posX, int posY){
    int numeroAleatorio;
    for(int i=0; i<8 ; i++){
        numeroAleatorio=rand()%12+1;
        dibujarDadoC(numeroAleatorio,posX,posY);
        rlutil::msleep(50);
    }
    return numeroAleatorio;
}

void dibujarDadoC(int num,int posX,int posY){
    rlutil::hidecursor();
    rlutil::saveDefaultColor();
    dibujarCuadrado(posX,posY);
    dibujarNumero(num,posX,posY);

    rlutil::resetColor();
}

void dibujarNumero(int num,int posX,int posY){
    switch(num){
        case 1 :
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3,posY+1);
            cout<<"1";
        break;
        case 2:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "2";
            break;

        case 3:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "3";
            break;

        case 4:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "4";
            break;

        case 5:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "5";
            break;

        case 6:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "6";
            break;

        case 7:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "7";
            break;

        case 8:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "8";
            break;

        case 9:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+3, posY+1);
            cout << "9";
            break;

        case 10:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+2, posY+1);
            cout << "10";
            break;

        case 11:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+2, posY+1);
            cout << "11";
            break;

        case 12:
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(posX+2, posY+1);
            cout << "12";
            break;
    }
}
