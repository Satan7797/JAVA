/*Write a program to create a “distance” class with methods where distance is computed in terms
  of feet and inches, how to create objects of a class and to see the use of this pointer*/

package program9;

class Distance {

    double distance, ininch, infeet;

    Distance(double distance) {
        this.distance = distance;
    }
    
    void inches() {
        this.ininch = distance * 0.393;
    }

    void feet() {
        this.infeet = distance * 0.0328;
    }

    void output() {
        inches();
        feet();
        System.out.println("Distance" + distance + " in feet:" + infeet);
        System.out.println("Distance in inch:" + ininch);
    }
}

public class DistanceDemo {

    public static void main(String[] args){

        Distance e = new Distance(23);
        e.output();
    }
}
