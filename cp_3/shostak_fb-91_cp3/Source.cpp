#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <cstring> 
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

void text_normalization(char character, int ANSI_CODE, string& text) {
    if (ANSI_CODE == -72 || ANSI_CODE == -88) {
        text.push_back('å');
    }
    else if (ANSI_CODE >= -64 && ANSI_CODE <= -1) {
        text.push_back(tolower(character));
    }
}

void zero_array(float(&bigram_array)[31][31]) {
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            bigram_array[i][j] = 0.0;
        }
    }
}

void bigram_freq_count(string& text, int& i, int& first_bigram_position, int& second_bigram_posotion) {
    first_bigram_position = second_bigram_posotion;
    if (text[i] == 'à') {
        second_bigram_posotion = 0;
    }
    else if (text[i] == 'á') {
        second_bigram_posotion = 1;
    }
    else if (text[i] == 'â') {
        second_bigram_posotion = 2;
    }
    else if (text[i] == 'ã') {
        second_bigram_posotion = 3;
    }
    else if (text[i] == 'ä') {
        second_bigram_posotion = 4;
    }
    else if (text[i] == 'å') {
        second_bigram_posotion = 5;
    }
    else if (text[i] == 'æ') {
        second_bigram_posotion = 6;
    }
    else if (text[i] == 'ç') {
        second_bigram_posotion = 7;
    }
    else if (text[i] == 'è') {
        second_bigram_posotion = 8;
    }
    else if (text[i] == 'é') {
        second_bigram_posotion = 9;
    }
    else if (text[i] == 'ê') {
        second_bigram_posotion = 10;
    }
    else if (text[i] == 'ë') {
        second_bigram_posotion = 11;
    }
    else if (text[i] == 'ì') {
        second_bigram_posotion = 12;
    }
    else if (text[i] == 'í') {
        second_bigram_posotion = 13;
    }
    else if (text[i] == 'î') {
        second_bigram_posotion = 14;
    }
    else if (text[i] == 'ï') {
        second_bigram_posotion = 15;
    }
    else if (text[i] == 'ð') {
        second_bigram_posotion = 16;
    }
    else if (text[i] == 'ñ') {
        second_bigram_posotion = 17;
    }
    else if (text[i] == 'ò') {
        second_bigram_posotion = 18;
    }
    else if (text[i] == 'ó') {
        second_bigram_posotion = 19;
    }
    else if (text[i] == 'ô') {
        second_bigram_posotion = 20;
    }
    else if (text[i] == 'õ') {
        second_bigram_posotion = 21;
    }
    else if (text[i] == 'ö') {
        second_bigram_posotion = 22;
    }
    else if (text[i] == '÷') {
        second_bigram_posotion = 23;
    }
    else if (text[i] == 'ø') {
        second_bigram_posotion = 24;
    }
    else if (text[i] == 'ù') {
        second_bigram_posotion = 25;
    }
    else if (text[i] == 'û') {
        second_bigram_posotion = 26;
    }
    else if (text[i] == 'ü') {
        second_bigram_posotion = 27;
    }
    else if (text[i] == 'ý') {
        second_bigram_posotion = 28;
    }
    else if (text[i] == 'þ') {
        second_bigram_posotion = 29;
    }
    else if (text[i] == 'ÿ') {
        second_bigram_posotion = 30;
    }
}

void show_bigram_freq(float(&bigram_array)[31][31], float amount) {
    ofstream file;
    file.open("Frequency of bigrams in ET.txt");
    float sum = 0;
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            file << bigram_array[i][j] / amount << "\t";
        }
        file << endl;
    }
    file.close();
}

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
}

int bigram_value_counter(string& bigram, string& alphabet) {
    int bigram_value = 0;
    for (int i = 0; i < alphabet.length(); i++) {
        if (bigram[0] == alphabet[i]) {
            bigram_value = alphabet.length() * i;
            i = alphabet.length();
        }
    }
    for (int i = 0; i < alphabet.length(); i++) {
        if (bigram[1] == alphabet[i]) {
            bigram_value += i;
            i = alphabet.length();
        }
    }
    return bigram_value;
}

void take_by_module(int& to_take, int module_to_take) {
    if (to_take < 0) {
        while (to_take < 0)
            to_take += module_to_take;
    }
    else {
        while (to_take > 0)
            to_take -= module_to_take;
        to_take += module_to_take;
    }
}

