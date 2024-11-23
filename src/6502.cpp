#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise() {
        for (u32 i = 32; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }
};

struct CPU {
    Word PC;
    Word SP;
    Byte A, X, Y;

    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

    void Reset(Mem& memory) {
        PC = 0xFFFC;
        SP = 0x0100;
        A = X = Y = 0;
        C = Z = I = B = V = N = 0;
        memory.Initialise();
    }
};

int main() {
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    return 0;
}
