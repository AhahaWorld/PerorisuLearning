#include "define.h"

#if PL_TARGET == 3

#define PL_TARGET_MIN 0

#if PL_TARGET_MIN == 1
// example type
#include <iostream>

#include <type_traits>

void print_var_detail(auto var) {
    if constexpr (std::is_same_v<char, decltype(var)>) {
        std::cout << typeid(var).name() << " : " << sizeof(var) << "byte : " << (int)var << std::endl;
    } else if constexpr (std::is_same_v<unsigned char, decltype(var)>) {
        std::cout << typeid(var).name() << " : " << sizeof(var) << "byte : " << (unsigned int)var << std::endl;
    } else {
        std::cout << typeid(var).name() << " : " << sizeof(var) << "byte : " << var << std::endl;
    }
}

int main() {
    // 整数
    char one_byte_max = 0x7F;
    short two_byte_max = 0x7FFF;
    int four_byte_max = 0x7FFFFFFF;
    long eight_byte_max = 0x7FFFFFFFFFFFFFFFl;

    std::cout << "[整数]" << std::endl;
    print_var_detail(one_byte_max);
    print_var_detail(two_byte_max);
    print_var_detail(four_byte_max);
    print_var_detail(eight_byte_max);

    // 自然数
    unsigned char unsigned_one_byte_max = 0xFFu;
    unsigned short unsigned_two_byte_max = 0xFFFFu;
    unsigned int unsigned_four_byte_max = 0xFFFFFFFFu;
    unsigned long unsigned_eight_byte_max = 0xFFFFFFFFFFFFFFFFul;

    std::cout << "[自然数]" << std::endl;
    print_var_detail(unsigned_one_byte_max);
    print_var_detail(unsigned_two_byte_max);
    print_var_detail(unsigned_four_byte_max);
    print_var_detail(unsigned_eight_byte_max);

    // 少数
    float four_byte_decimal = 0.1f;
    double eight_byte_decimal = 0.1;

    std::cout << "[少数]" << std::endl;
    print_var_detail(four_byte_decimal);
    print_var_detail(eight_byte_decimal);
}

/*
 * Cのtype, 型は細かくあげればもう少しあるが基本的に上記の10つを覚えておけば良い。
 * 上記の10つはjavaなどではプリミティブ型(Primitive Value)と呼ばれ、
 * ほとんどのプログラミング言語の型の基本である。
 * プログラミングで変数を作るというのは、
 * PCの内部ではのメモリーの一部を使いますよ！とOS(PC)に伝えて場所を取ってもらう事で、
 * 一般的にメモリーを確保すると言う。
 */
#endif

#if PL_TARGET_MIN == 2
// example suffix
#include <iostream>

#include <type_traits>

void print_var_detail(auto var) {
    if constexpr (std::is_same_v<char, decltype(var)>) {
        std::cout << typeid(var).name() << " : " << sizeof(var) << " : " << (int)var << std::endl;
    } else if constexpr (std::is_same_v<unsigned char, decltype(var)>) {
        std::cout << typeid(var).name() << " : " << sizeof(var) << " : " << (unsigned int)var << std::endl;
    } else {
        std::cout << typeid(var).name() << " : " << sizeof(var) << " : " << var << std::endl;
    }
}

int main() {
    // 整数
    std::cout << "[整数]" << std::endl;
    print_var_detail(1);
    print_var_detail(1l);

    std::cout << "[自然数]" << std::endl;
    print_var_detail(1u);
    print_var_detail(1ul);

    std::cout << "[少数]" << std::endl;
    print_var_detail(1.0f);
    print_var_detail(1.0);
}
#endif

#if PL_TARGET_MIN == 3
// example prefix
#include <iostream>

int main() {
    std::cout << "0b11111111(2) = " << 0b11111111u << " (2=2^1進数8桁　=> 1*8 = 8bit)" << std::endl;
    std::cout << "0177777(8) = " << 0177777u << " (8=2^3進数5桁 + 2=2^1進数1桁　=> 3*5 + 1*1 = 16bit)" << std::endl;
    std::cout << "4294967295(10) = " << 4294967295u << " (10進数はbit操作に使いずらい。 4294967295(10) = 0xFFFFFFFF(16) => 16=2^4進数8桁　=> 4*8 = 32bit)" << std::endl;
    std::cout << "0xFFFFFFFFFFFFFFFF(16) = " << 0xFFFFFFFFFFFFFFFFul << " (16=2^4進数16桁　=> 4*16 = 64bit)" << std::endl;
}
#endif

