package program4;
public class twoDimensionalArray{
   public static void main(String[] args){
      int arr[][]=new int[3][3];
      
      /*
      Storing values in array
      */
      for(int row=0;row<3;row++)
         for(int column=0;column<3;column++)
            arr[row][column]=row*column+1;
      
      System.out.println("Elements of array arr are:");
      for(int row=0;row<3;row++){
         for(int column=0;column<3;column++)
            System.out.print(arr[row][column]+" ");
            
         System.out.println();
      }
      
   }
}