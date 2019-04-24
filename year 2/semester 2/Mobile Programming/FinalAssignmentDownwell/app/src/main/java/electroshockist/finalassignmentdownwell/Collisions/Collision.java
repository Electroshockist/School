package electroshockist.finalassignmentdownwell.Collisions;

//collisions hold a collisiontype, a name and an object id
public class Collision {
    public CollisionType collisionType;
    public String name;
    public int objectID;

    public Collision(CollisionType collisionType, String name, int objectID) {
        this.collisionType = collisionType;
        this.name = name;
        this.objectID = objectID;
    }

    public boolean doesEqual(Collision collision){
        if (name.equals(collision.name) &&
            collisionType == collision.collisionType &&
            objectID == collision.objectID){
            return true;
        }
        else return false;
    }

    public String debugString() {
        return name + "\t" + collisionType.name() + "\t" + objectID;
    }
}
