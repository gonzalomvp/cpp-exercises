// practica13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"


int main()
{
	//String(const char* str = "");
	String string1("Hola mundo");

	//String(const String& str);
	String string2 = string1;

	//bool operator==(const String& other) const;
	if (string1 == string2) printf("IGUALES\n");

	//bool operator!=(const String& other) const;
	if (string1 != String()) printf("DISTINTOS\n");

	//bool operator<(const String& other) const;
	if (string1 < String("Hola mundp")) printf("MENOR\n");

	//bool operator>(const String& other) const;
	if (string1 > String("Hola mundnghgh")) printf("MAYOR\n");

	//String operator+(const String& other) const;
	printf("%s\n", (string1 + string2).ToCString());

	//String operator+(char c) const;
	printf("%s\n", (string1 + '!').ToCString());

	//String& operator=(const String& other);
	string2 = string1;
	printf("%s\n", string2.ToCString());

	//String& operator=(char c);
	string2 = 'H';
	printf("%s\n", string2.ToCString());

	//String& operator+=(const String& other);
	string2 += String("ello World");
	printf("%s\n", string2.ToCString());

	//String& operator+=(char c);
	string2 += '!';
	printf("%s\n", string2.ToCString());

	//char& operator[](unsigned int pos);
	string2[11] = '?';
	printf("%s\n", string2.ToCString());

	//const char& operator[](unsigned int pos) const;
	const String stringConst = string2;
	printf("%c\n", stringConst[11]);

	//int Length() const;
	printf("%d\n", string2.Length());

	//static String FromInt(int val);
	printf("%s\n", String::FromInt(15322).ToCString());
	
	//static String HexFromInt(int val);
	printf("%s\n", String::HexFromInt(1173182429).ToCString());

	//static String FromFloat(float val);
	printf("%s\n", String::FromFloat(327.05f).ToCString());

	//int ToInt() const;
	printf("%d\n", String("32341").ToInt());

	//float ToFloat() const;
	printf("%f\n", String("3928.553").ToFloat());

	//const char* ToCString() const;

	//String Left(int n) const;
	printf("%s\n", string1.Left(6).ToCString());
	
	//String Right(int n) const;
	printf("%s\n", string1.Right(4).ToCString());

	//String Mid(int ofs, int n) const;
	printf("%s\n", string1.Mid(2, 5).ToCString());

	//String Replace(const String& find, const String& rep) const;
	printf("%s\n", string1.Replace("mundo", "world").ToCString());

	//int Find(const String& str, int ofs) const;
	printf("%d\n", string1.Find("o", 1));
	printf("%d\n", string1.Find("o", 2));
	printf("%d\n", string1.Find("o", 10));

	//String ToUpper() const;
	printf("%s\n", string1.ToUpper().ToCString());

	//String ToLower() const;
	printf("%s\n", string1.ToLower().ToCString());

	//String LTrim() const;
	String trimTest("    Hola   Mundo  !  ");
	printf("%s.\n", trimTest.LTrim().ToCString());

	//String RTrim() const;
	printf("%s.\n", trimTest.RTrim().ToCString());

	//String Trim() const;
	printf("%s.\n", trimTest.Trim().ToCString());

	//String LSet(int len, char c) const;
	printf("%s\n", String("12345").LSet(10, 'x').ToCString());

	//String RSet(int len, char c) const;
	printf("%s\n", String("12345").RSet(10, 'x').ToCString());

	//String StripExt() const;
	String path("C:\\Users\\Gonzalo\\Desktop\\earth.jpg");
	printf("%s\n", path.StripExt().ToCString());

	//String StripDir() const;
	printf("%s\n", path.StripDir().ToCString());

	//String ExtractExt() const;
	printf("%s\n", path.ExtractExt().ToCString());

	//String ExtractDir() const;
	printf("%s\n", path.ExtractDir().ToCString());

	//static String Read(const String& filename);
	printf("%s\n", String::Read("test.txt").ToCString());

	//void Write(const String& filename, bool append = true) const;
	string1.Write("test2.txt", false);

	//String operator+(const char* str, const String& other);
	String str("hola");
	String str2 = "Hola " + str + " caracola";
	printf("%s\n", str2.ToCString());

	getchar();
    return 0;
}