void equation(int y1, int y2, int x1, int x2, int& a, int& b) {
    int pre1 = y1 - y2;
    int pre2 = x1 - x2;
    take_by_module(pre1, 961);
    take_by_module(pre2, 961);
    a = pre1 * modInverse(pre2, 961);
    take_by_module(a, 961);
    //cout << "a=" << a << endl;
    b = y1 - x1 * a;
    take_by_module(b, 961);
    //cout << "b=" << b << endl;
}

void decryption(string& bigram, string& alphabet, string& decrypted_text, int a, int b) {
    int first_letter = 0, second_letter = 0, first_decrypted_letter = 0, second_decrypted_letter = 0, x = 0, y = 0;
    for (int i = 0; i < alphabet.length(); i++) {
        if (bigram[0] == alphabet[i]) {
            first_letter = i;
        }
        if (bigram[1] == alphabet[i]) {
            second_letter = i;
        }
    }
    x = first_letter * alphabet.length() + second_letter;
    y = (x - b) * modInverse(a, alphabet.length() * alphabet.length());
    take_by_module(y, alphabet.length() * alphabet.length());
    second_decrypted_letter = y;
    take_by_module(second_decrypted_letter, alphabet.length());
    first_decrypted_letter = (y - second_decrypted_letter) / alphabet.length();
    decrypted_text.push_back(alphabet[first_decrypted_letter]);
    decrypted_text.push_back(alphabet[second_decrypted_letter]);
}

