#include <iostream>
#include <array>
#include "Tetriminoes.h"
#include "Field.h"

int main() {
    using std::array;
    //std::array<int, 4> arr = {4, 5, 6, 7};

    Tetrimino O({4, 5, 6, 7}, tetriminoes::O);
    Tetrimino A = O;

    A.printBlockTmp();
    //O.printBlock();

    std::cout << '\n';

    Field f;

    f.setRowTmp(16);
    f.setRowTmp(17);
    f.setRowTmp(18);
    f.setRowTmp(19);

    f.setHalfRowTmp(15);
    f.RunGame();
    //f.printField();

    return 0;
}
