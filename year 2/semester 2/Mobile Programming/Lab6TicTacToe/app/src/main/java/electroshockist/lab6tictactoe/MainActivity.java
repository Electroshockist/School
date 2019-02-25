package electroshockist.lab6tictactoe;

import android.os.PersistableBundle;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static final String debugTag = "TicTacToeDebug";

    private static final String X = "X", O = "O", none = "none";

    int[] xImages = {R.drawable.x, R.drawable.x_unselected};
    int[] oImages = {R.drawable.o, R.drawable.o_unselected};

    String selectedSymbol;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        clearSelection();
    }

    public void SelectX(View view) {
        selectedSymbol = X;
        resolveImages();
    }

    public void SelectO(View view) {
        selectedSymbol = O;
        resolveImages();
    }

    void clearSelection(){
        selectedSymbol = none;

        ImageView ivX = findViewById(R.id.X);
        ImageView ivO = findViewById(R.id.O);

        ivX.setImageResource(R.drawable.x_unselected);
        ivO.setImageResource(R.drawable.o_unselected);
    }

    void resolveImages(){
        ImageView ivX = findViewById(R.id.X);
        ImageView ivO = findViewById(R.id.O);

        if(selectedSymbol.equals(X)){
            ivX.setImageResource(R.drawable.x);
            ivO.setImageResource(R.drawable.o_unselected);
        }
        else {
            ivX.setImageResource(R.drawable.x_unselected);
            ivO.setImageResource(R.drawable.o);
        }

    }

    public void onPlay(View view) {
        if (selectedSymbol.equals(none)){
            Toast.makeText(this,"Please select a symbol",Toast.LENGTH_SHORT).show();
        }
    }

    //save
    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        Log.v(debugTag,"test");

        outState.putString("selectedSymbol", selectedSymbol);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        selectedSymbol = savedInstanceState.getString("selectedSymbol");
        resolveImages();
    }
}
