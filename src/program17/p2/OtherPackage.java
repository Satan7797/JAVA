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