#define DEBUG
#include <iostream>
#include "Data.h"
using namespace std;

void get_Error_Position(int*, int*, Data*);

int main(int argc, char *argv[]) {
	// Sender data (16 bits), Receiver noisy data (16 bits)
	// and allow user input data to Sender and Receiver
	Data Sender, Receiver;
	
	// fill in the parity bits (0 = even / 1 = odd)
	// 0th bit for all (1st ~ 15th bits)
	// 1st bit for 2nd & 4th column (odd bits)
	// 2nd bit for 3rd & 4th column (3rd & 6th ~ 7th & 10th ~ 11th & 14th ~ 15th bit)
	// 4th bit for 2nd & 4th row (5th ~ 7th & 12th ~ 15th bit)
	// 8th bit for 3rd & 4th row (9th ~ 15th bit)
	Sender.fill_parity();
	Receiver.fill_parity();

	#ifdef DEBUG
	// print out the Sender code
	// print out the Receiver code
	cout << "Sender";
	Sender.printData();
	cout << "Receiver";
	Receiver.printData();
	#endif

	get_Error_Position(Sender.parity_bits, Receiver.parity_bits, &Receiver);
	Receiver.fill_parity();
	// After Correction
	cout << "Receiver (After Correction)";
	Receiver.printData();
	return 0;

}

// Get error position and change it back
void get_Error_Position(int *Sender_Parity, int *Receiver_Parity, Data *Receiver) {
	int error_bit[4][4];
	// Initialization
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			error_bit[i][j] = 1;
	}
	error_bit[0][0] = 0;

	// Check 1st Parity_Bit
	if (Sender_Parity[1] == Receiver_Parity[1]) {
		for (int i = 0; i < 4; i++) {
			error_bit[i][1] = 0;
			error_bit[i][3] = 0;
		}
	} else {
		for (int i = 1; i < 4; i++) {
			error_bit[i][0] = 0;
			error_bit[i][2] = 0;
		}
	}
	// Check 2nd Parity_Bit
	if (Sender_Parity[2] == Receiver_Parity[2]) {
		for (int i = 0; i < 4; i++) {
			error_bit[i][2] = 0;
			error_bit[i][3] = 0;
		}
	} else {
		for (int i = 1; i < 4; i++) {
			error_bit[i][0] = 0;
			error_bit[i][1] = 0;
		}
	}
	// Check 3rd Parity_Bit
	if (Sender_Parity[3] == Receiver_Parity[3]) {
		for (int i = 0; i < 4; i++) {
			error_bit[1][i] = 0;
			error_bit[3][i] = 0;
		}
	} else {
		for (int i = 1; i < 4; i++) {
			error_bit[0][i] = 0;
			error_bit[2][i] = 0;
		}
	}
	// Check 4th Parity_Bit
	if (Sender_Parity[4] == Receiver_Parity[4]) {
		for (int i = 0; i < 4; i++) {
			error_bit[2][i] = 0;
			error_bit[3][i] = 0;
		}
	} else {
		for (int i = 1; i < 4; i++) {
			error_bit[0][i] = 0;
			error_bit[1][i] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (error_bit[i][j]) {
				cout << "The error bit is at" << endl;
				cout << "row : " << i << endl;
				cout << "col : " << j << endl;
				Receiver->setBits(!(Receiver->getBits(i, j)), i, j);
				return;
			}
		}
	}
	cout << "There is no error bit" << endl;

}