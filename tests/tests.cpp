#include <gtest/gtest.h>
#include <memory_resource>
#include "../include/queue.hpp"
#include "../include/memory_resource.hpp"


TEST(allocator, allocate_and_deallocate_single) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    auto ptr = allocator.allocate(1); 
    *ptr = 42; 
    EXPECT_EQ(*ptr, 42); 

    allocator.deallocate(ptr, 1); 
}

TEST(allocator, allocate_multiple) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    auto ptr = allocator.allocate(3); 
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    EXPECT_EQ(ptr[0], 10);
    EXPECT_EQ(ptr[1], 20);
    EXPECT_EQ(ptr[2], 30);

    allocator.deallocate(ptr, 3); 
}


TEST(queue, push_and_iterate) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(1);
    queue.push(2);
    queue.push(3);

    int expected[] = {1, 2, 3};
    int index = 0;

    for (int value : queue) {
        EXPECT_EQ(value, expected[index++]);
    }
}

TEST(queue, pop_and_check_size) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.pop();
    EXPECT_EQ(*queue.begin(), 20); 
}

TEST(queue, empty_check) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    EXPECT_TRUE(queue.begin() == queue.end()); 

    queue.push(1);
    EXPECT_FALSE(queue.begin() == queue.end()); 
}

TEST(queue, complex_type) {
    struct ComplexType {
        int id;
        std::string name;
    };

    memory_resource resource;
    std::pmr::polymorphic_allocator<ComplexType> allocator(&resource);

    Queue<ComplexType, std::pmr::polymorphic_allocator<ComplexType>> queue(allocator);

    queue.push({1, "First"});
    queue.push({2, "Second"});

    auto it = queue.begin();
    EXPECT_EQ(it->id, 1);
    EXPECT_EQ(it->name, "First");
    ++it;
    EXPECT_EQ(it->id, 2);
    EXPECT_EQ(it->name, "Second");
}

TEST(queue, memory_reuse_after_pop) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(100);
    queue.pop();
    queue.push(200);

    EXPECT_EQ(*queue.begin(), 200); 
}

TEST(queue, const_iterator) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(5);
    queue.push(10);
    queue.push(15);

    const Queue<int, std::pmr::polymorphic_allocator<int>>& const_queue = queue;

    auto it = const_queue.begin();
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 15);
}

TEST(queue, fifo_behavior) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.pop();
    EXPECT_EQ(*queue.begin(), 2); 
}

TEST(allocator, allocate_and_deallocate_single_different_value) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    auto ptr = allocator.allocate(1); 
    *ptr = 99;
    EXPECT_EQ(*ptr, 99); 

    allocator.deallocate(ptr, 1);
}

TEST(allocator, allocate_multiple_different_values) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    auto ptr = allocator.allocate(3);
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    EXPECT_EQ(ptr[0], 100);
    EXPECT_EQ(ptr[1], 200);
    EXPECT_EQ(ptr[2], 300);

    allocator.deallocate(ptr, 3); 
}

TEST(queue, push_and_iterate_different_values) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(10);
    queue.push(20);
    queue.push(30);

    int expected[] = {10, 20, 30};
    int index = 0;

    for (int value : queue) {
        EXPECT_EQ(value, expected[index++]);
    }
}

TEST(queue, pop_and_check_size_different_values) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(50);
    queue.push(60);
    queue.push(70);

    queue.pop();
    EXPECT_EQ(*queue.begin(), 60);
}

TEST(queue, empty_check_after_operations) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    EXPECT_TRUE(queue.begin() == queue.end()); 

    queue.push(7);
    EXPECT_FALSE(queue.begin() == queue.end());

    queue.pop();
    EXPECT_TRUE(queue.begin() == queue.end());
}

TEST(queue, complex_type_different_values) {
    struct ComplexType {
        int id;
        std::string name;
    };

    memory_resource resource;
    std::pmr::polymorphic_allocator<ComplexType> allocator(&resource);

    Queue<ComplexType, std::pmr::polymorphic_allocator<ComplexType>> queue(allocator);

    queue.push({3, "Third"});
    queue.push({4, "Fourth"});

    auto it = queue.begin();
    EXPECT_EQ(it->id, 3);
    EXPECT_EQ(it->name, "Third");
    ++it;
    EXPECT_EQ(it->id, 4);
    EXPECT_EQ(it->name, "Fourth");
}

TEST(queue, memory_reuse_after_pop_different_values) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(500);
    queue.pop();
    queue.push(600);

    EXPECT_EQ(*queue.begin(), 600);
}

TEST(queue, fifo_behavior_different_values) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(15);
    queue.push(25);
    queue.push(35);

    queue.pop();
    EXPECT_EQ(*queue.begin(), 25);
}

TEST(queue, push_pop_mixed_operations) {
    memory_resource resource;
    std::pmr::polymorphic_allocator<int> allocator(&resource);

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);
    queue.push(1);
    queue.push(2);
    queue.pop();
    queue.push(3);

    int expected[] = {2, 3};
    int index = 0;

    for (int value : queue) {
        EXPECT_EQ(value, expected[index++]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
