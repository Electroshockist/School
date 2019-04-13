package electroshockist.finalassignmentdownwell;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.media.MediaPlayer;
import android.text.Layout;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class GameView extends SurfaceView{

    private GameThread gameThread;

    private float yOffset;

    private List<Entity> entities;
    private List<Block> blocks;

    public GameView(Context context) {
        super(context);

        gameThread = new GameThread(this);

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
            canvas.drawColor(Color.WHITE);

            Block block;
            //loop through first set of entities
            for (int i = 0; i < blocks.size(); i++) {
                block = blocks.get(i);

                //check each entity against the first set
                for (int j = 0; j < blocks.size(); j++) {

                    //do not check self
                    if (i != j) {
                        //do collision response if colliding
                        entities.interCollision(blocks.get(j));
                    }
                }

                entity.onDraw(canvas);

            }



            Entity entity;

            //loop through first set of entities
            for (int i = 0; i < entities.size(); i++) {
                entity = entities.get(i);

                //check each entity against the first set
                for (int j = 0; j < entities.size(); j++) {

                    //do not check self
                    if (i != j) {
                        entity.interCollision((Entity)(BaseObject)blocks.get(j));
                        //do collision response if colliding
                        entity.interCollision(entities.get(j));
                    }
                }

                entity.onDraw(canvas);

            }
            //loop through first set of entities
            for (int i = 0; i < entities.size(); i++) {
                entity = entities.get(i);

                //check each entity against the first set
                for (int j = 0; j < entities.size(); j++) {

                    //do not check self
                    if (i != j) {
                        //do collision response if colliding
                        entity.interCollision(entities.get(j));
                    }
                }

                entity.onDraw(canvas);

            }


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
    }

    //shortform
    public Bitmap DecodeBitmap(int drawable){
        return  BitmapFactory.decodeResource(getResources(), drawable);
    }
}
