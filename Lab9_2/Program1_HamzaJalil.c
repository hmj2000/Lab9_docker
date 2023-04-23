#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

float  *read_data_from(char *file_name) // Reads in file
    {
        float *sales = (float*)malloc(sizeof(float) * MONTHS);
        FILE *fp = fopen(file_name, "r*");

        for(int i = 0; i < MONTHS; ++i)
            {
                fscanf(fp, "%f\n", &sales[i]);
            }
        
        return sales;
    }


void monthly_sales_report(char *months[], float sales[]) // Monthly Sales Report - Prints the months and their respective sales data given from file
    {
        printf("\nMonthly Report for 2023:\n\n"); // Prints out title
        printf("Month \t\t\t Sales\n"); // Prints out Month and Sales subheading

        for(int i = 0; i < 2; ++i) // For loop prints out the first two months and sales numbers to ensure formating matches required results
            {
                printf("%s \t\t $%.2f\n", months[i], sales[i]);
            }
        for(int i = 2; i < 8; ++i)  // For loop prints out the next six months to ensure formating matches required results
            {
                printf("%s \t\t\t $%.2f\n", months[i], sales[i]);
            } 
        for(int i = 8; i < MONTHS; ++i)  // For loop prints out the last four months to ensure formating matches required results
            {
                printf("%s \t\t $%.2f\n", months[i], sales[i]);
            }
    }

float return_max_sales(char *months[], float sales[], float *max_sales) // Returns max sales - Takes in months, sales, and max sales value to return max sales value and print max sales value and month
    {
        float max = 0; // Initialise a variable to set as a max so we set max as 0 since we know the largest value must be 0or greater in this example
        char *month_max; // Initialise a variable to set as max sales month
        float temp = 0; // Initialise a variable to use as a temp
    
        for(int i = 0; i < MONTHS; ++i) // For loop that reads the sales data and sets it to a temp. Then the temp is compared to the max value and if the temp is the larger value then we reassign max to temp and update the month with the highest sale
            {
                temp = sales[i];
                if (temp > max)
                {
                    max = temp;
                    month_max = months[i];
                }
            }
        printf("Maximum sales: $%.2f \t", max); // Prints the maximum sales
        printf("(%s) \n", month_max); // Prints the Month the maximum sales occured
        *max_sales = max; // Reassigns the max value to the varriable passed in and to be returned
    }

void return_min_sales(char *months[], float sales[], float *max_sales) // Returns min sales - takes in months, sales, and max sales to return min sales month and value
    {
        float min = *max_sales; // Initialise a variable t oset as a min so we set min to max since we know the largest value must be the highest bound
        char *month_min; // Initialise a variable to set as min sales month
        float temp = 0; // Initialise a variable to use as temp
    
        for(int i = 0; i < MONTHS; ++i) // For loop that reads the sales data and sets it to a temp. Then the temp is compared to the min value and if the temp is the smaller value then we reassign min to temp and update the month with the lowest sale
            {
                temp = sales[i];
                if (temp < min)
                {
                    min = temp;
                    month_min = months[i];
                }
            }
        printf("Minimum sales: $%.2f \t", min); // Prints the Minuimum sales
        printf("(%s) \n", month_min); // Prints the Month the minimum sales occured
    }

void return_avg_sales(float sales[]) // Return average sales - Takes in sales data and sums it all up and divided by number of sales datat
    {
        float temp = 0; // Initialise a variable to be used as a temp
        float avg = 0; // Initialise a variable to represent as average
    
        for(int i = 0; i < MONTHS; ++i) // For loop that sums all the sales data
            {
                temp = sales[i];
                avg = avg + temp;
            }
    
        avg = avg / 12; // Takes the sales data and divded by number of monhts (a.k.a number of sales data points)
        printf("Average sales: $%.2f \n", avg); // Prints the average sales
    }

void sales_summary(char *months[], float sales[]) //Sales Summary
    {
        printf("\nSales Summary:\n\n"); // Prints sales summmary title 
        float max_sales; // Type float variable for maximum sales amount
        return_max_sales(months, sales, &max_sales); // Calls the max function
        return_min_sales(months, sales, &max_sales); // Calls the min function
        return_avg_sales(sales); // Type float variable for average sales amount
    }

float six_month_moving_average (int start_month, int end_month, float sales[])// sinx month moving average - takes in the start month, end mont, and sales data to spit out the average during that time period
    {
        float avg = 0; // Initialise a variable to repsresent the average
        float temp = 0; // Initialise a variable to use as temperary

        for(int i = start_month - 1; i < end_month; ++i) // For loop to read and sum the sales data during the required months
            {
                temp = sales[i]; // Sets the temp as a value from sales data at a particular index
                avg = avg + temp; // adds the value of temp to the average
            }
        
        avg = avg / (6); // divids the sum by six to make it a six month average
        return avg; // returns the average 
    }

