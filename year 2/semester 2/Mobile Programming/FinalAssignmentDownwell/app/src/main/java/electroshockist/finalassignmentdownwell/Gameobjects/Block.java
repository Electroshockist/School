package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import electroshockist.finalassignmentdownwell.Vector2;

public abstract class Block extends BaseObject {
    Block(Bitmap image, Vector2 position, int scale) {
        super(image, position, scale);
    }
}
