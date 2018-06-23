package program15;

import java.util.Scanner;
public class inputFile{
   public static void main(String[] args){
      Scanner in=new Scanner(System.in);
      display.p("Enter string message:");
      String msg=in.nextLine();
      display.p(msg);
      in.close();
   }
}