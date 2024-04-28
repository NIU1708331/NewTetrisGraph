#include "Joc.h"
#include <iostream>
using namespace std;


void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxerInit;
    ifstream fitxerInit(nomFitxer); 

    if (fitxerInit.is_open())
    {
        int tipusFigura, fila, columna, tipusGir;
        fitxerInit >> tipusFigura >> fila >> columna >> tipusGir;

        TipusFigura tipus;
        switch (tipusFigura) {
        case 0:
            tipus = NO_FIGURA;
            break;
        case 1:
            tipus = FIGURA_O;
            break;
        case 2:
            tipus = FIGURA_I;
            break;
        case 3:
            tipus = FIGURA_T;
            break;
        case 4:
            tipus = FIGURA_L;
            break;
        case 5:
            tipus = FIGURA_J;
            break;
        case 6:
            tipus = FIGURA_Z;
            break;
        case 7:
            tipus = FIGURA_S;
            break;
        default:
            tipus = NO_FIGURA;
            break;
        }

        m_figura.setTipus(tipus);
        m_figura.setPosicio(columna, fila);
        m_figura.setDir(tipusGir);

        fitxerInit >> m_tauler;
        fitxerInit.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio) 
{
	return 1;
}
bool Joc::mouFigura(int dirX)
{
	return 1;
}

int Joc::baixaFigura()
{
	return 1;
}

void Joc::escriuTauler(const string& nomFitxer)
{

}

bool Joc::mouFigura(int dirX, int dirY)
{
	return 1;
}
