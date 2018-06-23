package program13;

class staticDemo {
	static void func() {
		System.out.println("\n\nInside method func()...");
	}

	void test1() {
		System.out.println("\n\nInside method test()...");
	}
}

public class staticFunction {

	/**
	 * Here we need to define function fun() as static or else main() won't be able
	 * to access it. Also here we pass variable length arguments 
	 * @param a
	 */
	static void fun(int... a) {
		System.out.println("Number of arguments entered=" + a.length);

		for (int x : a)
			System.out.println(x);
	}

	public static void main(String[] args) {
		int[] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

		/*
		 * Here we are calling method fun() using different number of arguments
		 */
		fun(); // calling method fun() without argument
		fun(a); // passing array as argument
		fun(1, 2, 3, 4, 5, 6); // passing multiple integers

		/*
		 * Calling func() without using object This shows that we can use static method
		 * without creating an object of class
		 */
		staticDemo.func();

		staticDemo d = new staticDemo();
		/*
		 * Calling test() using object of class staticDemo
		 */
		d.test1();
	}

}
