#include <iostream>
#include "../include/user_solver.h"

void UserSolver::solve(Board &board) {
    // Your Implementation goes here
    ReturnType t = guess(1, 1, board);
    std::cout << t << std::endl;
}
