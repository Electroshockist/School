package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Canvas;
import android.util.Log;

import electroshockist.finalassignmentdownwell.Collisions.Collision;
import electroshockist.finalassignmentdownwell.Collisions.CollisionList;
import electroshockist.finalassignmentdownwell.Collisions.CollisionType;
import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.ScreenVariables;
import electroshockist.finalassignmentdownwell.Vector2;

public abstract class Entity extends BaseObject {

    //position vector
    protected Vector2 velocity;

    protected int DeathSound;

    public int getDeathSound() {
        return DeathSound;
    }

    private boolean canMoveLeft, canMoveRight, canMoveUp, canMoveDown;

    public boolean isCanMoveLeft() {
        return canMoveLeft;
    }

    public boolean isCanMoveRight() {
        return canMoveRight;
    }

    public boolean isCanMoveUp() {
        return canMoveUp;
    }

    public boolean isCanMoveDown() {
        return canMoveDown;
    }

    private CollisionList collisionList;

    //constructor (set default values)
    Entity(GameView view, Vector2 position, int imageID) {
        super(view, position, imageID);

        velocity = new Vector2(0, 0);

        canMoveDown = true;
        canMoveUp = true;
        canMoveRight = true;
        canMoveLeft = true;

        collisionList = new CollisionList();
    }

    //quick access for the next self's left side position next frame
    public float left() {
        return (super.left() + velocity.y);
    }

    //quick access for the next self's top side position next frame
    public float top() {
        return super.top() + velocity.y;
    }

    //quick access for the next self's right side position next frame
    public float right() {
        return super.right() + velocity.x;
    }

    //quick access for the next self's bottom side position next frame
    public float bottom() {
        return super.bottom() + velocity.y;
    }

    public void setMovableDirs() {

        canMoveLeft = !collisionList.isCollisionTypeActive(CollisionType.LEFT);

        canMoveRight = !collisionList.isCollisionTypeActive(CollisionType.RIGHT);

        canMoveUp = !collisionList.isCollisionTypeActive(CollisionType.TOP);

        canMoveDown = !collisionList.isCollisionTypeActive(CollisionType.BOTTOM);
    }

    //move self
    void Move() {
        //left velocity and right velocity check
        if (velocity.x > 0 && !canMoveRight || velocity.x < 0 && !canMoveLeft) velocity.x = 0.0f;
        //down velocity and up velocity check
        if (velocity.y > 0 && !canMoveDown || velocity.y < 0 && !canMoveUp) velocity.y = 0.0f;

        position.x += velocity.x;
        position.y += velocity.y;
    }

    public void update() {
        setMovableDirs();
        Move();
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

    //check collision between self and given image
    public void InterCollision(BaseObject object2) {
        String collisionID = "InterCollision";

        Collision leftCollision = new Collision(CollisionType.LEFT, collisionID);
        Collision rightCollision = new Collision(CollisionType.RIGHT, collisionID);
        Collision upCollision = new Collision(CollisionType.TOP, collisionID);
        Collision downCollision = new Collision(CollisionType.BOTTOM, collisionID);


        if (detectedCollision(object2)) {
            ////check x////
            //check left
            if (detectedCollision(object2) && checkLeft(object2)) {
                collisionList.addUnique(leftCollision);
            } else collisionList.remove(leftCollision);

            //check right
            if (detectedCollision(object2) && checkRight(object2)) {
                collisionList.addUnique(rightCollision);
            } else collisionList.remove(rightCollision);

            ////check y////
            //check top
            if (detectedCollision(object2) && checkUp(object2)) {
                collisionList.addUnique(upCollision);
            } else collisionList.remove(upCollision);

            //check bottom
            if (detectedCollision(object2) && checkDown(object2)) {
                Log.v("lel", "Added Down collision");
                collisionList.addUnique(downCollision);
            } else {
                Log.v("lel", "Removed Down collision");
                collisionList.remove(downCollision);
            }
        }
        //else collisionList.removeAll();
        //collisionList.print();
    }

    private boolean checkLeft(BaseObject object2) {
        return left() <= object2.right() && right() >= object2.right();
    }

    private boolean checkRight(BaseObject object2) {
        return left() <= object2.left() && right() >= object2.left();
    }

    private boolean checkUp(BaseObject object2) {
        return top() <= object2.bottom() && bottom() >= object2.bottom();
    }

    private boolean checkDown(BaseObject object2) {
        return top() <= object2.top() && bottom() >= object2.top();
    }

    //check border collisions
    public void WallCollisions(Canvas canvas) {
        String collisionID = "Wall Collision";
        Collision leftCollision = new Collision(CollisionType.LEFT, collisionID);
        Collision rightCollision = new Collision(CollisionType.RIGHT, collisionID);

        //check left border
        if (left() <= 0) collisionList.addUnique(leftCollision);
        else collisionList.remove(leftCollision);
        //check right border
        if (right() >= canvas.getWidth())
            collisionList.addUnique(rightCollision);
        else collisionList.remove(rightCollision);
        //check right border
    }

    public Vector2 getVelocity() {
        return velocity;
    }

    public CollisionList getCollisionList() {
        return collisionList;
    }
}
