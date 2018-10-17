package chess;
public abstract class Piece implements Coordinates{      
    //piece position
    public int x; 
    public int y;
    //piece type and team
    public String type, team;
    
    public Boolean canMoveTo(int x_, int y_){
        return !board[y][x];
    }
    public void moveTO(int x, int y){
        if (canMoveTo(x, y)){
            //update position
            board[this.x][this.y] = false;
            board[x][y] = true;
            this.x = x;
            this.y = y;
        }
    }
}
