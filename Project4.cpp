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


}											

 
//	%This function will malloc space for a single kit ----
//	%Read in the name from "filePtr", malloc space for the name and store a reference to the space in the structure -----
//	%Call "ReadAPart" to read in the parts and store the pointer returned in the strucure ------
//	%Call "kitCost", below, to determine the cost of all the parts in the kit, and store that into the structure -----   


struct ReadAKit(FILE *filePtr){
}

// %This function will go through the linked list of parts---------
// %And print all of the parts that follow the part referenced by the pointer argument "currentPart"-----

void PrintParts(struct part *currentPart){
}


// %This function goes through the kit referenced by "aKit" ----
// %Determines the total cost for this kit be going through the linked list of parts, starting with the first part referenced by "firstPart"----
// %The cost of the single kit is returned by the function ----
 
double kitCost(struct kit *aKit){
}

//  %This function goes through the linked list of kits referenced by "kitList" and determines the total cost of all of the kits -------
// %The total cost of all of the kits is returned by the function.---------

double TotalCost(struct kit *KitList)

int main(){
}
