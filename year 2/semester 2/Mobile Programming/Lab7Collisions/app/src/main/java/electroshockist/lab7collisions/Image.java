package electroshockist.lab7collisions;

import android.graphics.Bitmap;
import android.graphics.Canvas;

class Image {
    //stores image width and height in shorter variables
    private float height, width;

    //position vector
    private Vector2 position;
    private Vector2 velocity;


    //quick access for the next self's left side position next frame
    private float left() {
        return position.x + velocity.x;
    }
    //quick access for the next self's top side position next frame
    private float top() {
        return position.y + velocity.y;
    }
    //quick access for the next self's right side position next frame
    private float right(){
        return position.x + velocity.x + width;
    }
    //quick access for the next self's bottom side position next frame
    private float bottom(){
        return position.y + velocity.y + height;
    }

    private Bitmap image;

    //constructor (set default values)
    Image(Bitmap image, float pX, float pY, float vX, float vY) {
        this.image = image;
        height = image.getHeight();
        width = image.getWidth();

        position = new Vector2(pX, pY);
        velocity = new Vector2(vX, vY);
    }

    //draw self
    void onDraw(Canvas canvas){
        canvas.drawBitmap(image, position.x, position.y,null);
    }

    //move self
    void Move(){
        position.x += velocity.x;
        position.y += velocity.y;
    }

    //check border collisions
    void WallCollisions(Canvas canvas){
        //check left border
        if(left() <= 0)
            setXVelocityPositive();
        //check right border
        if(right() >= canvas.getWidth())
            setXVelocityNegative();
        //check top border
        if(top() <=0)
            setYVelocityPositive();
        //check border
        if (bottom() >= canvas.getHeight())
            setYVelocityNegative();
    }

    //check if self's x values are between given image's x values
    private boolean isXInside(Image image2){
        //where 2 denotes image2
        //if left is between left2 and right2 or
        return left() <= image2.right() && left() >= image2.left() ||
                //right is between left2 and right2
                right() >= image2.left() && right() <= image2.right();
    }

    //check if self's y values are between given image's y values
    private boolean isYInside(Image image2){
        //where 2 denotes image2
        //if top is between top2 and bottom2 or
        return top() <= image2.bottom() && top() >= image2.top() ||
                //bottom is between top2 and bottom2
                bottom() >= image2.top() && bottom() <= image2.bottom();
    }

    //check if a collision has been detected
    boolean detectedCollision(Image image2){
        return (isYInside(image2)&& isXInside(image2));
    }

    //check collision between self and given image
    void interImageCollision(Image image2) {
        if (detectedCollision(image2)) {
            ////reverse x////
            //check left
            if (left() <= image2.left() && right() >= image2.left()) {
                setXVelocityNegative();
            }

            //check right
            if (left() <= image2.right() && right() >= image2.right()){
                setXVelocityPositive();
            }

            ////reverse y////
            //check top
            if (top() <= image2.top() && bottom() >= image2.top()){
                setYVelocityNegative();
            }

            //check bottom
            if (top() <= image2.bottom() && bottom() >= image2.bottom()) {
                setYVelocityPositive();
            }
        }
    }


    //set absolute velocity
    private void setXVelocityPositive(){
        velocity.x = Math.abs(velocity.x);
    }
    private void setXVelocityNegative(){
        velocity.x = -Math.abs(velocity.x);
    }
    private void setYVelocityPositive() { velocity.y = Math.abs(velocity.y); }
    private void setYVelocityNegative(){
        velocity.y = -Math.abs(velocity.y);
    }
}
