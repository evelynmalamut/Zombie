#ifndef History_h
#define History_h

#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    int m_rows; //rows of grid
    int m_cols; //cols of grid
    char m_grid[MAXROWS][MAXCOLS]; //array (rows) of arrays (cols)
};

#endif