// 数学演習 0xFFと0x7Fを比較して整数と自然数の違いを考えよう。
//         (2進数に直して比較してみよう。)

#if PL_TARGET_MIN == 4
// example calc
#include <iostream>

int main() {
    int a = 12, b = 3, c = 5;
    std::cout << "[a, b]" << std::endl
              << "a + b = " << a + b << std::endl
              << "a - b = " << a - b << std::endl
              << "a * b = " << a * b << std::endl
              << "a / b = " << a / b << std::endl
              << "a % b = " << a % b << std::endl;

    std::cout << "[a, c]" << std::endl
              << "a + c = " << a + c << std::endl
              << "a - c = " << a - c << std::endl
              << "a * c = " << a * c << std::endl
              << "a / c = " << a / c << std::endl
              << "a % c = " << a % c << std::endl;
}
#endif

#if PL_TARGET_MIN == 5
// learn calc
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << std::endl;
}
#endif

#if PL_TARGET_MIN == 6
// learn not div 0
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a / b << std::endl;
}
#endif

#if PL_TARGET_MIN == 7
// learn not div 0
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (b == 0){
        std::cout << "0では割れないよ。" << std::endl;
    } else {
        std::cout << a / b << std::endl;
    }
}
#endif

#if PL_TARGET_MIN == 7
// learn not div 0
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (b == 0){
        std::cout << "0では割れないよ。" << std::endl;
    } else {
        std::cout << (double)a / b << std::endl;
        // 整数から小数点キャストは整数の値が小さければ".0"が付くだけ、整数が大きいと勝手に小さくされる
        // 小数から整数のキャストは小数点以下切り捨て(round)される。
    }
}
#endif

#if PL_TARGET_MIN == 8
// test calculator

/*
 * ① 一つ目の数字を入力してもらう。
 * ② '+' '-' '*' '/' '%' のどれかを入力してもらう。
 * ③ 二つ目の数字を入力してもらう。
 * ④ その計算結果を表示する。
 */

#include <iostream>
#include <string>

int main() {
    int a, b;
    std::string op;
    std::cout << "<int> [+|-|*|/]　<int>" << std::endl;
    std::cin >> a >> op >> b;
    if (op == "+"){
        std::cout << a + b << std::endl;
    } else if (op == "-"){
        std::cout << a - b << std::endl;
    } else if (op == "*") {
        std::cout << a * b << std::endl;
    } else if (op == "/"){
        if (b == 0){
            std::cout << "0では割れないよ。" << std::endl;
        } else {
            std::cout << a / b << std::endl;
        }
    } else if (op == "%"){
        if (b == 0){
            std::cout << "0では割れないよ。" << std::endl;
        } else {
            std::cout << a % b << std::endl;
        }
    }
}
#endif

#if PL_TARGET_MIN == 9
// learn array
#include <iostream>

/*
 * arrayは日本語で配列のこと。
 */

int main() {
    constexpr int N = 4;
    int A[N /*size*/];
    // 行列みたいなもの

    // 代入
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;

    std::cout << A[0] << std::endl;
    std::cout << A[1] << std::endl;
    std::cout << A[2] << std::endl;
    std::cout << A[3] << std::endl;
    // 数学と違いA[1]からでなくA[0]から始まる。
}
#endif

#if PL_TARGET_MIN == 10
// learn array
#include <iostream>

int main() {
    int A[] = {1, 2, 3, 4}; // => sizeは4
    // 行列みたいなもの
    for (int a : A) { // 配列を扱う時は大体forを使う、これは拡張for文でC++の機能である。
        std::cout << a << std::endl;
    }
}
#endif

#if PL_TARGET_MIN == 11
// example array (search max)
#include <iostream>

int main() {
    constexpr int N = 10;
    int A[N];
    for (int i = 0; i < N; i++) { // これがC流の書き方、この方が後からiを使うことができるので様々な場面で役立つ。
        /* i = idx = index日本語で索引(まああんま深いこと考えずに番号でよし)*/
        std::cin >> A[i];
    }
    int max_idx = 0;
    for (int i = 1; i < N; i++) {
        if (A[max_idx] < A[i]) {
            max_idx = i;
        }
    }
    std::cout << max_idx << "番目に入力した" << A[max_idx] << "が最大です。" << std::endl;
}
#endif

#if PL_TARGET_MIN == 12
// test array sort

