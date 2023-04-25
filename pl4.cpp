#include "define.h"

#if PL_TARGET == 4

#define PL_TARGET_MIN 0

#if PL_TARGET_MIN == 1
// learn pointer
#include <iostream>

int main() {
    int a = 1, b = 2;
    std::cout << a << ", " << b << std::endl;
    b = a;
    std::cout << a << ", " << b << std::endl;
    std::cin >> a;
    std::cout << a << ", " << b << std::endl;
    /*
     * b = aをしたんだから、aの中身が変わったらbも一緒に変わるじゃないかと思う人もいると思うが、
     * 実際にはbは入力する前のaの値である、これは値が共有されるのでなくコピーされているから起る、
     * b = aでbにaの1がコピーされ、std::cinがでaの値が変わってもbには何も影響しない。
     */
}
#endif

#if PL_TARGET_MIN == 2
// learn pointer
#include <iostream>

int main() {
    /*
    * ここで一旦メモリに確保された変数を考える、メモリはPC上では1Byte毎に番地(番号)がついている。
    * と言うか、文字コードもそうだがPC上で扱えるのは前回教えた整数や少数だけなので、文字やメモリ、
    * 基本的に動物を管理するプログラムなら動物の種類毎に番号を付けるのがいちばん簡単なのだ(その他に文字列で管理する方法もある。)、
    */
    int a = 1;
    std::cout << &a << " : " << a << std::endl;
    std::cin >> a;
    std::cout << &a << " : " << a << std::endl;
    /*
     * 重要 : 変数の前に&を付けるとその変数が使用しているメモリの先頭1Byteめの番地が取得できる。
     */
}
#endif

#if PL_TARGET_MIN == 3
// learn read by pointer
#include <iostream>

int main() {
    int a = 1;
    int * b = nullptr;
    std::cout << a << ", " << "nullptr" /* *b => やってみよう */ << std::endl;
    b = &a;
    std::cout << a << ", " << *b << std::endl;
    std::cin >> a;
    std::cout << a << ", " << *b << std::endl;
    /*
     * aを変えると、*bも変わる
     * bの型は int* (int pointer)でintの"ポインタ変数"と呼ばれる、
     * ポインタ変数は int * b = &a; のように&で取得した変数のメモリの番地を代入できる。
     * 変数の番地がわかるとその番地のメモリが何の値を保持しているかわかる、
     * そのメモリが保持している値を取り出すには *b のようにポインタ変数の前に * を付ける。
     */
}
#endif

#if PL_TARGET_MIN == 4
// learn write by pointer
#include <iostream>

int main() {
    int a = 1;
    int * b = nullptr;
    std::cout << a << ", " << "nullptr" << std::endl;
    b = &a;
    std::cout << a << ", " << *b << std::endl;
    std::cin >> *b;
    std::cout << a << ", " << *b << std::endl;
    /*
     * 今度は逆にbを変えるとaも変わる。
     * 方法は先と同じく*を付けるだけである。
     */
}
#endif

#if PL_TARGET_MIN == 5
// example
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
using remove_type_detail = std::remove_const_t<std::remove_reference_t<T>>;

template<typename T>
void visualize_memory(T* t,int before_range, int behind_range){
    std::string address_line = "...|", data_line = "...|";

    for (T* p = t + before_range; p <= t + behind_range; p++) {
        std::stringstream address_ss, data_ss;
        address_ss << (void*)p;
        if constexpr (std::is_same_v<char, remove_type_detail<decltype(*p)>>) {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << (*p != '\0' ? *p : ' ') << "(" << (int)*p << ")";
        } else if constexpr (std::is_same_v<unsigned char, remove_type_detail<decltype(*p)>>) {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << (*p != '\0' ? *p : ' ') << "(" << (int)*p << ")";
        } else {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << *p;
        }
        std::string address = address_ss.str(), data = data_ss.str();
        size_t max = std::max(address.size(), data.size());
        address_line += std::string(max - address.size(), ' ') +  address + "|";
        data_line += std::string(max - data.size(), ' ') + data + "|";
        if (100 < address_line.size()) {
            std::cout << address_line << std::endl << data_line << std::endl << std::endl;
            address_line = "";
            data_line = "";
        }
    }
    std::cout << address_line << "..." << std::endl << data_line << "..." << std::endl;
}

