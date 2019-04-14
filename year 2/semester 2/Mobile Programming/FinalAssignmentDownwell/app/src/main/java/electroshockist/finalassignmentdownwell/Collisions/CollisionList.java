package electroshockist.finalassignmentdownwell.Collisions;

import android.util.Log;

import java.util.ArrayList;
import java.util.List;

public class CollisionList{
    //a list of four lists of collisions
    public List<List<Collision>> collisions;

    public CollisionList(){
        collisions = new ArrayList<>(4);
    }

    public void addUnique(Collision collision){
        //if collision already exists, return
        for (int i = 0; i < collisions.get(collision.collisionType.ordinal()).size(); i++) {
            if(collision.id == collisions.get(collision.collisionType.ordinal()).get(i).id) return;
        }

        //add new collision to respective list
        collisions.get(collision.collisionType.ordinal()).add(collision);
    }

    public void remove(Collision collision){
        collisions.get(collision.collisionType.ordinal()).remove(collision);
    }

    public boolean isCollisionTypeActive(CollisionType collisionType){
        if (collisions.size() == 0) return false;
        if (collisions.get(collisionType.ordinal()).size() > 0) return true;
        return false;
    }

}
