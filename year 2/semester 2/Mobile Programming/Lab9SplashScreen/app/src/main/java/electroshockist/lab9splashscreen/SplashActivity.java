package electroshockist.lab9splashscreen;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;

public class SplashActivity extends AppCompatActivity {
    ImageView logo;
    MediaPlayer mp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        logo = findViewById(R.id.logoImage);
        mp = MediaPlayer.create(this, R.raw.zelda);
        mp.start();

        Thread timer = new Thread(){
            @Override
            public void run() {
                super.run();
                try {
                    sleep(mp.getDuration());
                    mp = MediaPlayer.create(SplashActivity.this, R.raw.duck);
                    mp.start();
                    sleep(mp.getDuration());

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                finally {
                    Intent intent = new Intent(SplashActivity.this, MainActivity.class);
                    startActivity(intent);
                }
            }
        };
        timer.start();
    }


    @Override
    protected void onPause() {
        super.onPause();
        if (mp.isPlaying()) {
            mp.stop();
            mp.release();
        }

        this.finish();
    }
}
