package electroshockist.lab6tictactoe;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class Game extends AppCompatActivity {

    Tile[][] board;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);

        initializeBoard();
    }

    private void initializeBoard(){
        board = new Tile[3][3];
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board.length; j++)
                board[i][j] = new Tile();
        }
    }

    public void onSelect(View view) {
        switch (view.getId()){
            //case
        }
    }
}
