#include <iostream>
#include "../include/user_solver.h"
#include <set>

//void UserSolver::solve(Board &board) {
//    // Your Implementation goes here
//    ReturnType t = guess(1, 1, board);
//    std::cout << t << std::endl;
//    //mentions the test result
//    //std::cout << "Guess result: " << static_cast<int>(t) << std::endl;
//}


//example solver original
//void UserSolver::solve(Board &board) {
//    for (size_t i = 0; i < board.getX(); i++) {
//        for (size_t j = 0; j < board.getY(); j++) {
//            guess(i, j, board);
//        }
//    }
//}

// Apparently this guesses the entire board, this is used to intentify the amount of
// guesses(couldn't figure out how to access the guesser counter which I know exists in guesser void
// ExampleSolver::solve(Board &board) {
//     int myGuessCount = 0;
//
//     for (size_t i = 0; i < board.getX(); i++) {
//         for (size_t j = 0; j < board.getY(); j++) {
//             guess(i, j, board);
//             myGuessCount++;
//         }
//     }
//
//     std::cout << "Total guesses used: " << myGuessCount << std::endl;
// }

// Failed test trying to sink, I am an idiot who didn't realize sunk wasn't a return type for guesser
// void UserSolver::solve(Board &board) {
//     int myGuessCount = 0;
//     int sunkCount = 0;
//     const int totalShips = 5;
//
//     for (size_t i = 0; i < board.getX(); i++) {
//         for (size_t j = 0; j < board.getY(); j++) {
//             ReturnType result = guess(i, j, board);
//             myGuessCount++;
//
//             if (result == ReturnType::SUNK) {
//                 sunkCount++;
//             }
//
//             if (sunkCount >= totalShips) {
//                 std::cout << "All ships sunk!" << std::endl;
//                 std::cout << "Guesses used: " << myGuessCount << std::endl;
//                 return;
//             }
//         }
//     }
//
//     std::cout << "Finished full board scan." << std::endl;
//     std::cout << "Guesses used: " << myGuessCount << std::endl;
// }

// This code does appear to work, stopping after a certain number of guesses
// void UserSolver::solve(Board &board) {
//    std::set<std::pair<size_t, size_t>> hits;  // Track which ships have been hit
//    size_t totalShips = board.getShipCount();
//    size_t guessCount = 0;
//
//    for (size_t i = 0; i < board.getX(); ++i) {
//        for (size_t j = 0; j < board.getY(); ++j) {
//            ReturnType result = guess(i, j, board);
//            guessCount++;
//
//            if (result == ReturnType::hit) {
//                hits.insert({i, j});
//                std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//
//                if (hits.size() == totalShips) {
//                    std::cout << "All ships sunk after " << guessCount << " guesses." <<
//                    std::endl; return;
//                }
//            }
//        }
//    }
//
//    std::cout << "Board scan complete." << std::endl;
//    std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//    std::cout << "Total guesses: " << guessCount << std::endl;
//}


// void UserSolver::solve(Board &board) {
//     std::set<std::pair<size_t, size_t>> hits;
//     size_t totalShips = board.getShipCount();
//     size_t guessCount = 0;
//     bool done = false;
//
//     for (size_t i = 0; i < board.getX() && !done; ++i) {
//         for (size_t j = 0; j < board.getY(); ++j) {
//             ReturnType result = guess(i, j, board);
//             guessCount++;
//
//             if (result == ReturnType::hit) {
//                 hits.insert({i, j});
//                 std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//
//                 if (hits.size() == totalShips) {
//                     std::cout << "All ships sunk after " << guessCount << " guesses." <<
//                     std::endl; done = true; break;  // exit inner loop
//                 }
//             }
//         }
//     }
//
//     std::cout << "Board scan complete." << std::endl;
//     std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//     std::cout << "Total guesses: " << guessCount << std::endl;
// }

// Attempt at code for a near miss
//void UserSolver::solve(Board &board) {
//     size_t totalShips = board.getShipCount();
//     std::set<std::pair<size_t, size_t>> hits;
//     std::set<std::pair<size_t, size_t>> visited;
//
//     const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//     for (size_t i = 0; i < board.getX(); ++i) {
//         for (size_t j = 0; j < board.getY(); ++j) {
//             if (hits.size() == totalShips) break;
//             if (visited.count({i, j})) continue;
//
//             ReturnType result = guess(i, j, board);
//             visited.insert({i, j});
//
//             if (result == ReturnType::hit) {
//                 hits.insert({i, j});
//                 std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//             } else if (result == ReturnType::near_miss) {
//                 // Check neighbors when near miss is found
//                 for (const auto &dir : directions) {
//                     size_t ni = i + dir[0];
//                     size_t nj = j + dir[1];
//
//                     if (ni >= board.getX() || nj >= board.getY()) continue;
//                     if (visited.count({ni, nj})) continue;
//
//                     ReturnType followUp = guess(ni, nj, board);
//                     visited.insert({ni, nj});
//
//                     if (followUp == ReturnType::hit) {
//                         hits.insert({ni, nj});
//                         std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
//                         if (hits.size() == totalShips) break;
//                     }
//                 }
//             }
//         }
//         if (hits.size() == totalShips) break;
//     }
//
//     std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//
// }