int main() {
    int a = 64, b = 256;
    std::cout << &b << "(b) - " << &a << "(a) = " << (long)(&b) - (long)(&a) << std::endl << std::endl;

    if ((long)(&b) - (long)(&a) == sizeof(int) /* 4 */) {
        std::cout << "*(&a + 0) : " << *(&a + 0) << " *(&a + 1) : " << *(&a + 1) << std::endl;
        std::cout << "*(&b - 1) : " << *(&b - 1) << " *(&a - 0) : " << *(&b - 0) << std::endl << std::endl;
        visualize_memory(&a, 0, 1);
    } else if ((long)(&a) - (long)(&b) == sizeof(int) /* 4 */) {
        std::cout << "*(&a - 1) : " << *(&a - 1) << " *(&a - 0) : " << *(&a - 0) << std::endl;
        std::cout << "*(&b + 0) : " << *(&b + 0) << " *(&b + 1) : " << *(&b + 1) << std::endl << std::endl;
        visualize_memory(&a, -1, 0);
    }
    /*
     * aとbがメモリ上で隣り合っているとき、その番地の差 |(long)&a - (long)&b| は sizeof(int) = 4　である,
     * これは int が 4 Byteだからである。
     * なぜメモリが隣り合わせになるのかは、このプログラムだとプログラムがほぼ同時にPCにメモリをください！とお願いするので隣り合いやすい。
     * (と言うか、プログラム上では順番に取られることになっているが。同時にメモリをくださいと言うことも多い。)
     *
     * (long)(&b) - (long)(&a) = 4 のときaの次にbが確保されており、(long)(&b) - (long)(&a) = -4 のときbの次にaが確保されている。
     * メモリが隣り合っているとき、+1で次のメモリに、-1で前のメモリに移動できる。(番地上ではint型なら sizeof(int) = 4番地移動する)
     */
}
#endif

#if PL_TARGET_MIN == 6
// example array is pointer
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

template <typename T>
using remove_type_detail = std::remove_const_t<std::remove_reference_t<T>>;

template<typename T>
void visualize_memory(T* t,int before_range, int behind_range){
    std::string address_line = "...|", data_line = "...|";

    for (T* p = t + before_range; p <= t + behind_range; p++) {
        std::stringstream address_ss, data_ss;
        address_ss << (void*)p;
        if constexpr (std::is_same_v<char, remove_type_detail<decltype(*p)>>) {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << (*p != '\0' ? *p : ' ') << "(" << (int)*p << ")";
        } else if constexpr (std::is_same_v<unsigned char, remove_type_detail<decltype(*p)>>) {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << (*p != '\0' ? *p : ' ') << "(" << (int)*p << ")";
        } else {
            data_ss << typeid(*p).name() << ":" << sizeof(*p) << "B:" << *p;
        }
        std::string address = address_ss.str(), data = data_ss.str();
        size_t max = std::max(address.size(), data.size());
        address_line += std::string(max - address.size(), ' ') +  address + "|";
        data_line += std::string(max - data.size(), ' ') + data + "|";
        if (100 < address_line.size()) {
            std::cout << address_line << std::endl << data_line << std::endl << std::endl;
            address_line = "";
            data_line = "";
        }
    }
    std::cout << address_line << "..." << std::endl << data_line << "..." << std::endl;
}

int main() {
    int a[] = {64, 256};
    std::cout << (a + 1) << "(a + 1) - " << a << "(a) = " << (long)(a + 1) - (long)(a) << std::endl << std::endl;

    if ((long)(a + 1) - (long)(a) == sizeof(int) /* 4 */) {
        std::cout << "*a : " << *a << " *(a + 1) : " << *(a + 1) << std::endl;
        visualize_memory(a, 0, 1);
    }
    int * b = a;
    int * c = a + 1;
    std::cout << "*b : " << *b << " *c : " << *c << std::endl;
    /*
     * 配列のa[0], a[1]は"必ず"メモリが隣あう、番地の差は先ほどと同じく sizeof(int) = 4　である,
     * 配列は int * b = a; のようにポインタ変数に代入できる。
     * 配列とポインタの違いは、配列は変数を作ったとき(宣言)にメモリ上に配列の分のメモリが確保されるが
     * ポインタは宣言してもポインタが指す先の変数は確保されない。
     * 簡単に言えば int a[0]; したあと *a は a[0] と同じなので何もバグではないが。
     * int * a; のとき *a はaがどのメモリを参照しているかわからない、
     * めちゃくちゃ幸運にaが少なくとも10^6番地がある中で自分のプログラムが管理しているメモリを参照してない限りバグである。
     */
}
#endif
#endif