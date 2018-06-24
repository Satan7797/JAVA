/*Modify the “distance” class by creating constructor for assigning values (feet and inches) 
  to the distance object. Create another object and assign second object as reference variable 
  to another object reference variable. Further create a third object which is a clone of the 
  first object.*/

package program10;

class Distance {

    double distance, ininch, infeet;

    Distance(double distance) {
        this.distance = distance;
    }

    Distance(double infeet, double ininch) {
        this.infeet = infeet;
        this.ininch = ininch;
    }

    Distance(Distance d) {
        distance = d.distance;
        infeet = d.infeet;
        ininch = d.ininch;
    }

    void inches() {
        this.ininch = distance * 0.393;
    }

    void feet() {
        this.infeet = distance * 0.0328;
    }

    void output() {
        System.out.println("Distance in feet:" + infeet);
        System.out.println("Distance in inch:" + ininch);
    }

    void output1() {
        feet();
        inches();
        System.out.println("Distance in feet:" + infeet);
        System.out.println("Distance in inch:" + ininch);        
    }
}

public class distanceDemo {

    public static void main(String[] args){

        Distance e = new Distance(23);
        e.output1();

        Distance d = new Distance(12.34, 40.32);
        System.out.println("\nParameterized constructor:\n");
        d.output();

        Distance d1;
        d1 = d;
        System.out.println("Assigning values of first o"
                + "bject to second object...");
        System.out.println("Data in Second Object:\n");
        d1.output();

        Distance d2 = new Distance(e);
        System.out.println("Copy Data from second object to third object...");
        System.out.println("Data in third object:\n");
        d2.output1();
    }
}
