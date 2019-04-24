package electroshockist.finalassignmentdownwell.Gameobjects;

import android.util.Log;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.R;
import electroshockist.finalassignmentdownwell.Vector2;

public class Player extends GroundBasedEntity {

    boolean pressDown = false;
    float jumpVelocity, baseJumpVelocity, jumpVelocityDecrement;

    public Player(GameView view, Vector2 position) {
        super(view, position, R.drawable.gun2);
        baseJumpVelocity = 2;
        jumpVelocityDecrement = 0.1f;
    }

    public void manageInput(int x) {
    }

    @Override
    public void update() {
        if (pressDown) ;
        super.update();
    }

    public void centerX() {
        position.x -= width / 2.0f;
    }

    public void jump() {
        if(jumpVelocity >= 0){
            jumpVelocity -= jumpVelocityDecrement;
        }
        velocity.y -= jumpVelocity;
    }

    public void onPress() {
        pressDown = true;
        jump();
        jumpVelocity = baseJumpVelocity;
    }

    public void onRelease(){
        pressDown = false;
    }

}
