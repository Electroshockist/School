package electroshockist.finalassignmentdownwell;

import android.graphics.Bitmap;
import android.graphics.Canvas;

abstract class BaseObject {
    protected Bitmap image;
    protected Vector2 position;
    Canvas canvas;

    //stores image width and height in shorter variables
    protected float height, width;

    public BaseObject(Canvas canvas, Bitmap image, Vector2 position) {
        this.canvas = canvas;
        this.image = image;
        this.position = position;

        height = image.getHeight();
        width = image.getWidth();
    }

    abstract void update();

    abstract void onDraw(Canvas canvas);

    //quick access for the next self's left side position next frame
    public float left() { return position.x; }
    //quick access for the next self's top side position next frame
    public float top() { return position.y; }
    //quick access for the next self's right side position next frame
    public float right(){ return position.x + width; }
    //quick access for the next self's bottom side position next frame
    public float bottom(){ return position.y + height; }
}
