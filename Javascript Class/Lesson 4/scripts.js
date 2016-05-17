//Scripts file for Lesson #4
          
function processSwitch() {
  var switchValue = document.getElementById("switchInput").value;
          
  // test for vaild input from 1 to 5
  if (switchValue <1 || switchValue >5) {
      alert ("Your number must be from 1 to 5");
      return;
    } //end validation
          
          switch (switchValue) {
            case "1": document.getElementById("twos").src = "images/one.gif";
                    break;
            case "2": document.getElementById("twos").src = "images/two.gif";
                    break;
            case "3": document.getElementById("twos").src = "images/three.gif";
                    break;
            case "4": document.getElementById("twos").src = "images/four.gif";
                    break;
            case "5": document.getElementById("twos").src = "images/five.gif";
                    break;
            default: alert("Sorry- your input is not valid");
                    // default in case a non numeric is entered
            }  //end switch (switchValue)

  } //end function processSwitch()
          
          
          
function processNumber() {
 var numberInput = document.getElementById("userInput").value;
  
  // test for vaild input from 1 to 5
  if (numberInput <1 || numberInput >5) {
      alert ("Your number must be from 1 to 5");
      return;
    } //end validation
          
          if (numberInput == 1)
              document.getElementById("ones").src = "images/one.gif";
              else if (numberInput == 2)
                document.getElementById("ones").src = "images/two.gif";
                else if (numberInput == 3)
                  document.getElementById("ones").src = "images/three.gif";
                  else if (numberInput == 4)
                    document.getElementById("ones").src = "images/four.gif";
                    else if (numberInput == 5)
                      document.getElementById("ones").src = "images/five.gif";
                      else alert("Sorry-your input is not vaild");
                          // likely a non numeric was entered if this triggers
  
  } // end function processNumber()
        
        
