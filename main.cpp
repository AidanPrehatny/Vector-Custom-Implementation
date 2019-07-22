#include <iostream>
#include "vec.hpp"

int main() {
    Vec<int> vec;
    int foo[] = {1,2,3,4,5};
    for (int n : foo) vec.push_back(n);
    for (Vec<int>::size_type i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}