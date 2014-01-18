/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 2 - extend grades2.c by adding the calculation of the standard deviationand the median 
 *run like: "gcc -g -Wall ./Michael_Hug_cs3540_SPR2014_Assignment2.c -o Assignment2.out -lm && ./Assignment2.out"
 */
  
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/************************************************
 * preconditions: num_grades is not NULL 
 * postconditions: num_grades points to the number of grades in the array
 * return: non-NULL pointer to an array of grades
 * */
double* get_grades (int* num_grades);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: median of elements in array - 0 if array is empty 
 * */
double calc_median (double* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */
void display_median (int num_grades, double ave);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: average of elements in array - 0 if array is empty
 * */
double calc_standard_deviation (double* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */
void display_standard_deviation (int num_grades, double ave);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: average of elements in array - 0 if array is empty
 * */
double calc_ave (double* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */
void display_ave (int num_grades, double ave);

/*************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * postcondition : grades is sorted in ascending order
 * */
void insertion_sort (double* grades, int num_grades)

int main ()
{
	int num_grades = 0;
	double* grades = get_grades (&num_grades);
	double ave = calc_ave (grades, num_grades);
	display_ave (num_grades, ave); 
	double median = calc_median(grades, num_grades);
	display_median (num_grades, median);
	double standard_deviation = calc_standard_deviation(grades, num_grades);
	display_standard_deviation (num_grades, standard_deviation);
	return 0;
}

void insertion_sort (double* grades, int num_grades)
{
	assert (grades != NULL);
	assert (num_grades >= 0);
	int i,j,temp;
	for(i=1;i<num_grades;i++)
	{
		temp = grades[i];
		j=i-1;
		while(temp<grades[j] && j>=0)
		{
			grades[j+1] = grades[j];
			--j;
		}
		grades[j+1]=temp;
	}
}

void display_ave (int num_grades, double ave)
{
	assert (num_grades >= 0);
	if (num_grades == 0)
		printf ("no data\n");
	else
		printf ("average: %g\n", ave);
}

double calc_ave (double* grades, int num_grades)
{
	assert (grades != NULL);
	assert (num_grades >= 0);
	double ave = 0;
	if (num_grades > 0)
	{
		int sum = 0;
		int i = 0;
		for (i = 0; i < num_grades; i++)
			sum += grades[i];
		ave = (double)sum / num_grades;
	}
	return ave;
}

void display_standard_deviation (int num_grades, double standard_deviation)
{
	assert (num_grades >= 0);
	if (num_grades != 0)
		printf ("standard deviation: %g\n", standard_deviation);
}

double calc_standard_deviation (double* grades, int num_grades)
{
	assert (grades != NULL);
	assert (num_grades >= 0);
	double standard_deviation = 0;
	double mean = calc_ave(grades, num_grades);
	int i;
	for(i = 0; i<num_grades; i++)
	{
		standard_deviation+=(grades[i]-mean)*(grades[i]-mean);
	}
	standard_deviation/=num_grades;
	return standard_deviation;
}

void display_median (int num_grades, double median)
{
	assert (num_grades >= 0);
	if (num_grades != 0)
		printf ("median: %g\n", median);
}

double calc_median (double* grades, int num_grades)
{
	assert (grades != NULL);
	assert (num_grades >= 0);
	double median = 0;
	if (num_grades > 0)
	{
		insertion_sort(grades, num_grades);
		if(num_grades % 2==0)
			median = (grades[num_grades/2] + grades[num_grades/2-1]) / 2.0;
		else
			median = grades[num_grades/2];
	}
	return median;
}

double* get_grades (int* num_grades)
{
	assert (num_grades != NULL);
	*num_grades = 0;
	int size = 10;
	int* grades = malloc (size * sizeof (int));
	int grade;
	printf ("enter a grade: \n");
	scanf ("%d", &grade);
	while (grade >= 0)
	{
		if (*num_grades == size)
		{
			int* temp = malloc (2 * size * sizeof (int));
			int i;
			for (i = 0; i < size; i++)
				temp[i] = grades[i];
			free (grades);
			grades = temp;
			size *= 2;
		}
		grades[*num_grades] = grade;
		(*num_grades)++;
		printf ("enter a grade: \n");
		scanf ("%d", &grade);
	}
	assert (grades != NULL);
	assert (*num_grades >= 0);
	return grades; 
}
