package electroshockist.finalassignmentdownwell.Collisions;

//collisions hold a collisiontype, a name and an object id
public class Collision {
    public CollisionType collisionType;
    public String name;

    public Collision(CollisionType collisionType, String name) {
        this.collisionType = collisionType;
        this.name = name;
    }

    public String debugString() {
        return name + "\t" + collisionType.name();
    }
}
