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