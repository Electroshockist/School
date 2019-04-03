package towe.def;

/**
 * Bullet.java
 * MIDTERM PROJECT "Tower Defence"
 * You need to  modify this file to complete the project
 * Please, include your name here:
 * You name: Eric Balas
 * Group :
 * Date:
 * Don't forget to comment any code you will add below!
 * * Your comments should start with your INITIALS!
 */


import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.util.Log;

public class Bullet {
    private Bitmap bmp;
    public int x;
    public int y;

    public double UX;
    public double UY;
    /** */
    private int mSpeed = 25;
    /** */
    public int width;
    /** */
    public int height;
    public GameView gameView;

    /** */
    public Bullet(GameView gameView, Bitmap bmp, int touchX, int touchY) {
        this.gameView = gameView;
        this.bmp = bmp;

        this.x = Player.x;
        this.y = Player.y;

        this.width = 9;  // width
        this.height = 8; // height


        //EB #1 get vector relative to spawn location
        int relativeX = touchX - x;
        int relativeY = touchY - y;


        //EB #1 get magnitude of vector
        double magnitude = Math.sqrt(relativeX*relativeX + relativeY*relativeY);

        //EB #1 unit X = x/magnitude, same for y
        UX = relativeX / magnitude;
        UY = relativeY / magnitude;
    }

    /** */
    private void update() {
        //EB #1 multiply speed by unit vector to get proportional speed
        x += mSpeed * UX;
        y += mSpeed * UY;

    }

    /** */
    public void onDraw(Canvas canvas) {
        update();
        canvas.drawBitmap(bmp, x, y, null);
    }
}
