
  //Code Written by Blake Luna


#include <stdio.h>
#include <math.h>

//Constant Definitions
#define YEARS      3        /*used to calculate average*/
#define COMPANYLENGTH  31   /*company name from input file*/



// Variable Declrations
FILE *reportfile;              /* report file (for output) */
FILE *inputfile;               /* disk file (for input)    */
char company[COMPANYLENGTH];   /* sets length for company name*/
float  asset_fy1;              /* Assets Fiscal Year 1 */
float  debt_fy1;               /* Debts Fiscal Year 1*/
float  asset_fy2;              /* Assets Fiscal Year 2 */
float  debt_fy2;               /* Debts Fiscal Year 2*/
float  asset_fy3;              /* Assets Fiscal Year 3 */
float  debt_fy3;               /* Debts Fiscal Year 3*/
float  asset_average;          /* Asset 3 Year Average*/
float  debt_average;           /* Debt 3 Year Average*/
float  ratio_average;          /* Ratio 3 Year Average*/
float  ratio_fy1;              /* Ratio Fiscal Year 1*/
float  ratio_fy2;              /* Ratio Fiscal Year 2*/
float  ratio_fy3;              /* Ratio Fiscal Year 3*/


void GetInfo(void);        // Prototype for GetInfo function
void DoCalcs(void);        // Prototype for DoCalcs function
void Report(void);         // Prototype for Report function


//*****************************************************************************
//****************************************************************************
//    M A I N   F U N C T I O N
//****************************************************************************
//****************************************************************************

int main(void)
{

	printf("**Current Ratio Program**\n\n");

	GetInfo();              // Retrieves input information
	DoCalcs();              // Calculates averages and ratios
	Report();               // Display the final report

    system("pause");

    return 0;

}

//****************************************************************************
// The GetInfo functions retrieves input information from specified file destination
//****************************************************************************

	
void GetInfo(void)
{
		/* Get information from disk file  */

	inputfile = fopen("c:\\class\\current.txt","r");
    fgets  (company,COMPANYLENGTH,inputfile);
    fscanf (inputfile,"%f %f %f %f %f %f",&asset_fy1,&debt_fy1,&asset_fy2,&debt_fy2,&asset_fy3,&debt_fy3);
    fclose (inputfile);
    
}


//****************************************************************************
// The DoCalcs function calculates the averages and yearly ratios, based on the
// amount read in during GetInfo.
//****************************************************************************

void DoCalcs(void)
{

  // Calculate Yearly Ratios

	ratio_fy1 = asset_fy1 / debt_fy1;
	ratio_fy2 = asset_fy2 / debt_fy2;
	ratio_fy3 = asset_fy3 / debt_fy3;
	
  // Calculate Averages

    asset_average = (asset_fy1 + asset_fy2 + asset_fy3) / YEARS;
	debt_average = (debt_fy1 + debt_fy2 + debt_fy3) / YEARS;
	ratio_average = (ratio_fy1 + ratio_fy2 + ratio_fy3) / YEARS;

}


//****************************************************************************
// The Report function exports information summarizing the calculations
// performed in the DoCalcs function.
//****************************************************************************

void Report(void)
{

    reportfile = fopen("c:\\class\\bluna_cr.txt","w");   // This opens and creates the file


	fprintf(reportfile,"\n");
	fprintf(reportfile,"%s", company);                // Inserts company name
	fprintf(reportfile,"Current Ratio Report\n\n");
	fprintf(reportfile,"                Current                Current                Current\n");
	fprintf(reportfile,"Year            Assets                 Liabilities            Ratio\n");
	fprintf(reportfile,"---------------------------------------------------------------------\n");
	fprintf(reportfile,"2005           %8.0f               %8.0f                 %6.2f\n", asset_fy1, debt_fy1, ratio_fy1);   //2005 Fiscal Information
    fprintf(reportfile,"2006           %8.0f               %8.0f                 %6.2f\n", asset_fy2, debt_fy2, ratio_fy2);   //2006 Fiscal Information
    fprintf(reportfile,"2007           %8.0f               %8.0f                 %6.2f\n", asset_fy3, debt_fy3, ratio_fy3);   //2007 Fiscal Information
    fprintf(reportfile,"---------------------------------------------------------------------\n");
    fprintf(reportfile,"Average        %8.0f               %8.0f                 %6.2f\n", asset_average, debt_average, ratio_average);  //Averages Displayed
    fprintf(reportfile,"\n");
	fprintf(reportfile,"This report produced by Blake Luna\n");    //Produced by line
	


    fclose(reportfile);    // Closes the report file

}

	
	
	
