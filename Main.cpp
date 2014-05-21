#include "longInt.h"
#include "longInt.cpp"
int main()
{
	longInt A, B, C, D, AX, AZ;

	string a = "2222";
	string b = "99999999";
	string c = "246813575732";
	string d = "180270361023456789";
	string ax = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";
	string az = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";
	
	/*------------INITIALIZATION------------*/
	A.INITIALIZE(a);
	cout << "A initialized" << endl;
	B.INITIALIZE(b);
	cout << "B initialized" << endl;
	C.INITIALIZE(c);
	cout << "C initialized" << endl;
	D.INITIALIZE(d);
	cout << "D initialized" << endl;
	AX.INITIALIZE(ax);
	cout << "AX initialized" << endl;
	AZ.INITIALIZE(az);
	cout << "AZ initialized" << endl;
	/*------------INITIALIZATION------------*/
	
	cout << endl;
	
	/*---------------PRINTING---------------*/
	cout << "A: ";
	A.PRINT();

	cout << "B: ";
	B.PRINT();

	cout << "C: ";
	C.PRINT();

	cout << "D: ";
	D.PRINT();

	cout << "AX: ";
	AX.PRINT();

	cout << "AZ: ";
	AZ.PRINT();
	/*---------------PRINTING---------------*/

	
	cout << "---------------------------------------------------" << endl;
	
	
	/*--------------DIGIT COUNT-------------*/
	cout << "DIGIT COUNT FOR A: " << A.GETDIGITCOUNT() << endl;
	cout << "DIGIT COUNT FOR B: " << B.GETDIGITCOUNT() << endl;
	cout << "DIGIT COUNT FOR C: " << C.GETDIGITCOUNT() << endl;
	cout << "DIGIT COUNT FOR D: " << D.GETDIGITCOUNT() << endl;
	cout << "DIGIT COUNT FOR AX: " << AX.GETDIGITCOUNT() << endl;
	cout << "DIGIT COUNT FOR AZ: " << AZ.GETDIGITCOUNT() << endl;
	/*--------------DIGIT COUNT-------------*/
		
	cout << "---------------------------------------------------" << endl;
	
	/*-------------GREATER THAN------------*/
	cout << "col GREATER THAN row: " << endl;
	cout << "	A		B		C		D		AX		AZ" << endl;
	cout << "__|___________________________________________________________________________________________" << endl;
	cout << "A |	" << A.GREATERTHAN(A) << "		" << A.GREATERTHAN(B) << "		" << A.GREATERTHAN(C) << "		" << A.GREATERTHAN(D) << "		" << A.GREATERTHAN(AX) << "		" << A.GREATERTHAN(AZ)<< endl;
	cout << "B |	" << B.GREATERTHAN(A) << "		" << B.GREATERTHAN(B) << "		" << B.GREATERTHAN(C) << "		" << B.GREATERTHAN(D) << "		" << B.GREATERTHAN(AX) << "		" << B.GREATERTHAN(AZ)<< endl;
	cout << "C |	" << C.GREATERTHAN(A) << "		" << C.GREATERTHAN(B) << "		" << C.GREATERTHAN(C) << "		" << C.GREATERTHAN(D) << "		" << C.GREATERTHAN(AX) << "		" << C.GREATERTHAN(AZ)<< endl;
	cout << "D |	" << D.GREATERTHAN(A) << "		" << D.GREATERTHAN(B) << "		" << D.GREATERTHAN(C) << "		" << D.GREATERTHAN(D) << "		" << D.GREATERTHAN(AX) << "		" << D.GREATERTHAN(AZ)<< endl;
	cout << "AX|	" << AX.GREATERTHAN(A) << "		" << AX.GREATERTHAN(B) << "		" << AX.GREATERTHAN(C) << "		" << AX.GREATERTHAN(D) << "		" << AX.GREATERTHAN(AX) << "		" << AX.GREATERTHAN(AZ)<< endl;
	cout << "AZ|	" << AZ.GREATERTHAN(A) << "		" << AZ.GREATERTHAN(B) << "		" << AZ.GREATERTHAN(C) << "		" << AZ.GREATERTHAN(D) << "		" << AZ.GREATERTHAN(AX) << "		" << AZ.GREATERTHAN(AZ)<< endl;	
	/*-------------GREATER THAN------------*/
	
	cout << endl;

	/*---------------LESS THAN-------------*/
	cout << "col LESS THAN row: " << endl;
	cout << "	A		B		C		D		AX		AZ" << endl;
	cout << "__|___________________________________________________________________________________________" << endl;
	cout << "A |	" << A.LESSTHAN(A) << "		" << A.LESSTHAN(B) << "		" << A.LESSTHAN(C) << "		" << A.LESSTHAN(D) << "		" << A.LESSTHAN(AX) << "		" << A.LESSTHAN(AZ)<< endl;
	cout << "B |	" << B.LESSTHAN(A) << "		" << B.LESSTHAN(B) << "		" << B.LESSTHAN(C) << "		" << B.LESSTHAN(D) << "		" << B.LESSTHAN(AX) << "		" << B.LESSTHAN(AZ)<< endl;
	cout << "C |	" << C.LESSTHAN(A) << "		" << C.LESSTHAN(B) << "		" << C.LESSTHAN(C) << "		" << C.LESSTHAN(D) << "		" << C.LESSTHAN(AX) << "		" << C.LESSTHAN(AZ)<< endl;
	cout << "D |	" << D.LESSTHAN(A) << "		" << D.LESSTHAN(B) << "		" << D.LESSTHAN(C) << "		" << D.LESSTHAN(D) << "		" << D.LESSTHAN(AX) << "		" << D.LESSTHAN(AZ)<< endl;
	cout << "AX|	" << AX.LESSTHAN(A) << "		" << AX.LESSTHAN(B) << "		" << AX.LESSTHAN(C) << "		" << AX.LESSTHAN(D) << "		" << AX.LESSTHAN(AX) << "		" << AX.LESSTHAN(AZ)<< endl;
	cout << "AZ|	" << AZ.LESSTHAN(A) << "		" << AZ.LESSTHAN(B) << "		" << AZ.LESSTHAN(C) << "		" << AZ.LESSTHAN(D) << "		" << AZ.LESSTHAN(AX) << "		" << AZ.LESSTHAN(AZ)<< endl;	
	/*---------------LESS THAN-------------*/
	
	cout << endl;
	
	/*---------------EQUAL TO-------------*/
	cout << "col EQUAL TO row: " << endl;
	cout << "	A		B		C		D		AX		AZ" << endl;
	cout << "__|___________________________________________________________________________________________" << endl;
	cout << "A |	" << A.EQUALTO(A) << "		" << A.EQUALTO(B) << "		" << A.EQUALTO(C) << "		" << A.EQUALTO(D) << "		" << A.EQUALTO(AX) << "		" << A.EQUALTO(AZ)<< endl;
	cout << "B |	" << B.EQUALTO(A) << "		" << B.EQUALTO(B) << "		" << B.EQUALTO(C) << "		" << B.EQUALTO(D) << "		" << B.EQUALTO(AX) << "		" << B.EQUALTO(AZ)<< endl;
	cout << "C |	" << C.EQUALTO(A) << "		" << C.EQUALTO(B) << "		" << C.EQUALTO(C) << "		" << C.EQUALTO(D) << "		" << C.EQUALTO(AX) << "		" << C.EQUALTO(AZ)<< endl;
	cout << "D |	" << D.EQUALTO(A) << "		" << D.EQUALTO(B) << "		" << D.EQUALTO(C) << "		" << D.EQUALTO(D) << "		" << D.EQUALTO(AX) << "		" << D.EQUALTO(AZ)<< endl;
	cout << "AX|	" << AX.EQUALTO(A) << "		" << AX.EQUALTO(B) << "		" << AX.EQUALTO(C) << "		" << AX.EQUALTO(D) << "		" << AX.EQUALTO(AX) << "		" << AX.EQUALTO(AZ)<< endl;
	cout << "AZ|	" << AZ.EQUALTO(A) << "		" << AZ.EQUALTO(B) << "		" << AZ.EQUALTO(C) << "		" << AZ.EQUALTO(D) << "		" << AZ.EQUALTO(AX) << "		" << AZ.EQUALTO(AZ)<< endl;		
	/*---------------EQUAL TO-------------*/
	cout << "---------------------------------------------------" << endl;	
	cout << endl;
	
	
	
	longInt E = A.ADD( D );
	cout << "E = A + D = " << endl;
	E.PRINT(); cout << endl;
	
	longInt F = B.ADD( C );
	cout << "F = B + C = " << endl; 
	F.PRINT(); cout << endl;
	
	longInt G = C.ADD( D );
	cout << "G = C + D = " << endl;
	G.PRINT(); cout << endl;
	
	longInt H = E.ADD( E );
	cout << "H = E + E = " << endl;
	H.PRINT(); cout << endl;
	
	longInt I = A.ADD( E );
	cout << "I = A + E = " << endl;
	I.PRINT(); cout << endl;
	
	longInt J = B.ADD( G );
	cout << "J = B + G = " << endl;
	J.PRINT(); cout << endl;
	
	cout << "---------------------------------------------------" << endl;	
	cout << endl;
	
	//SUBTRACT
	longInt K = A.SUBTRACT( D );
	cout << "K = A - D = " << endl;
	K.PRINT(); cout << endl;
	
	longInt L = C.SUBTRACT( D );
	cout << "L = C - D = " << endl;
	L.PRINT(); cout << endl;
	
	longInt M = D.SUBTRACT( C );
	cout << "M = D - C = " << endl;
	M.PRINT(); cout << endl;
	
	longInt N = H.SUBTRACT( H );
	cout << "N = H - H = " << endl;
	N.PRINT(); cout << endl;
	
	longInt O = L.SUBTRACT( K );
	cout << "O = L - K = " << endl; 
	O.PRINT(); cout << endl;
	
	longInt P = J.SUBTRACT( M );
	cout << "P = J - M = " << endl;
	P.PRINT(); cout << endl;
	
	cout << "---------------------------------------------------" << endl;	
	cout << endl;
	
	//MULTIPLY
	longInt Q = A.MULTIPLY( D );
	cout << "Q = A * D = " << endl;
	Q.PRINT(); cout << endl;
		
	longInt R = B.MULTIPLY( C );
	cout << "R = B * C = " << endl;
	R.PRINT(); cout << endl;

	longInt S = D.MULTIPLY( D );
	cout << "S = D * D = " << endl;
	S.PRINT(); cout << endl;
	
	longInt T = K.MULTIPLY( E );
	cout << "T = K * E = " << endl;
	T.PRINT(); cout << endl;
	
	longInt U = F.MULTIPLY( L );
	cout << "U = F * L = " << endl;
	U.PRINT(); cout << endl;
	
	longInt V = I.MULTIPLY( J );
	cout << "V = I * J = " << endl;
	V.PRINT(); cout << endl;
	
	cout << "---------------------------------------------------" << endl;	
	cout << endl;
	
	//POWER!!!!!!!!!!!!!!!!!!!!
	longInt W = D.POWER( 2 );
	cout << "W = D ^ 2 = " << endl;
	W.PRINT(); cout << endl;
	
	longInt X = A.POWER( 5 );
	cout << "X = A ^ 5 = " << endl;
	X.PRINT(); cout << endl;
	
	longInt Y = B.POWER( 10 );
	cout << "Y = B ^ 10 = " << endl;
	Y.PRINT(); cout << endl;
	
	longInt Z = W.POWER( 4 );
	cout << "Z = W ^ 4 = " << endl;
	Z.PRINT(); cout << endl;
	
	longInt AA = E.POWER( 2 );
	cout << "AA = E ^ 2 = " << endl;
	AA.PRINT(); cout << endl;
	
	longInt AB = K.POWER( 2 );
	cout << "AB = K ^ 2 = " << endl;
	AB.PRINT(); cout << endl;
	
	cout << "---------------------------------------------------SKIPPING DIVIDE" << endl;	
	cout << endl;
	
	//DIVIDE	
	//TODO: FIX DIVIDE
	//TEST CASE FOR AD WILL !ONLY! WORK IF THE PREVIOUS TEST CASE (AC) IS COMMENTED OUT
	
	// longInt AC = D.DIVIDE( B );
	// cout << "AC = D / B = " << endl;
	// AC.PRINT(); cout << endl;
	
	// longInt AD = D.DIVIDE( A );
	// cout << "AD = D / A = " << endl;
	// AD.PRINT(); cout << endl;
	
	// longInt AE = Q.DIVIDE( D );
	// cout << "AE = Q / D = " << endl;
	// AE.PRINT(); cout << endl;

	// longInt AF = T.DIVIDE( K );
	// cout << "AF = T / K = " << endl;
	// AF.PRINT(); cout << endl;

	longInt AG = D.DIVIDE( E );
	cout << "AG = D / E = " << endl;
	AG.PRINT(); cout << endl;
	
	longInt AH = U.DIVIDE( U );
	cout << "AH = U / U = " << endl;
	AH.PRINT(); cout << endl;
	
	/**********WHERE SANITY GOES TO DIE**********/
	
	cout << ">--------------------------------------------<WHERE SANITY GOES TO DIE>--------------------------------------------<" << endl;
	longInt E1 = AX.MULTIPLY( AZ );
	cout << "E1 = AX * AZ = " << endl;
	E1.PRINT(); cout << endl;

	longInt E2 = AX.MULTIPLY( AX );
	cout << "E2 = AX * AX = " << endl;
	E2.PRINT(); cout << endl;
	
	longInt E3 = AZ.MULTIPLY( AZ );
	cout << "E3 = AZ * AZ = " << endl;
	E3.PRINT(); cout << endl;
	
	longInt E4 = E2.MULTIPLY( E3 );
	cout << "E4 = E2 * E3 = " << endl;
	E4.PRINT(); cout << endl;	
	
	longInt E5 = AX.POWER( 10 );
	cout << "E5 = AX ^ 10 = " << endl;
	E5.PRINT(); cout << endl;	
	
	longInt E6 = AZ.POWER( 14 );
	cout << "E6 = AZ ^ 14 = " << endl;
	E6.PRINT(); cout << endl;
	
	longInt E7 = E2.POWER( 4 );
	cout << "E7 = E2 ^ 4 = " << endl;
	E7.PRINT(); cout << endl;
	
	longInt E8 = E3.POWER( 7 );
	cout << "E8 = E3 ^ 7 = " << endl;
	E8.PRINT(); cout << endl;	
	
	return 0;
}