public class grade {
      public static void main(String[] args) {
        int maths = 90;
        int science = 95;
        int history = 90;

        int average = (maths + science + history) / 3;

        String grade;

        if (average >= 90) {
            grade = "A";
        } else if (average >= 70) { 
            grade = "B";
        } else if (average >= 50) { 
            grade = "C";
        } else if (average >= 30) { 
            grade = "D";
        } else {
            grade = "Fail";
        }
        System.out.println("Average Marks: " + average);
        System.out.println("Grade: " + grade);
    }
}
