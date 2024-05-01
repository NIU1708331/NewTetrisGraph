#include "Tauler.h"
#include<iostream>
using namespace std;


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

	// 1. Buscar de abajo a arriba todas las filas que se pueden eliminar
	// 2. Eliminarlas y desplazar todas las que esten encima
	m_filesFet = 0;
	for (int y = MAX_FILA - 1; y >= 0; --y) 
	{
		bool isFull = true;
		int x = 0;
		while (isFull && x < MAX_COL)
		{
			if (m_taula[y][x] == COLOR_NEGRE)
			{
				isFull = false;
			}
			else {
				x++;
			}
		}
		if (isFull)
		{
			eliminaYDesplaza(y);
			m_filesFet++;
		}
	}
}
			
void Tauler::eliminaYDesplaza(int y)
{
	for (int x = 0; x < MAX_COL; x++)
	{
		m_taula[y][x] = COLOR_NEGRE;
	}

	for (int nY = y; nY > 0; nY--)
	{
		for (int x = 0; x < MAX_COL; x++)
		{
			m_taula[nY][x] = m_taula[nY-1][x];
		}
	}

	for (int i = 0; i < MAX_COL; i++)
	{
		m_taula[0][i] = COLOR_NEGRE;
	}

	fila_a_eliminar();
}


void Tauler::NEW_fila_a_eliminar()
{

	bool trobat = false;
	int i = 0;
	while (!trobat&&i<MAX_FILA)
	{
		int j = 0;
		while (m_taula[i][j]!=COLOR_NEGRE&&j<=MAX_COL+1)
		{
			j++;
			if (j==(MAX_COL))
			{	
				m_filesFet++;
				trobat = true;
				std::cout << i;
				eliminar_fila(i);
			}
		}
		i++;
	}
}

void Tauler::eliminar_fila(int y)//Y=fila X=col
{
	//eliminar
	for (int i = 0; i < MAX_COL; i++)
	{
		m_taula[y][i] = COLOR_NEGRE;
		std::cout << y << i << std::endl;
	}
	/*
	for (int i = MAX_FILA-1; i >= y; i--)
	{
		
		for (int j = 0; j < MAX_COL; j++)
		{
			m_taula[i][j] = m_taula[j + 1][i];
		}
	}
	*/
	//baixar taula
	
	
	//comprovar de nou
	//fila_a_eliminar();
}


void Tauler::desatFigura(Figura figura)
{
	for (int i = 0; i < figura.getSize(); i++)
	{
		
		for (size_t j = 0; j < figura.getSize(); j++)
		{
			if (figura.getPixel(j,i) != COLOR_NEGRE)
			{
				if (figura.getX() + j < MAX_COL && figura.getX() + j >= 0 &&
					figura.getY() + i < MAX_FILA && figura.getY() + i >= 0
				)
				{
			
					m_taula[figura.getY() + i][figura.getX() + j] = figura.getPixel(j,i);
				}
			}
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
