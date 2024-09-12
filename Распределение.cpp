//Переменные:
//1. grid: Двумерный вектор, представляющий игровую сетку.Каждая ячейка может содержать символ пустой ячейки(`emptyCell`) или символ корабля(`shipCell`).
//2. row и col: Координаты начальной ячейки, где пользователь хочет разместить корабль. `row` определяет строку, а `col` — столбец.
//3. size: Размер корабля в клетках.Например, корабль размером 3 занимает 3 ячейки в сетке.
//4. horizontal: Определяет ориентацию корабля.Если 'true', корабль размещается горизонтально.Если `false`, вертикально.
//5. orientation: Пользовательский ввод, определяющий направление размещения корабля : 'h' для горизонтального и `'v'` для вертикального.
//6.shipSizes: Вектор, содержащий размеры кораблей, которые нужно разместить на сетке.Например, `{1, 1, 2, 2, 3, 4}` означает, что нужно разместить два корабля размером 1, два корабля размером 2, один корабль размером 3 и один корабль размером 4 клетки.
//7.placed: Флаг, указывающий, успешно ли корабль был размещен на сетке.Если `true`, размещение было успешным, и программа переходит к следующему кораблю.
//Константы:
//gridSize: Используется в условии проверки в isPlacementValid() для определения границ сетки.
//emptyCell и shipCell : Обозначают символы, используемые в сетке для пустых ячеек и ячеек с кораблями соответственно.
#include <iostream>
#include <vector>

using namespace std;

const int gridSize = 7;
const char emptyCell = '~';
const char shipCell = 'S';

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
