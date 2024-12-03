#include <memory>
#include <iterator>
#include <stdexcept>

#ifndef QUEUE_HPP
#define QUEUE_HPP


template <typename T, typename Allocator = std::pmr::polymorphic_allocator<T>>
class Queue {
private:
    struct Node {
        T value;
        Node* next = nullptr;

        Node(const T& val, Node* nxt): value(val), next(nxt) {}
        Node(T&& val, Node* nxt): value(std::move(val)), next(nxt) {}
    };

    using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    NodeAllocator alloc;
    Node* head = nullptr;
    Node* tail = nullptr;
    std::size_t size_ = 0;

public:
    explicit Queue(const Allocator& allocator = Allocator())
        : alloc(allocator) {}

    ~Queue() {
        clear();
    }

    void push(const T& value) {
        Node* new_node = std::allocator_traits<NodeAllocator>::allocate(alloc, 1);
        std::allocator_traits<NodeAllocator>::construct(alloc, new_node, value, nullptr);

        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        ++size_;
    }

    void push(T&& value) {
        Node* new_node = std::allocator_traits<NodeAllocator>::allocate(alloc, 1);
        std::allocator_traits<NodeAllocator>::construct(alloc, new_node, std::move(value), nullptr);

        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        ++size_;
    }

    void pop() {
        if (!head) throw std::runtime_error("Queue is empty");

        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;

        std::allocator_traits<NodeAllocator>::destroy(alloc, temp);
        std::allocator_traits<NodeAllocator>::deallocate(alloc, temp, 1);
        --size_;
    }

    const T& front() const {
        if (!head) throw std::runtime_error("Queue is empty");
        return head->value;
    }

    bool empty() const { return size_ == 0; }

    std::size_t size() const { return size_; }

    void clear() {
        while (!empty()) pop();
    }

    class Iterator {
    private:
        Node* current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(Node* start) : current(start) {}

        reference operator*() const { return current->value; }
        pointer operator->() const { return &current->value; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

#endif