#include <memory_resource>
#include <list>
#include <cstdlib>
#include <cassert>

#ifndef MEMORY_RESOURCE_HPP
#define MEMORY_RESOURCE_HPP

class memory_resource : public std::pmr::memory_resource {
private:
    std::list<void*> allocated_blocks; 
    std::list<void*> free_blocks;

    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        for (auto i = free_blocks.begin(); i != free_blocks.end(); ++i) {
            if (std::align(alignment, bytes, *i, bytes)) {
                void* ptr = *i;
                free_blocks.erase(i);
                return ptr;
            }
        }

        void* ptr = std::aligned_alloc(alignment, bytes);
        if (!ptr) throw std::bad_alloc();
        allocated_blocks.push_back(ptr);
        return ptr;
    }

    void do_deallocate(void* ptr, std::size_t, std::size_t) override {
        free_blocks.push_back(ptr);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

public:
    ~memory_resource() {
        for (void* ptr : allocated_blocks) {
            std::free(ptr);
        }
        allocated_blocks.clear();
        free_blocks.clear();
    }
};


#endif