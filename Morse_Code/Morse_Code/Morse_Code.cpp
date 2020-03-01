#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* morse[55] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..." };
const char* ascii[55] = { "A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS" };
int spaces(const char* morse_code, int* idx);
char trans(const char* temp);
char* decode_morse(const char* morse_code)
{
	char* result = (char*)malloc(256 * sizeof(char));
	if( !result )
	{
		return 0;
	}
	
	char temp[32] = {};
	int i = 0;
	int k = 0;
	int j = 0;
	int z = 0;
	spaces(morse_code, &i);

	while( morse_code[i] != '\0' )
	{
		j = 0;
		while( !( k = spaces(morse_code, &i) ) && morse_code[i] != 0 )
		{
			temp[j] = morse_code[i];
			j++;
			i++;
		}
		temp[j] = '\0';
		if( trans(temp) != 1 )
			result[z++] = trans(temp);
		else
		{
			result[z++] = 'S';
			result[z++] = 'O';
			result[z++] = 'S';
		}
		if( k == 3 )
			result[z++] = ' ';
	}
	if( k == 3 )
		result[--z] = '\0';

	return result;
	free(result);
}

int spaces(const char* morse_code, int* idx)
{
	int count = 0;

	while( morse_code[*idx] == ' ' )
	{

		( *idx )++;
		count++;
	}

	return count;
}

char trans(const char* temp)
{
	int i = 0;
	for( ; i < 55; i++ )
		if( !( strcmp(temp, morse[i]) ) ) {
			if( i != 54 ) {
				return *ascii[i];
			}
			else
				return 1;
		}

	return 0;
}