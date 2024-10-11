#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() =0;
};

class People: public Base {
public:
    void foo() override {
        cout << "People foo()" << endl;
    }
};

class peopleProxy: public Base {
public:
    peopleProxy(Base *ptr) :m_ptr(ptr) {}
    void foo() override {
        cout << "peopleProxy foo()" << endl;
        m_ptr->foo();
    }
private:
    Base *m_ptr;
};

int main() {
    Base *p = new People();
    Base *pp = new peopleProxy(p);
    pp->foo();
}


