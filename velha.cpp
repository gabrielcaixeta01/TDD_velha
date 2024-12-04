// Copyright [2024] Gabriel Caixeta
#include "./velha.hpp"

int VerificaVelha(const int tabuleiro[3][3]) {
    int countX = 0, countO = 0;

    // Contagem de X e O
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == 1) countX++;
            if (tabuleiro[i][j] == 2) countO++;
        }
    }

    // Verifica condições impossíveis
    if (countX > countO + 1 || countO > countX + 1) {
        return -2;
    }

    int vencedorX = 0, vencedorO = 0;

    // Verifica linhas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2] &&
            tabuleiro[i][0] != 0) {
            if (tabuleiro[i][0] == 1) vencedorX++;
            if (tabuleiro[i][0] == 2) vencedorO++;
        }
    }

    // Verifica colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i] &&
            tabuleiro[0][i] != 0) {
            if (tabuleiro[0][i] == 1) vencedorX++;
            if (tabuleiro[0][i] == 2) vencedorO++;
        }
    }

    // Verifica diagonal principal
    if (tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2] &&
        tabuleiro[0][0] != 0) {
        if (tabuleiro[0][0] == 1) vencedorX++;
    }

    // Verifica diagonal secundária
    if (tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0] &&
        tabuleiro[0][2] != 0) {
        if (tabuleiro[0][2] == 1) vencedorX++;
        if (tabuleiro[0][2] == 2) vencedorO++;
    }

    // Dois vencedores simultâneos
    if (vencedorX > 0 && vencedorO > 0) {
        return -2;
    }

    // Retorna vencedor X ou O
    if (vencedorX > 0) return 1;
    if (vencedorO > 0) return 2;

    // Verifica se o tabuleiro está cheio
    bool cheio = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == 0) {
                cheio = false;
                break;
            }
        }
    }
    if (cheio) {
        return 0;
    }

    return -1;
}
