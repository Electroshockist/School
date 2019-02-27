package electroshockist.lab6tictactoe;

import android.content.Context;
import android.widget.ImageView;
import android.widget.Toast;

public class Tile {
    public static final int emptySymbol = 0, XSymbol = 1, OSymbol = 2;

    public static final State
            empty = new State(emptySymbol, R.drawable.blank),
            X = new State(XSymbol, R.drawable.x),
            O = new State(OSymbol, R.drawable.o);

    public State currentState;

    public Tile(){
        currentState = empty;
    }

    //change tile state
    public boolean swapState(int state, Tile target, Context context){
        if(target.currentState != empty){
            Toast.makeText(context,"This tile is occupied, please pick another", Toast.LENGTH_LONG).show();
            return false;
        }
        else {
            switch (state) {
                case XSymbol:
                    currentState = X;
                    break;
                case OSymbol:
                    currentState = O;
                    break;
            }
            return true;
        }
    }
}
