package electroshockist.finalassignmentdownwell.Gameobjects;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.R;
import electroshockist.finalassignmentdownwell.Vector2;

public class Player extends GroundBasedEntity {


    public Player(GameView view, Vector2 position) {
        super(view, position, R.drawable.gun2);
    }

    public void setPosition(Vector2 position) {
        this.position = position;
    }

    public void manageInput(int x) {
    }

    @Override
    public void update() {
        super.update();
    }

    public void centerX() {
        position.x -= width / 2.0f;
    }

}