void six_month_moving_average_report(float sales[]) //Six Month Moving Average Report
    {
        printf("\nSix Month Moving Average Report:\n\n"); // Prints out the title for six month moving average 
        float moving_average_1; // Type float variable for sales amount for Janurary to June
        moving_average_1 = six_month_moving_average (1, 6, sales); // sets value for moving_average_1
        float moving_average_2; // Type float variable for sales amount for February to July
        moving_average_2 = six_month_moving_average (2, 7, sales); // sets value for moving_average_2
        float moving_average_3; // Type float variable for sales amount for March to August
        moving_average_3 = six_month_moving_average (3, 8, sales); // sets value for moving_average_3
        float moving_average_4; // Type float variable for sales amount for April to September
        moving_average_4 = six_month_moving_average (4, 9, sales); // sets value for moving_average_4
        float moving_average_5; // Type float variable for sales amount for May to October
        moving_average_5 = six_month_moving_average (5, 10, sales); // sets value for moving_average_5
        float moving_average_6; // Type float variable for sales amount for June to November
        moving_average_6 = six_month_moving_average (6, 11, sales); // sets value for moving_average_6
        float moving_average_7; // Type float variable for sales amount for July to December
        moving_average_7 = six_month_moving_average (7, 12, sales); // sets value for moving_average_7
    
         // Prints the data as per format requirments

        printf(" Janurary \t  - June: \t\t\t $%.2f \n", moving_average_1);
        printf(" February \t  - July: \t\t\t $%.2f \n", moving_average_2);
        printf(" March \t\t  - August: \t\t $%.2f \n", moving_average_3);
        printf(" April \t\t  - September: \t\t $%.2f \n", moving_average_4);
        printf(" May \t\t  - October: \t\t $%.2f \n", moving_average_5);
        printf(" June \t\t  - November: \t\t $%.2f \n", moving_average_6);
        printf(" July \t\t  - December: \t\t $%.2f \n", moving_average_7);
    }

void sales_report(char *months[], float sales[]) //Sales Report (Highest to Lowest) - takes in montgs and sales data
    {
        float temp_sales[12]; // Initialise a variable to be a temp sales data that will be manipulated to be in high to low
        float temp1; // Initialise a variable to be a temp for sales data 
        char *temp_months[12]; // Initialise a variable to be a temp month data that will be manipulated to be in order, respectivly, with sales data
        char *temp2; // Initialise a variable to be temp for month data
        
        for(int i = 0; i < MONTHS; ++i) // Set temp month data
            {
                temp_months[i] = months[i];
            }

        for(int i = 0; i < MONTHS; ++i) // Set temp sales data 
            {
                temp_sales[i] = sales[i];
            }

        for(int i = 0; i < MONTHS; i++) // Compare the temp sales data and order it with month data
            {
                for(int j = i + 1; j < MONTHS; j++)
                {
                    if(temp_sales[i] < temp_sales[j]) // If the data at position I is smaller than J then move it down to J and coordinate that with the month array
                        {
                            temp1 = temp_sales[i];
                            temp_sales[i] = temp_sales[j];
                            temp_sales[j] = temp1;

                            temp2 = temp_months[i];
                            temp_months[i] = temp_months[j];
                            temp_months[j] = temp2;
                        }
                }
            }

        printf("\nSales Report (Highest to Lowest):\n\n"); // Print sales report title 
        printf("Month \t\t\t Sales\n"); // Print month and sales subheading
        for(int i = 0; i < MONTHS; ++i) // Print the data as per the format required
            {   
                if (temp_months[i] == "July" || temp_months[i] == "June" || temp_months[i] == "August" || temp_months[i] == "March" || temp_months[i] == "May" || temp_months[i] == "April")
                    {
                        printf("%s \t\t\t $%.2f\n", temp_months[i], temp_sales[i]);
                    }
                else
                    {
                        printf("%s \t\t $%.2f\n", temp_months[i], temp_sales[i]); 
                    }           
            }
    }

int main()
    {
        char file_name[30];
        //printf("What is the input file: \n");
        //scanf("%s", file_name); // For some reason my scan function was not working so I used a direct file name

        float *sales = read_data_from("Sales.txt");
        char *months[] = {"January", "February", "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"}; // Initialise an array to store Months

        monthly_sales_report(months, sales);
        sales_summary(months, sales);
        six_month_moving_average_report(sales);
        sales_report(months, sales);
        return 0;
    }

