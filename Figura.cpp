#include "Figura.h"
#include "Tauler.h"


void Figura::girar_figura(DireccioGir gir )
{

	int matriu_tmp[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			matriu_tmp[j][i] = m_figura[i][j];
		}
	}

	if (gir==GIR_HORARI)
	{
		for (int i = 0; i < MAX_ALCADA; i++)
		{
			
			for (int j = 0; j < MAX_AMPLADA; j++)
			{
				m_figura[i][j] = matriu_tmp[i][MAX_ALCADA - j - 1];
			}
		}
	}
	else
	{

		for (int i = 0; i < MAX_ALCADA; i++)
		{

			for (int j = 0; j < MAX_AMPLADA; j++)
			{
				m_figura[j][i] = matriu_tmp[MAX_ALCADA - j - 1][i];
			}
		}

	}
}

void Figura::mov_figura(int dirx, int dirY)
{
	m_x += dirx;
	m_y += dirY;
}

bool Figura::mov_legal(DireccioGir gir, int dirX, int dirY, Tauler* tauler)
{
	bool resultat = true;
	int i = 0;
	//gir legal
	girar_figura(gir);
	while (resultat&&i<MAX_ALCADA)
	{
		for (int j = 0; i < MAX_AMPLADA; i++)
		{

			if (getPixel(i,j) != COLOR_NEGRE && tauler->getPixel(i + m_y,j + m_x) != COLOR_NEGRE)
			{

			}
		}
	}

	

	return resultat;
}
