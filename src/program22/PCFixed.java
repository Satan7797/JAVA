/*Write a program to demonstrate multithread communication by implementing synchronization
  among threads (Hint: you can implement a simple producer and consumer problem).*/

package program22;

class Q{
   int n;
   boolean valueSet=false;
   
   synchronized int get(){
      while(!valueSet)
      try{
         wait(200);
      } catch(InterruptedException e){
         System.out.println("Exception caught: "+e);
      }
      
      System.out.println("Got: "+n);
      valueSet = false;
      notify();
      return n;
   }
   
   synchronized void put(int n){
      while(valueSet)
         try{
            wait(200);
         } catch(InterruptedException e){
            System.out.println("Exception caught: "+e);
         }
         
         this.n=n;
         valueSet = true;
         System.out.println("Put: "+n);
         notify();
   }
}

class Producer implements Runnable{
   Q q;
   Thread t;
   
   Producer(Q q){
      this.q = q;
      t = new Thread(this, "Producer");
   }
   
   public void run(){
      int i=0;
      while(true)
         q.put(i++);
   }
}

class Consumer implements Runnable{
   Q q;
   Thread t;
   
   Consumer(Q q){
      this.q = q;
      t = new Thread(this, "Consumer");
   }
   
   public void run(){
      int i=0;
      while(true)
         q.get();
   }
}

class PCFixed{
   public static void main(String[]  args){
      Q q = new Q();
      Producer p = new Producer(q);
      Consumer c = new Consumer(q);
      
      p.t.start();
      c.t.start();
      
      System.out.println("Press Control-C to stop");
   }
}
