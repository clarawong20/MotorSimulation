#include <stdio.h>
#include "modifiedPMSM_Model.h"
#include "rtwtypes.h"


int main(int argc, char** argv) {
	// modifiedPMSM_Model_Y is aliase of output struct
	// to call ThetaOutput, we use the dot to access the variable ThetaOutput, use modifiedPMSM_Model_Y  which holds the output values
	printf("Theta Output: %f \n", modifiedPMSM_Model_Y.ThetaOutput);

	return 0;
}