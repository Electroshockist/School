package electroshockist.lab7collisions;

import android.graphics.Bitmap;

public class Enemy extends Entity {
    public static int imageID = R.drawable.dvd;

    public Enemy(Bitmap image, float pX, float pY, float vX, float vY) {
        super(image, pX, pY, vX, vY);
    }
}
