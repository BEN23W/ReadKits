#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct part {
     char *description;
     int qtyPerKit;
     double costPerItem;
     struct part *nextPart;
};

struct kit {
     char *kitName;
     struct part *firstPart;
     double kitCost;
     struct kit *nextKit;
}; 

//Functions

//struct part *ReadAPart(FILE *filePtr) - this function will malloc space for a single part structure, 
//read in the description, qty per kit,
//and cost per part from the file and store those values into the structure created, then return a pointer to that structure. 
//The format of the file is described later in this writeup.

struct part *ReadAPart(FILE *filePtr) {
	
	struct part *newPart = NULL;
	
	newPart = (struct part*)malloc(sizeof(struct part));
	newPart->description = (char*)malloc(sizeof(char)*100);
	
	fscanf(filePtr, " %[^\n]s", newPart->description);
	printf("%s\n", newPart->description);
	
	fscanf(filePtr, "%d", &newPart->qtyPerKit);
	printf("%d ", newPart->qtyPerKit);
	fscanf(filePtr, " %lf", &newPart->costPerItem);
	printf("%lf\n", newPart->costPerItem);
	
	if(!feof(filePtr))													//if not end of file:
	{
	newPart->nextPart = ReadAPart(filePtr);				
	}
	return newPart;	
}

//struct kit *ReadAKit(FILE *filePtr) - this function will malloc space for a single kit, read in the name from filePtr, 
//	malloc space for the name and store a reference to the space in the structure. 
//	Then call ReadAPart to read in the parts and store the pointer returned in the strucure. 
//	Then call kitCost, described below, to determine the cost of all the parts in the kit, and store that into the structure. 
//	Then return a pointer to the structure created. 

struct kit *ReadAKit(FILE *filePtr) {
	struct kit *newKit = NULL;
	newKit = (struct kit*)malloc(sizeof(struct kit));
	newKit->kitName = (char*)malloc(sizeof(char));
	fscanf(filePtr, "%[^\n]s", newKit->kitName);	
	printf("%s\n", newKit->kitName); //Check for correct name
	
	newKit->firstPart = ReadAPart(filePtr);	
	
	return newKit;
}

//void PrintParts(struct part *currentPart) - this function will go through the linked list of parts and 
//	print all of the parts that follow the part referenced by the pointer argument currentPart.  

void PrintParts(struct part *currentPart) {
	
		

}

//double kitCost(struct kit *aKit) - this function goes through the kit referenced by aKit and 
//determines the total cost for this kit be going through the linked list of parts, 
//starting with the first part referenced by firstPart. 
//The cost of the single kit is returned by the function. 

double kitCost(struct kit *aKit) {
	
}

//double TotalCost(struct kit *kitList) - this function goes through the linked list of kits referenced by kitList and 
//	determines the total cost of all of the kits. The total cost of all of the kits is returned by the function.
 
double TotalCost(struct kit *kitList) {
	
}

int main(void) {
struct kit currentKit = NULL;	
struct part *currentPart = NULL;	
	
	
	FILE* currentFile = NULL;
	char fileName[100] = " ";
	
	char *removeLine;
	
	printf("Please type in the name of the file you wish to open\n");
	fgets(fileName, sizeof fileName, stdin);
	
		if((removeLine = strchr(fileName, '\n')) != NULL){
			*removeLine = '\0';					/* remove newline */
		}
	
//	printf("Enter file name: \n");
//	currentFile = fopen(fileName, "r");
//	currentFile = fopen("samplefile.txt", "r"); //remove this after completion
//	ReadAKit(currentFile);
    currentFile = fopen(fileName, "r");
    if (currentFile != NULL)
    {
        puts("opened file");
    }
    else
    {
        printf("File failed to open");

    }
	while(!feof(currentFile)) 
	{
	currentKit = ReadAKit(currentFile);
	currentPart = currentKit->firstPart;
	
	PrintParts(currentPart);
	
	}
	
	
	return 0;
}
