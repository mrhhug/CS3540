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

int* get_grades (int* num_grades);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: average of elements in array - 0 if array is empty
 * */

double calc_ave (int* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */

void display_ave (int num_grades, double ave);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: average of elements in array - 0 if array is empty
 * */

double calc_standard_deviation (int* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */

void display_standard_deviation (int num_grades, double ave);

/**********************************************************
 * precondition: grades is not NULL & num_grades >= 0
 * return: median of elements in array - nothing if array is empty 
 * The no data printf is handled by ave, seems redundant to print again 
 * */

double calc_median (int* grades, int num_grades);

/*************************************************
 * precondition: num_grades >= 0
 * */

void display_median (int num_grades, double ave);

int main ()
{
  int num_grades = 0;
  int* grades = get_grades (&num_grades);
  double ave = calc_ave (grades, num_grades);
  display_ave (num_grades, ave); 
  double median = calc_median(grades, num_grades);
  display_median (num_grades, median);
  double standard_deviation = calc_standard_deviation(grades, num_grades);
  display_standard_deviation (num_grades, standard_deviation);
  return 0;
}

void insertion_sort (int* grades, int num_grades)
{
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
    printf ("average: %f\n", ave);
}

double calc_ave (int* grades, int num_grades)
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
    printf ("standard deviation: %f\n", standard_deviation);
}

double calc_standard_deviation (int* grades, int num_grades)
{
  assert (grades != NULL);
  assert (num_grades >= 0);
  double standard_deviation, mean = calc_ave(grades, num_grades);
  int i;
  for(i = 0; i<num_grades; i++)
  {
    grades[i]=(grades[i]-mean);
    printf("%d\n",grades[i]); 
  }
    standard_deviation = (calc_ave(grades, num_grades)); 
  return standard_deviation;
}

void display_median (int num_grades, double median)
{
  assert (num_grades >= 0);
  if (num_grades != 0)
    printf ("median: %f\n", median);
}

double calc_median (int* grades, int num_grades)
{
  assert (grades != NULL);
  assert (num_grades >= 0);
  insertion_sort(grades, num_grades);
  double median;
  if (num_grades > 0)
  {
    if(num_grades % 2==0)
      median = (grades[num_grades/2] + grades[num_grades/2-1]) / 2.0;
    else
      median = grades[num_grades/2];
  }
  return median;
}

int* get_grades (int* num_grades)
{
  /*
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
  */
	int* grades = malloc (8 * sizeof (int));
  grades[0]=45;
  grades[1]=19;
  grades[2]=10;
  grades[3]=99;
  grades[4]=1;
  grades[5]=3;
  grades[6]=4;
  grades[7]=5;
  *num_grades=8;
  return grades; 
}
