package towe.def;


/**
 * GameView.java
 * MIDTERM PROJECT "Tower Defence"
 * You need to modify this file to complete the project
 * Please, include your name here:
 * You name: Eric Balas
 * Group : A
 * Date: 04/02/2019
 * Don't forget to comment any code you will add below!
 * * Your comments should start with your INITIALS!!!!!*********
 */


import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.media.MediaPlayer;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class GameView extends SurfaceView implements Runnable {
    private GameThread mThread;
    private Thread thred = new Thread(this);
    private List<Bullet> bullet = new ArrayList<Bullet>();
    private List<Enemy> enemy = new ArrayList<Enemy>();
    private Bitmap enemies;
    private Bitmap player;

    public int shotX; // - x-coordiante of onTouchEvent
    public int shotY; // - y-coordiante of onTouchEvent

    //death sound media player
    MediaPlayer mediaPlayer;


    public GameView(Context context) {
        super(context);
        mThread = new GameThread(this);
        thred.start();

        mediaPlayer = MediaPlayer.create(context, R.raw.punch);

        getHolder().addCallback(new SurfaceHolder.Callback() {
            public void surfaceDestroyed(SurfaceHolder holder) {
                boolean retry = true;
                mThread.setRunning(false);
                while (retry) {
                    try {
                        mThread.join();
                        retry = false;
                    } catch (InterruptedException e) {
                    }
                }
            }

            /**   */
            public void surfaceCreated(SurfaceHolder holder) {
                mThread.setRunning(true);
                mThread.start();
            }

            /**  */
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
            }
        });

        enemies = BitmapFactory.decodeResource(getResources(), R.drawable.target);
        // one enemy added in constructor
        enemy.add(new Enemy(this, enemies));

        player = BitmapFactory.decodeResource(getResources(), R.drawable.player);
        // one player added in constructor
        new Player(this, player);
    } // end of GameView constructor

    /**
     * onDraw()
     */
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.WHITE);
        Player.x = canvas.getWidth()/2;

        canvas.drawBitmap(player, Player.x, Player.y, null);

        for (Bullet b : bullet) {
            if (b.x < 0 || b.y < 0 || b.x > canvas.getWidth() || b.y > canvas.getHeight())
                bullet.remove(b);
            b.onDraw(canvas);
        }


        for (Enemy e : enemy) {
            // 1. you should draw enemy only withing screen boundaries;
            // 2. to prevent memory leaks, enemy outside of the screen should be deleted
            //EB #3 remove enemy from list if out of bounds
            if (e.x < 0 || e.y < 0 || e.x > canvas.getWidth() || e.y > canvas.getHeight())
                enemy.remove(e);

            e.onDraw(canvas);
        }


    }

    private boolean isXInside(Enemy e, Bullet b) {
        //if left is between left2 and right2 or
        return e.x <= b.x + b.width && e.x >= b.x ||
                //right is between left2 and right2
                e.x + e.width >= b.x && e.x + e.width <= b.x + b.width;
    }

    //check if self's y values are between given image's y values
    private boolean isYInside(Enemy e, Bullet b) {
        //if top is between top2 and bottom2 or
        return e.y <= b.y + b.height && e.y >= b.y ||
                //bottom is between top2 and bottom2
                e.y + e.height >= b.y && e.y + e.height <= b.y + b.height;
    }

    //check if a collision has been detected
    boolean detectedCollision(Enemy e, Bullet b) {

        return (isYInside(e, b) && isXInside(e, b));
    }

    /**
     * testCollision()
     */
    public void testCollision() {
        // Complete your code below :
        for (Bullet b : bullet) {
            for (Enemy e : enemy) {

                // if bullet hits the enemy,
                if (detectedCollision(e, b)) {
                    Log.v("lel", "hit");
                    enemy.remove(e);
                    bullet.remove(b);

                    // 3. a short sound should be played
                    mediaPlayer.start();
                    break;
                }
            }
        }
    }

    public Bullet createSprite(int resouce, int touchX, int touchY) {
        Bitmap bmp = BitmapFactory.decodeResource(getResources(), resouce);
        return new Bullet(this, bmp, touchX, touchY);
    }

    public boolean onTouchEvent(MotionEvent e) {
        shotX = (int) e.getX();
        shotY = (int) e.getY();
        if (e.getAction() == MotionEvent.ACTION_DOWN)
            bullet.add(createSprite(R.drawable.bullet, shotX, shotY));
        return true;
    }

    public void run() {
        while (true) {
            Random rnd = new Random();
            try {
                // Your code is here :
                // new enemies should be added here every 0-2 seconds to enemy list
                //EB #2 add new enemy to list
                enemy.add(new Enemy(this, enemies));
                Thread.sleep(rnd.nextInt(2000));

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}
