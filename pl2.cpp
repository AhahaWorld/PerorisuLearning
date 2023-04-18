#include "define.h"
#if PL_TARGET == 1

#define PL_TARGET_MIN 10

#if PL_TARGET_MIN == 1
// learn if
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cin >> name;
    if (name == "perorisu") {
        std::cout << "perorisuは暴言厨です。" << std::endl;
    } else {
        std::cout << name << "は聖人です。" << std::endl;
    }
}
#endif

#if PL_TARGET_MIN == 2
// learn else if
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cin >> name;
    if (name == "perorisu") {
        std::cout << "perorisuは暴言厨です。" << std::endl;
    } else if (name == "kaogon"){
        std::cout << "kaogonのケツは10年後100トンになります。" << std::endl;
    } else {
        std::cout << name << "は聖人です。" << std::endl;
    }
}
#endif

#if PL_TARGET_MIN == 3
// learn while break
#include <iostream>
#include <string>

int main() {
    std::cout << "weedは聖人ですか？ (\"はい\"か\"いいえ\"で答えてください。)" << std::endl;

    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "はい") {
            break;
        }
        std::cout << "で す か ?" << std::endl;
    }

    std::cout << "そうですよね!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 4
// learn while condition
#include <iostream>
#include <string>

int main() {
    std::string input;
    while (input != "はい") {
        std::cout << "weedは聖人ですか？ (\"はい\"か\"いいえ\"で答えてください。)" << std::endl;
        std::cin >> input;
    }

    std::cout << "そうですよね!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 5
// あんまいい例じゃない
// learn do-while
#include <iostream>
#include <string>

int main() {
    std::cout << "weedは聖人ですか？ (\"はい\"か\"いいえ\"で答えてください。)" << std::endl;

    std::string input = "";
    do {
        if (input != "")
            std::cout << "で す か ?" << std::endl;
        std::cin >> input;
    } while (input != "はい");

    std::cout << "そうですよね!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 6
// learn for
#include <iostream>
#include <string>

int main() {
    std::cout << "weedは聖人ですか？ (\"はい\"か\"いいえ\"で答えてください。)" << std::endl;

    for (std::string input = ""; input != "はい"; std::cin >> input);
    // for (loopのための変数初期化; loopを続ける条件; 変数のアップデート)

    std::cout << "そうですよね!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 7
// learn for block
#include <iostream>
#include <string>

int main() {
    for (std::string input = ""; input != "はい"; std::cin >> input) {
        std::cout << "weedは聖人ですか？ (\"はい\"か\"いいえ\"で答えてください。)" << std::endl;
    }
    // for (loopのための変数初期化; loopを続ける条件; 変数のアップデート) { loop中の処理 }

    std::cout << "そうですよね!" << std::endl;
}
#endif

#if PL_TARGET_MIN == 10
// TEST
/*
 * ① メールアドレスを入力してもらう
 * ② 確認のためもう一度入力してもらう
 * ③ 2回入力してもらったメールアドレスが同じか確認し、違ったら①からもう一度
 * ④ "確認できました。"と表示する
 */
#include <iostream>
#include <string>

int main() {
    std::string address, confirm;
    do {
        std::cout << "メールアドレスを入力してください。" << std::endl;
        std::cin >> address;
        std::cout << "確認のためもう一度、メールアドレスを入力してください。" << std::endl;
        std::cin >> confirm;
    } while (address == confirm);
    std::cout << "確認できました。" << std::endl;
}
#endif
#endif