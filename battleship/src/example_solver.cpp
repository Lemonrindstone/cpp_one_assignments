#include "../include/example_solver.h"
#include <iostream>

void ExampleSolver::solve(Board &board) {
    for (size_t i = 0; i < board.getX(); i++) {
        for (size_t j = 0; j < board.getY(); j++) {
            guess(i, j, board);
        }
    }
}



