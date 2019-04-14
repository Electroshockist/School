package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;

import electroshockist.finalassignmentdownwell.Vector2;

public class Player extends Entity {

    public Player(Bitmap image, Vector2 position, int scale) {
        super(image, position, scale);
    }

    public void manageInput(int x){}
}
