#include <iostream>
#include <vector>

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

std::vector<std::string> split(const std::string &str, const char delimiter = ' ') {
    std::vector<std::string> res{};

    std::string tempStr{};
    for (const auto c :  str) {
        if (c == delimiter) {
            res.push_back(tempStr);
            tempStr = "";
        }

        tempStr += c;
    }
    res.push_back(tempStr);

    return res;
}

auto operator+(const Client &c1, const Client &c2) {
    const std::string newName = split(c1.name)[0] + split(c2.name)[1];

    Client newC(newName, c1.age +c2.age);

    return newC;
}

std::ostream & operator<<(std::ostream &os, Client &c) {
    return os << c.name << " is " << c.age << " years old";
}

int main() {
    Client c1("Illia Prykhodko", 18);
    Client c2("Andrew Klykavka", 19);

    Client resC = sum2(c1, c2);
    Client resC2 = sum(c2, c1);
    std::cout << resC << std::endl;
    std::cout << resC2 << std::endl;
    return 0;
}