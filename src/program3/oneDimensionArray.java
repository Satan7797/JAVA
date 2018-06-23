package program3;

public class oneDimensionArray{
   public static void main(String[] args){
      int arr[]=new int[10];
      
      for(int i=0;i<10;i++)
         arr[i]=i+2*10;
         
      System.out.println("Contents of array arr are:");
      for(int i=0;i<10;i++)
         System.out.print(arr[i]+" ");
   }
}