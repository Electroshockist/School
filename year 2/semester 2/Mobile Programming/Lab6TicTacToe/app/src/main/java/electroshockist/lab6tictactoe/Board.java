package electroshockist.lab6tictactoe;

import android.content.Context;
import android.widget.Button;

public class Board {
    public boolean XTurn;

    Tile[][] grid;

    public Board(Button[][] buttons) {
        XTurn = true;

        this.grid = new Tile[3][3];

        grid[0][0] = new Tile(buttons[0][0]);
        grid[0][1] = new Tile(buttons[0][1]);
        grid[0][2] = new Tile(buttons[0][2]);
        grid[1][0] = new Tile(buttons[1][0]);
        grid[1][1] = new Tile(buttons[1][1]);
        grid[1][2] = new Tile(buttons[1][2]);
        grid[2][0] = new Tile(buttons[2][0]);
        grid[2][1] = new Tile(buttons[2][1]);
        grid[2][2] = new Tile(buttons[2][2]);
    }

    public boolean onClick(int y, int x, Context context){

        boolean returnValue = grid[y][x].onClick(XTurn, context);
        XTurn = !XTurn;

        return returnValue;
    }
}
