#ifndef EXTERNAL_SOLVER_H
#define EXTERNAL_SOLVER_H

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include "SatProblem.h"

#include "libs/pstreams-1.0.3/pstream.h"

/*
Class for all kinds of pre-compiled SAT solvers, e.g. cadical, cryptominisat5
SAT calls are answered by opening a pipe to an instance of the external solver with pstream
*/
class ExternalSatSolver {
public:    
    /// <summary>
    /// Computes the solution of the specified SAT-problem.
    /// </summary>
    /// <param name="problem">The SAT-problem to solve.</param>
    /// <returns>Returns '10' if the operation was successful. Otherwise returns '20'.</returns>
    static uint8_t solve(SATProblem_t *problem, std::string path_to_solver);
    
       
    /// <summary>
    /// Computes the solution of the specified SAT-problem combined with the specified assumptions.
    /// </summary>
    /// <param name="problem">The SAT-problem to solve.</param>
    /// <param name="assumptions">The assumptions to take into account.</param>
    /// <returns>
    /// Returns '10' if the operation was successful. Otherwise returns '20'.
    /// </returns>
    static uint8_t solve_with_assumptions(SATProblem_t *problem, nodeInt64_t *assumptions, std::string path_to_solver);
};

#endif
