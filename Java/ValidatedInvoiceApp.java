import java.text.NumberFormat;
import java.util.*;

public class ValidatedInvoiceApp
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String choice = "y";
        
        while (!choice.equalsIgnoreCase("n"))
            {
                String customerType = getValidCustomerType (sc);
    
                double subtotal = 0.0 ;
                try
                     {
                        subtotal = getValidSubtotal (sc);
                     } 
                catch (InputMismatchException e)
                     {
                        sc.next();
                        System.out.println("Error! Invalid number. Try Again");
                        continue;
                     } 
        	// get the discount percent
        	double discountPercent = 0;
        	if (customerType.equalsIgnoreCase("R"))
        	{
        	    if (subtotal < 100)
        	        discountPercent = 0;
        	    else if (subtotal >= 100 && subtotal < 250)
        	        discountPercent = .1;
        	    else if (subtotal >= 250)
        	        discountPercent = .2;
        	}
        	else if (customerType.equalsIgnoreCase("C"))
        	{
        	    if (subtotal < 250)
        	        discountPercent = .2;
        	    else
        	        discountPercent = .3;
        	}
        	else
        		discountPercent = .1;

        	// calculate the discount amount and total
        	double discountAmount = subtotal * discountPercent;
        	double total = subtotal - discountAmount;

        	// format and display the results
        	NumberFormat currency = NumberFormat.getCurrencyInstance();
        	NumberFormat percent = NumberFormat.getPercentInstance();
        	System.out.println(
        	    "Discount percent: " + percent.format(discountPercent) + "\n" +
        	    "Discount amount:  " + currency.format(discountAmount) + "\n" +
        	    "Total:            " + currency.format(total) + "\n");

        	// see if the user wants to continue
			System.out.print("Continue? (y/n): ");
			choice = sc.nextLine();
            System.out.println();
		}
    }


    
public static String getValidCustomerType (Scanner sc )
{ 
    String customerType = "" ;
    boolean isValid = false;     
    while (isValid == false) 
    {
        System.out.print("Enter customer type (r/c): ");
        customerType = sc.next();
        
        	if (customerType.equalsIgnoreCase ("R"))
                { 
                  isValid = true;
                }
                else if (customerType.equalsIgnoreCase ("C"))
                {                
                   isValid = true; 
                }
                else 
                {
                    System.out.println("Error Invalid Customer Type. Try Again.\n");  
                }
              sc.nextLine(); 
    }
    return customerType;
}


public static Double getValidSubtotal (Scanner sc)
{
        double subtotal = 0.0 ;
        boolean isValid = false;
        while (isValid == false)
    {   
        System.out.print("Enter Subtotal: ");
        if (sc. hasNextDouble())  
        { 
            subtotal = sc.nextDouble();  
            isValid = true;
        }
        else 
        {
            System.out.println("Error! Invalid Number. Try Again.");
        }
        sc.nextLine();
        
        if (isValid == true && subtotal <= 0)
        {
            System.out.println("Error! Number must be greater than 0.");
            isValid = false;
        }
        else if (isValid == true && subtotal >= 1000)
        {
            System.out.println("Error! Number must be less than 1000");
            isValid = false;
        }
    }
        return subtotal;
} 
}


                