package electroshockist.finalassignmentdownwell.Gameobjects;

import android.graphics.Bitmap;

import electroshockist.finalassignmentdownwell.Vector2;

public class Player extends GroundBasedEntity {
    public Player(Bitmap image, Vector2 position, int scale) {
        super(image, position, scale);
    }

    public void manageInput(int x){
        boolean hasReacted = false;
    }

    @Override
    public void update(){
        super.update();
        scrollScreen();
    }
    //if player is lower than y threshold,
//    private boolean doesScreenScroll() {
//        return renderedY > yThreshold;
//    }

    private void scrollScreen(){
//        if (doesScreenScroll()) {
//            yOffset = player.renderedY - yThreshold;
//            player.renderedY = yThreshold;
//        }
//        else renderedY += getVelocity().y;
    }
}
