#include <iostream>
#include <vector>

using namespace std;

const int gridSize = 7;
const char emptyCell = '~';
const char shipCell = 'S';

void initializeGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < gridSize; ++i) {
        vector<char> row(gridSize, emptyCell);
        grid.push_back(row);
    }
}

void displayGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

bool isPlacementValid(const vector<vector<char>>& grid, int row, int col, int size, bool horizontal) {
    if (horizontal) {
        if (col + size > gridSize) return false;
        for (int i = 0; i < size; ++i) {
            if (grid[row][col + i] != emptyCell) return false;
        }
    }
    else {
        if (row + size > gridSize) return false;
        for (int i = 0; i < size; ++i) {
            if (grid[row + i][col] != emptyCell) return false;
        }
    }
    return true;
}

void placeShip(vector<vector<char>>& grid, int row, int col, int size, bool horizontal) {
    if (horizontal) {
        for (int i = 0; i < size; ++i) {
            grid[row][col + i] = shipCell;
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            grid[row + i][col] = shipCell;
        }
    }
}

void placeShips(vector<vector<char>>& grid) {
    vector<int> shipSizes = { 1, 1, 2, 2, 3, 4 };

    for (int size : shipSizes) {
        bool placed = false;

        while (!placed) {
            int row, col;
            char orientation;

            cout << "Введите начальную координату для корабля размером " << size << " клетки (например, 0 1): ";
            cin >> row >> col;

            if (size > 1) {
                cout << "Введите ориентацию корабля (h - горизонтально, v - вертикально): ";
                cin >> orientation;
            }
            else {
                orientation = 'h';
            }

            bool horizontal = (orientation == 'h');

            if (isPlacementValid(grid, row, col, size, horizontal)) {
                placeShip(grid, row, col, size, horizontal);
                displayGrid(grid);
                placed = true;
            }
            else {
                cout << "Невозможно разместить здесь корабль. Попробуйте снова.\n";
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<char>> grid;

    initializeGrid(grid);
    cout << "Начальная сетка:\n";
    displayGrid(grid);

    placeShips(grid);

    cout << "Все корабли размещены:\n";
    displayGrid(grid);

    return 0;
}