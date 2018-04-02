#include <string>
#include "board.hpp"
#include <iostream>
#include <QCoreApplication>


//init the board
Board::Board(QWidget* pwindow)
{
    QString assets_path = QCoreApplication::applicationDirPath() + "/src/assets/";
    std::vector< std::vector <ChessPiece*>> chessBoard;
    chessBoard.resize(8,std::vector<ChessPiece*>(8));

    for(int i = 0; i < 8;i++){
        Pawn* tmp = new Pawn(WHITE_,position{i,1},pwindow,assets_path);
        tmp->set_image(assets_path);
        chessBoard[1][i] = tmp;
    }

    for(int i = 0; i < 8;i++){
        Pawn* tmp = new Pawn(BLACK_,position{i,6},pwindow,assets_path);
        tmp->set_image(assets_path);
        chessBoard[2][i] = tmp;
    }

    //rooks
    Rook* rook = new Rook(WHITE_,position{0,0},pwindow,assets_path);
    rook->set_image(assets_path);
    chessBoard[0][0] = rook;
    Rook* rook1 = new Rook(WHITE_,position{7,0},pwindow,assets_path);
    rook1->set_image(assets_path);
    chessBoard[7][0] = rook;
    Rook* rookb = new Rook(BLACK_,position{0,7},pwindow,assets_path);
    rookb->set_image(assets_path);
    chessBoard[0][0] = rookb;
    Rook* rookb1 = new Rook(BLACK_,position{7,7},pwindow,assets_path);
    rookb1->set_image(assets_path);
    chessBoard[7][7] = rookb1;

    // Knights
    Knight* knight = new Knight(WHITE_,position{1,0},pwindow,assets_path);
    knight->set_image(assets_path);
    chessBoard[1][0] = knight;
    Knight* knight1 = new Knight(WHITE_,position{6,0},pwindow,assets_path);
    knight1->set_image(assets_path);
    chessBoard[6][0] = knight1;
    Knight* knightb = new Knight(BLACK_,position{1,7},pwindow,assets_path);
    knightb->set_image(assets_path);
    chessBoard[1][7] = knightb;
    Knight* knightb1 = new Knight(BLACK_,position{6,7},pwindow,assets_path);
    knightb1->set_image(assets_path);
    chessBoard[6][7] = knightb1;


    Bishop* bish = new Bishop(WHITE_,position{2,0},pwindow,assets_path);
    bish->set_image(assets_path);
    chessBoard[2][0] = bish;
     Bishop* bish1 = new Bishop(WHITE_,position{5,0},pwindow,assets_path);
    bish1->set_image(assets_path);
    chessBoard[5][0] = bish1;
     Bishop* bishb = new Bishop(BLACK_,position{2,7},pwindow,assets_path);
    bishb->set_image(assets_path);
    chessBoard[2][7] = bishb;
     Bishop* bishb1 = new Bishop(BLACK_,position{5,7},pwindow,assets_path);
    bishb1->set_image(assets_path);
    chessBoard[5][7] = bishb1;

    Queen* queen = new Queen(WHITE_,position{3,0},pwindow,assets_path);
    queen->set_image(assets_path);
    chessBoard[3][0] = queen;
    Queen* queenb = new Queen(BLACK_,position{3,7},pwindow,assets_path);
    queenb->set_image(assets_path);
    chessBoard[3][7] = queenb;

    King* king = new King(WHITE_,position{4,0},pwindow,assets_path);
    king->set_image(assets_path);
    chessBoard[4][0] = king;
    King* kingb = new King(BLACK_,position{4,7},pwindow,assets_path);
    kingb->set_image(assets_path);
    chessBoard[4][7] = kingb;

}

char Board::get_position(int row, int col)
{
    return board[col][row];
}

int Board::move_piece(int row1, int col1, int row2, int col2)
{
    char piece = get_position(row1, col1);

    // std::cout << piece << std::endl;
    // no piece at original position
    if (piece == ' '){
        return 1;
    }

    // move piece and reset pieces initial position
    board[row1][col1] = ' ';
    board[row2][col2] = piece;


    return 0;

}

void Board::print_board()
{
    for(int i = 7;i>=0; i--){
         for(int j = 0;j<8; j++){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }

}

std::string Board::board_to_FEN(colour_ active_colour)
{

    int blank_count = 0; // count how many blank tiles for each row
    bool counting_blanks = false;
    std::string FEN_board;

    for(int i=0;i<8;i++) {
        counting_blanks = false;
        for(int j=0;j<8;j++) {
            if (board[i][j] == ' '){
                blank_count++;
                counting_blanks=true;
            } else { // there is a piece

                if(blank_count>=1 && counting_blanks){
                    FEN_board += std::to_string(blank_count);
                    counting_blanks = false;
                    
                }
                blank_count = 0;
                FEN_board +=  board[i][j];

            }
            
        }
        if(blank_count>0){
            FEN_board += std::to_string(blank_count);
            blank_count = 0;
        }
        FEN_board += "/";
    }

    // set active colour
    if (active_colour == WHITE_){
        FEN_board += " w";
    } else {
        FEN_board += " b";
    }
    return FEN_board;
}