#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/strfunctions.hpp"

TEST_CASE( "it returns 0" ) {
    REQUIRE( strcmp_case_insensitive( "Hi", "hi", false, 0) == 0 );
}
