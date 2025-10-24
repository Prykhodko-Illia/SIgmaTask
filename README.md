# SigmaTask
### Task designer: Klykavka Andrew [@andriiklykavkaa](https://github.com/andriiklykavkaa)
### Task implementer: Illia Prykhodko [@Prykhodko-Illia](https://github.com/Prykhodko-Illia)

## Task Description
Having two generic `sum` functions and `struct Person` instance: 
```c++
template<typename T>
T sum(T &a, T &b) {
    return a + b;
}

// From c++ 20:
auto sum2(auto &a, auto &b) {
    return a + b;
}

struct Client {
    std::string name{};
    int age = 0;
};
```
in the `main()` scope such approach should work without changing the main function itself:
```c++
int main() {
    Client c1("Name1 Surname1", 18);
    Client c2("Name2 Surname2", 19);

    Client resC = sum2(c1, c2);
    Client resC2 = sum(c2, c1);
    std::cout << resC << std::endl;
    std::cout << resC2 << std::endl;
    return 0;
}
```

> Note: Sum of struct `a` and struct `b` where `a + b = c`: c.name = a[First Name] + b[Second Name], c.age = a.age + b.age

## Learning outcomes
- learn the difference between same functionality in different C++ versions
- learn how templates work
- learn `auto` keyword functionality
- learn how to write operators overloading
- improve algorithmical practical knowledge
