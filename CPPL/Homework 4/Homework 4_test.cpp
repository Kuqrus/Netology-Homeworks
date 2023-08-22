#include "List.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

#define TEST_SIZE 6

TEST_CASE("Checking tasks 3-1", "[3-1]") {
    SECTION("Testing Empty function") {
        List test;
        test.PushBack(1);
        CHECK(!test.Empty());
    }
    SECTION("Testing Size function") {
        List test;
        for (int i = 0; i < TEST_SIZE; i++) {
            test.PushBack(i);
        }
        CHECK(test.Size() == TEST_SIZE);
    }
    SECTION("Testing Clear function") {
        List test;
        test.PushBack(1);
        test.Clear();
        CHECK(test.Empty());
    }
}

TEST_CASE("Checking tasks 3-2", "[3-2]") {
    SECTION("Testing PushBack functions") {
        List test;
        for (int i = 0; i <= TEST_SIZE; i++) {
            test.PushBack(i);
        }
        CHECK(test.PopBack() == TEST_SIZE);
    }

    SECTION("Testing PushFront functions") {
        List test;
        for (int i = 0; i <= TEST_SIZE; i++) {
            test.PushFront(i);
        }
        CHECK(test.PopBack() == 0);
    }

    SECTION("Testing PopBack functions on empty list") {
        List test;
        bool b = false;
        test.Clear();
        
        try { test.PopBack(); }
        catch (const std::exception&) { b = true; }
        CHECK(b);
    }

    SECTION("Testing PopFront functions on empty list") {
        List test;
        bool b = false;
        test.Clear();

        try { test.PopFront(); }
        catch (const std::exception&) { b = true; }
        CHECK(b);
    }
}

int main() {
    return Catch::Session().run();
}