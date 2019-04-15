package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.util.Log;

import electroshockist.finalassignmentdownwell.Vector2;

public abstract class GroundBasedEntity extends Entity {
    private float yAccel, topYVel;
    GroundBasedEntity(Bitmap image, Vector2 position, int scale) {
        super(image, position, scale);

        yAccel = 0.1f;
        topYVel = 10.0f;
    }

    @Override
    public void update() {

        Log.v("lel", Float.toString(velocity.y));
        gravity();
        super.update();
    }

    private void gravity(){
        //if can move down accelerate due to gravity
        if (isCanMoveDown()) {
            velocity.y += yAccel;
            if (velocity.y > topYVel)velocity.y = topYVel;
        }
    }
}
