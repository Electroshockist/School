package electroshockist.finalassignmentdownwell.Collisions;

import android.util.Log;

import java.util.ArrayList;
import java.util.List;

public class CollisionList{
    //a list of four lists of collisions
    public List<List<Collision>> collisions;

    public CollisionList(){
        collisions = new ArrayList<>(4);
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());

        Log.v("panky", Integer.toString(collisions.size()));
    }

    public void addUnique(Collision collision){
        //check if collision of same type exists
        if(isCollisionTypeActive(collision.collisionType)) {
            //for each collision of the same type, check if id matches
            for (int i = 0; i < collisions.get(collision.collisionType.ordinal()).size(); i++) {
                //if collision with same type and id already exists, return
                if (collision.id == collisions.get(collision.collisionType.ordinal()).get(i).id) return;
            }
        }

        //add new collision to respective list
        collisions.get(collision.collisionType.ordinal()).add(collision);
    }

    public void remove(Collision collision){
        if (isCollisionTypeActive(collision.collisionType)) collisions.get(collision.collisionType.ordinal()).remove(collision);
    }

    public boolean isCollisionTypeActive(CollisionType collisionType){
        //return false if no collisions exist
        if (collisions.isEmpty()) return false;
        //return false list collisions of same type is empty
        if (collisions.get(collisionType.ordinal()).size() > 0) return true;
        return false;
    }

}
