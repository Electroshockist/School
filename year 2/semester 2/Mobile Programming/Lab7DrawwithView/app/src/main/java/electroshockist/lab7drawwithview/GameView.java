package electroshockist.lab7drawwithview;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.view.View;

public class GameView extends View {
    private Bitmap duck, avocado;
    public GameView(Context context){
        super(context);
        duck = BitmapFactory.decodeResource(getResources(),R.drawable.duck);
        avocado = BitmapFactory.decodeResource(getResources(),R.drawable.avocado);
    }

    protected void onDraw(Canvas canvas){
        canvas.drawColor(Color.BLACK);
        canvas.drawBitmap(duck,10,10,null);
        canvas.drawBitmap(avocado,500,1000,null);
    }

}
