#include "define.h"

#if PL_TARGET == 5

#define PL_TARGET_MIN 0

#if PL_TARGET_MIN == 1
// learn gets() puts()
#include <stdio.h>

int main() {
    char str[256];
    // 256文字文のメモリを確保する
    gets(str); // (in) 取ってくる
    puts(str); // (out) 表示
}
#endif

#if PL_TARGET_MIN == 2
// learn pointe is fixed
#include <iostream>
#include <stdio.h>

int main() {
    char str[256];
    std::cout << (void*)str << std::endl;
    gets(str);
    puts(str);
    std::cout << (void*)str <<  std::endl;
    /*
     * get(), put()をした後でstrのメモリの番地は変わらない。
     *
     * char*は文字列として表示されてしまうため一旦void*にキャストする。
     */
}
#endif

#if PL_TARGET_MIN == 3
// learn strlen
#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = strlen(str);
    // strlenで文字列の長さが取得できる。
    puts(str);
    std::cout << (void*)str << " : " << length << " : " << str << std::endl;
}
#endif

#if PL_TARGET_MIN == 4
// example puts ポインタアクセスver.
#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = strlen(str);
    // puts(str);
    for (char* p = str; p < (str + length); p++) {
        putchar(*p);
    }
    putchar('\n');
    // ここまで
    std::cout << (void*)str << " : " << length << " : " << str << std::endl;
}
#endif

#if PL_TARGET_MIN == 5
// test puts 配列アクセスver.

/*
 * 上記(pl5-4を配列アクセス(arr[2]のような)書き方に直そう。
 * ("*"を一度も使わずに書こう)
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = strlen(str);
    // puts(str);
    for (int i = 0; i < length; i++) {
        putchar(str[i]);
    }
    putchar('\n');
    // ここまで
    std::cout << (void*)str << " : " << length << " : " << str << std::endl;
}
#endif

#if PL_TARGET_MIN == 6
// learn How strlen

/*
 * 今度は逆にstrlenがどうやって文字列の長さを計算しているか理解しよう。
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = strlen(str);
    puts(str);
    std::cout << (void*)str << " : " << length << " : " << str[length] << std::endl;
}
#endif

#if PL_TARGET_MIN == 7
// learn How strlen

/*
 * 何も表示されなかっただろう、今度は str[length] が文字コード何番か確認してみよう。
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = strlen(str);
    puts(str);
    std::cout << (void*)str << " : " << length << " : " << (int)str[length] << std::endl;
}

/*
 * 何度やっても0になるだろう、と言うのは文字コード0の文字が文の終了ですと決められているからだ。
 */

#endif

#if PL_TARGET_MIN == 8
// example How strlen
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

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
    char str[256];
    gets(str);
    puts(str);
    visualize_memory(str, 0, 10);
}

/*
 * この文字コード0番は終端文字と言い、'\0'で表す。
 */
#endif

#if PL_TARGET_MIN == 9
// learn How strlen

/*
 * よってstrlenは文字コード0番の終端文字が出てくるまでの文字数を調べれば良いので。
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    gets(str);
    int length = 0;
    for (char* p = str; *p != '\0'; p++) length++;
    puts(str);
    std::cout << (void*)str << " : " << length << " : " << str << std::endl;
}

/*
 * こう書ける、思ったより簡単だったでしょ！
 */

#endif

#if PL_TARGET_MIN == 10
// learn c-string to int

/*
 * ここからは文字と数値の変換に触れていく。
 * 今まで std::cin, std::cout が勝手に文字列<=>数値に直してくれたが
 * 本来なら入力した文字列は文字列数値ではないし、出力した数値は文字列ではない。
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
    puts("数字を入力してね!");
    char str[20]; // long long = 19桁 => 19桁 + '\0' で20文字あれば良い、忘れがちだが'\0'の分がないとバグの元になる。
    gets(str);
    // str[19] = '\0'; これを付けることで確実にバグを防げる。
    int result = 0;
    for (char* p = str; *p != '\0'; p++) {
        result *= 10; // 今保存されてる数を10倍にして最後尾に0を付ける(例: 1234 -> 12340)
        result += *p - '0'; // 先程の0の部分に *p - '0' を足す(例: 12340 -> 12345)
    }
    std::cout << result << std::endl;
}
#endif

#if PL_TARGET_MIN == 11
// learn int to c-string

/*
 * ここからは文字と数値の変換に触れていく。
 * 今まで std::cin, std::cout が勝手に文字列<=>数値に直してくれたが
 * 本来なら入力した文字列は文字列数値ではないし、出力した数値は文字列ではない。
 */

#include <stdio.h>
#include <math.h>

int main() {
    puts("数字を二つ入力してね!");

    char a_string[20], b_string[20];

    gets(a_string);
    gets(b_string);

    long long a = 0, b = 0;

    for (char* p = a_string; *p != '\0'; p++) {
        a *= 10;
        a += *p - '0';
    }
    for (char* p = b_string; *p != '\0'; p++) {
        b *= 10;
        b += *p - '0';
    }

    long long result = a + b;
    int digit = (int)log10(result); // 10が底の対数をとりresultが何桁(digit)かを調べる。
    char result_string[20];

    result_string[digit + 1] = '\0'; // 先に終端文字をつける。
    for (char* p = result_string + digit; result_string <= p; p--) {
        *p = '0' + result % 10;
        result /= 10;
    }
    // さっきと真逆の挙動。

    puts(result_string);
}

/*
 * 次回はこのソースコードを縮める。
 */
#endif
#endif