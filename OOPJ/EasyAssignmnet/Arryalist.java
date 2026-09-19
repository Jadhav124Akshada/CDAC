package ass2;
import java.util.*;
public class Arryalist {
	public static void main(String[] args) {
		ArrayList<String> al = new ArrayList<>();
		
        // Adding elements to ArrayList at the end
        al.add("Black");
        al.add("red");
        al.add("orange");
        al.add("Green");
        al.add("white");
        System.out.println("1.Original list:"+al);
        
      	// Adding Elements at the specific index
        al.add(1,"yellow");
        System.out.println("2.after adding element at index 1:"+al);
        
        // retrieve an element (at a specified index) from a given array list.
        String objAl = al.get(3);
        System.out.println("3.retrive element from index 3:"+objAl);
        
        // update specific array element by given element.
        Collections.replaceAll(al, "yellow", "blue");
        System.out.println("4.After updating element by specific element:"+al);
        
      	// Removing Element using index
        String objal=al.remove(2);
        System.out.println("5.element remove fromt index 2:"+objal);
        
        //search an element in a array list
        System.out.println(al.contains("red"));
        
       
	}

}
