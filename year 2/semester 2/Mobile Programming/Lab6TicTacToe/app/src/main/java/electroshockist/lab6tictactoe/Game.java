package electroshockist.lab6tictactoe;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class Game extends AppCompatActivity {

    Board board;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);

        initializeBoard();
    }

    private void initializeBoard(){
        Button[][] tiles = {
                {
                        findViewById(R.id.Grid00),
                        findViewById(R.id.Grid01),
                        findViewById(R.id.Grid02)
                },
                {
                        findViewById(R.id.Grid10),
                        findViewById(R.id.Grid11),
                        findViewById(R.id.Grid12)
                },
                {
                        findViewById(R.id.Grid20),
                        findViewById(R.id.Grid21),
                        findViewById(R.id.Grid22)
                }
        };

        board = new Board(tiles);
    }

    public void onSelect(View view) {
        if(!board.checkEndConditions()) {
            switch (view.getId()) {
                case R.id.Grid00:
                    board.onClick(0, 0, this);
                    break;

                case R.id.Grid01:
                    board.onClick(0, 1, this);
                    break;

                case R.id.Grid02:
                    board.onClick(0, 2, this);
                    break;

                case R.id.Grid10:
                    board.onClick(1, 0, this);
                    break;

                case R.id.Grid11:
                    board.onClick(1, 1, this);
                    break;

                case R.id.Grid12:
                    board.onClick(1, 2, this);
                    break;

                case R.id.Grid20:
                    board.onClick(2, 0, this);
                    break;

                case R.id.Grid21:
                    board.onClick(2, 1, this);
                    break;

                case R.id.Grid22:
                    board.onClick(2, 2, this);
                    break;

            }
        }
        else {
            Toast.makeText(this,"The game is over.", Toast.LENGTH_SHORT).show();
        }
    }
}
