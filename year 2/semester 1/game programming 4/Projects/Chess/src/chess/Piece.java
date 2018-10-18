package chess;
public abstract class Piece implements Coordinates{      
    //piece position
    public int x; 
    public int y;
    //piece type and team
    public String type, team;
    
    public Boolean canMoveTo(int x_, int y_){
        if (board[y][x] != null) return true;
        else return false;
    }
    public void moveTO(int x, int y){
        if (canMoveTo(x, y)){
            //update position
            board[this.x][this.y] = null;
            board[x][y] = type;
            this.x = x;
            this.y = y;
        }
    }
}
