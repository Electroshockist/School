package electroshockist.finalassignmentdownwell;

import android.util.Log;

//2d vector class for readability
public class Vector2 {
    public float x, y;

    public Vector2() {
        this(0,0);
    }

    public Vector2(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public void print(String tag, String name){
        Log.v(tag, name + ": " + Float.toString(x) + ", " + Float.toString(y));
    }
}