// void UserSolver::solve(Board &board) {
//     std::set<std::pair<size_t, size_t>> hits;
//     std::set<std::pair<size_t, size_t>> visited;
//     size_t totalShips = board.getShipCount();
//     size_t guessCount = 0;
//     bool done = false;
//
//     const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//     for (size_t i = 0; i < board.getX() && !done; ++i) {
//         for (size_t j = 0; j < board.getY(); ++j) {
//             if (visited.count({i, j})) continue;
//
//             ReturnType result = guess(i, j, board);
//             guessCount++;
//             visited.insert({i, j});
//
//             if (result == ReturnType::hit) {
//                 hits.insert({i, j});
//                 std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//                 if (hits.size() == totalShips) {
//                     done = true;
//                     break;
//                 }
//             } else if (result == ReturnType::near_miss) {
//                 for (const auto &dir : directions) {
//                     size_t ni = i + dir[0];
//                     size_t nj = j + dir[1];
//                     if (ni >= board.getX() || nj >= board.getY()) continue;
//                     if (visited.count({ni, nj})) continue;
//
//                     ReturnType followUp = guess(ni, nj, board);
//                     guessCount++;
//                     visited.insert({ni, nj});
//
//                     if (followUp == ReturnType::hit) {
//                         hits.insert({ni, nj});
//                         std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
//                         if (hits.size() == totalShips) {
//                             done = true;
//                             break;
//                         }
//                     }
//                 }
//                 if (done) break;
//             }
//         }
//     }
//
//     std::cout << "Board scan complete." << std::endl;
//     std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//     std::cout << "Total guesses: " << guessCount << std::endl;
// }


//Successful Near Miss code but it doesn't seem to affect the guess count, I need to find a way to more effectively use the near miss. Most effective so far and technically is better than checking all 1 million squares. But I think all that it's really doing is ending the program once it finds the 5th ship, and that's where the bulk of the guesses are going. 
//void UserSolver::solve(Board &board) {
//    std::set<std::pair<size_t, size_t>> hits;
//    std::set<std::pair<size_t, size_t>> visited;
//    size_t totalShips = board.getShipCount();
//    size_t guessCount = 0;
//    bool done = false;
//
//    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//    for (size_t i = 0; i < board.getX() && !done; ++i) {
//        for (size_t j = 0; j < board.getY(); ++j) {
//            if (visited.count({i, j})) continue;
//
//            ReturnType result = guess(i, j, board);
//            guessCount++;
//            visited.insert({i, j});
//
//            if (result == ReturnType::hit) {
//                hits.insert({i, j});
//                std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//                if (hits.size() == totalShips) {
//                    done = true;
//                    break;
//                }
//            } else if (result == ReturnType::near_miss) {
//                for (const auto &dir : directions) {
//                    size_t ni = i + dir[0];
//                    size_t nj = j + dir[1];
//                    if (ni >= board.getX() || nj >= board.getY()) continue;
//                    if (visited.count({ni, nj})) continue;
//
//                    ReturnType followUp = guess(ni, nj, board);
//                    guessCount++;
//                    visited.insert({ni, nj});
//
//                    if (followUp == ReturnType::hit) {
//                        hits.insert({ni, nj});
//                        std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
//                        if (hits.size() == totalShips) {
//                            done = true;
//                            break;
//                        }
//                    }
//                }
//                if (done) break;
//            }
//        }
//    }
//
//    std::cout << "Board scan complete." << std::endl;
//    std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//    std::cout << "Total guesses: " << guessCount << std::endl;
//}

//dogshit code for a stride that didn't work, I think i'm skipping too many spaces
//void UserSolver::solve(Board& board) {
//    std::set<std::pair<size_t, size_t>> hits;
//    std::set<std::pair<size_t, size_t>> visited;
//    size_t totalShips = board.getShipCount();
//    size_t guessCount = 0;
//    bool done = false;
//
//    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//    int stride = 10;  // Adjust stride size for better coverage
//
//    for (size_t i = 0; i < board.getX() && !done; i += stride) {
//        for (size_t j = 0; j < board.getY(); j += stride) {
//            if (visited.count({i, j})) continue;
//
//            ReturnType result = guess(i, j, board);
//            guessCount++;
//            visited.insert({i, j});
//
//            if (result == ReturnType::hit) {
//                hits.insert({i, j});
//                std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//                if (hits.size() == totalShips) {
//                    done = true;
//                    break;
//                }
//            } else if (result == ReturnType::near_miss) {
//                // Explore surrounding cells more thoroughly
//                for (const auto& dir : directions) {
//                    size_t ni = i + dir[0];
//                    size_t nj = j + dir[1];
//
//                    if (ni >= board.getX() || nj >= board.getY()) continue;
//                    if (visited.count({ni, nj})) continue;
//
//                    ReturnType followUp = guess(ni, nj, board);
//                    guessCount++;
//                    visited.insert({ni, nj});
//
//                    if (followUp == ReturnType::hit) {
//                        hits.insert({ni, nj});
//                        std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
//                        if (hits.size() == totalShips) {
//                            done = true;
//                            break;
//                        }
//                    }
//                }
//                if (done) break;
//            }
//        }
//    }
//
//    std::cout << "Board scan complete." << std::endl;
//    std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//    std::cout << "Total guesses: " << guessCount << std::endl;
//}


