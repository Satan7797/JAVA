/*Write a program to demonstrate the concept of boxing and unboxing.*/

package program14;

public class boxingAndAutoboxing{
   public static void main(String[] args){
      Integer i=10;  //autobox of int
      int j=i; //auto-unbox
      System.out.println(j+" "+i);  //displays 10 10
   }
}