package electroshockist.lab7collisions;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.util.Log;

public class Image {
    float height, width;

    public float x() {
        return position[0];
    }
    public float y() {
        return position[1];
    }
    public float[] position = new float[2];
    public float[] velocity = new float[2];

    Bitmap image;

    public Image(Bitmap image,float pX, float pY,  float vX, float vY) {
        this.image = image;
        height = image.getHeight();
        width = image.getWidth();

        position[0] = pX;
        position[1] = pY;

        velocity[0] = vX;
        velocity[1] = vY;
    }

    public void onDraw(Canvas canvas){
        canvas.drawBitmap(image, position[0], position[1],null);
    }

    public void Move(){
        position[0] += velocity[0];
        position[1] += velocity[1];
    }

    public void Physics(Canvas canvas){
        if(position[0] <=0|| position[0] + width >= canvas.getWidth()){
            velocity[0] *= -1;
        }
        if(position[1] <=0|| position[1] + height >= canvas.getHeight()){
            velocity[1] *= -1;
        }
    }

    private boolean isXInside(Image image2){
        if (x() <= image2.x() + width  && x() >= image2.x() ||
                //y + h is between y2 and y2 + h2
                x() + width >= image2.x() && x() + width <= image2.x() + image2.width) {
            return true;
        }
        return false;
    }

    private boolean isYInside(Image image2){
        //if y is between y2 and y2 + h2 or
        if (y() <= image2.y() + height  && y() >= image2.y() ||
                //y + h is between y2 and y2 + h2
                position[1] + height >= image2.position[1] && position[1] + height <= image2.position[1] + image2.height) {
            return true;
        }
        return false;
    }

    public boolean detectedCollision(Image image2){
        if (isYInside(image2)) {
            if (isXInside(image2)) {
                return true;
            }
        }
        return false;
    }

    public void interImageCollision(Image image2){

        //check if collision detected
        if (detectedCollision(image2)) {
            //reverse x
            if (position[0] + width >= image2.position[0] && position[0] <= image2.position[0] + image2.width) {
                velocity[0] *= -1;
            }
            //reverse y
            if (position[1] + height >= image2.position[1] && position[1] <= image2.position[1] + image2.height) {
                velocity[1] *= -1;
            }
        }
    }
}
