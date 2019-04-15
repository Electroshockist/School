package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import electroshockist.finalassignmentdownwell.Collisions.Collision;
import electroshockist.finalassignmentdownwell.Collisions.CollisionList;
import electroshockist.finalassignmentdownwell.Collisions.CollisionType;
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
    Entity(Bitmap image, Vector2 position, int scale) {
        super(image, position, scale);

        velocity = new Vector2(0, 0);

        canMoveDown = true;
        canMoveUp = true;
        canMoveRight = true;
        canMoveLeft = true;

        collisionList = new CollisionList();
    }

    //quick access for the next self's left side position next frame
    public float left() {
        return super.left() + velocity.x;
    }

    //quick access for the next self's top side position next frame
    public float top() {
        return super.top() + velocity.y;
    }

    //quick access for the next self's right side position next frame
    public float right() {
        return super.right() + velocity.x ;
    }

    //quick access for the next self's bottom side position next frame
    public float bottom() {
        return super.bottom() + velocity.y ;
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
        if (velocity.x > 0 && !canMoveRight || velocity.x < 0 && !canMoveLeft) velocity.x = 0;
        //down velocity and up velocity check
        if (velocity.y > 0 && !canMoveDown || velocity.y < 0 && !canMoveUp) velocity.y = 0;


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
    public void InterCollision(BaseObject entity2) {
        String collisionID = "InterCollision";
        if (detectedCollision(entity2)) {
            ////check x////
            //check left
            if (left() <= entity2.left() && right() >= entity2.left()) {
                collisionList.addUnique(new Collision(collisionID, CollisionType.LEFT));
            } else collisionList.remove(new Collision(collisionID, CollisionType.LEFT));

            //check right
            if (left() <= entity2.right() && right() >= entity2.right()) {
                collisionList.addUnique(new Collision(collisionID, CollisionType.RIGHT));
            } else collisionList.remove(new Collision(collisionID, CollisionType.RIGHT));

            ////check y////
            //check top
            if (top() <= entity2.top() && bottom() >= entity2.top()) {
                collisionList.addUnique(new Collision(collisionID, CollisionType.TOP));
            } else collisionList.remove(new Collision(collisionID, CollisionType.TOP));

            //check bottom
            if (top() <= entity2.bottom() && bottom() >= entity2.bottom()) {
                collisionList.addUnique(new Collision(collisionID, CollisionType.BOTTOM));
            } else collisionList.remove(new Collision(collisionID, CollisionType.BOTTOM));
        }
    }

    //check border collisions
    public void WallCollisions(Canvas canvas) {
        String collisionID = "Wall Collision";

        //check left border
        if (left() <= 0) collisionList.addUnique(new Collision(collisionID, CollisionType.LEFT));
        else collisionList.remove(new Collision(collisionID, CollisionType.LEFT));
        //check right border
        if (right() >= canvas.getWidth())
            collisionList.addUnique(new Collision(collisionID, CollisionType.RIGHT));
        else collisionList.remove(new Collision(collisionID, CollisionType.RIGHT));
        //check right border
    }

    public Vector2 getVelocity() {
        return velocity;
    }
}
