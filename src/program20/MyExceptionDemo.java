/*Write a program to create your own exception types to handle situation specific to your
  application (Hint: Define a subclass of Exception which itself is a subclass of Throwable).*/

package program20;

class MyException extends Exception{
   private int detail;
   
   MyException(int a){
      detail=a;
   }
   
   public String toString(){
      return "MyException ["+ detail +"]";
   }
}

class ExceptioDemo{
   static void compute(int a) throws MyException{
      System.out.println("Called compute("+ a + ")");
      
      if(a>10)
         throw new MyException(a);
       
      System.out.println("Normal exit");
   }
   
   public static void main(String[] args){
      try{
         compute(1);
         compute(20);
      } catch(MyException e){
         System.out.println("Caught "+e);
      }
   }
}