//Most Recent attempt
//void UserSolver::solve(Board& board) {
//    std::set<std::pair<size_t, size_t>> hits;
//    std::set<std::pair<size_t, size_t>> visited;
//    size_t totalShips = board.getShipCount();
//    size_t guessCount = 0;
//    bool done = false;
//
//    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//    size_t rows = board.getX();
//    size_t cols = board.getY();
//
//    for (size_t i = 0; i < rows && !done; ++i) {
//        for (size_t j = 0; j < cols && !done; ++j) {
//            if (visited.count({i, j})) continue;
//
//            ReturnType result = guess(i, j, board);
//            guessCount++;
//            visited.insert({i, j});
//
//            if (result == ReturnType::hit) {
//                hits.insert({i, j});
//                std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
//                if (hits.size() == totalShips) {
//                    done = true;
//                    break;
//                }
//            } else if (result == ReturnType::near_miss) {
//                // Check the four adjacent directions
//                for (const auto& dir : directions) {
//                    size_t ni = i + dir[0];
//                    size_t nj = j + dir[1];
//
//                    // bounds check
//                    if (ni >= rows || nj >= cols) continue;
//                    if (visited.count({ni, nj})) continue;
//
//                    ReturnType followUp = guess(ni, nj, board);
//                    guessCount++;
//                    visited.insert({ni, nj});
//
//                    if (followUp == ReturnType::hit) {
//                        hits.insert({ni, nj});
//                        std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
//                        if (hits.size() == totalShips) {
//                            done = true;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    std::cout << "Board scan complete." << std::endl;
//    std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << std::endl;
//    std::cout << "Total guesses: " << guessCount << std::endl;
//}


//Final Code, finally I am actually skipping a significant amount of uneccesary checks due to using the miss result, means I skip the cardinal guesses if I get a miss. The code's a little bloated but it works. 
void UserSolver::solve(Board& board) {
    std::set<std::pair<size_t, size_t>> hits;
    std::set<std::pair<size_t, size_t>> visited;
    std::set<std::pair<size_t, size_t>> toSkip;  // To track adjacents of confirmed misses

    size_t totalShips = board.getShipCount();
    size_t guessCount = 0;

    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    size_t rows = board.getX();
    size_t cols = board.getY();

    for (size_t i = 0; i < rows && hits.size() < totalShips; ++i) {
        for (size_t j = 0; j < cols && hits.size() < totalShips; ++j) {
            std::pair<size_t, size_t> current = {i, j};
            if (visited.count(current) || toSkip.count(current)) continue;

            ReturnType result = guess(i, j, board);
            guessCount++;
            visited.insert(current);

            if (result == ReturnType::hit) {
                hits.insert(current);
                std::cout << "Hit at (" << i << ", " << j << ")!" << std::endl;
            } else if (result == ReturnType::near_miss) {
                for (auto [dx, dy] : directions) {
                    size_t ni = i + dx;
                    size_t nj = j + dy;
                    if (ni >= rows || nj >= cols) continue;

                    std::pair<size_t, size_t> adj = {ni, nj};
                    if (visited.count(adj) || toSkip.count(adj)) continue;

                    ReturnType adjResult = guess(ni, nj, board);
                    guessCount++;
                    visited.insert(adj);

                    if (adjResult == ReturnType::hit) {
                        hits.insert(adj);
                        std::cout << "Hit at (" << ni << ", " << nj << ")!" << std::endl;
                        if (hits.size() == totalShips) break;
                    }
                }
            } else if (result == ReturnType::miss) {
                for (auto [dx, dy] : directions) {
                    size_t ni = i + dx;
                    size_t nj = j + dy;
                    if (ni < rows && nj < cols) {
                        toSkip.insert({ni, nj});  // Avoid checking these
                    }
                }
            }
        }
    }

    std::cout << "Board scan complete.\n";
    std::cout << "Ships sunk: " << hits.size() << "/" << totalShips << "\n";
    std::cout << "Total guesses: " << guessCount << "\n";
}