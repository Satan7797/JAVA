/*To find the sum of any number of integers interactively, i.e., entering every number 
  from the Keyboard, whereas the total number of integers is given as a command line argument*/

package program7;

public class sumOfNumbers{
   public static void main(String[] args){
      int n=Integer.parseInt(args[0]);
      int sum=0;
      
      for(int i=1;i<=n;i++)
         sum+=Integer.parseInt(args[i]);
      
      System.out.println("Sum is: "+sum);
   }
}