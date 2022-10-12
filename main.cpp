#include <iostream>
#include <map>
#include <list>
#include <vector>

#include "include/enhanced_allocator.h"
#include "include/linked_list.h"

int main(int, char *[]) {
    try {

        auto default_map = std::map<int, int, std::less<>>{};

        int factorial = 1;
        for (int i = 0; i < 10; ++i) {
            factorial *= i > 0 ? i : 1;
            default_map[i] = factorial;
        }

        auto enhanced_map = std::map<int, int, std::less<>, enhanced_allocator<std::pair<const  int, int>, 10>>{};
        factorial = 1;
        for (int i = 0; i < 10; ++i) {
            factorial *= i > 0 ? i : 1;
            enhanced_map[i] = factorial;
        }

        std::cout << "Print values of balanced trees" << std::endl;
        std::cout << "Key value pairs of default map:" << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << '(' << i << ' ' <<  default_map[i] << ')' << "  ";
        }
        std::cout << std::endl;

        std::cout << "Key value pairs of enhanced map:" << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << '(' << i << ' ' <<  enhanced_map[i] << ')' << "  ";
        }
        std::cout << std::endl;


        auto common_list = linked_list<int>{};
        for (int i = 0; i < 10; ++i) {
            common_list.push_back(i);
        }

        auto enhanced_list = linked_list<int, enhanced_allocator<int, 10>>{};
        for (int i = 0; i < 10; ++i) {
            enhanced_list.push_back(i);
        }

        std::cout << "Print values of custom linked lists" << std::endl;
        std::cout << "Values of default custom linked list:" << std::endl;
        for (int iter: common_list) {
            std::cout << iter << ' ';
        }
        std::cout << std::endl;

        std::cout << "Values of enhanced custom linked list:" << std::endl;
        for (int iter: enhanced_list) {
            std::cout << iter << ' ';
        }
        std::cout << std::endl;
    }
    catch(std::bad_alloc &) {
        std::cout << "Not enough memory to create container!" << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "Error! " << e.what() << std::endl;
    }

    return 0;
}
