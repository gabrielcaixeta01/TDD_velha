// Copyright [2024] Gabriel Caixeta

#include "./velha.hpp"
#include "./catch_amalgamated.hpp"
#define CATCH_CONFIG_MAIN

// Teste para verificar tabuleiro vazio
TEST_CASE("Tabuleiro vazio deve retornar jogo indefinido", "[indefinido]") {
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(VerificaVelha(tabuleiro) == -1);
}

// Teste linha completa
TEST_CASE("Linha completa deve retornar X como vencedor", "[vencedor]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {2, 0, 2},
        {0, 0, 0}
    };
    REQUIRE(VerificaVelha(tabuleiro) == 1);
}
