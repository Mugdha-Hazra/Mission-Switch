#include <iostream>
#include <string>

class Student {
public:
    int age;
    std::string name;

    Student(std::string name = "", int age = 0) {
        this->age = age;
        this->name = name;
    }

    void display() {
        std::cout << "My name is " << this->name << ". I am " << this->age << " years old" << std::endl;
    }

    void sayHello(std::string name) {
        std::cout << this->name << " says hello to " << name << std::endl;
    }
};

int main() {
    // In C++, we use pointers to mimic object referencing semantics (like Java/JS)
    Student* s1 = new Student();
    s1->age = 10;
    s1->name = "A";

    Student* s2 = new Student();

    Student* temp = s1;
    s1 = s2;
    s2 = temp;

    s2->display();

    // Clean up dynamically allocated memory
    delete s1;
    delete s2;

    return 0;
}

/*
Step-by-Step ExecutionCreating Objects & Initializing s1:Student s1 = new Student(); creates a new Student instance (let's call it Instance 1).s1.age = 10; and s1.name = "A"; sets the fields of Instance 1 to age = 10 and name = "A".s1 references Instance 1.Creating s2:Student s2 = new Student(); creates another new Student instance (let's call it Instance 2). Since no values are explicitly assigned to s2, its fields take default values (age = 0, name = null in Java/JS, or empty string in Python).s2 references Instance 2.Swapping References (temp, s1, s2):Student temp = s1; $\rightarrow$ temp now points to Instance 1 (which has name "A" and age 10).s1 = s2; $\rightarrow$ s1 now points to Instance 2.s2 = temp; $\rightarrow$ s2 now points back to Instance 1.Final Call (s2.display()):Since s2 now references Instance 1, calling s2.display() prints the values stored in Instance 1.Correct AnswerMy name is A. I am 10 years old.
  */
