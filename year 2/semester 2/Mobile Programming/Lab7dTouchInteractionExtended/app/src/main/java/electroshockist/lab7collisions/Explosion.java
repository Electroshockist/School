package electroshockist.lab7collisions;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import java.util.List;

public class Explosion {
    //position vector
    private Vector2 position;

    //stores image
    private Bitmap image;

    private List<Explosion> tempList;

    private int lifeTime = 15;

    public Explosion(Bitmap image, Vector2 position, List<Explosion> tempList) {
        this.image = image;
        this.position = position;
        this.tempList = tempList;
    }

    void onDraw(Canvas canvas){
        Update();
        canvas.drawBitmap(image, position.x, position.y,null);
    }

    private void Update(){
        if(--lifeTime <= 0){
            tempList.remove(this);
        }
    }
}
