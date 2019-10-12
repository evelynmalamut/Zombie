#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include "globals.h"
#include "History.h"
using namespace std;

History::History(int nRows, int nCols)
: m_rows(nRows), m_cols(nCols) //intializing rows and cols of grid
{
    for (int r = 0; r < nRows; r++) { //generating grid (similar to arena), by filling up the rows and cols with '.'s
        for (int c = 0; c < nCols; c++) {
            m_grid[r][c] = '.';
        }
    }
}

bool History::record(int r, int c) {
    if (r > m_rows || c > m_cols || r < 1 || c < 1) {
        return false;
    }
    char currentChar = m_grid[r-1][c-1]; //determining surrent character at player's position
    if(currentChar == '.') {
        m_grid[r-1][c-1] = 'A'; //-1 b/c top left of grid is (1,1)
    }
    else if (currentChar == 'Z') {
        m_grid[r-1][c-1] = 'Z'; //keeping Z as character if another Zombie killed at a location where 26+ Zombies have been killed alraedy
    }
    else {
        m_grid[r-1][c-1] = currentChar + 1; //replacing with next letter if Zombie already killed at that spot
    }
    return true;
}


void History::display() const {
    
    // Draw the grid (same as arena)
    clearScreen();
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
            cout << m_grid[r][c];
        cout << endl;
    }
    cout << endl;
}


