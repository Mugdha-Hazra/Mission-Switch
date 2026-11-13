#iostream> // Note: Include standard libraries as needed (e.g., #include <iostream>)

class P {
protected:
    int d1 = 10;
    int d = 100;

public:
    void fun1() {
        std::cout << "P's fun1" << std::endl;
    }

    void fun() {
        std::cout << "P's fun" << std::endl;
    }

    static void sfun() {
        std::cout << "P's sfun" << std::endl;
    }
};

class C : public P {
protected:
    int d2 = 20;
    int d = 200;

public:
    void fun2() {
        std::cout << "C's fun2" << std::endl;
    }

    void fun() {
        std::cout << "C's fun" << std::endl;
    }

    static void sfun() {
        std::cout << "C's sfun" << std::endl;
    }
};

int main() {
    C obj;
    std::cout << obj.d1 << std::endl;
    std::cout << obj.d << std::endl;
    obj.fun1();
    obj.fun();
    obj.sfun(); // Or C::sfun();
    
    return 0;
}


/*
Here is a step-by-step explanation of how the code works and how the output is determined:

---

### 1. **Variable Shadowing (`d1` and `d`)**

* `System.out.println(obj.d1);` prints **`10`**: Since `C` inherits from `P`, it gets `d1` from `P`.
* `System.out.println(obj.d);` prints **`200`**: Both class `P` and class `C` declare a variable named `d` (`P` has `d = 100`, and `C` has `d = 200`). In Java, member variables are **hidden (shadowed)** rather than overridden. When you access `obj.d` via a reference of type `C`, it resolves to `C`'s own variable `d`, which is `200`.

---

### 2. **Method Overriding (`fun1` and `fun`)**

* `obj.fun1();` prints **`P's fun1`**: Class `C` does not define its own `fun1`, so it falls back to the implementation in parent class `P`.
* `obj.fun();` prints **`C's fun`**: Both classes define `fun()`. In Java, instance methods are dynamically dispatched (overridden) at runtime. Since `obj` is an instance of `C`, the overridden method in `C` is executed.

---

### 3. **Static Methods (`sfun`)**

* `obj.sfun();` prints **`C's sfun`** (or `C's sfun` behavior): Static methods belong to the class rather than any individual instance. In Java, static methods are **hidden**, not overridden. Even though it is called using an object reference (`obj.sfun()`), the compiler resolves it based on the reference/variable type (`C`), executing `C`'s static method.

---

### **Correct Option Selection**

Putting it all together, the printed sequence is:

1. `10`
2. `200`
3. `P's fun1`
4. `C's fun`
5. `C's sfun`

Thus, the correct answer choice from your options is:

> **`10 200 P's fun 1C's fun C's sfun`** *(Note: The text in the option combines `P's fun1` and `C's fun` visually as `P's fun 1C's fun`)*
*/
