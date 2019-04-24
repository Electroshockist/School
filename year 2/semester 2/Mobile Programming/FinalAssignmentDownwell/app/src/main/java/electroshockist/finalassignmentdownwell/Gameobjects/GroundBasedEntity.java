package electroshockist.finalassignmentdownwell.Gameobjects;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.Vector2;

public abstract class GroundBasedEntity extends Entity {
    private float yAccel, topYVel;

    GroundBasedEntity(GameView view, Vector2 position, int imageID) {
        super(view, position, imageID);

        yAccel = 0.1f;
        topYVel = 10.0f;
    }

    @Override
    public void update() {
        gravity();
        super.update();
    }

    private void gravity() {
        //if can move down accelerate due to gravity
        velocity.y += yAccel;
        if (velocity.y > topYVel) velocity.y = topYVel;
    }
}
