//Copyright © 2018 Paitorocxon/Fabian Müller
//Consolereader

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif


#ifdef _WIN32
  #include <windows.h>
	void gotoxy( int x, int y ){
		COORD p = { x, y };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
	}
#else
  #include <unistd.h>
  #include <term.h>
	void gotoxy( int x, int y ){
		int err;
		if (!cur_term)
		  if (setupterm( NULL, STDOUT_FILENO, &err ) == ERR)
		    return;
		putp( tparm( tigetstr( "cup" ), y, x, 0, 0, 0, 0, 0, 0, 0 ) );
	}
#endif 

//=====================Here starts the normal crap-stuff
using namespace std;



	int main (int argc, char *argv[], char *envp[]) {
		if (argc < 2){
			cout << "Usage is <PATH/TO/FILE.txt>";
			exit(0);
		}
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int X = 0;
		int Y = 0;
		
		int MaxHeight = 60;
		int MaxWidth = 100;
		
		
		std::string filepath = argv[1];
		
		
		/*
		std::ifstream PAIS_FILE("C:\\Users\\Niggi Gamin'\\Desktop\\test.txt"); //Read PAIS- File with ifstream
		std::string LINE;
		for( std::string line; getline(PAIS_FILE, LINE); ){	
			cout << "Line is '" << LINE << "'" << "\n";
			
			for(std::string::size_type i = 0; i < LINE.size(); ++i) {
			    cout << LINE[i]  << "\n";
			}
		}
		*/
		int ch;
		
		_cputs( "Type 'Y' when finished typing keys: " );
		do
		{
		ch = _getch();
		ch = toupper( ch );
		if (ch == 'W'){
			if (Y != 0){
				Y--;
			}
		}else if (ch == 'A'){
			if (X != 0){
				X--;
			}
		}else if (ch == 'S') {
				Y++;
		}else if (ch == 'D'){
				X++;
		}else if (ch == 'I'){
			if (Y-5 >= 0){
				Y-=5;
			} else {
				Y = 0;
			}
		}else if (ch == 'J'){
			if (X-5 >= 0){
				X-=5;
			} else {
				X = 0;
			}
		}else if (ch == 'K') {
				Y+=5;
		}else if (ch == 'L'){
				X+=5;
		}else if (ch == 'H'){
				
					
			gotoxy(0,0);
			if (system("CLS")) system("clear");
			
			SetConsoleTextAttribute(hConsole, 15);
			
			
			cout << "Consolereader by Paitorocxon (C) 2018" << "\n";
			
			SetConsoleTextAttribute(hConsole, 12);
			cout << "      __________." << "\n";
			cout << "     /_/-----/_/|   __" << "\n";
			cout << "     ( ( ' ' ( (| /'--'\\" << "\n";
			cout << "     (_( ' ' (_(|/.    .\\" << "\n";
			cout << "     / /=====/ /|  '||'" << "\n";
			cout << "    /_//____/_/ |   ||" << "\n";
			cout << "   (o|:.....|o) |   ||" << "\n";
			cout << "   |_|:_____|_|/'  _||_" << "\n";
			cout << "    '        '    /____\\" << "\n";


			SetConsoleTextAttribute(hConsole, 15);

			cout << "" << "\n";
			cout << "[Controls:]" << "\n";
			cout << "|    " << "\n";
			cout << "|-{Scroll]" << "\n";
			cout << "|     [W] [A] [S] [D]" << "\n";
			cout << "|     [I] [J] [K] [L] (x 5)" << "\n";
			cout << "|    " << "\n";
			cout << "|-{Scroll/Fast]" << "\n";
			cout << "|     [4] [7] = x 100   " << "\n";
			cout << "|     [5] [8] = x 500   " << "\n";
			cout << "|     [6] [9] = x 1000  " << "\n";
			cout << "|    " << "\n";
			cout << "|-{Keys]    " << "\n";
			cout << "      [X] Exit Program  " << "\n";
			cout << "      [H] Show Help (This)  " << "\n";
		

		
				getch();
				
		}else if (ch == '6'){
				Y+=1000;
		}else if (ch == '9'){
			if (Y-1000 >= 0){
				Y-=1000;
			} else {
				Y = 0;
			}
		}else if (ch == '5'){
				Y+=500;
		}else if (ch == '8'){
			if (Y-500 >= 0){
				Y-=500;
			} else {
				Y = 0;
			}
		}else if (ch == '4'){
				Y+=100;
		}else if (ch == '7'){
			if (Y-100 >= 0){
				Y-=100;
			} else {
				Y = 0;
			}
				
				
		}else if (ch == '1'){
				cout << "Maximum Height [NUMBER]:";
				cin >> MaxHeight;
				cout << "\n";
		}else if (ch == '2'){
				cout << "Maximum Weight [NUMBER]:";
				cin >> MaxWidth;
				cout << "\n";
				
				
		}else if (ch == 'X') {
			if (system("CLS")) system("clear");
			cout << "File Closed";
			exit(0);
		}

		SetConsoleTextAttribute(hConsole, 10);
		gotoxy(0,0);
		if (system("CLS")) system("clear");
		
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Consolereader by Paitorocxon (C) 2018" << "\n";
		cout << "[" << filepath << "]" << "\n";
		
		//==============================================
		std::ifstream PAIS_FILE(filepath.c_str()); //Read PAIS- File with ifstream
		std::string LINE;
		int xi = 0;
		int yi = 0;
		
		int LinesWidth = 0;
		for( std::string line; getline(PAIS_FILE, LINE);){//For each line in file
			if (yi >= Y){
				
				xi++;
				
				if (Y+xi <= 9){
					
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "     ]      ";
				} else if (Y+xi > 9 && Y+xi < 100) {
					SetConsoleTextAttribute(hConsole, 12);					
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "    ]      ";
				} else if (Y+xi > 99 && Y+xi < 1000) {	
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "   ]      ";
				} else if (Y+xi > 999 && Y+xi < 10000) {
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "  ]      ";
				} else if (Y+xi > 9999 && Y+xi < 100000) {
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << " ]      ";
				} else if (Y+xi > 99999 && Y+xi < 1000000) {
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "[";
					SetConsoleTextAttribute(hConsole, 11);
				    cout << Y+xi;
					SetConsoleTextAttribute(hConsole, 12);
				    cout << "]      ";
				}
	
				
				SetConsoleTextAttribute(hConsole, 15);
				//cout << "[" << Y+xi << "]|";
				for(std::string::size_type i = X; i < LINE.size(); ++i) {//For each char in LINE of FILE
				string TwoLineChars = "";
				string LineChar = "";
				LineChar = LINE[i];
				TwoLineChars = LINE[i];
				TwoLineChars += LINE[i+1];
					if (i >= X){
						if (LineChar == ";"){
							SetConsoleTextAttribute(hConsole, 12);
						}else if (LineChar == "'"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "\""){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "["){
							SetConsoleTextAttribute(hConsole, 13);
						}else if (LineChar == "]"){
							SetConsoleTextAttribute(hConsole, 13);
						}else if (LineChar == "("){
							SetConsoleTextAttribute(hConsole, 13);
						}else if (LineChar == ")"){
							SetConsoleTextAttribute(hConsole, 13);
						}else if (LineChar == "$"){
							SetConsoleTextAttribute(hConsole, 11);
						}else if (TwoLineChars == "//"){
							SetConsoleTextAttribute(hConsole, 11);
						}else if (LineChar == "{"){
							SetConsoleTextAttribute(hConsole, 9);
						}else if (LineChar == "}"){
							SetConsoleTextAttribute(hConsole, 9);
						}else if (LineChar == "#"){
							SetConsoleTextAttribute(hConsole, 3);
						}else if (LineChar == "="){
							SetConsoleTextAttribute(hConsole, 12);
						}else if (TwoLineChars == "::"){
							SetConsoleTextAttribute(hConsole, 12);
						}else if (LineChar == ","){
							SetConsoleTextAttribute(hConsole, 6);
						}else if (LineChar == "."){
							SetConsoleTextAttribute(hConsole, 6);
							
							
							
							
							
							
							
						}else if (LineChar == "0"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "1"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "2"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "3"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "4"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "5"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "6"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "7"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "8"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "9"){
							SetConsoleTextAttribute(hConsole, 14);
							
							
							
							
						/*
						}else if (LineChar == "a"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "b"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "c"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "d"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "e"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "f"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "g"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "h"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "i"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "j"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "k"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "l"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "m"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "n"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "o"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "p"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "q"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "r"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "s"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "t"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "u"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "v"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "w"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "x"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "y"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "z"){
							SetConsoleTextAttribute(hConsole, 14);
							
							
							
							
							
						}else if (LineChar == "A"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "B"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "C"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "D"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "E"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "F"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "G"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "H"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "I"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "J"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "K"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "L"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "M"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "N"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "O"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "P"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "Q"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "R"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "S"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "T"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "U"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "V"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "W"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "X"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "Y"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "Z"){
							SetConsoleTextAttribute(hConsole, 14);
	
						*/
						} else  if (TwoLineChars == "  "){
							SetConsoleTextAttribute(hConsole, 15);
						}
				    	cout << LINE[i];
				    	LinesWidth++;
					}
				    if (LinesWidth >= MaxWidth){
						break;
					}
				}
				LinesWidth = 0;
				
				cout << " " << "\n";
				if (xi == MaxHeight){
					break;
				}
			}
			yi++;
			
		}
		//==============================================
		
		
		
		
		SetConsoleTextAttribute(hConsole, 14);
		
		cout << "[X:" << X << " Y:" << Y << " Max Line width: " << MaxWidth  << " Max Line height: " << MaxHeight << "]" << "\n";
		cout << "Control:       [W] [A] [S] [D]" << "\n";
		cout << "               [I] [J] [K] [L]" << "\n";
		cout << "               [X] - Exit Program" << "\n";
		cout << "               [1] [2] - Change Max Height/Width" << "\n";
		
		
		
		} while( ch != 'X' );
		_putch( ch );
		_putch( '\r' );    // Carriage return
		_putch( '\n' );    // Line feed  

	
		
		return 0; 
	}
