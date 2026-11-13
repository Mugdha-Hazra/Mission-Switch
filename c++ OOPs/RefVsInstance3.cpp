#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int age;
    string name;

    // Constructor to initialize default values
    Student() {
        age = 0;
        name = "";
    }

    void display() {
        cout << "My name is " << this->name << ". I am " << this->age << " years old" << endl;
    }

    void sayHello(string name) {
        cout << this->name << " says hello to " << name << endl;
    }
};

int main() {
    Student s1;
    s1.age = 10;
    s1.name = "A";

    Student s2;

    int tempAge = s1.age;
    s1.age = s2.age;
    s2.age = tempAge;

    s2.display();

    return 0;
}


/*
The correct answer is:

* **My name is null. I am 10 years old.** *(or `My name is . I am 10 years old.` depending on default string initializations, but looking at the options provided, this corresponds to the third option)*

---

### Explanation:

1. **Initialization (`s1` and `s2`)**:
* `s1` is created with `age = 10` and `name = "A"`.
* `s2` is created as a new `Student` instance with default values (`age = 0` and `name = null` or empty/uninitialized depending on the language).


2. **Swapping Ages**:
* `tempAge = s1.age;` ($\text{tempAge} = 10$)
* `s1.age = s2.age;` ($s1.\text{age} = 0$)
* `s2.age = tempAge;` ($s2.\text{age} = 10$)
* *Note:* Only the `age` fields are swapped. The `name` fields remain untouched (`s1.name` is still `"A"`, and `s2.name` remains `null`/empty).


3. **Final Call (`s2.display()`)**:
* When `s2.display()` is called, it prints the properties of object `s2`.
* Since `s2.name` was never assigned a value, its name is `null` (or empty), and its `age` is now `10` (after the swap).
*/
