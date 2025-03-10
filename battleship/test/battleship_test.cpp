#include <gtest/gtest.h>

#include "../include/board.h"
#include "../include/example_solver.h"
#include "../include/user_solver.h"

TEST(SOLVER_TEST, BasicAssertions) {
    Board b = Board(1000, 1000, 5);

    ExampleSolver es;
    es.solve(b);

    UserSolver us;
    us.solve(b);
    EXPECT_EQ(us.score() < es.score(), true);
}
