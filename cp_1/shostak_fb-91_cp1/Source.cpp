#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <cstring> 
#include <string>
#include <string.h>
#include <math.h>
using namespace std;


float q = 0, w = 0, e = 0, r = 0, t = 0, y = 0, u = 0, i = 0, o = 0, p = 0, a = 0, s = 0, d = 0, f = 0,
g = 0, h = 0, j = 0, k = 0, l = 0, z = 0, x = 0, c = 0, v = 0, b = 0, n = 0, m = 0, qq = 0, ww = 0, ee = 0, rr = 0, tt = 0, yy = 0, all_letters1 = 0, all_letters2 = 0, space = 0, bigrams_amount = 0;

void is_russian_with_U_0020(char character, int ANSI_CODE, string &text) {
    if (ANSI_CODE == -72 || ANSI_CODE == -88) {
        text.push_back('�');
        y++;
    }
    else if (ANSI_CODE == -6 || ANSI_CODE == -38) {
        text.push_back('�');
        ee++;
    }
    else if (ANSI_CODE >= -64 && ANSI_CODE <= -1) {
        text.push_back(tolower(character));
        if (character == '�')
            q++;
        else if (character == '�')
            w++;
        else if (character == '�')
            e++;
        else if (character =='�')
            r++;
        else if (character == '�')
            t++;
        else if (character == '�')
            y++;
        else if (character == '�')
            u++;
        else if (character == '�')
            i++;
        else if (character == '�')
            o++;
        else if (character == '�')
            p++;
        else if (character == '�')
            a++;
        else if (character == '�')
            s++;
        else if (character == '�')
            d++;
        else if (character == '�')
            f++;
        else if (character == '�')
            g++;
        else if (character == '�')
            h++;
        else if (character == '�')
            j++;
        else if (character == '�')
            k++;
        else if (character == '�')
            l++;
        else if (character == '�')
            z++;
        else if (character == '�')
            x++;
        else if (character == '�')
            c++;
        else if (character == '�')
            b++;
        else if (character == '�')
            n++;
        else if (character == '�')
            m++;
        else if (character == '�')
            qq++;
        else if (character == '�')
            ww++;
        else if (character == '�')
            ee++;
        else if (character == '�')
            rr++;
        else if (character == '�')
            tt++;
        else if (character == '�')
            yy++;
    }
    else {
        text.push_back(' ');
        space++;
    }
    all_letters1++;
}

void is_russian_without_U_0020(char character, int ANSI_CODE, string& text) {
    if (ANSI_CODE == -72 || ANSI_CODE == -88) {
        text.push_back('�');
        y++;
        all_letters1++;
    }
    else if (ANSI_CODE == -6 || ANSI_CODE == -38) {
        text.push_back('�');
        ee++;
        all_letters1++;
    }
    else if (ANSI_CODE >= -64 && ANSI_CODE <= -1) {
        text.push_back(tolower(character));
        if (character == '�')
            q++;
        else if (character == '�')
            w++;
        else if (character == '�')
            e++;
        else if (character == '�')
            r++;
        else if (character == '�')
            t++;
        else if (character == '�')
            y++;
        else if (character == '�')
            u++;
        else if (character == '�')
            i++;
        else if (character == '�')
            o++;
        else if (character == '�')
            p++;
        else if (character == '�')
            a++;
        else if (character == '�')
            s++;
        else if (character == '�')
            d++;
        else if (character == '�')
            f++;
        else if (character == '�')
            g++;
        else if (character == '�')
            h++;
        else if (character == '�')
            j++;
        else if (character == '�')
            k++;
        else if (character == '�')
            l++;
        else if (character == '�')
            z++;
        else if (character == '�')
            x++;
        else if (character == '�')
            c++;
        else if (character == '�')
            b++;
        else if (character == '�')
            n++;
        else if (character == '�')
            m++;
        else if (character == '�')
            qq++;
        else if (character == '�')
            ww++;
        else if (character == '�')
            ee++;
        else if (character == '�')
            rr++;
        else if (character == '�')
            tt++;
        else if (character == '�')
            yy++;
        all_letters2++;
    }
}

