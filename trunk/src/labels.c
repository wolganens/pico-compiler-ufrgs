#include "labels.h"

char * new_temp (int temp_counter)
{
	char * temp_string = (char *) malloc(7*sizeof(char));
	sprintf(temp_string, "%03d(Rx)", temp_counter);	
	return temp_string;	
}


char * new_label (int label_counter)
{
	char * label_string = (char *) malloc(7*sizeof(char));
	sprintf(label_string, "L%03d: ", label_counter);	
	return label_string;
}
