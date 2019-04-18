package electroshockist.finalassignmentdownwell.Gameobjects;

import electroshockist.finalassignmentdownwell.GameView;
import electroshockist.finalassignmentdownwell.Vector2;

public abstract class Block extends BaseObject {
    Block(GameView view, Vector2 position, int imageID) {
        super(view, position, imageID);
    }
}
