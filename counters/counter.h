#pragma once

#include <inttypes.h>
#include <atomic>

namespace crdt_counter
{
    class Counter
    {
    public:
        virtual void Add() = 0;
        virtual void Subtract() = 0;
        virtual int64_t Get() = 0;
    };

    class LocalCounter : Counter
    {
    public:
        LocalCounter() : value_(0) { }
        void Add() override
        {
            value_.fetch_add(1, std::memory_order_seq_cst);
        }

        void Subtract() override
        {
            value_.fetch_add(-1, std::memory_order_seq_cst);
        }

        int64_t Get() override
        {
            return value_.load(std::memory_order_seq_cst);
        }

    private:
        std::atomic<int64_t> value_;
    };
} // crdt_counter