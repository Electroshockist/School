package electroshockist.finalassignmentdownwell;

import android.graphics.Canvas;
import android.graphics.Color;
import android.util.Log;

public class World {
    private EntityManager entityManager;

    public World(GameView gameView) {

        entityManager = new EntityManager(gameView);
    }

    public void onDraw(Canvas canvas) {
        if (canvas != null) {
            canvas.drawColor(Color.BLACK);

            entityManager.updateEntities(canvas);

            entityManager.drawObjects(canvas);

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
}
