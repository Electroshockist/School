package electroshockist.finalassignmentdownwell.Gameobjects;

import android.util.Log;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.R;
import electroshockist.finalassignmentdownwell.Vector2;

public class Player extends GroundBasedEntity {

    boolean pressDown = false, previousCanMoveDownState = false;
    float jumpVelocity, baseJumpVelocity, jumpVelocityDecrement;

    public Player(GameView view, Vector2 position) {
        super(view, position, R.drawable.gun2);
        baseJumpVelocity = 7.0f;
        jumpVelocityDecrement = 0.1f;
    }

    public void manageInput(int x) {
    }

    @Override
    public void update() {
        //reset velocity on ground
//        if (previousCanMoveDownState != isCanMoveDown() && !isCanMoveDown() && !pressDown) {
//            velocity.x = 0;
//        }

        if (pressDown) ;
        super.update();
        previousCanMoveDownState = isCanMoveDown();
    }

    public void centerX() {
        position.x -= width / 2.0f;
    }

    public void jump() {
        if (velocity.y >= 0) {
            velocity.y = 0.0f;
            if (!isCanMoveDown()) {
                velocity.y -= jumpVelocity;
            }
        }
    }

    public void onPress() {
        pressDown = true;
        jump();
        jumpVelocity = baseJumpVelocity;
    }

    public void onRelease() {
        pressDown = false;
    }

    public void getTouchPos(Vector2 touchPos) {
        float x = -((position.x + (width / 2)) - touchPos.x);
        float xSign = x/Math.abs(x);

        velocity.x =  (x /50);

    }

}
