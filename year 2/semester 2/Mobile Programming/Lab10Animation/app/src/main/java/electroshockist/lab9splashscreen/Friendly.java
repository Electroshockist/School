package electroshockist.lab9splashscreen;

import android.graphics.Bitmap;

public class Friendly extends Entity {
    public Friendly(Bitmap image, float pX, float pY, float vX, float vY) {
        super(image, pX, pY, vX, vY);
        DeathSound = Variables.SoundIDs.FRIENDLYSOUND.getID();
        explosionImageID = Variables.Explosions.FRIENDLYEXPLOSION.getIds()[3];
    }

    @Override
    public int value() {
        return -1;
    }
}
