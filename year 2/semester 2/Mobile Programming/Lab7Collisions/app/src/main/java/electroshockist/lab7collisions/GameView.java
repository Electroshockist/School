package electroshockist.lab7collisions;

import android.content.Context;
import android.graphics.Bitmap;
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

    public GameView(Context context) {
        super(context);

        //istantiate 5 entities
        entities.add(new Image(DecodeBitmap(R.drawable.dvd),200,1000, 2,-1));
        entities.add(new Image(DecodeBitmap(R.drawable.duck),700,1000, -3,1));
        entities.add(new Image(DecodeBitmap(R.drawable.dvd),750,250, 5,-7));
        entities.add(new Image(DecodeBitmap(R.drawable.duck),400,1000, -2,-10));
        entities.add(new Image(DecodeBitmap(R.drawable.duck),100,1500, 5,-2));

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

            //loop through first set of entities
            for(int i = 0; i < entities.size(); i++){
                entities.get(i).onDraw(canvas);

                //check each entity against the first set
                for (int j = 0; j < entities.size(); j++) {

                    //do not check self
                    if (i != j) {
                        //do collision response if colliding
                        entities.get(i).interImageCollision(entities.get(j));
                    }
                }
                entities.get(i).WallCollisions(canvas);
                entities.get(i).Move();
            }
        }
    }

    //shortform
    private Bitmap DecodeBitmap(int drawable){
        return  BitmapFactory.decodeResource(getResources(), drawable);
    }


}
