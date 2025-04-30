#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos únicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    
    REQUIRE( romanos_para_decimal("V") == 5 );

    REQUIRE( romanos_para_decimal("X") == 10 );

    REQUIRE( romanos_para_decimal("L") == 50 );

    REQUIRE( romanos_para_decimal("C") == 100 );

    REQUIRE( romanos_para_decimal("D") == 500 );

    REQUIRE( romanos_para_decimal("M") == 1000 );

}

TEST_CASE( "Numeros romanos - algarismos repetidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("II") == 2 );
    
    REQUIRE( romanos_para_decimal("VV") == 10 );

    REQUIRE( romanos_para_decimal("XX") == 20 );

    REQUIRE( romanos_para_decimal("LL") == 100 );

    REQUIRE( romanos_para_decimal("CC") == 200 );

    REQUIRE( romanos_para_decimal("DD") == 1000 );

    REQUIRE( romanos_para_decimal("MM") == 2000 );
}

TEST_CASE( "Numeros romanos - algarismos subtraídos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    
    REQUIRE( romanos_para_decimal("IX") == 9 );

    REQUIRE( romanos_para_decimal("XL") == 40 );

    REQUIRE( romanos_para_decimal("XC") == 90 );

    REQUIRE( romanos_para_decimal("CD") == 400 );

    REQUIRE( romanos_para_decimal("CM") == 900 );
}

TEST_CASE( "Numeros romanos - algarismos misturados", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("XIV") == 14 );
    
    REQUIRE( romanos_para_decimal("XXIX") == 29 );

    REQUIRE( romanos_para_decimal("XLII") == 42 );

    REQUIRE( romanos_para_decimal("XCIX") == 99 );

    REQUIRE( romanos_para_decimal("CDXLIV") == 444 );

    REQUIRE( romanos_para_decimal("CMXCIX") == 999 );
}

/*
TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    
    REQUIRE( romanos_para_decimal("i") == -1 );
*/