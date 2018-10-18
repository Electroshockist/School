package chess;
public class WhitePiece extends Piece {    
    WhitePiece(String type, int x, int y){
        team = "White";
        Piece.board[x][y] = type;
    }
}
