package electroshockist.finalassignmentdownwell;

import android.graphics.Bitmap;
import android.graphics.Canvas;

public abstract class Block extends BaseObject {
    Block(Canvas canvas, Bitmap image, float pX, float pY) {
        super(canvas, image, new Vector2(pX,pY));
    }
}
