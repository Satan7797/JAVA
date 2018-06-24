/*Write a program that creates illustrates different levels of protection 
  in classes/subclasses belonging to same package or different packages*/


/*Class Demo, Protection and SamePackage are three Different classes 
  from different files. So create a seprate file for them.

  Class Demo,OtherPackage and Protection2 are part of Package p2. So 
  create separate files for three of them.*/


/*------------------------------------------------------------------*/
package program17.p1;

public class Demo{
   public static void main(String[] args){
   /*Here 3 objects will be created
   */
      Protection ob1 = new Protection();
      SamePackage ob2 = new SamePackage();
   }
}


/*------------------------------------------------------------------*/
package program17.p1;

public class Protection{
   int n = 1;
   private int n_pri=2;
   protected int n_pro=3;
   public int n_pub=4;
   
   public Protection(){
      System.out.println("Base Constructor");
      System.out.println("n = " + n);
      System.out.println("n_pri = " + n_pri);
      System.out.println("n_pro = " + n_pro);
      System.out.println("n_pub = " + n_pub);
   }
}


/*------------------------------------------------------------------*/
package program17.p1;

class SamePackage{
   SamePackage(){
      Protection p = new Protection();
      System.out.println("SamePackage constructor");
      System.out.println("n = " + p.n);
      
      /*
      System.out.println("n_pri = " + p.n_pri);
      n_pri cannot be accessed. Because it is declared as private
      */
      System.out.println("n_pro = " + p.n_pro);
      System.out.println("n_pub = " + p.n_pub);      
   }
}


/*------------------------------------------------------------------*/
package program17.p2;

public class Demo{
   public static void main(String[] args){
   //Here four constructors will be called
      Protection2 ob1 = new Protection2();
      OtherPackage ob2 = new OtherPackage();
   }
}


/*------------------------------------------------------------------*/
package program17.p2;

import program17.p1.Protection; 
class OtherPackage{
   OtherPackage(){
      Protection p = new Protection();
      System.out.println("OtherPackage Constructor");
      
      //class or package only
      //System.out.println("n = "+ p.n);
      
      //class only
      //System.out.println("n_pri = "+p.n_pri);
      
      //class, subclass or package only
      //System.out.println("n_pro = " + p.n_pro);
      
      System.out.println("n_pub = " + p.n_pub); 
   }
}


/*------------------------------------------------------------------*/
package program17.p2;

class Protection2 extends program17.p1.Protection{
    Protection2(){  
      System.out.println("Derived other package constructor");
      
      //class or package only
      //System.out.println("n_pri = " + n);
      
      //class only
      //System.out.println("n_pri = " + n_pri);
      System.out.println("n_pro = " + n_pro);
      System.out.println("n_pub = " + n_pub);
   }
}