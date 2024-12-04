// Copyright [2024] Gabriel Caixeta

#include "./velha.hpp"
#include "./catch_amalgamated.hpp"
#define CATCH_CONFIG_MAIN

// Teste para verificar tabuleiro vazio
TEST_CASE("Tabuleiro vazio, jogo indefinido", "[indefinido]") {
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(VerificaVelha(tabuleiro) == -1);
}

