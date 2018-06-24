/*Write a program to show the difference between public and private access specifiers. The
  program should also show that primitive data types are passed by value and objects are passed
  by reference and to learn use of final keyword*/

package program12;

class specifiers {
	int c, d;

	/**
	 * Here we define this function using 'private' access specifier. So now we
	 * cannot access this function outside the class
	 * 
	 * @param a
	 * @param b
	 */
	private void test(int a, int b) {
		System.out.println("\n\nInside the function test()...");
		System.out.println("Swapping values of a and b...");

		int temp = a;
		a = b;
		b = temp;

		System.out.println("Values of a and b:\na=" + a + "\nb=" + b);

		System.out.println("Exiting the function test()...");
	}

	/**
	 * Here we defined this function as 'public' and thus we can call this function
	 * outside the class
	 * 
	 * @param s
	 * @param a
	 * @param b
	 */
	void test1(specifiers s, int a, int b) {
		test(a, b);

		System.out.println("\n\nInside function test1()...");
		System.out.println("Assigning new values to c and d...");
		s.c = 12;
		s.d = 13;

		System.out.println("Values of c and d:\nc=" + s.c + "\nd=" + s.d);

		System.out.println("Exiting function test1()...");
	}

	/**
	 * After defining variable e=12, we cannot change its value. Same is the case
	 * with functions. After defining a function with final keyword, we can't
	 * Override it.
	 */
	final int e = 12;
}

public class AccessSpecifiers {
	public static void main(String[] args) {

		int a, b;

		a = 234;
		b = 300;

		System.out.println("Values before passing...\na=" + a + "\nb=" + b);
		specifiers s = new specifiers();

		System.out.println(
				"Values of c and d of class before passing the object in function...\nc=" + s.c + "\nd=" + s.d);
		s.test1(s, a, b);
		System.out
				.println("Values in main()...\na=" + a + "\nb=" + b + "\n\nInside Object...\nc=" + s.c + "\nd=" + s.d);

		System.out.println(
				"\nValue of a and b are same but value of c and d are different. This shows that primitive datatypes are passed by value "
						+ "and objects are passed by referance.");
	}
}
