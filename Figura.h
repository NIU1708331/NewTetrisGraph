#ifndef FIGURA_H
#define FIGURA_H

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    bool girar_figura(DireccioGir gir, int taula );
    bool mov_figura(int dirX, int dirY);
    bool mov_legal(DireccioGir gir, int dirX, int dirY);

    int getPixel(int x, int y) { return m_figura[x][y]; }


private:
    int m_figura[MAX_AMPLADA][MAX_ALCADA];
    TipusFigura m_type;
    DireccioGir m_direccio;
    int m_x, m_y;
};


#endif