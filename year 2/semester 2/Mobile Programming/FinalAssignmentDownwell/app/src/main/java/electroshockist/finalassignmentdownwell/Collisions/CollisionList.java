package electroshockist.finalassignmentdownwell.Collisions;

public class CollisionList{
    public CollisionType[] collisionTypes = new CollisionType[4];

    public void addUnique(CollisionType collisionType){
        switch (collisionType){
            case LEFT:
                collisionTypes[0] = collisionType;
                break;
            case RIGHT:
                collisionTypes[1] = collisionType;
                break;
            case TOP:
                collisionTypes[2] = collisionType;
                break;
            case BOTTOM:
                collisionTypes[3] = collisionType;
                break;
        }

    }

    public boolean exists(CollisionType collisionType){
        for (int i = 0; i < collisionTypes.length; i++) {

            if (collisionType == collisionTypes[i]){
                return true;
            }
        }
        return false;
    }

}
