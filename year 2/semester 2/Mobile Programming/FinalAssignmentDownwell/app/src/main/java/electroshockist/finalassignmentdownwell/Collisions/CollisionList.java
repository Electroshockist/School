package electroshockist.finalassignmentdownwell.Collisions;

import android.util.Log;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class CollisionList {
    String debugTag = "Collisions";
    //a list of four lists of collisions
    public List<List<Collision>> collisions;

    public CollisionList() {
        collisions = new ArrayList<>(4);
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());
        collisions.add(new ArrayList<Collision>());
    }

    public void addUnique(Collision collision){
        List<Collision> currentList =  collisions.get(collision.collisionType.ordinal());
        //check if collision of same type exists
        if(isCollisionTypeActive(collision.collisionType)) {
            //for each collision of the same type, check if id matches
            for (int i = 0; i < currentList.size(); i++) {
                //if collision with same type and id already exists, return
                if (collision.objectID == currentList.get(i).objectID) return;
            }
        }

        //add new collision to respective list
        collisions.get(collision.collisionType.ordinal()).add(collision);
    }

    public void remove(Collision collision){
        List<Collision> currentList =  collisions.get(collision.collisionType.ordinal());
        Collision currentItem;
        for (int i = 0; i < currentList.size(); i++) {

            currentItem = currentList.get(i);

            //Log.v("lel","Initial size: " + Integer.toString(collisions.get(collision.collisionType.ordinal()).size()) );
            if (currentItem.doesEqual(collision)) {

                collisions.get(collision.collisionType.ordinal()).remove(i);

                //Log.v("lel", "New size" + Integer.toString(collisions.get(collision.collisionType.ordinal()).size()) );

                return;
            }
        }
        if (isCollisionTypeActive(collision.collisionType)) {

            //Log.v("lel", Boolean.toString(collisions.get(collision.collisionType.ordinal()).contains(collision)));
        }

    }

    public void removeAllOfID(int id) {

//        Collision currentCollision;
//        for (int i = 0; i < collisions.size(); i++) {
//            if (collisions.get(collision.collisionType.ordinal()))
//        }
    }

    public boolean isCollisionTypeActive(CollisionType collisionType) {
        //return false if no collisions exist
        if (collisions.isEmpty()) return false;
        //return false list collisions of same type is empty
        if (collisions.get(collisionType.ordinal()).size() > 0) return true;
        return false;
    }

    public void print() {
        if (collisions.isEmpty()) {
            Log.v(debugTag, "No Collisions");
            return;
        }
        Log.v(debugTag, "Name:\t\t\tType:\tObject ID:");
        for (int i = 0; i < collisions.size(); i++) {
            for (int j = 0; j < collisions.get(i).size(); j++) {
                Collision currentCollision = collisions.get(i).get(j);
                Log.v(debugTag, currentCollision.debugString());
            }
        }
    }


}
