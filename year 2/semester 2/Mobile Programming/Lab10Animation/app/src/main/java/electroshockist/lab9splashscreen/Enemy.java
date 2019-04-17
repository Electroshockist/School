package electroshockist.lab9splashscreen;

import android.graphics.Bitmap;

public class Enemy extends Entity {

    public Enemy(Bitmap image, float pX, float pY, float vX, float vY) {
        super(image, pX, pY, vX, vY);
        DeathSound = Variables.SoundIDs.ENEMYSOUND.getID();
        explosionImageID = Variables.Explosions.ENEMYEXPLOSION.getIds()[3];
    }

    @Override
    public int value() {
        return 1;
    }
}
