package electroshockist.lab7collisions;

import android.graphics.Bitmap;
import android.graphics.Canvas;

public class Explosion {
    //position vector
    private Vector2 position;

    //stores image
    private Bitmap image;

    public Explosion(Bitmap image, Vector2 position) {
        this.image = image;
        this.position = position;
    }

    void onDraw(Canvas canvas){
        canvas.drawBitmap(image, position.x, position.y,null);
    }
}
