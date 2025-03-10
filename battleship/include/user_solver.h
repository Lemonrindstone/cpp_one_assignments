#ifndef USER_SOLVER_H_
#define USER_SOLVER_H_

#include "solver.h"

class UserSolver : public Solver {
   public:
    void solve(Board &board) override;
};

#endif // USER_SOLVER_H_
