/*Chekhonin Sergei Team 5*/
/*Module 14 Lab 10*/

/*This program returns sorted parallel arrays*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define dim1 6
#define dim2 20

int findMinIndex(char[dim1][dim2], int);

int main()
{

	char names[dim1][dim2] = {  {"Ryan, Elizabeth"}, {"McIntyre, Osborne"}, {"DuMond, Kristin"},
		{"Larson, Lois"}, {"Thorpe, Trinity"},  {"Ruiz, Pedro" } };
	int ages[dim1] = { 62,84,18,42,15,35 };

	printf("This program will return following parallel\n");
	printf("arrays sorted by alphabetical order\n");
	for (int i = 0; i < dim1; i++)
		printf("%17s  -  %d\n", names[i], ages[i]);

	printf("Please push any button to sort alphabetically\n");
	getchar();

	for (int i = 0; i < dim1; i++)
	{
		char tempString[20] = { "" };
		char tempInt[1] = { 0 };
		int indexOfMin = findMinIndex(names, i);

		if (i != indexOfMin)
		{
		strcpy(tempString, names[i]);
		strcpy(names[i], names[indexOfMin]);
		strcpy(names[indexOfMin], tempString);

		tempInt[0] = ages[i];
		ages[i] = ages[indexOfMin];
		ages[indexOfMin] = tempInt[0];
		}
	}

	printf("Sorted parallel arrays:\n");
	for (int i = 0; i < dim1; i++)
		printf("%17s  -  %d\n", names[i], ages[i]);
	return 0;
}

int findMinIndex(char stringArray[dim1][dim2], int n)
{
	char minString[dim2];
	int minIndex = n;
	strcpy(minString, stringArray[n]);
	for (int i = n + 1; i < dim1; i++)
	{
		if (strcmp(minString, stringArray[i]) > 0)
		{
			strcpy(minString, stringArray[i]);
			minIndex = i;
		}
	}
	return minIndex;
}