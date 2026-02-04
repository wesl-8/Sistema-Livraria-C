#include "interface.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void textbackground(int color) {
    // No Windows, o background é a parte alta do byte de cor (bits 4-7)
    // Precisamos pegar a cor atual e mudar só o fundo
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int text_color = csbi.wAttributes & 0x0F;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color << 4) | text_color);
}

int getTecla() {
    int ch;
    ch = getch();
    if (ch == 224 || ch == 0) { // Tecla especial (setas, f1, etc)
        return getch() + 1000;
    }
    return ch;
}

// Função para desenhar janelas bonitas
void Borda(int x, int y, int largura, int altura, int tipo, int sombra) {
    // Caracteres ASCII estendidos para borda dupla ou simples
    // Tipo 0 = Borda Dupla, Tipo 1 = Borda Simples
    int C_CIMA_ESQ, C_CIMA_DIR, C_BAIXO_ESQ, C_BAIXO_DIR, LINHA_HOR, LINHA_VER;

    if (tipo == 0) { // Borda Dupla
        C_CIMA_ESQ = 201; C_CIMA_DIR = 187; C_BAIXO_ESQ = 200; C_BAIXO_DIR = 188;
        LINHA_HOR = 205; LINHA_VER = 186;
    } else { // Borda Simples
        C_CIMA_ESQ = 218; C_CIMA_DIR = 191; C_BAIXO_ESQ = 192; C_BAIXO_DIR = 217;
        LINHA_HOR = 196; LINHA_VER = 179;
    }

    textcolor(WHITE); // Cor da borda

    // Desenha linhas superior e inferior
    for (int i = 0; i < largura; i++) {
        gotoxy(x + i, y); printf("%c", LINHA_HOR);
        gotoxy(x + i, y + altura); printf("%c", LINHA_HOR);
    }

    // Desenha linhas laterais
    for (int i = 0; i < altura; i++) {
        gotoxy(x, y + i); printf("%c", LINHA_VER);
        gotoxy(x + largura, y + i); printf("%c", LINHA_VER);
    }

    // Cantos
    gotoxy(x, y); printf("%c", C_CIMA_ESQ);
    gotoxy(x + largura, y); printf("%c", C_CIMA_DIR);
    gotoxy(x, y + altura); printf("%c", C_BAIXO_ESQ);
    gotoxy(x + largura, y + altura); printf("%c", C_BAIXO_DIR);

    // Sombra (Opcional - dá efeito 3D)
    if (sombra) {
        textcolor(DARK_GRAY);
        for (int i = 1; i <= altura; i++) {
            gotoxy(x + largura + 1, y + i); printf("%c", 177);
        }
        for (int i = 1; i <= largura + 1; i++) {
            gotoxy(x + i, y + altura + 1); printf("%c", 177);
        }
        textcolor(WHITE); // Volta para branco
    }
}
