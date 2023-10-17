#pragma once

#include <iostream>

namespace technikum
{

    auto baseDeleter = [](auto* ptr) { delete ptr; };

    template<typename T, typename CustomDeleter = decltype(baseDeleter)>

    class unique_ptr
    {
        private:
            T* ptr_;
            CustomDeleter deleter;

        public:
            // Constructor
            explicit unique_ptr(T* ptr = nullptr, CustomDeleter d = baseDeleter) : ptr_(ptr), deleter(d)
            {
            }

            // Destructor
            ~unique_ptr()
            {
                deleter(ptr_);
            }

            // Delete the Copy constructor and assignment operator
            unique_ptr(const unique_ptr&) = delete;
            unique_ptr& operator=(const unique_ptr&) = delete;

            // Move constructor and assignment operator
            unique_ptr(unique_ptr&& other) noexcept 
            {
                ptr_ = other.ptr_;
                other.ptr_ = nullptr;
            }

            unique_ptr& operator=(unique_ptr&& other) noexcept
            {
                if (this != &other)
                {
                    delete ptr_;
                    ptr_ = other.ptr_;
                    other.ptr_ = nullptr;
                }
                return *this;
            }

            // Member functions
            T* get() const noexcept
            {
                return ptr_;
            }

            T* release() noexcept
            {
                T* temp = ptr_;
                ptr_ = nullptr;
                return temp;
            }

            void reset(T* ptr = nullptr) noexcept
            {
                delete ptr_;
                ptr_ = ptr;
            }

            void swap(T*& other) noexcept
            {
                T* temp = ptr_;
                ptr_ = other;
                other = temp;
            }

            void swap(unique_ptr<T>& other) noexcept
            {
                T* temp = ptr_;
                ptr_ = other.ptr_;
                other.ptr_ = temp;
            }

            T& operator*() const noexcept
            {
                return *ptr_;
            }

            T* operator->() const noexcept
            {
                return ptr_;
            }

            explicit operator bool() const noexcept
            {
                return ptr_ != nullptr;
            }
    };
}  // namespace technikum