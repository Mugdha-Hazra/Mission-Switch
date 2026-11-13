#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int age;
    string name;

    void display() {
        cout << "My name is " << this->name << ". I am " << this->age << " years old" << endl;
    }

    void sayHello(string name) {
        cout << this->name << " says hello to " << name << endl;
    }
};

void swap(Student* s1, Student* s2) {
    Student* temp = s1;
    s1 = s2;
    s2 = temp;
}

int main() {
    Student* s1 = new Student();
    s1->age = 10;
    s1->name = "A";

    Student* s2 = new Student();
    s2->age = 20;
    s2->name = "B";

    swap(s1, s2);

    s1->display();

    // Clean up dynamically allocated memory
    delete s1;
    delete s2;

    return 0;
}


/*
Explanation of the Output:
Regardless of the programming language, Java, Python, JS, or C++, languages use pass-by-value for function arguments (where references/pointers are copied).

Inside the swap function, local parameter variables s1 and s2 are swapped, but this only swaps the local references—it does not affect the original s1 and s2 pointers/references in the main scope.

Therefore, when s1.display() is called afterward, it still points to Student "A" (age 10).

Correct Answer Option:

My name is A. I am 10 years old.

*/
