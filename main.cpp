#include "include/memory_resource.hpp"
#include "include/queue.hpp"
#include <iostream>
#include <string>

struct ComplexType {
    int id;
    std::string name;

    ComplexType(int id, std::string name) : id(id), name(std::move(name)) {}
};

int main() {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> int_allocator(&resource);
    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> int_queue(int_allocator);
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    for (const auto& value : int_queue) {
        std::cout << value << " ";
    }

    std::cout << "\n" << std::endl;

    Queue<ComplexType, std::pmr::polymorphic_allocator<ComplexType>> complex_queue(complex_allocator);
    complex_queue.push({1, "? ? ? MAI or MEI ? ? ?\n\n"});
    complex_queue.push({2, "! ! ! NOT BAMONKA ! ! !\n"});

    for (const auto& value : complex_queue) {
        std::cout << value.id << ": " << value.name << std::endl;
    }

    return 0;
}
