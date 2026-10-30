#include <bits/stdc++.h>

using namespace std;

int find_ascii(char character){
    return character;
}

void trun_notifier(bool mistrun=false, bool mispiece=false){
    if(mispiece){
        cout << "It's not your trun!!!";
    }
}

map<string, string> live_board = {
    {"A8", "r"}, {"B8", "n"}, {"C8", "b"}, {"D8", "q"}, {"E8", "k"}, {"F8", "b"}, {"G8", "n"}, {"H8", "r"},
    {"A7", "p"}, {"B7", "p"}, {"C7", "p"}, {"D7", "p"}, {"E7", "p"}, {"F7", "p"}, {"G7", "p"}, {"H7", "p"},
    {"A6", "."}, {"B6", "."}, {"C6", "."}, {"D6", "."}, {"E6", "."}, {"F6", "."}, {"G6", "."}, {"H6", "."},
    {"A5", "."}, {"B5", "."}, {"C5", "."}, {"D5", "."}, {"E5", "."}, {"F5", "."}, {"G5", "."}, {"H5", "."},
    {"A4", "."}, {"B4", "."}, {"C4", "."}, {"D4", "."}, {"E4", "."}, {"F4", "."}, {"G4", "."}, {"H4", "."},
    {"A3", "."}, {"B3", "."}, {"C3", "."}, {"D3", "."}, {"E3", "."}, {"F3", "."}, {"G3", "."}, {"H3", "."},
    {"A2", "P"}, {"B2", "P"}, {"C2", "P"}, {"D2", "P"}, {"E2", "P"}, {"F2", "P"}, {"G2", "P"}, {"H2", "P"},
    {"A1", "R"}, {"B1", "N"}, {"C1", "B"}, {"D1", "Q"}, {"E1", "K"}, {"F1", "B"}, {"G1", "N"}, {"H1", "R"}
};

string RANKS[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
string FILES[] = {"A", "B", "C", "D", "E", "F", "G", "H"};


void showBoard(){
//    cout<<"show board below" << endl;
   int cnt =0;
    for(int i=8; i>=0; i--){
        cnt++;
        for(int j=0; j<8; j++){
            string square_notation = FILES[j] + RANKS[i]; 
            string piece = live_board[square_notation];
            cout << "|" <<piece;
            
        }
        cout << "|" << endl;
    }
//    cout<< cnt << "end the board" << endl;

}



void startDialog(){
    int option_selected;
    cout << "===============================" << endl;
    cout << "| WELCOME TO THE CHESS MASTER |" << endl;
    cout << "===============================\n" << endl << endl;

    cout << "CHOOSE OPTION\n\n";
    cout << "1. New Game\n";
    cout << "2. Continue Game\n";
    cout << "3. Settings\n";
    cout << "4. Help\n\n";
    cout << "Option: ";
    cin >> option_selected;




    




}



int main(){

    
    // startDialog();

    showBoard();
    bool is_white_turn = true;
    while(true){
        string piece_square, move_square;
        cout << ((is_white_turn) ? "White's move\n" : "Black's move\n");
        cout << "Square from move: "; cin >> piece_square;
        cout << "\nSquare to move: "; cin >> move_square;
        string selected_piece = live_board[piece_square];
        int ascii_of_piece = find_ascii(selected_piece[0]);


        if(ascii_of_piece>=92 && is_white_turn) {
            cout << "Sorry it's white trun." << endl;
            continue;
        }else if(ascii_of_piece<=92 && !is_white_turn){
            cout << "Sorry it's white trun." << endl;
            continue;
        }

        if(is_white_turn || ascii_of_piece<=92){
            live_board[move_square] = selected_piece;
            live_board[piece_square] = ".";
            showBoard();
            is_white_turn = false;
        }else{
            live_board[move_square] = selected_piece;
            live_board[piece_square] = ".";
            showBoard();
            is_white_turn = true;
        }
    }


}
