package electroshockist.finalassignmentdownwell.Gameobjects;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.R;
import electroshockist.finalassignmentdownwell.Vector2;

public class Bullet extends Entity {

    Bullet(GameView view, Vector2 position) {
        super(view, position, R.drawable.bullet);
        velocity.y = 5;
    }
}
