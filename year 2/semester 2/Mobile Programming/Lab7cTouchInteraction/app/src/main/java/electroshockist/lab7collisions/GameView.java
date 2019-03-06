package electroshockist.lab7collisions;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class GameView extends SurfaceView{
    private SurfaceHolder holder;

    private Image[] entities = new Image[2];

    private GameThread gameThread;

    public GameView(Context context) {
        super(context);

        entities[0] = new Image(BitmapFactory.decodeResource(getResources(),R.drawable.dvd),550,100, 5,10);
        entities[1] = new Image(BitmapFactory.decodeResource(getResources(),R.drawable.duck),100,1000, -2,10);

        gameThread = new GameThread(this);

        holder = getHolder();

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
    protected void onDraw(Canvas canvas){
        if(canvas != null){
            canvas.drawColor(Color.WHITE);
            Log.v("debugger", Float.toString(entities[0].position[0]));

            for(int i = 0; i < entities.length; i++){
                entities[i].onDraw(canvas);
                entities[i].Physics(canvas);
                entities[i].Move();
            }
            entities[0].interImageCollision(entities[1]);
            entities[1].interImageCollision(entities[0]);

        }
    }


}
