package electroshockist.finalassignmentdownwell.Collisions;

import android.util.Log;

import java.util.ArrayList;
import java.util.List;

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

    public void addUnique(Collision collision) {
        //check if collision of same type exists
        if (isCollisionTypeActive(collision.collisionType)) {
            //for each collision of the same type, check if id matches
            for (int i = 0; i < collisions.get(collision.collisionType.ordinal()).size(); i++) {
                Collision currentCollision = collisions.get(collision.collisionType.ordinal()).get(i);
                //if collision with same type and id already exists, return
                if (collision.name.equals(currentCollision.name))
                    return;
            }
        }

        //add new collision to respective list
        collisions.get(collision.collisionType.ordinal()).add(collision);
    }

    public void remove(Collision collision) {
        if (isCollisionTypeActive(collision.collisionType)) {
            List<Collision> currentCollisions = collisions.get(collision.collisionType.ordinal());
            //print();
            for (int i = 0; i < currentCollisions.size(); i++) {
                boolean condition = currentCollisions.get(i).name.equals(collision.name);
                //Log.v(debugTag, " \n" + currentCollisions.get(i).debugString() + " = \n" + collision.debugString() + "\n" + Boolean.toString(condition));

                if (condition) {
                    currentCollisions.remove(i);
                }

            }
        }
    }

    public void removeAll() {
        for (int i = 0; i < collisions.size(); i++) {
            collisions.get(i).clear();
        }
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
