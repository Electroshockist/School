package electroshockist.lab7collisions;

import android.graphics.Bitmap;
import android.graphics.Canvas;

class Image {
    private float height, width;

    private float[] position = new float[2];
    private float[] velocity = new float[2];


    private float left() {
        return position[0] + velocity[0];
    }
    private float top() {
        return position[1] + velocity[1];
    }

    private float right(){
        return position[0] + velocity[0] + width;
    }

    private float bottom(){
        return position[1] + velocity[1] + height;
    }

    private Bitmap image;

    Image(Bitmap image, float pX, float pY, float vX, float vY) {
        this.image = image;
        height = image.getHeight();
        width = image.getWidth();

        position[0] = pX;
        position[1] = pY;

        velocity[0] = vX;
        velocity[1] = vY;
    }

    void onDraw(Canvas canvas){
        canvas.drawBitmap(image, position[0], position[1],null);
    }

    void Move(){
        position[0] += velocity[0];
        position[1] += velocity[1];
    }

    void WallCollisions(Canvas canvas){
        if(left() <= 0)
            velocity[0] = Math.abs(velocity[0]);
        if(right() >= canvas.getWidth())
            velocity[0] = -Math.abs(velocity[0]);
        if(top() <=0)
            velocity[1] =Math.abs(velocity[1]);
        if (bottom() >= canvas.getHeight())
            velocity[1] = -Math.abs(velocity[1]);
    }

    private boolean isXInside(Image image2){
        return left() <= image2.right() && left() >= image2.left() ||
                //y + h is between y2 and y2 + h2
                right() >= image2.left() && right() <= image2.right();
    }

    private boolean isYInside(Image image2){
        //if y is between y2 and y2 + h2 or
        return top() <= image2.bottom() && top() >= image2.top() ||
                //y + h is between y2 and y2 + h2
                bottom() >= image2.top() && bottom() <= image2.bottom();
    }

    public boolean detectedCollision(Image image2){
        if (isYInside(image2)) {
            if (isXInside(image2)) {
                interImageCollision(image2);
                //image2.interImageCollision(this);
                return true;
            }
        }
        return false;
    }

    private void interImageCollision(Image image2){
        //reverse x
        //check left
        if (left() <= image2.left()  && right() >= image2.left())
            velocity[0] = -Math.abs(velocity[0]);
        //check right
        if (left() <= image2.right()  && right() >= image2.right())
            velocity[0] = Math.abs(velocity[0]);

        //reverse y
        //check top
        if (top() <= image2.top() && bottom() >= image2.top())
            velocity[1] = -Math.abs(velocity[1]);

        //check bottom
        if (top() <= image2.bottom() && bottom() >= image2.bottom())
            velocity[1] = Math.abs(velocity[1]);
    }
}
