


#include <stdio.h>
#include <math.h>

//Constant Declarations

const float YEARONE = 40;  /* Drachmas per US dollar YearOne*/
const float YEARTWO = 35;  /* Drachmas per US Dollar YearTwo*/

// Variable Declarations

float amount;         /* amount entered by user       */
float totalone;       /* year one monetary conversion */
float totaltwo;       /* year two monetary conversion */
float change;         /* year over year difference    */

FILE *diskfile;

//Main Function

main ()
{
                  /* Prompt User for information */

    printf("***Drachma Converstion Program***\n\n");

    printf("How many drachmas do you have in your savings account? ", amount);
    scanf("%f", &amount);
    
    printf("\n");
    
    printf( "The conversion information for %.0f drachmas is now being recorded. \n\n",amount);
  
                 /* Calculations for Monetary Conversion */
                 
    totalone = amount / YEARONE;
    totaltwo = amount / YEARTWO;
    change = fabs(totalone - totaltwo);

                /* Opens File Location for Output Results */
                
    diskfile = fopen ("c:\\class\\bluna-dc.txt","w");
    

                /* Conversion and Output Information to be sent to disk */
                
    fprintf(diskfile,"For %.0f drachmas:\n", amount);
    fprintf(diskfile,"At the rate of %.0f drachmas per U.S. dollar,\n", YEARONE);
    fprintf(diskfile,"   you have %0.2f U.S. dollars.\n", totalone);
    fprintf(diskfile,"At the rate of %.0f drachmas per U.S. dollar,\n", YEARTWO);
    fprintf(diskfile,"   you have %0.2f U.S. dollars.\n\n", totaltwo);
    
                /* Calculates difference year over year */
    
    fprintf(diskfile,"The difference is %0.2f U.S. dollars. \n\n", change);


    fclose(diskfile);        /*Closes Diskfile*/

    system ("pause");        /* Inserts "Press Any Key" Pause*/
    return 0;
    
    
}
