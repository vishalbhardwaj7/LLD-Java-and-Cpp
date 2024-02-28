#include <bits/stdc++.h>
using namespace std;

class StudentBuilder;

class Student{
    string name;
    int rollNo;
    string father;
    string mother;
public:
    vector<string> *subjects;
    Student(StudentBuilder *builder);

    string toString(){
        string res =  (" roll number: " + to_string(this->rollNo) + " name: "+ this->name +
                " father name: " + this->father +
                " mother name: " + this->mother +
                " subjects: " + subjects->at(0) + "," + subjects->at(1) + "," + subjects->at(2));
        return res;
    }
};
class StudentBuilder{
public:
    string name;
    int rollNo;
    string father;
    string mother;
    vector<string> *subjects;
    StudentBuilder* setRollNo(int roll){
        this->rollNo=roll;
        return this;
    }
    StudentBuilder* setName(string name){
        this->name=name;
        return this;
    }
    StudentBuilder* setFatherName(string name){
        this->father=name;
        return this;
    }
    StudentBuilder* setMotherName(string name){
        this->mother=name;
        return this;
    }
    virtual StudentBuilder* setSubjects() = 0; // this will be override by derived builders
    Student* build();
};


Student* StudentBuilder::build() {
    return new Student(this);
}


Student::Student(StudentBuilder* builder){
    this->father=builder->father;
    this->mother=builder->mother;
    this->name=builder->name;
    this->rollNo=builder->rollNo;
    // or we can deep copy too
    this->subjects=builder->subjects;
}




class MBAStudentBuilder: public StudentBuilder{
public:
    StudentBuilder* setSubjects(){
        vector<string> *subjects = new vector<string>();
        subjects->push_back("Micro Ecomomics");
        subjects->push_back("Finance");
        subjects->push_back("Operations ManageMent");
        this->subjects=subjects;
        return this;
    }
};

class EngineeringStudentBuilder: public StudentBuilder{
public:
    StudentBuilder* setSubjects(){
        vector<string> *subjects = new vector<string>();
        subjects->push_back("Maths");
        subjects->push_back("Physics");
        subjects->push_back("Cpp");
        this->subjects=subjects;
        return this;
    }
};

class Director{// defines the set of operations involved in making a 
    StudentBuilder *studentBuilder;// has a 
public:
    Director(StudentBuilder *studentBuilder):studentBuilder(studentBuilder){}

    Student* createStudent(){
        if(dynamic_cast<EngineeringStudentBuilder*> (studentBuilder))
            return createEngineeringStudent();
        else if(dynamic_cast<MBAStudentBuilder*> (studentBuilder))   
            return createMBAStudent();
        else return NULL;// return null or use null object design pattern here
    }

private:
    Student* createEngineeringStudent(){
        return studentBuilder->setRollNo(1)->setFatherName("Father of engineer")->setMotherName("mother of engg")->setName("engineer king")->setSubjects()->build();
    }
    Student* createMBAStudent(){
        return studentBuilder->setRollNo(2)->setFatherName("Father of mba")->setMotherName("mother of engg")->setName("mba king")->setSubjects()->build(); // lets say there were some more variable and i wanted to set them specifically for mba student so i can do that too 
    }
};

int main(){
    Director * dir1= new Director(new EngineeringStudentBuilder());
    Director * dir2= new Director(new MBAStudentBuilder());

    Student * engineer = dir1->createStudent();
    Student * mba = dir2->createStudent();

    cout<<engineer->toString();
    cout<<endl;
    cout<<mba->toString();
}

// chat gpt rocks

// In summary, the order in which you define these two functions doesn't matter in this particular case, as C++ allows member function definitions outside of the class as long as they are provided after the full class definition.