void bigram_freq_count(string &text, int i, int &first_bigram_position, int& second_bigram_posotion) {
    first_bigram_position = second_bigram_posotion;
    if (text[i] == ' ') {
        second_bigram_posotion = 31;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 0;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 1;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 2;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 3;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 4;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 5;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 6;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 7;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 8;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 9;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 10;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 11;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 12;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 13;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 14;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 15;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 16;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 17;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 18;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 19;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 20;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 21;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 22;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 23;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 24;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 25;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 26;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 27;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 28;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 29;
    }
    else if (text[i] == '�') {
        second_bigram_posotion = 30;
    }
    bigrams_amount++;
    if (i % 2 == 0) {
        bigram_freq_count(text, i + 1, first_bigram_position, second_bigram_posotion);
    }
}

void zero_array(float(&bigram_array)[32][32]) {
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 31; j++) {
            bigram_array[i][j] = 0.0;
        }
    }
}

void show_bigram_freq(float (&bigram_array)[32][32], float amount) {
    //cout << "�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�\t\t�" << endl;
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            cout << bigram_array[i][j]/amount << "\t";
        }
        cout << endl;
    }
}

void entropy_count(float& entropy, float all_letters, bool with_space) {
    entropy = -1 *((q / all_letters) * log2(q / all_letters) +
        (w / all_letters) * log2(w / all_letters) +
        (e / all_letters) * log2(e / all_letters) +
        (r / all_letters) * log2(r / all_letters) +
        (t / all_letters) * log2(t / all_letters) +
        (y / all_letters) * log2(y / all_letters) +
        (u / all_letters) * log2(u / all_letters) +
        (i / all_letters) * log2(i / all_letters) +
        (o / all_letters) * log2(o / all_letters) +
        (p / all_letters) * log2(p / all_letters) +
        (a / all_letters) * log2(a / all_letters) +
        (s / all_letters) * log2(s / all_letters) +
        (d / all_letters) * log2(d / all_letters) +
        (f / all_letters) * log2(f / all_letters) +
        (g / all_letters) * log2(g / all_letters) +
        (h / all_letters) * log2(h / all_letters) +
        (j / all_letters) * log2(j / all_letters) +
        (k / all_letters) * log2(k / all_letters) +
        (l / all_letters) * log2(l / all_letters) +
        (z / all_letters) * log2(z / all_letters) +
        (x / all_letters) * log2(x / all_letters) +
        (c / all_letters) * log2(c / all_letters) +
        (b / all_letters) * log2(b / all_letters) +
        (n / all_letters) * log2(n / all_letters) +
        (m / all_letters) * log2(m / all_letters) +
        (qq / all_letters) * log2(qq / all_letters) +
        (ww / all_letters) * log2(ww / all_letters) +
        (ee / all_letters) * log2(ee / all_letters) +
        (rr / all_letters) * log2(rr / all_letters) +
        (tt / all_letters) * log2(tt / all_letters) +
        (yy / all_letters) * log2(yy / all_letters));
    if (with_space) {
        entropy += -1* ((space / all_letters) * log2(space / all_letters));
    }
}

