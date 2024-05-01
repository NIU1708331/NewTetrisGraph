#include "Tauler.h"
#include<iostream>

Tauler::Tauler()
{
	for (int i = 0; i < MAX_COL; i++)
	{
		
		for (int j = 0; j < MAX_FILA; j++)
		{
			m_taula[i][j] = 0;
		}
	}
}

void Tauler::setTaula(int taula[MAX_FILA][MAX_COL])
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_taula[i][j] = taula[i][j];
		}
	}
}

void Tauler::fila_a_eliminar()
{
	bool trobat = false;
	int i = 0,j = 0;
	while (!trobat&&i<MAX_FILA)
	{
		while (m_taula[i][j]!=COLOR_NEGRE)
		{
			j++;
			if (j==MAX_COL)
			{	
				m_filesFet++;
				trobat = true;
				std::cout << i;
				eliminar_fila(i-1);
			}
		}
		i++;
	}
	
}

void Tauler::eliminar_fila(int x)//X=fila Y=col
{
	//eliminar
	for (int i = 0; i < MAX_COL; i++)
	{
		m_taula[x][i] = COLOR_NEGRE;
	}
	
	//baixar taula
	/*
	for (int i = MAX_FILA-1; i >= x; i--)
	{
		
		for (int j = 0; j < MAX_COL; j++)
		{
			m_taula[i][j] = m_taula[i + 1][j];
		}
	}
	*/
	//comprovar de nou
	//fila_a_eliminar();
}


void Tauler::desatFigura(Figura figura)
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		
		for (size_t j = 0; j < MAX_COL; j++)
		{
			m_taula[figura.getX() + i][figura.getY() + j] = figura.getPixel(j,i);
		}
	}
}

std::ifstream& operator>>(std::ifstream& is, Tauler& tauler) {

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			is >> tauler.m_taula[i][j];
		}
	}

	return is;
}
