#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"sort.h"
#include<math.h>
#include<stdio.h>
/*
 * function to convert a given str into a given int array
 * @param int pointer is the postion in the int array the str will be stored in.
 * @param *str is the given string that will be converted into an integer
 * @param arr[] is the array the converted integers will be saved int to used for the sorting algorithem.
 */
int argparse_intArray(const char *str, int pointer , int arr[]){
	char *end;
	arr[pointer] = strtol(str, &end, 10);
	return 0;

}
/*
 * function to print an sorted array from last to frist element.
 */
int reverse(int arr[], int endarr){
	for(int i = endarr; i > 0;i--){
		printf("%i ", arr[i]);
	}
	printf("\n");
	return 0;
}
/*
 * function to print the contents of an array line by line
 */
int prntaln(int arr[], int length){
	for(int i=1; i < length; i++){
		printf("%i \n", arr[i]);
	}
	return 0;
}

/*
 * function to sort an integer array from smallest to greatest.
 * the function uses the selctionsort algorithem
 * for-loop i is for the sorted part of the array.
 * for-loop j is for the unsorted part of the array.
 */
int sort(int arr[], int length){
	int temp[length];
	for(int i = 0; i < length-1;i++){
		for(int j = i + 1; j < length; j++){
			if(arr[i] > arr[j]){
				temp[i]=arr[i];
				arr[i]=arr[j];
				arr[j]=temp[i];
			}
		}
	}
	return 1;

}
