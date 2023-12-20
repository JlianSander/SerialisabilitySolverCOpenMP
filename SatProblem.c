//#include <stdio.h>
//#include <stdint.h>
//#include <stdbool.h>
//#include <string.h>
//#include "List.h"
#include "SatProblem.h"

uint8_t add_assumption(SATProblem_t *solver, int64_t literal)
{
	uint8_t result = EXIT_SUCCESS;
	if (solver->assumptions == NULL)
	{
		solver->assumptions = create_list_int64(literal);
		result |= EXIT_SUCCESS;
	}
	else
	{
		result |= push_int64(solver->assumptions, literal);
	}

	solver->numberOfAssumptions += 1;

	return result;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

uint8_t add_clause(SATProblem_t *solver, nodeInt64_t *clause)
{
	uint8_t result = EXIT_SUCCESS;
	if (solver->clauses == NULL)
	{
		solver->clauses = create_list_list_int64(clause);
		result |= EXIT_SUCCESS;
	}
	else
	{
		result |= push_list_int64(solver->clauses, clause);
	}

	solver->numberOfClauses += 1;

	result =  push_int64(clause, 0);
	return result;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

SATProblem_t *create_sat_problem(uint32_t number_variables)
{
	SATProblem_t *solver = NULL;
	solver = (SATProblem_t*) malloc(sizeof *solver);
	if (solver == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}else 
	{
		solver->assumptions = NULL;
		solver->clauses = NULL;
		solver->numberOfAssumptions = 0;
		solver->numberOfClauses = 0;
		solver->solution = create_array(number_variables);
		return solver;
	}
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

uint8_t free_problem(SATProblem_t *solver)
{
	uint8_t result = EXIT_SUCCESS;
	result |= free_array(solver->solution);
	result |= free_list_list_int64(solver->clauses);
	result |= free_list_int64(solver->assumptions);
	free(solver);
	return EXIT_SUCCESS;
}