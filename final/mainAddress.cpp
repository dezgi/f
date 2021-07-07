/*
    Ezgi Diþbudak 2243400
    I read and accept the submission rules and the extra rules specified in each question.This is my own work that
    is done by myself only. */

#include <iostream>
#include "Address.h"

using std::cin;
using std::cout;
using std::cin;
using std::strcpy;
using std::strlen;

int main()
{
	//A1 1080:0012:3456:789A:0008:0800:200C:417A
	//A2 2080:00FE:3456:789A:FEDC:BA98:7654:3210

	Address a;
	Address result;
	Address addressA1;
	Address addressA2;
	Address addressA3;

	char *A1; //initialize A1
	A1 = new char[40];
	strcpy(A1, "000000000000000000000000000000000000000"); // 39 bit included ':'

	char* A2; //initialize A2
	A2 = new char[40];
	strcpy(A2, "000000000000000000000000000000000000000"); // 39 bit included ':'
	
	cout << "\nWelcome to my solution for assignment 3. \n";
	cout << "Ezgi Disbudak- 2243400";
	cout << "\n-------------------------------------";
	int check1 = 0;
	int check2 = 0;
	int c = 0;

	/*Check inputs for A1*/
	while (check1 != 1) {
		cout << "\nFor A1:\n";
		cout << "\nPlease enter Address in Hexadecimal,\nseparated with ':' every 4 digits: ";
		cin >> A1;
		if (a.Contains(A1) == 0 && strlen(A1) == 39) {
			addressA1.setHexvalue(A1);
			addressA1.HexConvertBinary(A1);
			cout << "\nSuccesfully created!\n";
			cout << "\n-------------------------------------";
			cout << "\n-------------------------------------";
			check1 = 1;
		}
		else {

			if (a.Contains(A1) == 1) {
				cout << "\n\nInvalid input! Please only use: ,0-9,A-F characters!";
			}
			if (strlen(A1) != 39) {
				cout << "\n\nInvalid input! Length of the input must be 39 characters!";
			}
			cout << "\nPlease re-enter";
		}
		
	}

	/*Check inputs for A2*/
	while (check2 != 1) {
		cout << "\n\nFor A2:\n";
		cout << "\nPlease enter Address in Hexadecimal,\nseparated with ':' every 4 digits:";
		cin >> A2;
		if (a.Contains(A2) == 0 && strlen(A2) == 39) {
			addressA2.setHexvalue(A2);
			addressA2.HexConvertBinary(A2);
			cout << "\nSuccesfully created!\n";
			cout << "\n-------------------------------------";
			cout << "\n-------------------------------------";
			check2 = 1;
		}
		else {
			if (a.Contains(A2) == 1) {
				cout << "\n\nInvalid input! Please only use: ,0-9,A-F characters!";
			}
			if (strlen(A2) != 39) {
				cout << "\n\nInvalid input! Length of the input must be 39 characters!";
			}
			cout << "\nPlease re-enter";
		}
	}


	int input = 16;
	int choice = 0;

	while (input != 0) {
		cout << "\n\na. Change first address(A1)\n";
		cout << "b. Change first address(A2)\n";
		cout << "1. Print the result of classification\n";
		cout << "2. Print TLA ID\n";
		cout << "3. Print NLA ID\n";
		cout << "4. Print SLA ID\n";
		cout << "5. Bitwise disjunctions\n";
		cout << "6. Bitwise conjunction\n";
		cout << "7. Bitwise NOR\n";
		cout << "8. Bitwise NAND\n";
		cout << "9. Bitwise XOR\n";
		cout << "10. Bitwise XNOR\n";
		cout << "11. Copy content of first address to another\n";
		cout << "12. Compare if A1 == A2\n";
		cout << "13. Compare if A1 != A2\n";
		cout << "14. Print address\n";
		cout << "15. Enter an address\n";
		cout << "0. Exit\n";
		cout << "Please select:";
		cin >> input;
		switch (input) {
		case 'a':
			break;
		case 'b':
			break;
		case 1: //do operator 1
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				~addressA1;
			}
			else {
				~addressA2;
			}
			break;
		case 2: // do operator 2
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				cout << "\nTLA ID of A1\n";
				!addressA1;
			}
			else {
				cout << "\nTLA ID of A2\n";
				!addressA2;
			}
			break;
		case 3: // do operator 3
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				cout << "\nNLA ID of A1\n";
				++addressA1;
			}
			else {
				cout << "\nNLA ID of A2\n";
				++addressA2;
			}
			break;
		case 4: // do operator 4
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				cout << "\nSLA ID of A1\n";
				&addressA1;
			}
			else {
				cout << "\nSLA ID of A2\n";
				&addressA1;
			}
			break;
		case 5: // do operator 5
			cout << "\nResult of A1 + A2";
			cout << "\n";
			result = addressA1 + addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << result.getFPBinary() << result.getTLA_IDbinary() << result.getResBinary() << result.getNLA_IDbinary() << result.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 6: // do operator 6
			cout << "\nResult of A1 * A2";
			cout << "\n";
			result = addressA1 * addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 7: // do operator 7
			cout << "\nResult of A1 - A2";
			cout << "\n";
			result = addressA1 - addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << result.getFPBinary() << result.getTLA_IDbinary() << result.getResBinary() << result.getNLA_IDbinary() << result.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 8: // do operator 8
			cout << "\nResult of A1 / A2";
			cout << "\n";
			result = addressA1 / addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << result.getFPBinary() << result.getTLA_IDbinary() << result.getResBinary() << result.getNLA_IDbinary() << result.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 9: // do operator 9
			cout << "\nResult of A1 % A2";
			cout << "\n";
			result = addressA1 % addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << result.getFPBinary() << result.getTLA_IDbinary() << result.getResBinary() << result.getNLA_IDbinary() << result.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 10: // do operator 10
			cout << "\nResult of A1 ^ A2";
			cout << "\n";
			result = addressA1 ^ addressA2;
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getFPhex() << addressA1.getTLA_IDhex() << addressA1.getReshex() << addressA1.getNLA_IDhex() << addressA1.getSLA_IDhex();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << result.getFPBinary() << result.getTLA_IDbinary() << result.getResBinary() << result.getNLA_IDbinary() << result.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << result.getInterface_IDbinary();
			break;
		case 11: // do operator 11
			cout << "\nCreating a new object (A3)";
			char* A3;
			A3 = new char[40];
			strcpy(A3, "0000:0000:0000:0000:0000:0000:0000:0000");
			addressA3.setHexvalue(A3);
			cout << "\nA3 is created.";
			cout << "\n\nContents of A3:";
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA3.getHexvalue();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << addressA3.getFPBinary() << addressA3.getTLA_IDbinary() << addressA3.getResBinary() << addressA3.getNLA_IDbinary() << addressA3.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << addressA3.getInterface_IDbinary();

			cout << "\n\n\nContents of A1:";
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getHexvalue();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << addressA1.getFPBinary() << addressA1.getTLA_IDbinary() << addressA1.getResBinary() << addressA1.getNLA_IDbinary() << addressA1.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << addressA1.getInterface_IDbinary();

			addressA3 = addressA1; //copy address of addressA1 to addressA3
			cout << "\n\n\nAfter A3 = A1";
			cout << "\n\nContents of A3:";
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA3.getHexvalue();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << addressA3.getFPBinary() << addressA3.getTLA_IDbinary() << addressA3.getResBinary() << addressA3.getNLA_IDbinary() << addressA3.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << addressA3.getInterface_IDbinary();

			cout << "\n\n\nContents of A1:";
			cout << "\n\nHexadecimal: ";
			cout << "\n" << addressA1.getHexvalue();
			cout << "\n\nBinary:";
			cout << "\nFP,TLA,Res,NLA,SLA";
			cout << "\n" << addressA1.getFPBinary() << addressA1.getTLA_IDbinary() << addressA1.getResBinary() << addressA1.getNLA_IDbinary() << addressA1.getSLA_IDbinary();
			cout << "\nInterface Identifier";
			cout << "\n" << addressA1.getInterface_IDbinary();
			break;
		case 12: // do operator 12
			if (addressA1 == addressA2) {
				cout << "Result of A1 == A2: TRUE "; // same objects	
			}
			else {
				cout << "Result of A1 == A2: FALSE "; // different objects
				cout << "\nSame Sections "; // different objects
				a.same(addressA1, addressA2);
			}
			break;
		case 13: // do operator 13
			if (addressA1 != addressA2) {
				cout << "\nResult of A1 != A2: TRUE "; // different objects
				cout << "\nDifferent Sections "; // different objects
				a.differences(addressA1, addressA2);
			}
			else {
				cout << "Result of A1 != A2: FALSE "; // same objects
			}
			break;
		case 14: // do operator 14
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				operator<<(cout, addressA1);
			}
			else {
				operator<<(cout, addressA2);
			}
			break;
		case 15: // do operator 15
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			cin >> choice;
			if (choice == 1) {
				Address newAddressA1; // create new address object
				cout << "\nFor A1:\n";
				cout << "Please enter Address in Hexadecial,\nseparated with ':' every 4 digits: ";
				operator>>(cin, newAddressA1);
				cout << "\nSuccesfully created!\n";
				cout << "\n-------------------------------------";
				cout << "\n-------------------------------------";
				cout << "\nHexadecimal: " << newAddressA1.getHexvalue();
				newAddressA1.HexConvertBinary(newAddressA1.getHexvalue());
				cout << "Binary:" << newAddressA1.getBinaryValue();
			}
			else {

				Address newAddressA2;
				cout << "\n\nFor A2:\n";
				cout << "\nPlease enter Address in Hexadecimal,\nseparated with ':' every 4 digits:";
				operator>>(cin, newAddressA2);
				cout << "\nSuccesfully created!\n";
				cout << "\n-------------------------------------";
				cout << "\n-------------------------------------";
				cout << "\nHexadecimal: " << newAddressA2.getHexvalue();
				newAddressA2.HexConvertBinary(newAddressA2.getHexvalue());
				cout << "\n\nBinary: " << newAddressA2.getBinaryValue();
			}
			break;
		default:
			cout << "You entered wrong number.\nPlease try again!!!";
			break;
		}
	}

	return 0;
}






