package towe.def;

/**
 * Player.java
 * MIDTERM PROJECT "Tower Defence"
 * If you update this code,
 * your comments should start with your INITIALS!!!!!!**
 */

import android.graphics.Bitmap;
import android.graphics.Canvas;

public class Player {
    GameView gameView;
    Bitmap bmp;
    public static int x;
    public static int y;

    public Player(GameView gameView, Bitmap bmp) {
        this.gameView = gameView;
        this.bmp = bmp;
        this.x = 0;
        this.y = 0;
    }

    public void onDraw(Canvas c) {
        c.drawBitmap(bmp, x, y, null);
    }
}
