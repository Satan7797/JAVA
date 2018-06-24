/*To check if a number is prime or not, by taking the number as 
  input from the keyboard*/

package program6;
import java.util.Scanner;

public class Prime {
    public static void main(String[] args){
        Scanner r=new Scanner(System.in);
        System.out.print("Enter a number:");
        int n=r.nextInt();
        int check=0;
        for(int i=2;i<n/2;i++)
        {
            if(n%i==0)
            {
                check=1;
                break;
            }
        }
        
        if(check==0)
            System.out.print("Number entered is prime");
        else
            System.out.print("Entered number is not prime");
        r.close();
    }
}
