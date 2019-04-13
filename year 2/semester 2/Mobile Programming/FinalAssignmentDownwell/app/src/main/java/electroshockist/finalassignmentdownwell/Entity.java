package electroshockist.finalassignmentdownwell;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import java.util.ArrayList;
import java.util.List;

import electroshockist.finalassignmentdownwell.Collisions.CollisionList;
import electroshockist.finalassignmentdownwell.Collisions.CollisionType;

abstract class Entity extends BaseObject {

    Canvas canvas;

    //position vector
    private Vector2 velocity;

    protected int DeathSound;

    public int getDeathSound() {
        return DeathSound;
    }

    private boolean canMoveLeft, canMoveRight, canMoveUp, canMoveDown;

    //constructor (set default values)
    Entity(Canvas canvas, Bitmap image, float pX, float pY) {
        super(canvas, image, new Vector2(pX, pY));

        this.canvas = canvas;

        canMoveDown = true;
        canMoveUp = true;
        canMoveRight = true;
        canMoveLeft = true;
    }
    //quick access for the next self's left side position next frame
    public float left() { return position.x + velocity.x; }

    //quick access for the next self's top side position next frame
    public float top() { return position.y + velocity.y; }

    //quick access for the next self's right side position next frame
    public float right() { return position.x + velocity.x + width; }

    //quick access for the next self's bottom side position next frame
    public float bottom() { return position.y + velocity.y + height; }

    //draw self
    void onDraw() {
        canvas.drawBitmap(image, position.x, position.y, null);
    }

    //move self
    void Move() {
        position.x += velocity.x;
        position.y += velocity.y;
    }

    public void update(){
        Move();
        onDraw();
    }


    //////Collisions//////
    //check if self's x values are between given image's x values
    private boolean isXInside(BaseObject entity2) {
        //where 2 denotes entity2
        //if left is between left2 and right2 or
        return left() <= entity2.right() && left() >= entity2.left() ||
                //right is between left2 and right2
                right() >= entity2.left() && right() <= entity2.right();
    }

    //check if self's y values are between given image's y values
    private boolean isYInside(BaseObject entity2) {
        //where 2 denotes entity2
        //if top is between top2 and bottom2 or
        return top() <= entity2.bottom() && top() >= entity2.top() ||
                //bottom is between top2 and bottom2
                bottom() >= entity2.top() && bottom() <= entity2.bottom();
    }

    //check if a collision has been detected
    private boolean detectedCollision(BaseObject entity2) {
        return (isYInside(entity2) && isXInside(entity2));
    }



    protected void setMoveableDirs(BaseObject object){
        CollisionList wallCollisions = WallCollisions();
        CollisionList interCollisions = InterCollision(object);

        canMoveLeft = !wallCollisions.exists(CollisionType.LEFT) && !interCollisions.exists(CollisionType.LEFT);

        canMoveRight = !wallCollisions.exists(CollisionType.RIGHT) && !interCollisions.exists(CollisionType.RIGHT);

        if (interCollisions.exists(CollisionType.TOP)) canMoveUp = false;


    }

    //check collision between self and given image
    CollisionList InterCollision(BaseObject entity2) {
        CollisionList tempList = new CollisionList();
        if (detectedCollision(entity2)) {
            ////check x////
            //check left
            if (left() <= entity2.left() && right() >= entity2.left()) { tempList.addUnique(CollisionType.LEFT); }

            //check right
            if (left() <= entity2.right() && right() >= entity2.right()) { tempList.addUnique(CollisionType.RIGHT); }

            ////check y////
            //check top
            if (top() <= entity2.top() && bottom() >= entity2.top()) { tempList.addUnique(CollisionType.TOP); }

            //check bottom
            if (top() <= entity2.bottom() && bottom() >= entity2.bottom()) { tempList.addUnique(CollisionType.BOTTOM);}
        }
        return tempList;
    }

    //check border collisions
    CollisionList WallCollisions() {
        CollisionList tempList = new CollisionList();
        //check left border
        if (left() <= 0) tempList.addUnique(CollisionType.LEFT);
        //check right border
        if (right() >= canvas.getWidth()) tempList.addUnique(CollisionType.RIGHT);

        return tempList;
    }
}
