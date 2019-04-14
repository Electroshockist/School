package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import electroshockist.finalassignmentdownwell.Vector2;

public abstract class BaseObject {
    protected Bitmap image;
    protected Vector2 position;
    protected int scale;

    //stores image width and height in shorter variables
    protected int height, width;

    Paint paint;

    public BaseObject(Bitmap image, Vector2 position, int scale) {
        this.image = image;
        this.position = position;
        this.scale = scale;

        height = image.getHeight() * scale;
        width = image.getWidth() * scale;

        paint = new Paint();

        this.image = Bitmap.createScaledBitmap(image, width, height, false);
    }

    //draw self
    void onDraw(Canvas canvas) {
        //set the paint settings
        paint.setAntiAlias(false);
        paint.setDither(true);
        paint.setFilterBitmap(false);
        paint.setColor(Color.GREEN);
        canvas.drawBitmap(image, position.x, position.y, paint);
    }

    //quick access for the left side position
    public float left() { return position.x; }
    //quick access for the top side position
    public float top() { return position.y; }
    //quick access for the right side position
    public float right(){ return position.x + width; }
    //quick access for the bottom side position
    public float bottom(){ return position.y + height; }
}
