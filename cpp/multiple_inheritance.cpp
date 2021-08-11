#include <iostream>

struct A {
    virtual ~A() = default;
};

struct C {
    virtual ~C() = default;

    void foo() {
        std::cout << "C: " << __func__ << std::endl;
    }
};

struct D : A, C {
    virtual ~D() = default;

    void bar() {
        std::cout << "D: " << __func__ << std::endl;
    }
};

struct B : A {
    virtual ~B() = default;

    void baz() {
        std::cout << "B: " << __func__ << std::endl;
    }
};

struct E : B, C, D {
    virtual ~E() = default;
};

int main() {
    E e;

    std::cout << sizeof e << std::endl;
    e.baz();

    D &d = e;
    d.foo();

    return 0;
}
