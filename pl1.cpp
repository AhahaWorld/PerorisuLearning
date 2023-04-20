#include "define.h"
#if PL_TARGET == 1

#define PL_TARGET_MIN 0

#if PL_TARGET_MIN == 1
// learn cout
#include <iostream>

int main() {
    std::cout << "Hello World!"; // <<そっちの向きにデータを流すみたいな意味
}
#endif

#if PL_TARGET_MIN == 2
// learn cout
#include <iostream>

int main() {
    std::cout << "Hello World!";
    std::cout << "My name is prorisu!";
}
#endif

#if PL_TARGET_MIN == 3
// learn endl
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl; // endl = end line
    std::cout << "My name is prorisu! << std::emdl";
}
#endif

#if PL_TARGET_MIN == 4
// learn stream
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl << "My name is prorisu!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 5
// learn variable
#include <iostream>
#include <string>

int main() {
    std::string name = "perorisu";
    std::cout << "Hello World!" << std::endl << "My name is " << name << "!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 6
// learn cin
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cin >> name;
    std::cout << "Hello World!" << std::endl << "My name is " << name << "!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 7
// test

/*
 * ① 名前と年齢を入力してもらいう。
 * ② 自己紹介を画面に表示する。
 * [例]
 * 入力 : perorisu 19
 * 出力
 */

#include <iostream>
#include <string>

int main() {
    std::string name, year;
    std::cin >> name >> year; // In
    std::cout << "Hello World!" << std::endl
              << "My name is " << name << "!" << std::endl
              << "I'm " << year << " years old." << std::endl; // Out
    // 基本的なプログラムはIOが全て、マウスやキーボード, バーコードリーダーなどで入力された情報を
    // モニターやスピーカー, ロボットアーム, プリンターなどで人間に送り返してあげるのが目的
}
#endif
#endif