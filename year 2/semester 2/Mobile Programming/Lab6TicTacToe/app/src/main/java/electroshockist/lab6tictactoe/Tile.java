package electroshockist.lab6tictactoe;

import android.content.Context;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.widget.Button;
import android.widget.Toast;

public class Tile {
    private Button button;

    public static final int emptySymbol = 0, XSymbol = 1, OSymbol = 2;

    public static final State
            empty = new State(emptySymbol, R.drawable.blank),
            X = new State(XSymbol, R.drawable.x),
            O = new State(OSymbol, R.drawable.o);

    public State currentState;

    public Button getButton() {
        return button;
    }

    public Tile(Button button){
        currentState = empty;
        this.button = button;
    }

    //change tile state
    public boolean onClick(boolean XTurn, Context context){
        boolean returnValue;
        if(currentState != empty){
            Toast.makeText(context,"This tile is occupied, please pick another", Toast.LENGTH_LONG).show();
            returnValue = false;
        }
        else {
            if (XTurn){
                changeState(X);
            }
            else {
                changeState(O);
            }
            returnValue = true;

            Log.v(MainActivity.debugTag,Integer.toString(currentState.symbol));
        }

        return returnValue;
    }

    private void changeState(State state){
        currentState = state;
        button.setBackgroundResource(state.imageID);
    }
}
