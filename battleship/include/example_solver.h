#ifndef EXAMPLE_SOLVER_H_
#define EXAMPLE_SOLVER_H_

#include "solver.h"

class ExampleSolver : public Solver {
   public:
    void solve(Board &board) override;
};

#endif // EXAMPLE_SOLVER_H_
