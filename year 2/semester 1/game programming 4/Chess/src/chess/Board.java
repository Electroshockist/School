package chess;
public class Board {
    BlackPiece blackRook[] = new BlackPiece[2];
    BlackPiece blackKnight[] = new BlackPiece[2];
    BlackPiece blackBishop[] = new BlackPiece[2];
    BlackPiece blackQueen;
    BlackPiece blackKing;
    
    WhitePiece whiteRook[] = new WhitePiece[2];
    WhitePiece whiteKnight[] = new WhitePiece[2];
    WhitePiece whiteBishop[] = new WhitePiece[2];
    WhitePiece whiteQueen;
    WhitePiece whiteKing;
    
    public Board(){
        blackRook[0] = new BlackPiece(0, 7);
        blackKnight[0] = new BlackPiece(1, 7);
        blackBishop[0] = new BlackPiece(2, 7); 
        blackQueen = new BlackPiece(3, 7);
        blackKing = new BlackPiece(4,7);
        blackBishop[1] = new BlackPiece(5, 7);                
        blackKnight[1] = new BlackPiece(6, 7);
        blackRook[1] = new BlackPiece(7, 7);
        
    }    
    
    public void displayBoard(){
        boolean whiteSquare = true;
        for (boolean[] board : Coordinates.board) {
            for (int w = 0; w < board.length; w++) {
                if (whiteSquare) System.out.print("□");
                else System.out.print("■");
                whiteSquare = !whiteSquare;
            }
            System.out.println("");
        }
    }
    
}
