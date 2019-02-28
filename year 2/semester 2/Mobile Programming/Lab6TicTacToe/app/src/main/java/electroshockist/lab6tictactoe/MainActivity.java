package electroshockist.lab6tictactoe;

import android.content.Intent;
import android.os.PersistableBundle;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;
import android.widget.ToggleButton;

public class MainActivity extends AppCompatActivity {

    public static final String debugTag = "TicTacToeDebug";

    int[] xImages = {R.drawable.x, R.drawable.x_unselected};
    int[] oImages = {R.drawable.o, R.drawable.o_unselected};

    int selectedSymbol;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        clearSelection();
    }

    public void SelectX(View view) {
        selectedSymbol = Tile.XSymbol;
        resolveImages();
    }

    public void SelectO(View view) {
        selectedSymbol = Tile.OSymbol;
        resolveImages();
    }

    void clearSelection(){
        selectedSymbol = Tile.emptySymbol;

        ImageView ivX = findViewById(R.id.X);
        ImageView ivO = findViewById(R.id.O);

        ivX.setImageResource(R.drawable.x_unselected);
        ivO.setImageResource(R.drawable.o_unselected);
    }

    void resolveImages(){
        ImageView ivX = findViewById(R.id.X);
        ImageView ivO = findViewById(R.id.O);

        if(selectedSymbol == Tile.XSymbol){
            ivX.setImageResource(R.drawable.x);
            ivO.setImageResource(R.drawable.o_unselected);
        }
        else {
            ivX.setImageResource(R.drawable.x_unselected);
            ivO.setImageResource(R.drawable.o);
        }

    }

    public void onPlay(View view) {
        if (selectedSymbol == Tile.emptySymbol){
            Toast.makeText(this,"Please select a symbol",Toast.LENGTH_SHORT).show();
        }
        else{
            loadGame();
        }
    }

    private void loadGame(){
        ToggleButton PlayerType = findViewById(R.id.PlayerType);

        Intent intent = new Intent(this, Game.class);
        intent.putExtra("PlayerType", PlayerType.getText().toString());
        intent.putExtra("selectedSymbol", selectedSymbol);

        startActivity(intent);
    }

    //save
    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        outState.putInt("selectedSymbol", selectedSymbol);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        selectedSymbol = savedInstanceState.getInt("selectedSymbol");
        resolveImages();
    }
}
