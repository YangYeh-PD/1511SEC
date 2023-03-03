#include <iostream>
#include <bits/stdc++.h>
#include "Data.h"
using namespace std;

Data::Data() {
    setData();
}
Data::~Data() {
    cleanData();
}

void Data::setBits(int info, int row, int column) {
    (info) ? (bits[row][column] = 1) : (bits[row][column] = 0);
}
int Data::getBits(int row, int column) {
    return bits[row][column];
}

void Data::setData(void) {
    int i = 0, info;
    while (i < size) {
        if (pow_2(i)) {
            bits[i / 4][i % 4] = -1;
            ++i;
            continue;
        }
        cin >> info;
        setBits(info, i / 4, i % 4);
        ++i;
    }
}
void Data::cleanData(void) {
    for (int i = 0; i < size; ++i)
        bits[i / 4][i % 4] = 0;
}
void Data::printData(void) {
    for (int i = 0; i < size; ++i) {
        if (! (i % 4))
            cout << endl;
        cout << bits[i / 4][i % 4] << " ";
    }
    cout << endl;
}

void Data::fill_parity(void) {
    int count1;
    // 8th bit for 3rd & 4th row (9th ~ 15th bit)
    count1 = 0;
    for (int i = 1; i <= 3; i++) {
        if (bits[2][i])
            count1++;
        if (bits[3][i])
            count1++;
    }
    if (bits[3][0])
        count1++;
    (count1 % 2) ? (bits[2][0] = 1) : (bits[2][0] = 0);
    parity_bits[4] = bits[2][0];

    // 4th bit for 2nd & 4th row (5th ~ 7th & 12th ~ 15th bit)
    count1 = 0;
    for (int i = 1; i <= 3; i++) {
        if (bits[1][i])
            count1++;
        if (bits[3][i])
            count1++;
    }
    if (bits[3][0])
        count1++;
    (count1 % 2) ? (bits[1][0] = 1) : (bits[1][0] = 0);
    parity_bits[3] = bits[1][0];

    // 2nd bit for 3rd & 4th column (3rd & 6th ~ 7th & 10th ~ 11th & 14th ~ 15th bit)
    count1 = 0;
    for (int i = 1 ; i <= 3; i++) {
        if (bits[i][2])
            count1++;
        if (bits[i][3])
            count1++;
    }
    if (bits[0][3])
        count1++;
    (count1 % 2) ? (bits[0][2] = 1) : (bits[0][2] = 0);
    parity_bits[2] = bits[0][2];

    // 1st bit for 2nd & 4th column (odd bits)
    count1 = 0;
    for (int i = 1 ; i <= 3; i++) {
        if (bits[i][1])
            count1++;
        if (bits[i][3])
            count1++;
    }
    if (bits[0][3])
        count1++;
    (count1 % 2) ? (bits[0][1] = 1) : (bits[0][1] = 0);
    parity_bits[1] = bits[0][1];

    // 0th bit for all (1st ~ 15th bits)
    count1 = 0;
    for (int i = 1; i < size; i++) {
        if (bits[i / 4][i % 4])
            count1++;
    }
    (count1 % 2) ? (bits[0][0] = 1) : (bits[0][0] = 0);
    parity_bits[0] = bits[0][0];
}


bool Data::pow_2(int num) {
    if (!num)
        return true;

    return (ceil(log2(num)) == floor(log2(num))); 
}