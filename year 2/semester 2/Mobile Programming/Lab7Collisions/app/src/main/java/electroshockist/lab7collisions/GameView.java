package electroshockist.lab7collisions;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.ArrayList;
import java.util.List;

public class GameView extends SurfaceView{
    private SurfaceHolder holder;

    private List<Image> entities = new ArrayList<>();

    private GameThread gameThread;

    boolean displayedThings = false;

    public GameView(Context context) {
        super(context);

        entities.add(new Image(BitmapFactory.decodeResource(getResources(),R.drawable.dvd),550,100, 5,10));
        entities.add(new Image(BitmapFactory.decodeResource(getResources(),R.drawable.duck),100,1000, -2,10));
        entities.add(new Image(BitmapFactory.decodeResource(getResources(),R.drawable.dvd),750,250, 5,-7));
        entities.add(new Image(BitmapFactory.decodeResource(getResources(),R.drawable.duck),400,1000, -2,10));
//        entities[4] = new Image(BitmapFactory.decodeResource(getResources(),R.drawable.dvd),250,250, 5,10);

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

            for(int i = 0; i < entities.size(); i++){
                entities.get(i).onDraw(canvas);
                entities.get(i).WallCollisions(canvas);

                for (int j = 0; j < entities.size(); j++) {
                    if(i!= j) {
                        if(!displayedThings) Log.v("lel", Integer.toString(i) + ", " + Integer.toString(j));
                        entities.get(i).detectedCollision(entities.get(j));
                    }
                }
                entities.get(i).Move();
            }
            displayedThings = true;
        }
    }


}
