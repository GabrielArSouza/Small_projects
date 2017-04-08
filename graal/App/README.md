# Dicas para trabalhar com ponteiro genérico

Considere o código abaixo:

    void func(void *ptr_void, size_t size) {
        using byte = unsigned char;
        byte *ptr = ( byte *) ptr_void;  // PASSO 1
        int i = 2, j = 4;

        // Copiando o elemento da posição 4 sobre a posição 2.
        memcpy( *(ptr + i*size), *(ptr + j*size ), size ); // PASSOS 2 e 3.
    }

1. Converter o ptr void para `unsigned char` (byte); para viabilizar aritmética de ponteiros.

2. Sempre que acessar um elemento do _range_, lembrar de multiplicar o tamanho (em bytes) de um elemento pelo offset (índice) desejado.

3. Utilizar funções de suporte a movimentação de memória: [`memcpy()`](http://en.cppreference.com/w/cpp/string/byte/memcpy).
