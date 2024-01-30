package BuilderDesignPattern;

import java.util.List;

public class Student{
    int rollNumber;
    int age;
    String name;
    String motherName;
    String fatherName;
    List<String> subjects;

    public Student(StudentBuilder builder){
        this.rollNumber=rollNumber;
        this.age=age;
        this.name=name;
        this.fatherName=fatherName;
        this.motherName=motherName;
        this.subjects=subjects;
    }

    public String toString(){
        return ""+ " roll number: " + this.rollNumber +
                " age: " + this.age +
                " name: " + this.name +
                " father name: " + this.fatherName +
                " mother name: " + this.motherName +
                " subjects: " + subjects.get(0) + "," + subjects.get(1) + "," + subjects.get(2);
    }

}
