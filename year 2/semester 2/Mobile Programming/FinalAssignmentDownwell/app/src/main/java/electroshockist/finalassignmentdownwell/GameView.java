package electroshockist.finalassignmentdownwell;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DrawFilter;
import android.graphics.Paint;
import android.graphics.RectF;
import android.graphics.drawable.Drawable;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Filter;
import java.util.logging.LogRecord;

import electroshockist.finalassignmentdownwell.Gameobjects.Block;
import electroshockist.finalassignmentdownwell.Gameobjects.Entity;
import electroshockist.finalassignmentdownwell.Gameobjects.Player;

public class GameView extends SurfaceView{

    private GameThread gameThread;

    private float yOffset;

    private Player player;

    private List<Entity> entities;
    private List<Block> blocks;

    public GameView(Context context) {
        super(context);

        gameThread = new GameThread(this);

        player = playerFactory();

        entities = new ArrayList<>();
        blocks = new ArrayList<>();

        SurfaceHolder holder = getHolder();

        holder.addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(SurfaceHolder holder) {
                gameThread.setRunning(true);
                gameThread.start();

            }

            @Override
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

            }

            @Override
            public void surfaceDestroyed(SurfaceHolder holder) {
                boolean retry = true;
                gameThread.setRunning(false);

                while(retry){
                    try{
                        gameThread.join();
                        retry = false;
                    }
                    catch (InterruptedException e){
                        e.printStackTrace();
                    }
                }

            }
        });
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return super.onTouchEvent(event); // has to be returned by this method
    }

    @Override
    protected void onDraw(Canvas canvas){

        if (canvas != null) {
            canvas.drawColor(Color.BLACK);

            if(entities.size() > 0) {
                Entity entity;
                //loop through first set of entities
                for (int i = 0; i < entities.size(); i++) {
                    entity = entities.get(i);

                    //check each entity-wall collision
                    entity.WallCollisions(canvas);

                    //check each entity against the first set
                    for (int j = 0; j < entities.size(); j++) {

                        //do not check self
                        if (i != j) {
                            //inter-sprite collision
                            entity.InterCollision(entities.get(j));
                        }
                    }

                    entity.update(canvas);
                }

            }

            player.update(canvas);

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

        }
        else Log.e("Canvas Error", "Could not get suitable canvas to draw game");
    }

    //shortform
    public Bitmap DecodeBitmap(int drawable){
        return  BitmapFactory.decodeResource(getResources(), drawable);
    }

    private Player playerFactory(){
        return new Player(DecodeBitmap(R.drawable.gun2),new Vector2(500, 100), 4);
    }
}
