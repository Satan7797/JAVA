/*Create a multi-file program where in one file a 
  string message is taken as input from the user
  and the function to display the message on the 
  screen is given in another file (make use of
  Scanner package in this program).*/

package program15;

import java.util.Scanner;
public class inputFile{
   public static void main(String[] args){
      Scanner in=new Scanner(System.in);
      display.p("Enter string message:");
      String msg=in.nextLine();
      display.p(msg);
      in.close();
   }
}
/*----------------------------------------------*/
package program15;

public class display{
   public static void p(String msg){
      System.out.println(msg);
   }
}