/*Write a program that show working of different functions of String and StringBufferclasss like
  setCharAt(, setLength(), append(), insert(), concat()and equals().*/

package program8;

public class stringAndStringBuffer {

    public static void main(String[] args) {
        System.out.println("Use of StringBuffer:");

        StringBuffer s = new StringBuffer("Hello");

        int len = s.length();

        System.out.println("Length of string " + s + " is " + len);

        System.out.println("Setting char 'A' at index 4 in string s...");
        s.setCharAt(4, 'A');
        System.out.println("String is " + s);

        System.out.println("Initializing second String s1...");
        StringBuffer s1 = new StringBuffer("World");

        System.out.println("Append s and s1...");
        s.append(s1);
        System.out.println("String is " + s);

        System.out.println("Setting length of s to original...");
        s.setLength(len);
        System.out.println("String s " + s);

        System.out.println("Inserting char 'B' at index 3 in string s1...");
        s1.insert(3, 'B');
        System.out.println("String s1 after changes:" + s1);

        System.out.println("Checking if s and s1 are equal...");
        if (s.equals(s1)) {
            System.out.println("String s = s1");
        } else {
            System.out.println("String s!=s1");
        }

        System.out.println("Use of String:");

        String str = "Hello";
        System.out.println("String is " + str);

        int l = str.length();
        System.out.println("Length of string is " + l);

        System.out.println("Converting all characters to uppercase...");
        str = str.toUpperCase();
        System.out.println("String str after changes:" + str);

        System.out.println("Initializing second string of String class...");
        String str1 = "World";
        System.out.println(str1);

        System.out.println("Concatenating strings str and str1...");
        String str2 = str + str1;
        System.out.println("New string is " + str2);

        System.out.println("Character at index 2 in String str...");
        char a = str.charAt(2);
        System.out.println(a);

        System.out.println("Checking if String str and str1 are equal or not...");
        if (!str.equals(str1)) {
            System.out.println("No");
        } else {
            System.out.println("Equal");
        }
    }
}
