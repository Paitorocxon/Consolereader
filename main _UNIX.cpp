//Copyright © 2018 Paitorocxon/Fabian Müller
//Consolereader

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <conio.h>
#include <ctype.h>


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


//UNIX PART
#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//=====================Here starts the normal crap-stuff
using namespace std;



	int main (int argc, char *argv[], char *envp[]) {
		if (argc < 2){
			cout << "Usage is <PATH/TO/FILE.txt>";
			exit(0);
		}
		
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
			
			
			
			cout << "Consolereader by Paitorocxon (C) 2018" << "\n";
			
			cout << "      __________." << "\n";
			cout << "     /_/-----/_/|   __" << "\n";
			cout << "     ( ( ' ' ( (| /'--'\\" << "\n";
			cout << "     (_( ' ' (_(|/.    .\\" << "\n";
			cout << "     / /=====/ /|  '||'" << "\n";
			cout << "    /_//____/_/ |   ||" << "\n";
			cout << "   (o|:.....|o) |   ||" << "\n";
			cout << "   |_|:_____|_|/'  _||_" << "\n";
			cout << "    '        '    /____\\" << "\n";



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

		gotoxy(0,0);
		if (system("CLS")) system("clear");
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
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << "     ]####| ";
				} else if (Y+xi > 9 && Y+xi < 100) {					
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << "    ]####| ";					
				} else if (Y+xi > 99 && Y+xi < 1000) {					
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << "   ]####| ";					
				} else if (Y+xi > 999 && Y+xi < 10000) {					
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << "  ]####| ";					
				} else if (Y+xi > 9999 && Y+xi < 100000) {					
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << " ]####| ";					
				} else if (Y+xi > 99999 && Y+xi < 1000000) {					
					cout << ANSI_COLOR_RED << "[" << ANSI_COLOR_CYAN << Y+xi << ANSI_COLOR_RED << "]####| ";					
				}
	
				
				
				
				//cout << "[" << Y+xi << "]|";
				for(std::string::size_type i = X; i < LINE.size(); ++i) {//For each char in LINE of FILE
					if (i >= X){
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
