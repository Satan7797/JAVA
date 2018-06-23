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
