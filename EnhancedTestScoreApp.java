import java.util.Scanner;
import java.lang.Math;

public class EnhancedTestScoreApp
{
    public static void main(String[] args)
    {
        
        String choice = "y";
        while (!choice.equalsIgnoreCase("n"))
        {
        //Creates a scanner object
        Scanner sc = new Scanner(System.in);
        
        //prompts user input and assigns the value to entryCount
        System.out.println("Enter number of test scores to be entered: ");
        int entryCount = sc.nextInt();
        System.out.println();  
          
        // initialize variables 
        int scoreTotal = 0;
        int testScore = 0;
        int scoreNumber = 1;
        int scoreCount = 0;
        int maxScore = 0;
        int minScore = 0;
        int maxScoreFinal = 0;
        int minScoreFinal = 100;
        
        
        for (int c =0; c<entryCount; c++)               //controls number of scores to be input
         {      
               System.out.print("Enter Score "+scoreNumber+":  ");   //retrieve score from user
               testScore = sc.nextInt()  ;                           //places score in testScore variable 
                      
                      if (testScore <= 100)    
        	             {
                        maxScore = Math.max (testScore,maxScoreFinal);      //compare max score
			minScore = Math.min (testScore,minScoreFinal);      //compare min score
        		maxScoreFinal = maxScore;                           //set max score for display
        		minScoreFinal = minScore;                           //set min score for display
        		scoreCount += 1;                                    //increase score count
        		scoreTotal += testScore;                            //add testScore to scoreTotal 
                        scoreNumber ++;                                     //increase scoreNumber
                              }  
		      if (testScore >100)    //display error message
                      {      	
                        System.out.println("Invalid Entry, not counted");
                        c--;
                      }                                
         }
	
    	// display the score count, score total, average, min, and max
    	double averageScore = scoreTotal / scoreCount;
    	String message = "\n" +
    	                 "Score count:   " + scoreCount + "\n"
    	               + "Score total:   " + scoreTotal + "\n"
		               + "Average score: " + averageScore + "\n"
		               + "Min score:     " + minScoreFinal+ "\n"
		               + "Max score:     " + maxScoreFinal+ "\n";
		System.out.println(message);
                
                
           //prompt user to continue
            System.out.print("Enter more test scores? (y/n): ");
            choice = sc.next();
            System.out.println();
        
        
        }
	}
    }
