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

    World world;

    public GameView(Context context) {
        super(context);

        world = new World(this);

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
        world.onDraw(canvas);
    }
}
