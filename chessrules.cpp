#include <bits/stdc++.h>
#include <string>
using namespace std;

#define F(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define ln long long int
#define test int t; cin >> t; while (t--)
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl
#else
#define debug(x)
#endif

void _print(int a) { cerr << a << " "; }
void _print(long long a) { cerr << a << " "; }
void _print(char a) { cerr << a << " "; }
void _print(string a) { cerr << a << " "; }
void _print(bool a) { cerr << a << " "; }
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(pair<T, T> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template <class T, class V> void _print(multimap<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(unordered_set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(unordered_multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }



void clearConsole() {
    system("clear");
}



bool valid_board_move(string position){
    if(position[0]<'A' || position[0]>'H' || position[1]<'1' || position[1] > '8') return false;
    return true;
}

string emojiOfPiece(string piece_notation){

    // Adding Black Emoji for game
    if(piece_notation=="p") return "♟";
    else if(piece_notation=="n") return "♞";
    else if(piece_notation=="b") return "♝";
    else if(piece_notation=="r") return "♜";
    else if(piece_notation=="q") return "♛";
    else if(piece_notation=="k") return "♚";

    // Adding White Emoji for game
    if(piece_notation=="P") return "♙";
    else if(piece_notation=="N") return "♘";
    else if(piece_notation=="B") return "♗";
    else if(piece_notation=="R") return "♖";
    else if(piece_notation=="Q") return "♕";
    else if(piece_notation=="K") return "♔";
    
    return ".";
}

string makeUpper(string getString){
    string concatstr = "";
    for(int i=0; i<getString.size(); i++){
    
        int str = getString[i];
        if(str<92){
            concatstr+=str;
            continue;
        }
        str-=32;
        concatstr+=str;
    }

    return concatstr;
}

string intToStr(int value) {
    return string(1, static_cast<char>(value));
}


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



vector<string> filterMoveForMyPiece(vector<string> all_target_move, bool isWhite){
    vector<string> LEGALMOVE;
    for(auto i : all_target_move){
        if(live_board[i][0] == '.'){LEGALMOVE.push_back(i); continue;}
        if(isWhite && find_ascii(live_board[i][0])>=97 && find_ascii(live_board[i][0])<=122) LEGALMOVE.push_back(i);
        if(!isWhite && find_ascii(live_board[i][0])<=92 && find_ascii(live_board[i][0])>=65) LEGALMOVE.push_back(i);
    }
    return LEGALMOVE;
}

bool isPiece(string position){
    if(find_ascii(live_board[position][0])>=65 && find_ascii(live_board[position][0])<=90) return true;
    if(find_ascii(live_board[position][0])>=97 && find_ascii(live_board[position][0])<=122) return true;
    return false;
}

bool isMyPiece(string position, bool isWhite){
    if(find_ascii(live_board[position][0])>=65 && find_ascii(live_board[position][0])<=90 && isWhite) return true;
    if(find_ascii(live_board[position][0])>=97 && find_ascii(live_board[position][0])<=122 && !isWhite) return true;
    return false;
}

class PieceMove{
    public:
    vector<string> LEGALMOVE;
    vector<string> kinghtMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        string target_move="";
        vector<string> all_target_move;
        // int positionAscii = find_ascii(piece_position[0]);
        
        // Left Up
        target_move = string(1, piece_position[0]-2);
        target_move+=piece_position[1]+1;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Right Up
        target_move = string(1, piece_position[0]+2);
        target_move+=piece_position[1]+1;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Left Down
        target_move = string(1, piece_position[0]-2);
        target_move+=piece_position[1]-1;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);

        // Right Down
        target_move = string(1, piece_position[0]+2);
        target_move+=piece_position[1]-1;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Top Left
        target_move = string(1, piece_position[0]-1);
        target_move+=piece_position[1]+2;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Top Right
        target_move = string(1, piece_position[0]+1);
        target_move+=piece_position[1]+2;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Bottom Left
        target_move = string(1, piece_position[0]-1);
        target_move+=piece_position[1]-2;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        
        // Bottom Right
        target_move = string(1, piece_position[0]+1);
        target_move+=piece_position[1]-2;
        if(valid_board_move(target_move)) all_target_move.push_back(target_move);
        

        // debug(all_target_move);

        LEGALMOVE = filterMoveForMyPiece(all_target_move, isWhite);

        // debug(LEGALMOVE);
        return LEGALMOVE;
        
    }

    vector<string> bishopMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        string target_move="";
        vector<string> all_target_move;

        
        for(int i=1; i<=8; i++){
            // left Top Digonal
            target_move = piece_position[0]-i;
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=8; i++){
            // left Bottom Digonal
            target_move = piece_position[0]-i;
            target_move += piece_position[1]-i;
            // debug(isMyPiece(piece_position, isWhite));
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }
        for(int i=1; i<=8; i++){
            // Right Top Digonal
            target_move = piece_position[0]+i;
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }
        for(int i=1; i<=8; i++){
            // Right Bottom Digonal
            target_move = piece_position[0]+i;
            target_move += piece_position[1]-i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;


        }

        
        
        // debug(LEGALMOVE);
        return LEGALMOVE;
    }

    vector<string> rookMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        string target_move="";
        vector<string> all_target_move;

        
        for(int i=1; i<=8; i++){
            // Top Move
            target_move = piece_position[0];
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=8; i++){
            // Bottom Move
            target_move = piece_position[0];
            target_move += piece_position[1]-i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=8; i++){
            // Left Move
            target_move = piece_position[0]-i;
            target_move += piece_position[1];
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=8; i++){
            // Right Move
            target_move = piece_position[0]+i;
            target_move += piece_position[1];
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        // debug(LEGALMOVE);
        return LEGALMOVE;
    }

    vector<string> queenMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        vector<string> rook = rookMove(piece_position, isWhite);
        vector<string> bishop = bishopMove(piece_position, isWhite);
        rook.insert(rook.end(), bishop.begin(), bishop.end());
        LEGALMOVE = rook;
        debug(LEGALMOVE);
        return LEGALMOVE;
    }

    vector<string> kingMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        string target_move="";
        vector<string> all_target_move;

        
        for(int i=1; i<=1; i++){
            // left Top Digonal
            target_move = piece_position[0]-i;
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=1; i++){
            // left Bottom Digonal
            target_move = piece_position[0]-i;
            target_move += piece_position[1]-i;
            // debug(isMyPiece(piece_position, isWhite));
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }
        for(int i=1; i<=1; i++){
            // Right Top Digonal
            target_move = piece_position[0]+i;
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }
        for(int i=1; i<=1; i++){
            // Right Bottom Digonal
            target_move = piece_position[0]+i;
            target_move += piece_position[1]-i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;


        }

        for(int i=1; i<=1; i++){
            // Top Move
            target_move = piece_position[0];
            target_move += piece_position[1]+i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=1; i++){
            // Bottom Move
            target_move = piece_position[0];
            target_move += piece_position[1]-i;
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=1; i++){
            // Left Move
            target_move = piece_position[0]-i;
            target_move += piece_position[1];
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        for(int i=1; i<=1; i++){
            // Right Move
            target_move = piece_position[0]+i;
            target_move += piece_position[1];
            if(!valid_board_move(target_move)) break;
            if(isMyPiece(target_move, isWhite) && isPiece(target_move)) break;
            if(valid_board_move(target_move))LEGALMOVE.push_back(target_move);
            if(!isMyPiece(target_move, isWhite) && isPiece(target_move)) break;

        }

        debug(LEGALMOVE);
        return LEGALMOVE;


    }

    vector<string> pawnMove(string piece_position, bool isWhite=true){
        LEGALMOVE.clear();
        string target_move="";
        vector<string> all_target_move;

        if(isWhite){
            if(piece_position[1]=='2'){
                for(int i=1; i<=2; i++){
                    target_move = piece_position[0];
                    target_move += piece_position[1]+i;
                    if(!isPiece(target_move)) LEGALMOVE.push_back(target_move);
                    else break;
                    target_move = "";
                }              
            }else{
                target_move = piece_position[0];
                target_move += piece_position[1]+1;
                if(valid_board_move(target_move) && !isPiece(target_move)) LEGALMOVE.push_back(target_move);
                target_move = "";
            }

            // left capture
            string target1cap = "", target2cap = "";
            target1cap = piece_position[0]-1;
            target1cap += piece_position[1]+1;
            if(valid_board_move(target1cap) && isPiece(target1cap) && !isMyPiece(target1cap, isWhite)) LEGALMOVE.push_back(target1cap);

            // right capture
            target2cap = piece_position[0]+1;
            target2cap += piece_position[1]+1;
            if(valid_board_move(target2cap) && isPiece(target2cap) && !isMyPiece(target2cap, isWhite)) LEGALMOVE.push_back(target2cap);
            
        }else{

            // Black move

            if(piece_position[1]=='7'){
                for(int i=1; i<=2; i++){
                    target_move = piece_position[0];
                    target_move += piece_position[1]-i;
                    if(!isPiece(target_move)) LEGALMOVE.push_back(target_move);
                    else break;
                    target_move = "";
                }              
            }else{
                target_move = piece_position[0];
                target_move += piece_position[1]-1;
                if(valid_board_move(target_move) && !isPiece(target_move)) LEGALMOVE.push_back(target_move);
                target_move = "";
            }

            // left capture
            string target1cap = "", target2cap = "";
            target1cap = piece_position[0]-1;
            target1cap += piece_position[1]-1;
            if(valid_board_move(target1cap) && isPiece(target1cap) && !isMyPiece(target1cap, isWhite)) LEGALMOVE.push_back(target1cap);

            // right capture
            target2cap = piece_position[0]+1;
            target2cap += piece_position[1]-1;
            if(valid_board_move(target2cap) && isPiece(target2cap) && !isMyPiece(target2cap, isWhite)) LEGALMOVE.push_back(target2cap);
            
            
        }
        
       
        return LEGALMOVE;

    }


};