bool check_for_noice(string& alphabet, string& decrypted_text, int& first_bigram_position, int& second_bigram_posotion, float(&bigram_array)[31][31]) {
    int freq_array[31];
    for (int i = 0; i < 31; i++)
        freq_array[i] = 0;
    zero_array(bigram_array);

    for (int i = 0; i <= decrypted_text.length() - 1; i = i + 2)
    {
        bigram_freq_count(decrypted_text, i, first_bigram_position, second_bigram_posotion);

        i++;
        bigram_freq_count(decrypted_text, i, first_bigram_position, second_bigram_posotion);
        i--;

        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }
    for (int i = 0; i < decrypted_text.length(); i++) {
        for (int j = 0; j < 31; j++) {
            if (alphabet[j] == decrypted_text[i]) {
                freq_array[j]++;
                j = 31;
            }
        }
    }
    for (int i = 0; i < 31; i++) {
        //if (i != 5) {
            if (freq_array[14] < freq_array[i])
                return false;
        //}
    }
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            //if (i != 13 && j != 14) {
                if (bigram_array[17][18] < bigram_array[i][j])
                    return false;
            //}
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    string encrypted_text, decrypted_text;
    string alphabet = "àáâãäåæçèéêëìíîïðñòóôõö÷øùüûýþÿ";
    int first_bigram_position = 0, second_bigram_posotion = 0, bigrams_amount = 0;
    char character;

    ifstream file1("Encrypted_text.txt");
    while (!file1.eof()) {
        file1.get(character);
        text_normalization(character, static_cast<int> (character), encrypted_text);
    }
    file1.close();

    float bigram_array[31][31];
    zero_array(bigram_array);
    for (int i = 0; i <= encrypted_text.length() - 1; i = i + 2)
    {
        bigram_freq_count(encrypted_text, i, first_bigram_position, second_bigram_posotion);

        i++;
        bigram_freq_count(encrypted_text, i, first_bigram_position, second_bigram_posotion);
        bigrams_amount++;
        i--;

        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }

    show_bigram_freq(bigram_array, bigrams_amount);

    int first1 = 0, first2 = 0, second1 = 0, second2 = 0, third1 = 0, third2 = 0, fourth1 = 0, fourth2 = 0, fifth1 = 0, fifth2 = 0;
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {

            if (bigram_array[i][j] >= bigram_array[first1][first2]) {
                fifth1 = fourth1;
                fifth2 = fourth2;
                fourth1 = third1;
                fourth2 = third2;
                third1 = second1;
                third2 = second2;
                second1 = first1;
                second2 = first2;
                first1 = i;
                first2 = j;
            }

            if (bigram_array[i][j] >= bigram_array[second1][second2] && bigram_array[i][j] != bigram_array[first1][first2]) {
                fifth1 = fourth1;
                fifth2 = fourth2;
                fourth1 = third1;
                fourth2 = third2;
                third1 = second1;
                third2 = second2;
                second1 = i;
                second2 = j;
            }

            if (bigram_array[i][j] >= bigram_array[third1][third2] && bigram_array[i][j] != bigram_array[first1][first2] && bigram_array[i][j] != bigram_array[second1][second2]) {
                fifth1 = fourth1;
                fifth2 = fourth2;
                fourth1 = third1;
                fourth2 = third2;
                third1 = i;
                third2 = j;
            }

            if (bigram_array[i][j] >= bigram_array[fourth1][fourth2] && bigram_array[i][j] != bigram_array[first1][first2] && bigram_array[i][j] != bigram_array[second1][second2] && bigram_array[i][j] != bigram_array[third1][third2]) {
                fifth1 = fourth1;
                fifth2 = fourth2;
                fourth1 = i;
                fourth2 = j;
            }

            if (bigram_array[i][j] >= bigram_array[fifth1][fifth2] && bigram_array[i][j] != bigram_array[first1][first2] && bigram_array[i][j] != bigram_array[second1][second2] && bigram_array[i][j] != bigram_array[third1][third2] && bigram_array[i][j] != bigram_array[fourth1][fourth2]) {
                fifth1 = i;
                fifth2 = j;
            }
        }
    }

    string the_most_frequent_bigram_here1, the_most_frequent_bigram_here2, the_most_frequent_bigram_here3, the_most_frequent_bigram_here4, the_most_frequent_bigram_here5;
    the_most_frequent_bigram_here1.push_back(alphabet[first1]);
    the_most_frequent_bigram_here1.push_back(alphabet[first2]);
    the_most_frequent_bigram_here2.push_back(alphabet[second1]);
    the_most_frequent_bigram_here2.push_back(alphabet[second2]);
    the_most_frequent_bigram_here3.push_back(alphabet[third1]);
    the_most_frequent_bigram_here3.push_back(alphabet[third2]);
    the_most_frequent_bigram_here4.push_back(alphabet[fourth1]);
    the_most_frequent_bigram_here4.push_back(alphabet[fourth2]);
    the_most_frequent_bigram_here5.push_back(alphabet[fifth1]);
    the_most_frequent_bigram_here5.push_back(alphabet[fifth2]);
    cout << "The most frequent bigrams:\n";
    cout << "array[" << first1 << "][" << first2 << "] = " << bigram_array[first1][first2] << " - > " << the_most_frequent_bigram_here1 << endl;
    cout << "array[" << second1 << "][" << second2 << "] = " << bigram_array[second1][second2] << " - > " << the_most_frequent_bigram_here2 << endl;
    cout << "array[" << third1 << "][" << third2 << "] = " << bigram_array[third1][third2] << " - > " << the_most_frequent_bigram_here3 << endl;
    cout << "array[" << fourth1 << "][" << fourth2 << "] = " << bigram_array[fourth1][fourth2] << " - > " << the_most_frequent_bigram_here4 << endl;
    cout << "array[" << fifth1 << "][" << fifth2 << "] = " << bigram_array[fifth1][fifth2] << " - > " << the_most_frequent_bigram_here5 << endl;

    string bigram_array2[5] = { the_most_frequent_bigram_here1,  the_most_frequent_bigram_here2, the_most_frequent_bigram_here3,the_most_frequent_bigram_here4,the_most_frequent_bigram_here5 };
    string bigram_array1[5] = { "ñò", "íî", "òî", "íà", "åí" };
    string bigram;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        if (k != l) {
                            equation(bigram_value_counter(bigram_array2[i], alphabet),
                                bigram_value_counter(bigram_array2[j], alphabet),
                                bigram_value_counter(bigram_array1[k], alphabet),
                                bigram_value_counter(bigram_array1[l], alphabet), a, b);

                            if (a != 961 && a != 155 && a != 248 && a != 124 && a != 806 && a != 868 && a != 620 && a != 713 && a != 93 && a != 837 && a != 341) {
                                for (int q = 0; q < encrypted_text.length(); q++) {
                                    bigram.push_back(encrypted_text[q]);
                                    q++;
                                    bigram.push_back(encrypted_text[q]);
                                    decryption(bigram, alphabet, decrypted_text, a, b);
                                    bigram.clear();
                                }
                                if (check_for_noice(alphabet, decrypted_text, first_bigram_position, second_bigram_posotion, bigram_array)) {
                                    cout << "For key(" << a << "," << b << ") — decrypted text may be not a noice: " << endl;
                                    cout << decrypted_text << endl;
                                }
                                decrypted_text.clear();
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}