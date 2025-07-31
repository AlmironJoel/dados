#include <iostream>
//archivos
#include "funcionDados.h"
#include "funcionPlayer.h"
#include "player.h"
#include "rlutil.h"
//metodos
#include <cstdlib>  //para rand() y srand()
#include <ctime>    //para time()
#include <stdlib.h> //para system()

using namespace std;

int main()
{
//Menu Principal
int opcion = 1 ;
int yMenu=0;
point top[5];
do{
showItem("INICIAR JUEGO",50,18,yMenu==0);
showItem(" TOP PUNTAJE ",50,19,yMenu==1);
showItem("  CREDITOS   ",50,20,yMenu==2);
showItem("    SALIR    ",50,21,yMenu==3);
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(48,18+yMenu);
cout << (char)175<<endl;

int keyMenu=rlutil::getkey();

    switch(keyMenu){
    case 14://UP
            rlutil::locate(48,18+yMenu);
            cout <<"  "<<endl;
            if(yMenu<=0){
                yMenu=0;
            }else{
                yMenu--;
            }

        break;
    case 15://Down
            rlutil::locate(48,18+yMenu);
            cout <<"  "<<endl;
            if(yMenu>=3){
                yMenu=3;
            }else{
                yMenu++;
            }
        break;
    case 1 ://Enter

            switch(yMenu){

            case 0:// Iniciar juego
                {
                rlutil::cls();
                game(top);
                break;
                }
            case 1:// Estadísticas
                rlutil::cls();
                topRanking(top);
            break;
            case 2: // Créditos
                rlutil::cls();
                showItem("Grupo 5",55,10,true);
                showItem("Joel Brian Almiron",50,11,false);
                showItem("Legajo : 32378",50,12,false);
                rlutil::locate(40,22);
                cout<<"Preciona una tecla para volver al menu Principal";
                rlutil::anykey();
                rlutil::cls();
            break;

            case 3:// Salir
                rlutil::cls();
                cout<<"Gracias por jugar! :3"<< endl;
                opcion=0;
                break;
            }//Switch Enter.

        break;
    }

  }while(opcion!=0);//DO WHILE

    return 0;
}


