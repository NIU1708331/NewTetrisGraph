#include "Figura.h"
#include "Tauler.h"

void Figura::setFigura(int figura[MAX_AMPLADA][MAX_ALCADA])
{
	for (int i = 0; i < MAX_AMPLADA; i++)
	{
		for (int j = 0; j < MAX_ALCADA; j++)
		{
			m_figura[i][j] = figura[i][j];
		}
	}
}

void Figura::girar_figura(DireccioGir gir )
{

	int max_alcada, max_amplada;
	if (m_type=FIGURA_I)
	{
		max_alcada = 4;
		max_amplada = 4;
	}
	else
	{
		max_alcada = 3;
		max_amplada = 3;
	}

	int matriu_tmp[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < max_alcada; i++)
	{
		for (int j = 0; j < max_amplada; j++)
		{
			matriu_tmp[j][i] = m_figura[i][j];
		}
	}

	if (gir==GIR_HORARI)
	{
		for (int i = 0; i < max_alcada; i++)
		{
			
			for (int j = 0; j < max_amplada; j++)
			{
				m_figura[i][j] = matriu_tmp[i][max_amplada - j - 1];
			}
		}
	}
	else
	{

		for (int i = 0; i < max_alcada; i++)
		{

			for (int j = 0; j < max_amplada; j++)
			{
				m_figura[j][i] = matriu_tmp[max_amplada - j - 1][i];
			}
		}

	}
}

void Figura::mov_figura(int dirx, int dirY)
{
	m_x += dirx;
	m_y += dirY;
}

bool Figura::gir_legal(DireccioGir gir, Tauler* tauler)
{
	bool resultat = true;
	int i = 0;
	//gir legal
	girar_figura(gir);
	while (resultat&&i<MAX_ALCADA)
	{
		for (int j = 0; i < MAX_AMPLADA; i++)//i->Columna, j->Fila
		{

			if (getPixel(i,j) != COLOR_NEGRE && tauler->getPixel(i + m_y,j + m_x) != COLOR_NEGRE)
			{
				resultat = false;
			}
		}
		i++;
	}

	if (!resultat)
	{
		if (gir==GIR_HORARI)
		{
			girar_figura(GIR_ANTI_HORARI);
		}
		else
		{
			girar_figura(GIR_HORARI);
		}
	}

	return resultat;
}
