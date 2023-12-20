#include <cstdio>
#include <iostream>
//#include <stdlib.h >
#include <stdio.h>
#include <stdint.h>

#include "Actives.c"
#include "AF.c"
#include "Array.c"
#include "Encodings.c"
#include "LinkedSparseMatrix.c"
#include "List.c"
#include "Matrix.c"
#include "Reduct.c"
#include "SatProblem.c"

#include "ExternalSolver.h"

int main()
{

	argumentInitTemp_t *head = set_up_initialization(4);
	add_attack(head, 1, 2);
	add_attack(head, 1, 3);
	add_attack(head, 3, 1);
	add_attack(head, 4, 1);
	argFramework_t *framework = initialize_framework(head);

	printf("Attackers\n");
	print_matrix(framework->attackers);
	printf("Victims\n");
	print_matrix(framework->victims);

	activeArgs_t *actives = initialize_actives(4);
	printf("\n Active Arguments: base\n");
	print_active_arguments(actives);
	printf("\n");

	activeArgs_t *reduct = get_reduct(actives, framework, 2);
	printf("\n Active Arguments: reducted by 2\n");
	print_active_arguments(reduct);
	printf("\n");

	activeArgs_t *reduct2 = get_reduct(reduct, framework, 3);
	printf("\n Active Arguments: reducted by 3\n");
	print_active_arguments(reduct2);
	printf("\n");
	/*
	activeArgs_t *reduct3 = get_reduct(reduct2, framework, 1);
	printf("\n Active Arguments: reducted by 1\n");
	print_active_arguments(reduct3);

	activeArgs_t *reduct4 = get_reduct(reduct3, framework, 4);
	printf("\n Active Arguments: reducted by 4\n");
	print_active_arguments(reduct4);*/

	SATProblem_t *problem = create_sat_problem(4);
	add_clauses_nonempty_admissible_set(problem, framework, actives);
	printf("\nEncoding SAT for basis: \n");
	print_list_list_int64(problem->clauses);
	printf("\n");

//	//ExternalSatSolver::solve(problem, path_to_Solver);

    printf("hello from %s!\n", "SerialisabilitySolverCOpenMP");
    return 0;
}