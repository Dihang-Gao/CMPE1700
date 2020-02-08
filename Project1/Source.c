// Dihang Gao 1700 Lab1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(int argc, char** argv) {

	//creat a new array which include 16 chars
	//record the numbers of bits
	//use sum to calculate how many numbers
	//calculate the average by runs/numbers
	char array[16];	
	int iNumbera;
	int total = 0;
	int sum = 0 ;
	int sumnum;
	double average;
	iNumbera = atoi(argv[1]);
	sumnum = pow(2, iNumbera);
	//if emtered a value not in the Range show Error;
		if (iNumbera < 0 || iNumbera >16)
		{
			printf("You should enter a value from 0-16");
		}
		else
		{	//i2 is the number to use to calculate Runs
			for (int i2 = 0; i2 < sumnum; i2++)
			{
				printf("\n");
				//use short to create a mask 1000 0000 0000 0000
				unsigned short mask = 0x8000;

				//use mask to write down the unsigned number of the value i2
				for (int i = 0; i < 16; i++)
				{					
					array[i] = ((i2 & mask) ? 1 : 0);
					mask >>= 1;
					//write down the value and the value saved in array
					printf("%d", array[i]);
				}

				if (array[0] == 1 )
				{
					//when the first array is 0; total run of this num +1;
					total++;
				}

				for (int i1 =0 ; i1 < 16; i1++)
				{
					//for every next bit - last bit = 1 should add a run like 101 has 2 run;
					if (array[i1+1] - array[i1 ] == 1)
					{
						total += 1;
					}
				}
				//add all the sum of runs;
				sum += total;
				
			}
			//average is total runs / total numbers
			average = (double)total / (double)sumnum;
			// print total runs
			printf("\nsum of run is %d", total);
			// print average
			printf("\nAverage is : %8.1f", average);
		}

	

}