/*
 * ① サイズが20のint配列A, B作る。
 * ② 20回数字を入力してもらいAに保存する。
 * ③ 配列Aから一番目に小さい数を探し、配列Bの一番目に代入する。
 * ④ 次にAから二番目に小さい数を探し、配列Bの二番目に代入する。
 * ⑤ これを10番目まで繰り返す。
 * ⑥ 配列Bを一番目から表示する。
 */

#include <iostream>

int main() {
    constexpr int N = 10;
    int A[N], B[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int front_min = -1;
    for (int i = 0; i < N; i++) {
        int min = 0x7FFFFFFF;
        for (int j = 0; j < N; j++) {
            if (front_min < A[j] && A[j] < min) {
                min = A[j];
            }
        }
        if (min == 0x7FFFFFFF) {
            B[i] = front_min;
        } else {
            B[i] = min;
            front_min = min;
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
}
#endif

#if PL_TARGET_MIN == 13
// group-test(example) bubble-sort

#include <iostream>

int main() {
    constexpr int N = 10;
    int A[N] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 0}; // {9, 0, 0, 0, 0, 0, 0, 0, 0, 0} {9, 9, 9, 9, 9, 9, 9, 9, 9, 0}
    for (int i = 0; i < N; i++) {
        // std::cin >> A[i];
        A[i] = (i * 7 + 5) % 10;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            if (A[j] > A[j + 1]) {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
            /* for (int a : A) {
                std::cout << a << " ";
            }
            std::cout << std::endl; */
        }
        // std::cout << "===================" << std::endl;
    }
    for (int a : A) {
        std::cout << a << " ";
    }
}

#endif

#if PL_TARGET_MIN == 14
// example char

/*
 * charは-128-128(0-255)の整数を保持できると教えたが、実際に使うときはaやBや1, ?などの文字一文字に番号を振り、
 * charが持つ番号(整数)に対応させて考える。
 */

#include <iostream>

int main() {
    for (char c = '0'; c <= '9'; c++) {
        std::cout << (int)c << " : " << c << std::endl;
    }
    std::cout << std::endl;
    for (char c = 'A'; c <= 'Z'; c++) {
        std::cout << (int)c << " : " << c << std::endl;
    }
    std::cout << std::endl;
    for (char c = 'a'; c <= 'z'; c++) {
        std::cout << (int)c << " : " << c << std::endl;
    }
}

/*
 * 元々、数字(10文字) + アルファベット小文字(26文字) + アルファベット小文字(26文字) = 62文字 < 2^6 = 64
 * でアルファベット全てに番号つけるのに6bitで足りるので、一文字6bitだった、
 * その後制御文字(LF(Line Feed)='¥n')などや!, ?などの記号を足した7bitの"ASCII"と呼ばれる文字コードが誕生した。
 * (文字コードとは94番がaのような番号と文字の組み合わせを決めたもの)
 * その後、8bit, 32bit, 64bitなど8*nのbitを基本として操作するCPUが一般的になり、
 * 一番小さい8bitを一文字(char)とした。
 *
 * 実行してみて貰えばわかるが、0-9, a-z, A-Zは数値が連続している。
 *
 * 文字コード : ASCII, shift-jis, utf-8...
 * (マルチバイト文字などは後述する)
 */
#endif

#if PL_TARGET_MIN == 15
// learn char <=> int

/*
 * ここで文字コードが数値で連続していると学んだら一つできるようになることがある。
 * それが数字一文字と一桁の整数の変換だ。
 */

#include <stdio.h>

int main() {
    char a_char = getchar(), b_char = getchar();
    int a_int = a_char - '0', b_int = b_char - '0';
    putchar('0' + a_int + b_int);
    // '0' < '0' + a_int + b_int < '9' 出ないと数字じゃない何かが表示されてしまうので、
    // 1+8 などの答えが0以上9以下の計算しかできない。
}
#endif

#if PL_TARGET_MIN == 16
// learn getchar() putchar()
#include <stdio.h>

int main() {
    // C言語で一文字を入力してもらうときはgetchar()を使い、
    char character = getchar();
    // C言語で一文字を出力するときはputchar()を使う。
    putchar(character);
}

/*
 * C++では基本的にI/Oの命名(名前)にそのままin/out(例:cin/cout)を使うが、
 * C言語ではget/putやread/writeをよく使う。
 */
#endif

#if PL_TARGET_MIN == 17
// learn C string
#include <stdio.h>

int main() {
    char str[] = "kore ga c no yarikata ka----";
    for (int i = 0; i < sizeof(str) / sizeof(char); i++){
        putchar(str[i]);
    }
}
#endif
#endif