void bigram_entropy_count(float(&bigram_array)[32][32], float &entropy, float all_bigrams) {
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 31; j++) {
            if (bigram_array[i][j] != 0)
                entropy -= (bigram_array[i][j]/all_bigrams)*log2(bigram_array[i][j] / all_bigrams);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream file1("X:\\Univ\\Crypto\\Lab1\\Lab1\\TEXT.txt");
    string text_with, text_without;
    char character;
    while (!file1.eof()) {
        file1.get(character);
        is_russian_with_U_0020(character, static_cast<int> (character), text_with);
    }
    cout << "Amount of symbols in file WITH U+0020: " << all_letters1 << endl;
    cout << "Frequency of letters in file WITH U+0020: " << endl << "1. � -> " << q / all_letters1 << endl <<
        "2. � -> " << w / all_letters1 << endl << "3. � -> " << e / all_letters1 << endl << "4. � -> " << r / all_letters1 << endl << "5. � -> " << t / all_letters1 << endl << "6. �+� -> " << y / all_letters1 << endl <<
        "7. � -> " << u / all_letters1 << endl << "8. � -> " << i / all_letters1 << endl << "9. � -> " << o / all_letters1 << endl << "10. � -> " << p / all_letters1 << endl << "11. � -> " << a / all_letters1 << endl <<
        "12. � -> " << s / all_letters1 << endl << "13. � -> " << d / all_letters1 << endl << "14. � -> " << f / all_letters1 << endl << "15. � -> " << g / all_letters1 << endl << "16. � -> " << h / all_letters1 << endl <<
        "17. � -> " << j / all_letters1 << endl << "18. � -> " << k / all_letters1 << endl << "19. � -> " << l / all_letters1 << endl << "20. � -> " << z / all_letters1 << endl << "21. � -> " << x / all_letters1 << endl <<
        "22. � -> " << c / all_letters1 << endl << "23. � -> " << b / all_letters1 << endl << "24. � -> " << n / all_letters1 << endl << "25. � -> " << m / all_letters1 << endl << "26. � -> " << qq / all_letters1 << endl <<
        "27. � -> " << ww / all_letters1 << endl << "28. �+� -> " << ee / all_letters1 << endl << "29. � -> " << rr / all_letters1 << endl << "30. � -> " << tt / all_letters1 << endl << "31. � -> " << yy / all_letters1 << endl <<
        "and 'space' - " << space / all_letters1 << endl << endl;
    file1.close();

    float entropy = 0.0;
    entropy_count(entropy, all_letters1, true);
    cout << "Entrophy for text with U+0020 = " << entropy << endl << endl;
    entropy = 0.0;
    
    float bigram_array[32][32];
    zero_array(bigram_array);
    int first_bigram_position = 0, second_bigram_posotion = 0;

    for (int i = 0; i <= all_letters1 - 1; i++)
    {
        bigram_freq_count(text_with, i, first_bigram_position, second_bigram_posotion);
        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }
    cout << "Bigram frequency for text WITH U+0020 with step 1 -> " << endl;
    show_bigram_freq(bigram_array, bigrams_amount);
    bigram_entropy_count(bigram_array, entropy, bigrams_amount);
    bigrams_amount = 0;
    cout << "Entropy for bigrams for text WITH U+0020 with step 1 -> " << entropy << endl << endl << endl;
    entropy = 0.0;

    zero_array(bigram_array);
    for (int i = 0; i <= all_letters1 - 1; i = i + 2)
    {
        bigram_freq_count(text_with, i, first_bigram_position, second_bigram_posotion);
        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }
    cout << "Bigram frequency for text WITH U+0020 with step 2 -> " << endl;
    show_bigram_freq(bigram_array, bigrams_amount);
    bigram_entropy_count(bigram_array, entropy, bigrams_amount);
    bigrams_amount = 0;
    cout << "Entropy for bigrams for text WITH U+0020 with step 2 -> " << entropy << endl << endl << endl;
    entropy = 0.0;

    q = 0, w = 0, e = 0, r = 0, t = 0, y = 0, u = 0, i = 0, o = 0, p = 0, a = 0, s = 0, d = 0, f = 0,
        g = 0, h = 0, j = 0, k = 0, l = 0, z = 0, x = 0, c = 0, v = 0, b = 0, n = 0, m = 0, qq = 0,
        ww = 0, ee = 0, rr = 0, tt = 0, yy = 0, space = 0;

    ifstream file1_1("X:\\Univ\\Crypto\\Lab1\\Lab1\\TEXT.txt");
    while (!file1_1.eof()) {
        file1_1.get(character);
        is_russian_without_U_0020(character, static_cast<int> (character), text_without);
    }
    file1_1.close();

    cout << endl << endl;
    cout << "Amount of symbols in file WITHOUT U+0020: " << all_letters2 << endl;
    cout << "Frequency of letters in file WITHOUT U+0020: " << endl << "1. � -> " << q / all_letters2 << endl <<
        "2. � -> " << w / all_letters2 << endl << "3. � -> " << e / all_letters2 << endl << "4. � -> " << r / all_letters2 << endl << "5. � -> " << t / all_letters2 << endl << "6. �+� -> " << y / all_letters2 << endl <<
        "7. � -> " << u / all_letters2 << endl << "8. � -> " << i / all_letters2 << endl << "9. � -> " << o / all_letters2 << endl << "10. � -> " << p / all_letters2 << endl << "11. � -> " << a / all_letters2 << endl <<
        "12. � -> " << s / all_letters2 << endl << "13. � -> " << d / all_letters2 << endl << "14. � -> " << f / all_letters2 << endl << "15. � -> " << g / all_letters2 << endl << "16. � -> " << h / all_letters2 << endl <<
        "17. � -> " << j / all_letters2 << endl << "18. � -> " << k / all_letters2 << endl << "19. � -> " << l / all_letters2 << endl << "20. � -> " << z / all_letters2 << endl << "21. � -> " << x / all_letters2 << endl <<
        "22. � -> " << c / all_letters2 << endl << "23. � -> " << b / all_letters2 << endl << "24. � -> " << n / all_letters2 << endl << "25. � -> " << m / all_letters2 << endl << "26. � -> " << qq / all_letters2 << endl <<
        "27. � -> " << ww / all_letters2 << endl << "28. �+� -> " << ee / all_letters2 << endl << "29. � -> " << rr / all_letters2 << endl << "30. � -> " << tt / all_letters2 << endl << "31. � -> " << yy / all_letters2 << endl << endl;

    entropy_count(entropy, all_letters2, false);
    cout << "Entrophy for text without U+0020 = " << entropy << endl << endl;
    entropy = 0.0;

    zero_array(bigram_array);
    first_bigram_position = 0, second_bigram_posotion = 0;
    for (int i = 0; i <= all_letters2 - 1; i++)
    {
        bigram_freq_count(text_without, i, first_bigram_position, second_bigram_posotion);
        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }
    cout << "Bigram frequency for text WITHOUT U+0020 with step 1 -> " << endl;
    show_bigram_freq(bigram_array, bigrams_amount);
    bigram_entropy_count(bigram_array, entropy, bigrams_amount);
    cout << "Entropy for bigrams for text WITHOUT U+0020 with step 1 -> " << entropy << endl << endl << endl;
    entropy = 0.0;
    bigrams_amount = 0;


    zero_array(bigram_array);
    first_bigram_position = 0, second_bigram_posotion = 0;
    for (int i = 0; i <= all_letters2 - 1; i = i + 2)
    {
        bigram_freq_count(text_without, i, first_bigram_position, second_bigram_posotion);
        bigram_array[first_bigram_position][second_bigram_posotion]++;
    }
    cout << "Bigram frequency for text WITHOUT U+0020 with step 2: " << endl;
    show_bigram_freq(bigram_array, bigrams_amount);

    bigram_entropy_count(bigram_array, entropy, bigrams_amount);
    cout << "Entropy for bigrams for text WITHOUT U+0020 with step 2 -> " << entropy << endl<< endl << endl;
    entropy = 0.0;
    bigrams_amount = 0;

    ofstream file2;
    file2.open("X:\\Univ\\Crypto\\Lab1\\Lab1\\SORTED_TEXT.txt");
    file2 << text_without;
    file2.close();

    file2.open("X:\\Univ\\Crypto\\Lab1\\Lab1\\SORTED_TEXT_WITH_U+0020.txt");
    file2 << text_with;
    file2.close();

    return 0;
}