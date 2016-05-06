//Written by Blake Luna
//08.02.13

#include <math.h>
#include <stdio.h>

// Variable declarations

FILE *datafile;            // Input File
FILE *reportfile;          // Report File
char  type[8];             // Input Transaction Type
float amount;              // Transaction Amount
float total;               // Monthly Total
float dsplyamount;         // Total Reported (always positive)
int count;                 // Number of Transactions

// Function Prototypes

void header (void);
void process (void);
void summary (void);

//*************************************************
//*************************************************
// M A I N   F U N C T I O N
//*************************************************
//*************************************************

int main (void)
{
	datafile = fopen("c:\\class\\ie.txt","r");   // Opens Input File

// Initialize accumulating variables

	count = 0;
	total = 0.00;

// Produces Report

	header();
	process();
	summary();

	fclose(datafile);  //Closes Input File

   system("pause");
	return 0;

}

// *************************************************************
// Header - prints a header on the report
// *************************************************************

void header (void)
{
	reportfile = fopen("c:\\class\\bluna_ie.txt","w");
	fprintf(reportfile, "The MoneyMaking Corporation\n");
	fprintf(reportfile, "550 Warm Sands Drive\n");
    fprintf(reportfile, "Palm Springs, CA 92262\n");
    fprintf(reportfile, "\n");
	fprintf(reportfile, "Type            Amount               Net\n");
	fprintf(reportfile, "----            ------               ---\n");
    fclose(reportfile);

}

// *************************************************************
// Process - produces the detail lines of the report
// *************************************************************

void process (void)
{

//Retrieves Information

    while(!feof(datafile))
	{
		fgets(type, 8, datafile);
		fscanf(datafile,"%f\n",&amount);

//Calculations

		dsplyamount = fabs(amount);
        total= total + amount;

//Output to File

        reportfile = fopen("c:\\class\\bluna_ie.txt","a");

		fprintf( reportfile,"%s%15.2f%18.2f\n",type, dsplyamount, total);

        fclose(reportfile);

// Updates Count

		count++;
        
    }
	
}

// *************************************************************
// Summary - prints the report summary (including accumulators)
// *************************************************************

void summary (void)
{
    reportfile = fopen("c:\\class\\bluna_ie.txt","a");
    fprintf(reportfile, "\n");
	fprintf(reportfile, "The net total for the month is $%0.2f\n", total);
	fprintf(reportfile, "Transactions processed: %d \n\n", count);
    fclose(reportfile);

}


