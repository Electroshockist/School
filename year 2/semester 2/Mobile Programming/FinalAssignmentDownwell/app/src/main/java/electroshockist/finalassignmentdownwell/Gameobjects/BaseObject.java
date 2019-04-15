package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import electroshockist.finalassignmentdownwell.Vector2;

public abstract class BaseObject {
    protected Bitmap image;
    protected Vector2 position;
    protected int scale;

    public float renderedY;

    //stores image width and height in shorter variables
    protected int height, width;

    public BaseObject(Bitmap image, Vector2 position, int scale) {
        this.image = image;
        this.position = position;
        this.scale = scale;

        renderedY = position.y;

        height = image.getHeight() * scale;
        width = image.getWidth() * scale;

        this.image = Bitmap.createScaledBitmap(image, width, height, false);
    }

    //draw self
    public void onDraw(Canvas canvas) {
        canvas.drawBitmap(image, position.x, renderedY, null);
    }

    //quick access for the left side position
    public float left() {
        return position.x;
    }

    //quick access for the top side position
    public float top() {
        return position.y;
    }

    //quick access for the right side position
    public float right() {
        return position.x + width;
    }

    //quick access for the bottom side position
    public float bottom() {
        return position.y + height;
    }

    public Vector2 getPosition() {
        return position;
    }
}
