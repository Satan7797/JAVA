/*Write a program to create a multilevel package and also creates a reusable class to generate
  Fibonacci series, where the function to generate Fibonacii series is given in a different file
  belonging to the same package.*/


/*Check the Packages first*/

/*-----------------------------------------------------------------------------*/
package program16.fibo;

public class fibonacciSeries {
	public static int fibonacci(int n) {
		if(n<=1)
			return 1;
		
		return fibonacci(n-1)+fibonacci(n-2);
	}
}



/*-----------------------------------------------------------------------------*/
package program16;

import java.util.Scanner;
import program16.fibo.fibonacciSeries;

public class fibonacciDemo {

	public static void main(String[] args){

		System.out.println("Enter n:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println("Fibonacci series of " + n + "terms:");

		for (int i = 0; i < n; i++)
			System.out.print(fibonacciSeries.fibonacci(i) + " ");

		in.close();
	}
}
