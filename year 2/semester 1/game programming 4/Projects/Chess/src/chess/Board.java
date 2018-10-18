package chess;
public class Board {
    BlackPiece[] blackPiece = new BlackPiece[16];
    WhitePiece[] whitePiece = new WhitePiece[16];
    public Board(){
        
        for (int i = 0; i < blackPiece.length; i++){
        }
    }
    public void setBoard(){
        //set
        for (int i = 0; i < Piece.board.length; i++){
            blackPiece[i] = new BlackPiece("pawn", i, 6);
            whitePiece[i] = new WhitePiece("pawn", i, 0);
        }
        
    }
    
    public void displayBoard(){
        System.out.println("a b c d e f g h");
        for (int i = 0; i < Piece.board.length; i++){
            System.out.println(Piece.board.length - i);
            for (int j = 0; j < Piece.board[j].length; j++){
                switch (Piece.board[i][j]){
                    case "pawn":
                        break;
                }
            }
        }
    }
    
}
