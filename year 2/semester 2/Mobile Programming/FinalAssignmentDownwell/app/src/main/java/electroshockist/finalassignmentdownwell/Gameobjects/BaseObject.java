package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.util.Log;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.Vector2;

public abstract class BaseObject {
    public Bitmap image;
    protected Vector2 position;
    protected float scale;

    public float renderedY;

    //stores image width and height in shorter variables
    protected float height, width;

    public BaseObject(GameView gameView, Vector2 gridPosition, int imageID) {

        this.position = new Vector2(gridPosition.x * (2 / width), gridPosition.y * (2 / width));

        renderedY = position.y;

        //set image
        if (imageID != 0) image = BitmapFactory.decodeResource(gameView.getResources(), imageID);
    }

    //draw self
    public void onDraw(Canvas canvas) {
        canvas.drawBitmap(image, (int) position.x, (int) renderedY, null);
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

    public void setScale(float scale) {
        this.scale = scale;

        height = (float) image.getHeight() * scale;
        width = (float) image.getWidth() * scale;

        this.image = Bitmap.createScaledBitmap(image, Math.round(width), Math.round(height), false);
    }

    public float getHeight() {
        return height;
    }

    public float getWidth() {
        return width;
    }
}
