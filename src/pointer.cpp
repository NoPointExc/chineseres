#include <iostream>

int main(void) {
    int i1 = 1;
    int *p1 = &i1;
    std::cout << "p1=" << p1 << " ; *p1=" << *p1 << std::endl;
    int *p2 = nullptr;
    std::cout << "p2=" << p2 << std::endl;
    //std::cout << "p2=" << p2 << " ; *p2=" << *p2 << std::endl;
    //p2 = &i1; 
    {
	int c = 1234;
	p2 = &c;
    }
    std::cout << "p2=" << p2 << " ; *p2=" << *p2 << std::endl;
    p2 = &i1;
    std::cout << "p2=" << p2 << " ; *p2=" << *p2 << std::endl;
    return 0;
}

