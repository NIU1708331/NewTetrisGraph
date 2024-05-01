#ifndef FIGURA_H
#define FIGURA_H
class Tauler;
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

namespace FiguraMatrices 
{
    const int NO_FIGURA[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    const int FIGURA_O[4][4] = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_I[4][4] = {
        {0,0,0,0},
        {2,2,2,2},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_T[4][4] = {
        {0,3,0,0},
        {3,3,3,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_L[4][4] = {
        {0,0,4,0},
        {4,4,4,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_J[4][4] = {
        {5,0,0,0},
        {5,5,5,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_Z[4][4] = {
        {6,6,0,0},
        {0,6,6,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    const int FIGURA_S[4][4] = {
        {0,7,7,0},
        {7,7,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
}


inline const int(*matriuFigures[8])[4][4] = {
    &FiguraMatrices::NO_FIGURA,
    &FiguraMatrices::FIGURA_O,
    &FiguraMatrices::FIGURA_I,
    &FiguraMatrices::FIGURA_T,
    &FiguraMatrices::FIGURA_L,
    &FiguraMatrices::FIGURA_J,
    &FiguraMatrices::FIGURA_Z,
    &FiguraMatrices::FIGURA_S,
};


class Figura
{
public:
    void girar_figura(DireccioGir gir);
    void mov_figura(int dirX, int dirY);
    bool gir_legal(DireccioGir gir,Tauler* tauler);
    bool mov_legal(int dirX, Tauler* taulaer);
    bool baixar(int dirY, Tauler* tauler);
    int getPixel(int x, int y) { return m_figura[x][y]; }
    void setFigura(const int figura[MAX_AMPLADA][MAX_ALCADA]);
    void setDir(int dir) { m_dir = dir; }
    void setPosicio(int x, int y) { m_x = x; m_y = y; }
    void setTipus(TipusFigura type) { m_type = type; }
    void getMax();
    TipusFigura gettype() { return m_type; }
    int getX() { return m_x; }
    int getY() { return m_y; }
    int getSize() { return max_alcada; }

private:
    
    int m_figura[MAX_AMPLADA][MAX_ALCADA];
    TipusFigura m_type;
    int m_dir;
    int m_x, m_y;
    int max_alcada=3, max_amplada=3;
};


#endif
