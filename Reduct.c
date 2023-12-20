//#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "AF.h"
//#include "List.h"
//#include "Matrix.h"
//#include "Actives.h"
//#include "LinkedSparseMatrix.h"
#include "Reduct.h"

activeArgs_t* get_reduct(activeArgs_t *activeArguments, argFramework_t *framework, uint32_t argument)
{
	activeArgs_t *newActives = copy_active_arguments(activeArguments);
	deactivate_argument(newActives, argument);
	uint32_t currentVictim = 0;
	if (!has_next_in_row(framework->victims, argument, currentVictim)){
		return newActives;
	}

	do {
		currentVictim = get_next_in_row(framework->victims, argument, currentVictim);
		if (is_active(newActives, currentVictim)){
			deactivate_argument(newActives, currentVictim);
		}
	} while (has_next_in_row(framework->victims, argument, currentVictim));

	return newActives;
}







