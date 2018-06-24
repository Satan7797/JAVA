/*Write a program “DivideByZero” that takes two numbers a and b as input, computes a/b, and
  Invokes Arithmetic Exception to generate a message when the denominator is zero.*/

package program18;

import java.util.Scanner;

public class DivideByZero {

	public static void main(String[] args) {
		int a, b;

		Scanner in = new Scanner(System.in);

		System.out.println("Enter a and b:");
		a = in.nextInt(); // to take input of the numerator
		b = in.nextInt(); // to take input of the denominator

		in.close();      
      try {


			double c = a / b; // to calculate result
			/*
			 * if the value above expression create an exception then it will throw it to
			 * the catch statement
			 */

			System.out.println("Result is " + c);

		}
		/*
		 * Here if the denominator is zero then the following statement will catch the
		 * AirthmeticException and print the message
		 */
		catch (ArithmeticException e) {
			System.out.println("Cannot divide by zero");
		}
	}

}
