package chess;
public class BlackPiece extends Piece {
    BlackPiece(String type, int x, int y){        
        team = "Black";
        this.x = x;
        this.y = y;
        Piece.board[x][y] = true;
    }
    
}
