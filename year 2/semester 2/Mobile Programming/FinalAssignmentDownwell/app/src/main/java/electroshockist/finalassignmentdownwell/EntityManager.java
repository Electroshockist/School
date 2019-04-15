package electroshockist.finalassignmentdownwell;

import android.graphics.Canvas;

import java.util.ArrayList;
import java.util.List;

import electroshockist.finalassignmentdownwell.Gameobjects.BaseObject;
import electroshockist.finalassignmentdownwell.Gameobjects.Entity;
import electroshockist.finalassignmentdownwell.Gameobjects.Player;

public class EntityManager {

    private float yOffset, yThreshold;

    private List<BaseObject> baseObjects;

    public List<BaseObject> getBaseObjects() {
        return baseObjects;
    }

    public EntityManager(GameView gameView){
        yOffset = 0;
        yThreshold = 200;

        baseObjects = new ArrayList<>();

        baseObjects.add(playerFactory(gameView));
    }

    public void add(BaseObject baseObject){
        baseObjects.add(baseObject);
    }
    
    public void drawObjects(Canvas canvas){
        for (BaseObject baseObject : baseObjects) { baseObject.onDraw(canvas);}
    }

    public void updateEntities(Canvas canvas){
        if(baseObjects.size() > 0) {
            Entity entity;
            //loop through first set of entities
            for (int i = 0; i < baseObjects.size(); i++) {
                entity = (Entity)baseObjects.get(i);

                //check each entity-wall collision
                entity.WallCollisions(canvas);

                //check each entity against the first set
                for (int j = 0; j < baseObjects.size(); j++) {

                    //do not check self
                    if (i != j) {
                        //inter-sprite collision
                        entity.InterCollision(baseObjects.get(j));
                    }
                }

                entity.update();
            }

        }
        scrollScreen();
    }

    private Player playerFactory(GameView gameView){
        return new Player(gameView.DecodeBitmap(R.drawable.gun2),new Vector2(500, 0), 4);
    }

    public Player getPlayer(){
        for (BaseObject baseObject : baseObjects) {
            if (baseObject instanceof Player){
                return (Player)baseObject;
            }
        }
        return null;
    }



}
