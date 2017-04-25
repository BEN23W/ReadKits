#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Ghost comment

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
	
	struct part *partPtr = NULL;
	
	
	partPtr = (struct part*)malloc(sizeof(struct part));
	partPtr->description = (char*)malloc(sizeof(char)*100);
	fscanf(filePtr, " %[^\n]s", partPtr->description);
	printf("%s\n", partPtr->description);
	fscanf(filePtr, "%d", &partPtr->qtyPerKit);
	printf("%d ", partPtr->qtyPerKit);
	fscanf(filePtr, " %lf", &partPtr->costPerItem);
	printf("%.2lf\n", partPtr->costPerItem);
	
	if(!feof(filePtr))													//if not end of file:
	{
	partPtr->nextPart = ReadAPart(filePtr);				
	}
	return partPtr;	
}

//struct kit *ReadAKit(FILE *filePtr) - this function will malloc space for a single kit, read in the name from filePtr, 
//	malloc space for the name and store a reference to the space in the structure. 
//	Then call ReadAPart to read in the parts and store the pointer returned in the strucure. 
//	Then call kitCost, described below, to determine the cost of all the parts in the kit, and store that into the structure. 
//	Then return a pointer to the structure created. 

struct kit *ReadAKit(FILE *filePtr) {
	struct kit *kitPtr = NULL;
	kitPtr = (struct kit*)malloc(sizeof(struct kit));
	kitPtr->kitName = (char*)malloc(sizeof(char));
	fscanf(filePtr, "%[^\n]s", kitPtr->kitName);	
	printf("%s\n", kitPtr->kitName); //Check for correct name
	ReadAPart(filePtr);	
}

//void PrintParts(struct part *currentPart) - this function will go through the linked list of parts and 
//	print all of the parts that follow the part referenced by the pointer argument currentPart.  

void PrintParts(struct part *currentPart) {
	currentPart = (struct part*)malloc(sizeof(struct part));
		

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
	ReadAKit(currentFile);
	}
	return 0;
}
