package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.ScreenVariables;
import electroshockist.finalassignmentdownwell.Vector2;

import static electroshockist.finalassignmentdownwell.ScreenVariables.screenWidth;
import static electroshockist.finalassignmentdownwell.ScreenVariables.tilesPerScreenWidth;

public abstract class BaseObject {
    public Bitmap image;
    protected Vector2 position;
    protected float scale;
    protected int id;

    public static  int currentID = 0;

    public float renderedY;

    Paint paint = new Paint();

    //stores image width and height in shorter variables
    protected float height, width;

    public BaseObject(GameView gameView, Vector2 gridPosition, int imageID) {
        paint.setColor(Color.RED);
        //set image
        if (imageID != 0) image = BitmapFactory.decodeResource(gameView.getResources(), imageID);

        height = (float) image.getHeight();
        width = (float) image.getWidth();

        this.position = new Vector2(gridPosition.x * (screenWidth / tilesPerScreenWidth), gridPosition.y * (screenWidth / tilesPerScreenWidth));

        renderedY = position.y;

        id = currentID++;
    }

    //draw self
    public void onDraw(Canvas canvas) {
        canvas.drawLine(left(), renderedY, right(), renderedY, paint);
        canvas.drawLine(left(), renderedY + height, right(), renderedY + height, paint);
        canvas.drawLine(left(), renderedY, left(), renderedY + height, paint);
        canvas.drawLine(right(), renderedY, right(), renderedY + height, paint);
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
