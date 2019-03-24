package electroshockist.lab7collisions;

public class Variables {
    public enum ImageIDs {
        ENEMYIMAGE(R.drawable.dvd), FRIENDLYIMAGE(R.drawable.duck);

        private int id;

        ImageIDs(int id) {
            this.id = id;
        }

        public int getID() { return id; }
    }

    public enum SoundIDs {
        ENEMYSOUND(R.raw.fortnite), FRIENDLYSOUND(R.raw.roblox);

        private int id;

        SoundIDs(int id) {
            this.id = id;
        }

        public int getID() {
            return id;
        }
    }

    //hold Explosion animations
    public enum  Explosions{
        ENEMYEXPLOSION(
                R.drawable.enemyexplosion0,
                R.drawable.enemyexplosion1,
                R.drawable.enemyexplosion2,
                R.drawable.enemyexplosion3,
                R.drawable.enemyexplosion4,
                R.drawable.enemyexplosion5,
                R.drawable.enemyexplosion6,
                R.drawable.enemyexplosion7),
        FRIENDLYEXPLOSION(
                R.drawable.friendlyexplosion0,
                R.drawable.friendlyexplosion1,
                R.drawable.friendlyexplosion2,
                R.drawable.friendlyexplosion3,
                R.drawable.friendlyexplosion4,
                R.drawable.friendlyexplosion5,
                R.drawable.friendlyexplosion6,
                R.drawable.friendlyexplosion7)
        ;

        private int[] ids;

        Explosions(int... ids) { this.ids = ids; }

        public int[] getIds() {
            return ids;
        }
    }
}
