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
                {cout<<"Entra al Juego"<< endl;
                game(top);
                break;
                }
            case 1:// Estadísticas
                cout<<"Entra a Estadisticas"<< endl;
                for(int i=0; i<5;i++){
                cout<<"Pos "<<i+1<<top[i].name<<" : "<<top[i].score<<endl;
                }
            break;
            case 2: // Créditos
                cout<<"Grupo 5"<< endl;
                cout<<"Joel Brian Almiron"<< endl;
                cout<<"Legajo : 32378"<<endl;

            break;

            case 3:// Salir
                cout<<"Salida"<< endl;
                opcion=0;
                break;
            }//Switch Enter.

        break;
    }

  }while(opcion!=0);//DO WHILE

    return 0;
}


