package electroshockist.lab6tictactoe;

import android.content.Context;
import android.support.annotation.NonNull;
import android.util.Log;
import android.widget.Button;

import java.util.Set;

public class Board {
    private static final String tie = "Tie";

    public boolean XTurn;

    Tile[][] grid;

    String winningSymbol;

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

        if (returnValue) XTurn = !XTurn;

        return returnValue;
    }

    //check rows
    private boolean checkRows(){
        Tile[] threeInARow;


        for (int i = 0; i < grid.length; i++){
            threeInARow = grid[i];

            if (checkThreeInARow(threeInARow)) return true;
        }
        return false;
    }

    private  boolean checkColumns(){
        Tile[] threeInARow = new Tile[3];
        //check columns
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid.length; j++){
                threeInARow[j] = grid[j][i];
            }

            if (checkThreeInARow(threeInARow)) return true;
        }
        return false;
    }

    //check forward diagonal
    private boolean checkForwardDiagonal(){
        Tile[] threeInARow = new Tile[3];
        for (int i = 0; i < grid.length; i++){
            threeInARow[i] = grid[i][i];
        }

        return checkThreeInARow(threeInARow);
    }

    private boolean checkBackwardDiagonal(){
        Tile[] threeInARow = new Tile[3];
        //check backward diagonal
        for (int i = 0; i < grid.length; i++){
            threeInARow[i] = grid[grid.length - i - 1][i];
        }

        return checkThreeInARow(threeInARow);

    }

    public boolean checkEndConditions(){
        if(checkRows()) return true;

        if(checkColumns()) return true;

        if(checkForwardDiagonal()) return true;

        if(checkBackwardDiagonal()) return true;

        return false;
    }

    //must be passed an array of size 3
    private boolean checkThreeInARow(@NonNull Tile[] threeInARow){
        int[] symbols = {
                threeInARow[0].currentState.symbol,
                threeInARow[1].currentState.symbol,
                threeInARow[2].currentState.symbol
        };

        //check if no symbols are empty
        if (symbols[0] != Tile.emptySymbol &&
            symbols[1] != Tile.emptySymbol &&
            symbols[2] != Tile.emptySymbol) {

            //check if all symbols are equal
            if (symbols[0] == symbols[1] && symbols[0] == symbols[2]) return true;

        }
        return false;
    }

    private void setWinningSymbol(State state){
        switch (state.symbol){
            case Tile.XSymbol:
                winningSymbol = "X";
                break;
            case Tile.OSymbol:
                winningSymbol = "O";
                break;
        }
    }

}
