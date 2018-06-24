/*To find the factorial of a given number.*/

package program2;

public class factorial {

	public static void main(String[] args) {
		int fac=1;
		int n=5;
		for(int i=1;i<=n;i++)
			fac*=i;
		System.out.println("Factorial of "+n+"is: "+fac);
	}

}
