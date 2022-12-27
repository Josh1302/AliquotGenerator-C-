/**
 * This program computes the sum of all the proper divisors  of a positive integer.
   It will also determine whether two positive integers are amicable and generate a
   special sequence related to the sum of the proper divisors
 * @JoshuaUnderwood
 * <pre>
 * Date: 3/23/2022
 * CSC 1253 Project #3 Section #1<br>
 * Instructor: Dr.Duncan
 * File: AliquotGenerator.cpp
 * </pre>
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

/**
 * Computes the aliquot sum of the specified number
 * @param num an integer
 * @return the aliquot sum of the specified number
 * if it is positive; otherwise, -1;
 */
long rSigma(long num) {
	int sum=0;
	int i;
	for (i = 1; i <= num/2; ++i) {
		if (num % i == 0)
			sum += i;
	}
	return sum;
}
/**
 * Generates the string representation of a series whose terms
 * are increasing and consist of proper divisors of the specified number.
 * @param num an integer
 * @return a string representation of the series when num is
 * greater than 1, "0" when num is 1; otherwise "nan"
 */
string genRSigSeries(long num) {
	long i;
	string iStr = "1";
	for (i = 2; i < num; i++) {
		if (num % i == 0)
			iStr += (" + " + to_string(i));
	}
	return iStr;
}
/**
* Generates the aliquot sequence of a number and determines the
* length of the sequence.
* @param num an integer
* @param sequence the aliquot sequence of the specified number when
* num is positive; otherwise "nan".
* @param length the length of the aliquot sequence of the specified
* number when num is positive; otherwise 0
*/
void aliquot(long num, string& sequence, long& length){
	sequence= to_string(num);
	length=1;
	while(num>0){
	sequence+=(','+to_string(rSigma(num)));
	num=rSigma(num);
	length++;
}
	}
int main() {
	long num;
	long length;
	string sequence;
	long m,n;
	cout << "Enter a positive integer for its classification -> ";
	cin >> num;
	if (num <= 0) {
		cout << "ERROR: The input must be a postive integer." << endl;
	}
	else{
	cout << "s(" << num << ") = " << genRSigSeries(num) << " = "
					<< rSigma(num) << endl;
	if (rSigma(num) == num) {
		cout << "s(" << num << ") = " << num << endl;
		cout << num << " is a perfect number." << endl;
	} else if (rSigma(num) > num) {
		cout << "s(" << num << ") > " << num << endl;
		cout << num << " is an abundant number." << endl;
	}
	else{
		cout << "s(" << num << ") < " << num << endl;
				cout << num << " is a deficient number." << endl;
	}

	}
cout<<"Enter two positive integers -> ";
cin>>m>>n;
if(m<=0||n<=0||m==n){
	cout<<"ERROR: The inputs must be distinct positive integers."<<endl;
}
else{
if(rSigma(m)==n&&rSigma(n)==m){
cout<<"?amicable"<<"("<<m<<","<<n<<")"<<" ="<<" true "<<endl;
}
else{
	cout<<"?amicable"<<"("<<m<<","<<n<<")"<<" ="<<" false "<<endl;
}
cout << "s(" << m << ") = " << genRSigSeries(m) << " = "
					<< rSigma(m) << endl;
cout << "s(" << n << ") = " << genRSigSeries(n) << " = "
					<< rSigma(n) << endl;
}
cout<<"Enter an imperfect positive integer -> ";
cin>>num;
if(num==rSigma(num)||num<=0){
cout<<"ERROR: The input must be an imperfect positive integer."<<endl;
}
else{
	aliquot(num,sequence,length);
	cout<<"aliquot {"<<num<<"} = "<<sequence<<endl;
	cout<<"length: "<<length<<endl;
}
return 0;
}





