#include "labels.h"

void new_temp (int * temp_counter, char * temp_string)
{
	char temp_number[6];
	sprintf(temp_number, "%03d", (*temp_counter)++);	
	strcpy(temp_string, "TMP");	
	strcat(temp_string, temp_number);	
}


void new_label (int * label_counter, char * label_string)
{
	char label_number[6];
	sprintf(label_number, "%03d: ", (*label_counter)++);	
	strcpy(label_string, "L");	
	strcat(label_string, label_number);
}
