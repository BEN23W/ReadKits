#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct part {
	char *description
	int qtyPerKit;
	double costPerItem;
	struct part *nextPart;
};

struct kit{
	char *kitName;
	struct part *firstPart;
	double kitCost;
	struct kit *nextKit;
};

// %This function will malloc space for a single part struct.
// %Read in the description, qty per kit, and cost per part from the file.
// %Store those values into the structure created, then return a pointer to that structure

struct part *ReadAPart(FILE *fileptr){		


struct part *aPart = malloc(sizeof(struct part));

aPart-> descpription = description;
aPart->qtyPerKit = qtyPerKit;
aPart->costPerItem = costPerItem;

return aPart;
}	

int main(){
	
	FILE *fileptr;
	char fileName[100];
	char *removeLine;
	
	
	fgets(fileName, sizeof fileName, stdin);
	
		if((removeLine = strchr(fileName, '\n')) != NULL){
			*removeLine = '\0';					/* remove newline */
		}
	
	
	
}		
