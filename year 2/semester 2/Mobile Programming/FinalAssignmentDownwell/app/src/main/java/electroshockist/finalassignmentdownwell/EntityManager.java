package electroshockist.finalassignmentdownwell;

import android.graphics.Canvas;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;

import electroshockist.finalassignmentdownwell.Gameobjects.BaseObject;
import electroshockist.finalassignmentdownwell.Gameobjects.Entity;
import electroshockist.finalassignmentdownwell.Gameobjects.Player;

public class EntityManager {

    private List<BaseObject> baseObjects;

    public List<BaseObject> getBaseObjects() {
        return baseObjects;
    }

    public Player player;

    private float globalScale;

    public EntityManager(){
        baseObjects = new ArrayList<>();
    }

    public void add(BaseObject baseObject){
        if (globalScale > 0) baseObject.setScale(globalScale);
        baseObjects.add(baseObject);
    }

    public void add(Player player){
        add((BaseObject) player);
        this.player = player;
    }
    
    public void drawObjects(Canvas canvas, float screenPos){
        if (!baseObjects.isEmpty()) {
            //loop through all objects
            for (int i = 0; i < baseObjects.size(); i++) {
                BaseObject baseObject = baseObjects.get(i);
                //set screen position
                baseObject.renderedY = baseObject.getPosition().y - screenPos;

                //if object is off screen, remove object
                if (baseObject.renderedY + baseObject.bottom() < 0) {
                    baseObjects.remove(baseObject);
                }

                //draw object
                baseObject.onDraw(canvas);
            }
        }
    }

    public void updateEntities(Canvas canvas){
        if(baseObjects.size() > 0) {
            Entity entity;
            //loop through first set of entities
            for (int i = 0; i < baseObjects.size(); i++) {
                if(baseObjects.get(i) instanceof Entity) {
                    entity = (Entity) baseObjects.get(i);

                    //check each entity-wall collision
                    entity.WallCollisions(canvas);

                    //check each entity against each baseObject
                    for (int j = 0; j < baseObjects.size(); j++) {

                        //do not check self
                        if (entity != baseObjects.get(j)) {
                            //inter-sprite collision
                            entity.InterCollision(baseObjects.get(j));
                        }
                    }

                    entity.update();
                }
            }
//            player.getCollisionList().print();

        }
    }

    public void setGlobalScale(float globalScale) {
        this.globalScale = globalScale;

        for (BaseObject baseObject : baseObjects) {
            baseObject.setScale(globalScale);
        }
    }
}
