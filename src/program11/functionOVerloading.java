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
