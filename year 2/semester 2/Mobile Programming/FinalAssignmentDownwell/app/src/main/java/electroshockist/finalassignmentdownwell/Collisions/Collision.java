package electroshockist.finalassignmentdownwell.Collisions;


//collisions hold a collisiontype and an id
public class Collision {
    public CollisionType collisionType;
    public String id;

    public Collision(String id, CollisionType collisionType) {
        this.id = id;
        this.collisionType = collisionType;
    }
}