void showBoard(){
    for(int i=7; i>=0; i--){
        for(int j=0; j<8; j++){
            string square_notation = FILES[j] + RANKS[i]; 
            string piece = emojiOfPiece(live_board[square_notation]);
            cout << "|" <<piece;
        }
        cout << "|" << endl;
    }
//    cout<< cnt << "end the board" << endl;

}


// Not integrated yet...
// void startDialog(){
//     int option_selected;
//     cout << "===============================" << endl;
//     cout << "| WELCOME TO THE CHESS MASTER |" << endl;
//     cout << "===============================\n" << endl << endl;

//     cout << "CHOOSE OPTION\n\n";
//     cout << "1. New Game\n";
//     cout << "2. Continue Game\n";
//     cout << "3. Settings\n";
//     cout << "4. Help\n\n";
//     cout << "Option: ";
//     cin >> option_selected;




    




// }





int main(){

    cout << isMyPiece("B5", true) << endl;
    
    PieceMove LegalMove;
    // showBoard();
    bool is_white_turn = true;
    while(true){
        // clearConsole();
        // Init the variables
        string piece_square, move_square;

        // Trun Indicator
        cout << ((is_white_turn) ? "\n* White's Move *\n" : "\n* Black's Move *\n");
       
        
        // Show the board initial
        showBoard();

        // Input piece_square and destination square
        cout << "\nSquare from move: "; cin >> piece_square;
        piece_square = makeUpper(piece_square);
        // Identify the trun and restrict the user to move opponent piece
        string selected_piece = live_board[piece_square];
        int ascii_of_piece = find_ascii(selected_piece[0]);
        // Find invalid move of empty square
        if(ascii_of_piece==46){
            cout << "\n\nThe move you are trying to make is INVALID!\nPlease see and make move with existing piece square!!!" << endl;
            continue;
        }
        // Restrict logic to user move opponent piece
        if(ascii_of_piece>=92 && is_white_turn) {
            cout << "Sorry it's white trun." << endl;
            continue;
        }else if(ascii_of_piece<=92 && !is_white_turn){
            cout << "Sorry it's black trun." << endl;
            continue;
        }



        // Finding Piece legalMoves
        vector<string> moves;
        if(selected_piece=="P" || selected_piece=="p") moves = LegalMove.pawnMove(piece_square, is_white_turn);
        else if(selected_piece=="N" || selected_piece=="n") moves = LegalMove.kinghtMove(piece_square, is_white_turn);
        else if(selected_piece=="B" || selected_piece=="b") moves = LegalMove.bishopMove(piece_square, is_white_turn);
        else if(selected_piece=="Q" || selected_piece=="q") moves = LegalMove.queenMove(piece_square, is_white_turn);
        else if(selected_piece=="K" || selected_piece=="k") moves = LegalMove.kingMove(piece_square, is_white_turn);
        else if(selected_piece=="R" || selected_piece=="r") moves = LegalMove.rookMove(piece_square, is_white_turn);

        if(moves.empty()){
            cout << "The piece you selected is not have leagal moves or invilied input.";
            continue;
        } 

        // showing moves to the user to follow up
        debug(moves);


        // Talking destination square to move piece
        cout << "Square to move: "; cin >> move_square;
        // Make uppercase so it doesnot remain case sensetive
        move_square = makeUpper(move_square);




        


        // Move core logic
        if(is_white_turn || ascii_of_piece<=92){

            for(int i=0; i<=moves.size(); i++){
                if(moves[i]==move_square){
                    live_board[move_square] = selected_piece;
                    live_board[piece_square] = ".";
                    is_white_turn = false;
                }
                else if(i==moves.size()-1 && moves[i]!=move_square) cout << "The piece you are setting to move is illigal." << endl;
            }


        }else{
            for(int i=0; i<=moves.size(); i++){
                if(moves[i]==move_square){
                    live_board[move_square] = selected_piece;
                    live_board[piece_square] = ".";
                    is_white_turn = true;
                }
                else if(i==moves.size()-1 && moves[i]!=move_square) cout << "The piece you are setting to move is illigal." << endl;
            }
        }

        // Clearing the console
        // clearConsole();
    }


}
