package electroshockist.lab9splashscreen;

import android.content.Intent;
import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;

public class SplashActivity extends AppCompatActivity {
    ImageView logo, duck;
    MediaPlayer mp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        logo = findViewById(R.id.logoImage);
        duck = findViewById(R.id.duckImage);
        animateLogo();
        animateDuck();
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
                    sleep(mp.getDuration()-3);

                } catch (InterruptedException e) {
                    e.printStackTrace();
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
        logo.clearAnimation();
        duck.clearAnimation();

        this.finish();
    }

    public void animateLogo(){
        Animation animation = AnimationUtils.loadAnimation(this, R.anim.logoanim);
        logo.startAnimation(animation);
    }

    public void animateDuck(){
        Animation animation = AnimationUtils.loadAnimation(this, R.anim.duckanim);
        duck.startAnimation(animation);
        animation.setAnimationListener(new CustomAnimationListener());
    }

    private class CustomAnimationListener implements Animation.AnimationListener {
        @Override
        public void onAnimationStart(Animation animation) {
        }

        @Override
        public void onAnimationEnd(Animation animation) {
            startActivity(new Intent(SplashActivity.this, MainActivity.class));
        }

        @Override
        public void onAnimationRepeat(Animation animation) {

        }
    }

}

