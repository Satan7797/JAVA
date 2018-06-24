/*Write a program to show that during function overloading, if no matching argument is found,
  then java will apply automatic type conversions(from lower to higher data type)*/

package program11;

public class functionOVerloading {
    
 static void function(){
     System.out.println("void function");
 }   
 static void function(double a){
     System.out.println("Double function");
 }
 
 public static void main(String[] args){
     function(); 
     function(1); //integer value passed
     function(12.34);   //double value passed
 }   
}
