/*To convert a decimal to binary number.*/
package program5;

public class binaryToDecimal{
   public static void main(String[] args){
        int dec=4;
        int[] bin=new int[100];
        int j=0;
        while(dec!=0)
        {
            bin[j++]=dec%2;
            dec/=2;
        }
        System.out.print("4 in binary is ");
        for(int i=j-1;i>=0;i--)
        {
            System.out.print(bin[i]);
        }

   }
}