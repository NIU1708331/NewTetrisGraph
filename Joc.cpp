#include "Joc.h"
#include <iostream>
#include <fstream>
using namespace std;

Joc::Joc()
{
    tipusFigura = 0;
    fila = 0; 
    columna = 0; 
    tipusGir = 0;
}
void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxerInit(nomFitxer); 

    int c_x=-1, c_y=-1;

    if (fitxerInit.is_open())
    {
        fitxerInit >> tipusFigura >> fila >> columna >> tipusGir;

        TipusFigura tipus;
        switch (tipusFigura) {
        case 0:
            tipus = NO_FIGURA;
            break;
        case 1:
            tipus = FIGURA_O;
            c_x = 0;
            c_y = 0;
            break;
        case 2:
            tipus = FIGURA_I;
            c_x = -2;
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
        m_figura.setPosicio(columna+c_x, fila+c_y);

        for (int i = 0; i < tipusGir; i++)
        {
            m_figura.girar_figura(GIR_HORARI);
        }

        fitxerInit >> m_tauler;
        fitxerInit.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio) 
{
   return m_figura.gir_legal(direccio,&m_tauler);
}
bool Joc::mouFigura(int dirX)
{
    bool resultat = m_figura.mov_legal(dirX,&m_tauler);
    if (resultat)
    {
        m_figura.mov_figura(dirX, 0);
    }
    return resultat;
}

int Joc::baixaFigura()
{
    while (m_figura.baixar(1 ,&m_tauler))
    {

    }
    m_tauler.fila_a_eliminar();
    return m_tauler.files_fet();
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxerTauler;
    fitxerTauler.open(nomFitxer);

    if (fitxerTauler.is_open())
    {
        for (int i = 0; i < MAX_FILA; ++i)
        {
            for (int j = 0; j < MAX_COL; ++j)
            {
                fitxerTauler << m_tauler.getPixel(i, j);
            }
            fitxerTauler << endl; 
        }
        fitxerTauler.close();
    }
}

bool Joc::mouFigura(int dirX, int dirY)
{
	return 1;
}
