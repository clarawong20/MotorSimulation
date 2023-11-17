#include <stdio.h>
#include "modifiedPMSM_Model.h"


int main(int argc, char** argv) {
	ExtY_modifiedPMSM_Model_T a;
	printf("Theta Output: %f \n", modifiedPMSM_Model_Y.ThetaOutput);
	printf("%f", a.ThetaOutput);
	return 0;
}