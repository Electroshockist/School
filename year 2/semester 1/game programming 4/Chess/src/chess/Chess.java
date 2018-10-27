package chess;
public class Chess {
    
    Board board = new Board();
    WhitePiece white = new WhitePiece(0, 0);
    
    public static void main(String[] args) {
        Board.displayBoard();
    }
    
}
