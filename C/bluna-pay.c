
// Written by Blake Luna 8.16.2013


#include <stdio.h>
#include <math.h>
#include <strings.h>

// Declared Constants

const float OVERRATE = 1.5;     // sets overtime payrate multiplier
const float THRESHOLD = 40;     // sets overtime threshold

// Declared Variables

FILE *outfile;          // declares ouput file
char again;             // used for count
char  department [11];  // department input
char  firstname [11];   // first name input
char  lastname [11];    // last name input
char  name [22];        // concoctanated input name
float payrate;          // payrate as input by user
float hours;            // hours as input by user
float reghours;         // regular hours worked
float overhours;        // overtime hours worked
float totpay;           // total pay for employee
float overpay;          // overtime pay rate
int count;              // accumulating employee count
float totreg;           // accumulating total of regular hours worked
float totover;          // accumulating total of overtime hours worked
float totregpay;        // accumulating total of regular pay
float totoverpay;       // accumulating total of overtime pay
float totwage;          // accumulating total wages paid
float tothours;         // accumlating total hours worked
float regpay;           // calculates regular pay for employeee
float overpayrate;      // calculates overtime pay rate for employee
float overpercent;      // calculates overtime percentage of total hours

// Function Prototypes

void header (void);
void process (void);
void summary (void);


//*************************************************
// M A I N   F U N C T I O N
//*************************************************

int main (void)
{
	
//opens output file

    outfile = fopen("c:\\class\\bluna-pay.txt","w");

// Initialize accumulating variables

    totreg = 0.00;
    totover = 0.00;
    totoverpay = 0.00;
    totregpay = 0.00;
    totwage = 0.00;
    tothours = 0.00;
    count = 1;

// Produce Report Header

	header();

// Produce Report Detail Lines

	process();

// Produce Report Summary

	summary();

// closes output file

    fclose(outfile);


    system("pause");
	return 0;

}

// *************************************************************
// Header - prints a header on the report
// *************************************************************

void header (void)
{

    printf("Mountain Pacific Corporation\n");
    printf("Department Salary Program\n\n");
    printf("Please enter the name of the department: ");
	scanf("%s", &department);
    printf("\n\n");

    fprintf(outfile, "Mountain Pacific Corporation\n");
    fprintf(outfile, "Department Salary Program\n\n");
    fprintf(outfile, "Department: %s\n\n", department);
    fprintf(outfile, "Employee                Reg Hrs         Overtime Hrs        Gross\n");
    fprintf(outfile, "-------------------------------------------------------------------\n");

}

// ****************************************************************
// Process - recieves user input and produces details of the report
// ****************************************************************

void process (void)
{

// retrieves interactive user input
   do {

      printf("Enter employee #%d:  " ,count);
      scanf("%s %s", &firstname, &lastname);
      
      strcpy(name, firstname);
      strcat(name, " ");
      strcat(name, lastname);
      printf("Enter the hourly wage of %s: ",&name);
      scanf("%f", &payrate);

      printf("Enter total number of hours: ");
      scanf("%f", &hours);
      
      printf("\n\n");
      
      printf("Thank you. Process another employee? ");
      scanf ("%s", &again);
      
      printf("\n\n");
      

// updates count
      count++;

// used to process overtime pay details

     if(hours > THRESHOLD){

        reghours = THRESHOLD; // sets regular hours to max
        regpay = payrate * THRESHOLD; // calculates regular pay for employee
        overhours = hours - THRESHOLD; // calculates overtime hours for employee
	    overpayrate = payrate * OVERRATE; // calculates overtime payrate for employee
	    overpay = overhours * overpayrate; //calculates overtime pay
        totpay = regpay + overpay; // calculates gross payment to employee
        totwage = totwage + totpay;  //updates total wages paid
        tothours = tothours + hours;   //updates total hours worked
        totover = totover + overhours;  // updates total over time hours
        totregpay = totregpay + (reghours * payrate); //updates total regular pay
        totoverpay = totoverpay + (overhours * overpayrate); //updates total overtime pay
        totreg = totreg + THRESHOLD; //updates total regular hours worked
	    
        
// Updates Report

	    fprintf(outfile,"%-17s%9.1f ($%5.2f)%8.1f ($%5.2f)     $%7.2f\n"
        ,name, reghours, payrate,overhours,overpayrate,totpay);

		
}
//used to process regular pay details

     else {

        overpayrate = payrate * OVERRATE; // calculates overtime payrate for employee
        overhours = 0; // sets overtime hours to zero
        regpay = payrate * hours; // calculates regular pay for employee
        overpay = 0; // sets overtime pay to zero
        totpay = regpay + overpay;    // calculates gross payment to employee
        totwage = totwage + totpay;  //updates total wages paid
        tothours = tothours + hours;   //updates total hours worked
        totregpay = totregpay + (hours * payrate); //updates total regular pay
        totreg = totreg + hours; //updates total regular hours worked
        
// Updates Report

        fprintf(outfile,"%-17s%9.1f ($%5.2f)%8.1f ($%5.2f)     $%7.2f\n"
        ,name, hours, payrate,overhours,overpayrate,totpay);
        
}
//sets input validation

} while (again=='Y' || again=='y');

}

// *************************************************************
// Summary - prints the report summary
// *************************************************************

void summary (void)
{

        overpercent = (totover / tothours) * 100;  // calculates overtime percentage
        
        printf("End of Processing\n\n");
        fprintf(outfile, "-------------------------------------------------------------------\n\n");
        fprintf(outfile, "Total Regular Hours Worked: %0.1f\n" , totreg);
        fprintf(outfile, "Total Overtime Hours Worked: %0.1f\n", totover);
        fprintf(outfile, "Percentage of Total Hours That Are Overtime: %.1f%%\n\n", overpercent);
        fprintf(outfile, "Total Regular Wages: $%0.2f\n", totregpay);
        fprintf(outfile, "Total Overtime Wages: $%0.2f\n\n", totoverpay);
        fprintf(outfile, "Total Wages This Period: $%0.2f\n", totwage);

}



