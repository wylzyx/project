#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Book.h"
using namespace std;

CBook::CBook(char* cName, char* cIsbn, char* cPrice, char* cAuthor)
{
	strncpy(m_cName, cName, NUM1);
	strncpy(m_cIsbn, cIsbn, NUM1);
	strncpy(m_cPrice, cPrice, NUM2);
	strncpy(m_cAuthor, cAuthor, NUM2);
}
char* CBook::GetName()
{
	return m_cName;
}
void CBook::SetName(char* cName)
{
	strncpy(m_cName, cName, NUM1);
}
char* CBook::GetIsbn()
{
	return m_cIsbn;
}
void CBook::SetIsbn(char* cIsbn)
{
	strncpy(m_cIsbn, cIsbn, NUM1);
}
char* CBook::GetPrice()
{
	return m_cPrice;
}
void CBook::SetPrice(char* cPrice)
{
	strncpy(m_cPrice, cPrice, NUM2);
}
char* CBook::GetAuthor()
{
	return m_cAuthor;
}
void CBook::SetAuthor(char* cAuthor)
{
	strncpy(m_cAuthor, cAuthor, NUM2);
}

void CBook::WriteData()
{
	ofstream ofile;
	ofile.open("book.dat", ios::binary | ios::app);
	try
	{
		ofile.write(m_cName, NUM1);
		ofile.write(m_cIsbn, NUM1);
		ofile.write(m_cPrice, NUM2);
		ofile.write(m_cAuthor, NUM2);
	}
	catch (...)
	{
		throw "file error occurred";
		ofile.close();
	}
	ofile.close();
}
void CBook::GetBookFromFile(int iCount)
{
	char cName[NUM1];
	char cIsbn[NUM1];
	char cPrice[NUM2];
	char cAuthor[NUM2];
	ifstream ifile;
	ifile.open("book.dat", ios::binary);
	try
	{
		ifile.seekg(iCount*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
		ifile.read(cName, NUM1);
		if (ifile.tellg() > 0)
			strncpy(m_cName, cName, NUM1);
		ifile.read(cIsbn, NUM1);
		if (ifile.tellg() > 0)
			strncpy(m_cIsbn, cIsbn, NUM1);
		ifile.read(cPrice, NUM2);
		if (ifile.tellg() > 0)
			strncpy(m_cPrice, cPrice, NUM2);
		ifile.read(cAuthor, NUM2);
		if (ifile.tellg() > 0)
			strncpy(m_cAuthor, cAuthor, NUM2);
	}
	catch (...)
	{
		throw "file error occurred";
		ifile.close();
	}
	ifile.close();
}
void CBook::DeleteData(int iCount)
{
	long respos;
	int iDataCount;
	fstream file;
	fstream tmpfile;
	ofstream ofile;
	char cTempBuf[NUM1 + NUM1 + NUM2 + NUM2];
	file.open("book.dat", ios::binary | ios::in | ios::out);
}

int main()
{
	return 0;
}