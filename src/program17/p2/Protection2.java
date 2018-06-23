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