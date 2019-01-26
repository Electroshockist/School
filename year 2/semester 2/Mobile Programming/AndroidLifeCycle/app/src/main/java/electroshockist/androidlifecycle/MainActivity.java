package electroshockist.androidlifecycle;

import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    String id = "testdese";

    MediaPlayer mediaPlayer;

    TextView txt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txt = findViewById(R.id.Title);

        mediaPlayer = MediaPlayer.create(this, R.raw.tetris);
        mediaPlayer.start();

        txt.setText("Playing");
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.i(id, "OnCreate called");
        mediaPlayer.start();
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.i(id, "OnResume called");
        mediaPlayer.start();
        txt.setText("Stopped");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.i(id, "OnPause called");
        txt.setText("Paused");
        mediaPlayer.pause();
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.i(id, "OnStop called");
        mediaPlayer.stop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.i(id, "OnDestroy called");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.i(id, "OnRestart called");
    }
}
