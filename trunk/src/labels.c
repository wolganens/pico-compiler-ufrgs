#include "labels.h"

char * new_temp (int temp_counter)
{
	static char temp_string[7];
	sprintf(temp_string, "TMP%03d", temp_counter);	
	return temp_string;	
}


char * new_label (int label_counter)
{
	static char label_string[7];
	sprintf(label_string, "L%03d: ", label_counter);	
	return label_string;
}
