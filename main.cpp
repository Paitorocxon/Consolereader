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


	inline bool file_exists (const std::string& name) {
	    ifstream f(name.c_str());
	    return f.good();
	}
	int main (int argc, char *argv[], char *envp[]) {
		if (argc < 2){
			cout << "Usage is <PATH/TO/FILE.txt>";
			exit(0);
		}
		if (file_exists(argv[1])){
			
		} else {
			cout << "The File you gave me '" << argv[1] << " does not exist! :/";
			exit(0);
		}
		

		
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int X = 0;
		int Y = 0;
		
		int MaxHeight = 60;
		int MaxWidth = 100;
		
		
		std::string filepath = argv[1];
		
		

		int ch;
		
		_cputs( "Press X to exit the Program! [hit any key to continue] " );
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
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "}"){
							SetConsoleTextAttribute(hConsole, 14);
						}else if (LineChar == "#"){
							SetConsoleTextAttribute(hConsole, 3);
						}else if (LineChar == "="){
							SetConsoleTextAttribute(hConsole, 12);
						}else if (TwoLineChars == "::"){
							SetConsoleTextAttribute(hConsole, 12);
						}else if (LineChar == ","){
							SetConsoleTextAttribute(hConsole, 6);
						}else if (LineChar == ","){
							SetConsoleTextAttribute(hConsole, 6);
						}else if (LineChar == "<"){
							SetConsoleTextAttribute(hConsole, 6);
						}else if (LineChar == ">"){
							SetConsoleTextAttribute(hConsole, 6);
						}else if (TwoLineChars == "/*"){
							SetConsoleTextAttribute(hConsole, 11);
							
						}else if (LineChar == "\t"){
							SetConsoleTextAttribute(hConsole, 136);
						}else if (TwoLineChars == "\v"){
							SetConsoleTextAttribute(hConsole, 136);
							
							
							
							
							
							
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
							
							
							
							
						
						}else if (TwoLineChars == " a"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " b"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " c"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " d"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " e"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " f"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " g"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " h"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " i"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " j"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " k"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " l"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " m"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " n"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " o"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " p"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " q"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " r"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " s"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " t"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " u"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " v"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " w"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " x"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " y"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " z"){
							SetConsoleTextAttribute(hConsole, 15);
							
							
							
							
							
							
						}else if (TwoLineChars == " A"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " B"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " C"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " D"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " E"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " F"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " G"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " H"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " I"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " J"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " K"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " L"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " M"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " N"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " O"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " P"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " Q"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " R"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " S"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " T"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " U"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " V"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " W"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " X"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " Y"){
							SetConsoleTextAttribute(hConsole, 15);
						}else if (TwoLineChars == " Z"){
							SetConsoleTextAttribute(hConsole, 15);
	
						
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
