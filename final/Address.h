#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>

using std::cin;
using std::cout;
using std::cin;
using std::strcpy;
using std::ostream;
using std::istream;

class Address
{
private:

	char *binaryvalue; // binary value of the address object
	char *hexvalue;   // hex value of the address object 

	char* FPbinary; // 3 bit Format Prefix for classification
	char *FPhex; 

	char *TLA_IDbinary; // 13 bits Top - Level Aggregation Identifier
	char *TLA_IDhex; 

	char *Resbinary; // 8 bits for Reserved field
	char* Reshex; 

	char *NLA_IDbinary; // 24 bits for Next-Level Aggregation Identifier
	char* NLA_IDhex; 

	char *SLA_IDbinary; // 16 bits for  Site Level Aggregation Identifier
	char* SLA_IDhex; 

	char *Interface_IDbinary; // 64 bits for s Interface ID
	char* Interface_IDhex;

public:

	Address(){ // Default Constructor

		FPbinary = new char[4];
		strcpy(FPbinary, "000"); // 3 bit

		FPhex = new char[5];
		strcpy(FPhex, "0000"); // 4 bit

		TLA_IDbinary = new char[14];
		strcpy(TLA_IDbinary, "0000000000000"); // 13 bit
	    TLA_IDhex = new char[5];
		strcpy(TLA_IDhex, "0000");

		
		Resbinary = new char[9];
		strcpy(Resbinary, "00000000"); //8 bit
		Reshex = new char[3];
		strcpy(Reshex, "00");

		NLA_IDbinary = new char[25];
		strcpy(NLA_IDbinary, "000000000000000000000000"); // 24 bit
		NLA_IDhex = new char[7];
		strcpy(NLA_IDhex, "000000");

		
		SLA_IDbinary = new char[17];
		strcpy(SLA_IDbinary, "0000000000000000"); // 16 bit
		SLA_IDhex = new char[7];
		strcpy(SLA_IDhex, "000000");

		Interface_IDbinary = new char[65];
		strcpy(Interface_IDbinary, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit
		Interface_IDhex = new char[20];
		strcpy(Interface_IDhex, "0000000000000000000");
		
		binaryvalue = new char[129];
		strcpy(binaryvalue, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		
		hexvalue = new char[40];
		strcpy(hexvalue, "0000:0000:0000:0000:0000:0000:0000:0000");
	}

	/*Operator 1*/
	void operator~() { 
		
		/*Check the input is Anycast or not*/
		if ((binaryvalue[0] == '0' && binaryvalue[1] == '0' && binaryvalue[2] == '0') && 
				(BinaryConvertDecimal(FPbinary) == 0  || BinaryConvertDecimal(FPbinary) == 2
				|| BinaryConvertDecimal(FPbinary) == 3  || BinaryConvertDecimal(FPbinary) == 4)) {
			cout << "Classification is Anycast.";
		}

		/*Check the input is Unicast or not*/
		if ((binaryvalue[0] == '0' && binaryvalue[1] == '0' && binaryvalue[2] == '1') && (BinaryConvertDecimal(FPbinary) == 1)) {
			cout << "Classification is Unicast.";
		}

		/*Check the input is Multicast or not*/
		if (BinaryConvertDecimal(FPbinary) > 4)  {
			cout << "Classification is Multicast.";
		}
		
	}

	/*Operator 2 , Print the TLA_ID value in terms of both hexadecimal and binary.*/
	void operator!() { //Operator 2
		cout << "\nHexadecimal: " << TLA_IDhex;
		cout << "\nBinary: " << TLA_IDbinary;
	
	}

	/*Operator 3 , Print the NLA_ID value in terms of both hexadecimal and binary.*/
	void operator++() { //Operator 3
		cout << "\nHexadecimal: " << NLA_IDhex;
		cout << "\nBinary: " << getNLA_IDbinary();;
	}

	/*Operator 4 , Print the SLA_ID value in terms of both hexadecimal and binary.*/
	void operator&() { //Operator 4
		cout << "\nHexadecimal: " << SLA_IDhex;
		cout << "\nBinary: " << SLA_IDbinary;
		
	}

	/*Operator 5 OR Operation*/
	friend Address operator+(const Address& address1, const Address& address2) { //Operator 5
		
		Address tempAddress;

		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit
		
		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while(i<64) { 
			for (int j = 0; j < 64; j++) { 
				if ((temp1[i] == '0' && temp2[j] == '0' ) ) {
					tempInterface_IDbin[c] = '0';
					c++;
					
				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '1';
					c++;
					
				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;
					
				}
				else {
					
				}
				i++;
			}
		}

		//cout << "\n"<<tempInterface_IDbin;
		//tempAddress.BinaryConvertHex(tempInterface_IDbin);

		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//cout << "\n\nFFF:" << tempAddress.getSLA_IDhex();
		//cout << "\n\n";
		return tempAddress;
		
	}

	/*Operator 6  AND Operation*/
	friend Address operator*(const Address& address1, const Address& address2) { //Operator 6


		Address tempAddress;

		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit

		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while (i < 64) {
			//cout << address1.Interface_IDbinary[i];
			for (int j = 0; j < 64; j++) {
				//cout << address2.Interface_IDbinary[i];
				if ((temp1[i] == '0' && temp2[j] == '0')) {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else {

				}
				i++;
			}
		}
		//cout << "\n" << tempInterface_IDbin;
		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//tempAddress.setInterface_IDhex();
		return tempAddress;
	}

	/*Operator 7 NOR Operation*/
	friend Address operator-(const Address& address1, const Address& address2) { //Operator 7

		Address tempAddress;
		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit

		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while (i < 64) {
			//cout << address1.Interface_IDbinary[i];
			for (int j = 0; j < 64; j++) {
				//cout << address2.Interface_IDbinary[i];
				if ((temp1[i] == '0' && temp2[j] == '0')) {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else {

				}
				i++;
			}
		}
		//cout << "\n" << tempInterface_IDbin;
		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//tempAddress.setInterface_IDhex();
		return tempAddress;
	}

	/*Operator 8 NAND Operation*/
	friend Address operator/(const Address& address1, const Address& address2) { //Operator 8

		Address tempAddress;
		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit

		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while (i < 64) {
			//cout << address1.Interface_IDbinary[i];
			for (int j = 0; j < 64; j++) {
				//cout << address2.Interface_IDbinary[i];
				if ((temp1[i] == '0' && temp2[j] == '0')) {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else {

				}
				i++;
			}
		}
		//cout << "\n" << tempInterface_IDbin;
		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//tempAddress.setInterface_IDhex();
		return tempAddress;
	}

	/*Operator 9 XOR Operation*/
	friend Address operator%(const Address& address1, const Address& address2) { //Operator 9

		Address tempAddress;
		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit

		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while (i < 64) {
			//cout << address1.Interface_IDbinary[i];
			for (int j = 0; j < 64; j++) {
				//cout << address2.Interface_IDbinary[i];
				if ((temp1[i] == '0' && temp2[j] == '0')) {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else {

				}
				i++;
			}
		}
		//cout << "\n" << tempInterface_IDbin;
		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//tempAddress.setInterface_IDhex();
		return tempAddress;
	}

	/*Operator 10 XNOR Operation*/
	friend Address operator^(const Address& address1, const Address& address2) { //Operator 10

		Address tempAddress;
		/*Set the FP ,TLA, Res, NLA and SLA values of the new object to the values of the Address1 object*/
		tempAddress.setFPBinary(address1.FPbinary);
		tempAddress.setFPhex(address1.FPhex);
		tempAddress.setTLA_IDbinary(address1.TLA_IDbinary);
		tempAddress.setTLA_IDhex(address1.TLA_IDhex);
		tempAddress.setResBinary(address1.Resbinary);
		tempAddress.setReshex(address1.Reshex);
		tempAddress.setNLA_IDbinary(address1.NLA_IDbinary);
		tempAddress.setNLA_IDhex(address1.NLA_IDhex);
		tempAddress.setSLA_IDbinary(address1.SLA_IDbinary);
		tempAddress.setSLA_IDhex(address1.SLA_IDhex);

		char* tempInterface_IDbin = new char[65];
		strcpy(tempInterface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit

		char temp1[65];
		strcpy(temp1, address1.Interface_IDbinary);

		char temp2[65];
		strcpy(temp2, address2.Interface_IDbinary);

		int c = 0;
		cout << "\n";
		int i = 0;
		while (i < 64) {
			//cout << address1.Interface_IDbinary[i];
			for (int j = 0; j < 64; j++) {
				//cout << address2.Interface_IDbinary[i];
				if ((temp1[i] == '0' && temp2[j] == '0')) {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else if (temp1[i] == '0' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '0';
					c++;
				}
				else if (temp1[i] == '1' && temp2[j] == '0') {
					tempInterface_IDbin[c] = '0';
					c++;

				}
				else if (temp1[i] == '1' && temp2[j] == '1') {
					tempInterface_IDbin[c] = '1';
					c++;

				}
				else {

				}
				i++;
			}
		}
		//cout << "\n" << tempInterface_IDbin;
		tempAddress.setInterface_IDbinary(tempInterface_IDbin);
		//tempAddress.setInterface_IDhex();
		return tempAddress;
	}

	/*Operator 11 , Copy the contents of A1 to A3*/
	Address& operator=(const Address& addressA3) {
		
		/*Copy the contents of address1 object to address3 object*/
		hexvalue = addressA3.hexvalue;
		FPbinary = addressA3.FPbinary;
		TLA_IDbinary = addressA3.TLA_IDbinary;
		NLA_IDbinary = addressA3.NLA_IDbinary;
		SLA_IDbinary = addressA3.SLA_IDbinary;
		Interface_IDbinary = addressA3.Interface_IDbinary;
		return *this;
	}

	/*Operator 12 , Compare two A1 and A2*/
	friend bool operator==(const Address& address1, const Address& address2) {
		
		char hex1[129];
		strcpy(hex1, address1.binaryvalue);
		//cout << "\n\n\n\n\nADDRES 1"<<"\n"<<temp;
		char hex2[129];
		strcpy(hex2, address2.binaryvalue);
		//cout << "\n\n\n\n\nADDRES 2" << "\n"<<temp2;
		int result = 0;
		for (int i = 0; i < 128; i++) {
			for (int j = 0; j < 128; j++) {
				if (hex1[i] != hex2[i]) return  0; //if the objects are different return 0
			}
		}
		return 1; //if the objects are same return 1
	}

	/*Operator 13 , Compare two A1 and A2*/
	friend bool operator!=(const Address& address1, const Address& address2) {

		char hex1[129];
		strcpy(hex1, address1.binaryvalue);
		//cout << "\n\n\n\n\nADDRES 1"<<"\n"<<temp;
		char hex2[129];
		strcpy(hex2, address2.binaryvalue);
		//cout << "\n\n\n\n\nADDRES 2" << "\n"<<temp2;
		int result = 0;
		for (int i = 0; i < 128; i++) {
			for (int j = 0; j < 128; j++) {
				if (hex1[i] != hex2[i]) return  1; //if the objects are different return 1.
			}
		}
		return 0; //if the objects are same return 0.

	}

	/*Operator 14, Print the address of the object*/
	friend ostream &operator<<(ostream& output,const Address& address) {
		
		output << "\n\nHexadecimal: " << address.hexvalue << "\n\nBinary:" << "\nFP,TLA,Res,NLA,SLA" << "\n" << address.FPbinary
			<< address.TLA_IDbinary << address.Resbinary << address.NLA_IDbinary << address.SLA_IDbinary << "\nInterface Identifier"<<"\n" << address.Interface_IDbinary;

		return output;
	}

	/*Operator 15 Read an address from the user */
	friend istream &operator>>(istream& input, Address &address) {

		input >> address.hexvalue;
		return input;
	 }

	/*To get differences between two objects*/
	void differences(const Address& address1, const Address& address2) {

		if ((Compare(address1.FPbinary, address2.FPbinary)) == 0) {
			cout << "\nFP";
		}
		if ((Compare(address1.NLA_IDbinary, address2.NLA_IDbinary)) == 0) {
			cout << "\nNLA";
		}
		if ((Compare(address1.TLA_IDbinary, address2.TLA_IDbinary)) == 0) {
			cout << "\nTLA";
		}
		if ((Compare(address1.Resbinary,address2.Resbinary)) == 0) { // if content of addres1 res is not equal to addres2 res then print
			cout << "\nRes";
		}
		if ((Compare(address1.SLA_IDbinary, address2.SLA_IDbinary)) == 0) {
			cout << "\nSLA";
		}
		if ((Compare(address1.Interface_IDbinary, address2.Interface_IDbinary)) == 0) {
			cout << "\nInterface";
		}
	}

	/*To get same values of two objects */
	void same(const Address& address1, const Address& address2) {

		if ((Compare(address1.FPbinary, address2.FPbinary)) == 1) {
			cout << "\nFP";
		}
		if ((Compare(address1.NLA_IDbinary, address2.NLA_IDbinary)) == 1) {
			cout << "\nNLA";
		}
		if ((Compare(address1.TLA_IDbinary, address2.TLA_IDbinary)) == 1) {
			cout << "\nTLA";
		}
		if ((Compare(address1.Resbinary, address2.Resbinary)) == 1) { 
			cout << "\nRes";
		}
		if ((Compare(address1.SLA_IDbinary, address2.SLA_IDbinary)) == 1) {
			cout << "\nSLA";
		}
		if ((Compare(address1.Interface_IDbinary, address2.Interface_IDbinary)) == 1) {
			cout << "\nInterface";
		}
	}

	/*Check if either A1 or A2 is include other than hex values for the beginning input of A1 and A2.*/
	int Contains(char *array){

		char temp[65];
		strcpy(temp, array);
		for (int i = 0; i < 64; i++) {
			if (temp[i] == 'G' || temp[i] == 'H' || temp[i] == 'I' || temp[i] == 'J' || temp[i] == 'K' || temp[i] == 'L' || temp[i] == 'M' || temp[i] == 'N' || temp[i] == 'O' || temp[i] == 'P' || temp[i] == 'R' || temp[i] == 'S' || temp[i] == 'T' || temp[i] == 'U' || temp[i] == 'V' || temp[i] == 'Y' || temp[i] == 'Z' || temp[i] == 'Q' || temp[i] == 'W')
				return 1;
		}
		return 0;
	}

	/*Compare the contents of two obects*/
	int Compare(char *x, char *y) {

		char temp[65];
		strcpy(temp, x);
	
		char temp2[65];
		strcpy(temp2, y);

		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 64; j++) {
				if (temp[i] != temp2[i])  return 0;
			}
		}
		return 1;
	}

	/*Convert the Hexadecimal value to the binary value*/
	char* HexConvertBinary(char * hex_Num) {

		char *binaryArray = new char[129];
		strcpy(binaryArray,"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		//cout << "\n\nlengthhh::" << strlen(binaryArray);
		//cout << "\n\n";
		int j = 0;
		
		for (int i = 0; i < 128; i = i + 4) {
			while (j <39) {
				if (hex_Num[j] == '0') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '1') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '2') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '3') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '4') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '5') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '6') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '7') {
					binaryArray[i] = '0';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '8') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == '9') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'A') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'B') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '0';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'C') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'D') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '0';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'E') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '0';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}
				if (hex_Num[j] == 'F') {
					binaryArray[i] = '1';
					binaryArray[i + 1] = '1';
					binaryArray[i + 2] = '1';
					binaryArray[i + 3] = '1';
					if (j == 3 || j == 8 || j == 13 || j == 18 || j == 23 || j == 28 || j == 33) j++;
					break;
				}	
			}
			j++;

		}

		setBinaryValue(binaryArray);
		//cout << getBinaryValue();
		//cout << binaryArray;

			//Set FB Value
		char* FP = new char[4];
		strcpy(FP, "000"); // 3 bit
		for (int i = 0; i < 3; i++) {
			FP[i] = binaryvalue[i];
		}
		setFPBinary(FP);
		//cout << "\nFP Binary" << FPbinary <<"\n";
		char* FPh = new char[5];
		strcpy(FPh, "0000");
		int rr = 0;
		for (int i = 0; i < 4; i++) {
			FPh[rr] = hex_Num[i];
			rr++;
		}
		setFPhex(FPh);
		//cout << "\nFP Hex" << FPh;

			//Set TLA_ Value
		char* TLA_IDbin = new char[14];
		strcpy(TLA_IDbin, "0000000000000"); // 13 bit
		int e = 0;
		for (int i = 3; i < 16; i++) {
			TLA_IDbin[e] = binaryvalue[i];
			e++;
		}
		setTLA_IDbinary(TLA_IDbin);
		//cout << "\nTLA Binary"<<TLA_IDbinary;

		char* TLA_IDh = new char[5];
		strcpy(TLA_IDh, "0000");
		int w = 0;
		for (int i = 0; i < 4; i++) {
			TLA_IDh[w] = hex_Num[i];
			w++;
		}
		setTLA_IDhex(TLA_IDh);
		//cout << "\nTLA Hex" << TLA_IDhex;


			//Set RES Value
		char* Resbin = new char[9];
		strcpy(Resbin, "00000000"); //8 bit
		int r = 0;
		for (int i = 16; i < 24; i++) { // between 16 - 23 bit(23 included) 
			Resbin[r] = binaryvalue[i];
			r++;
		}
		setResBinary(Resbin);
		//cout << "\nRes Binary"<<Resbinary;

		char* Resh = new char[3];
		strcpy(Resh, "00");
		int s = 0;
		for (int i = 4; i < 6; i++) {
			Resh[w] = hex_Num[i];
			s++;
		}
		setReshex(Resh);
		//cout << "\nRes Hex" << Reshex;
		

			//Set NLA_ID Value
		char* NLA_bin = new char[25];
		strcpy(NLA_bin, "000000000000000000000000"); // 24 bit
		int c = 0;
		for (int i = 24; i < 48; i++) { // between 24 - 47 bit(47 included)
			NLA_bin[c] = binaryvalue[i];
			c++;
		}
		setNLA_IDbinary(NLA_bin);
		//cout << "\nNLA_ID Binary" << NLA_IDbinary;

		char* NLAh = new char[7];
		strcpy(NLAh, "000000");
		int ee = 0;
		for (int i = 7; i < 14; i++) {
			NLAh[ee] = hex_Num[i];
			if (i == 8) i++;
			ee++;
		}
		//strcpy(NLAh[6], " ");
		setNLA_IDhex(NLAh);
		//cout << "\nNLA Hex" << NLA_IDhex;

			//Set SLA_ID Value
		char* SLA_bin = new char[17];
		strcpy(SLA_bin, "0000000000000000"); // 16 bit
		int c1 = 0;
		for (int i = 48; i < 64; i++) { // between 48 - 63 bit(63 included) 
			SLA_bin[c1] = binaryvalue[i];
			c1++;
		}
		setSLA_IDbinary(SLA_bin);
		//cout << "\nSLA_ID Binary" << SLA_IDbinary;

		char* SLAh = new char[5];
		strcpy(SLAh, "0000");
		int c2 = 0;
		for (int i = 15; i < 19; i++) {
			SLAh[c2] = hex_Num[i];
			//if (i == 8) i++;
			c2++;
		}
		//strcpy(NLAh[6], " ");
		setSLA_IDhex(SLAh);
		//cout << "\nSLA Hex" << SLA_IDhex;


			//Set Interface_ID Value
		char* Interface_IDbin = new char[65];
		strcpy(Interface_IDbin, "0000000000000000000000000000000000000000000000000000000000000000"); // 64 bit
		int c3 = 0;
		for (int i = 64; i < 127; i++) { // between 64 - 127 bit(127 included) 
			Interface_IDbin[c3] = binaryvalue[i];
			c3++;
		}
		setInterface_IDbinary(Interface_IDbin);
		//cout << "\nInterface_ID Binary" << Interface_IDbinary;

		char* Interface_IDh = new char[20];
		strcpy(Interface_IDh, "0000000000000000000");
		int c4 = 0;
		for (int i = 20; i < 39; i++) {
			Interface_IDh[c4] = hex_Num[i];
			//if (i == 8) i++;
			c4++;
		}
		//strcpy(NLAh[6], " ");
		setInterface_IDhex(Interface_IDh);
		//cout << "\nInterface_ID Hex" << Interface_IDhex;

		return binaryvalue;
	}

	/*Print hex array of the object*/
	void printHexArray(char* a) {
		cout << "Hexadecimal:" << "\n";
		for (int i = 0; i < 39; i++) {
			cout << a[i];
		}
	}

	/*Print binary array of the object*/
	void printBinaryArray(char *a) {
		cout << "\n\nBinary Length" << strlen(a);
		cout << "\n\n";
		cout << "Binary version:"<<"\n";
		for (int i = 0; i <128; i++) {
			cout << a[i];
		}
		
		
	}
	
	/*It converts binary value to the decimal value*/
	int BinaryConvertDecimal(char *binary_Num) {

		if (binary_Num[0] == '0' && binary_Num[1] == '0' && binary_Num[2] == '0') {
			return 0;
		}
		if (binary_Num[0] == '0' && binary_Num[1] == '0' && binary_Num[2] == '1') {
			return 1;
		}
		else if (binary_Num[0] == '0' && binary_Num[1] == '1' && binary_Num[2] == '0') {
			return 2;
		}
		else if (binary_Num[0] == '0' && binary_Num[1] == '1' && binary_Num[2] == '1') {
			return 3;
		}
		else if (binary_Num[0] == '1' && binary_Num[1] == '0' && binary_Num[2] == '0') { 
			return 4;
		}
		else {
			return 6;
		}
	}


	/*********Getter and Setter***************/
	void setFPhex(char* value) {
		this->FPhex = value;

	}
	char* getFPhex() {
		return FPhex;
	}
	void setFPBinary(char* a) {
		this->FPbinary = a;
	}
	char* getFPBinary() {
		return FPbinary;
	}

	void setTLA_IDhex(char* value) {
		this->TLA_IDhex = value;

	}
	char* getTLA_IDhex() {
		return TLA_IDhex;
	}
	void setTLA_IDbinary(char* value) {
		this->TLA_IDbinary = value;

	}	
	char* getTLA_IDbinary() {
		return TLA_IDbinary;
	}

	void setReshex(char* a) {
		this->Reshex = a;
	}
	char* getReshex() {
		return Reshex;
	}
	void setResBinary(char* a) {
		this->Resbinary = a;
	}
	char* getResBinary() {
		return Resbinary;
	}

	void setNLA_IDhex(char* value) {
		this->NLA_IDhex = value;

	}
	char* getNLA_IDhex() {
		return NLA_IDhex;
	}
	void setNLA_IDbinary(char* value) {
		this->NLA_IDbinary = value;

	}
	char* getNLA_IDbinary() {
		return NLA_IDbinary;
	}

	void setSLA_IDhex(char* value) {
		this->SLA_IDhex = value;

	}
	char* getSLA_IDhex() {
		return SLA_IDhex;
	}
	void setSLA_IDbinary(char* value) {
		this->SLA_IDbinary = value;

	}
	char* getSLA_IDbinary() {
		return SLA_IDbinary;
	}

	void setInterface_IDhex(char* value) {
		this->Interface_IDhex = value;

	}
	char* getInterface_IDhex() {
		return Interface_IDhex;
	}
	void setInterface_IDbinary(char* value) {
		this->Interface_IDbinary = value;

	}
	char* getInterface_IDbinary() {
		return Interface_IDbinary;
	}


	void setBinaryValue(char *a) {
		this->binaryvalue = a;
	}
	char* getBinaryValue() {
		return binaryvalue;
	}

	void setHexvalue(char* value) {
		this->hexvalue = value;
	}
	char* getHexvalue() {
		return hexvalue;
	}

};
#endif
