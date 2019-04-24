package electroshockist.finalassignmentdownwell;

import android.graphics.Canvas;
import android.graphics.Color;
import android.util.Log;

import electroshockist.finalassignmentdownwell.Gameobjects.BaseObject;
import electroshockist.finalassignmentdownwell.Gameobjects.Dirt;
import electroshockist.finalassignmentdownwell.Gameobjects.Player;

import static electroshockist.finalassignmentdownwell.ScreenVariables.*;

public class World {
    private EntityManager entityManager;
    private GameView view;
    private boolean initializedWithCanvas = false;


    public World(GameView gameView) {
        this.view = gameView;
        yThreshold = 200;
        screenPos = 0;
        tilesPerScreenWidth = 9;
        tileSize = 16;

        entityManager = new EntityManager();
    }

    private void initializeWithCanvas(Canvas canvas) { //scale to 9 objects horizontally
        screenWidth = canvas.getWidth();
        entityManager.setGlobalScale((float) canvas.getWidth() / (tilesPerScreenWidth * tileSize));
        initializeEntities();
        initializedWithCanvas = true;
    }

    private void initializeEntities(){
        entityManager.add(new Player(view, new Vector2(5, 0)));
        entityManager.add(new Dirt(view, new Vector2(0, 3)));
        entityManager.add(new Dirt(view, new Vector2(1, 3)));
        entityManager.add(new Dirt(view, new Vector2(2, 3)));
        entityManager.add(new Dirt(view, new Vector2(3, 3)));
        entityManager.add(new Dirt(view, new Vector2(4, 3)));
        entityManager.add(new Dirt(view, new Vector2(5, 3)));
        entityManager.add(new Dirt(view, new Vector2(6, 3)));
        entityManager.add(new Dirt(view, new Vector2(7, 3)));
        entityManager.add(new Dirt(view, new Vector2(8, 3)));
        entityManager.add(new Dirt(view, new Vector2(9, 3)));

        for (BaseObject b :
                entityManager.getBaseObjects()) {
            Log.v("lel", Integer.toString(b.getId()));
        }
    }

    public void onDraw(Canvas canvas) {
        if (canvas != null) {
            //wait for canvas bounds to be set
            if (!initializedWithCanvas) {
                initializeWithCanvas(canvas);
            }

            canvas.drawColor(Color.BLACK);

            entityManager.updateEntities(canvas);

            scrollScreen();

            entityManager.drawObjects(canvas, screenPos);

//            //point/lose text
//            Paint paint = new Paint();
//            paint.setColor(Color.BLACK);
//            paint.setTextSize(200);
//
//            if (totalPoints >= 0) {
//                canvas.drawText("Points: " + pointsAsString, canvas.getWidth() / 2 - 500, 300, paint);
//            }
//            else {
//                canvas.drawText("You Lose!", canvas.getWidth() / 2 - 500, 300, paint);
//            }


        } else Log.e("Canvas Error", "Could not get suitable canvas to draw game");
    }

    private void scrollScreen() {
        if (entityManager.player.renderedY > yThreshold) {
            screenPos += entityManager.player.renderedY - yThreshold;
        }
    }

    public void onPress(){
        entityManager.player.onPress();
    }

    public void onRelease(){

    }
}
