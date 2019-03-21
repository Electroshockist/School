package electroshockist.lab7collisions;

public class Variables {
    public enum ImageIDs {
        ENEMYIMAGE(R.drawable.dvd), FRIENDLYIMAGE(R.drawable.duck);

        private int id;

        ImageIDs(int id) {
            this.id = id;
        }

        public int getID() {
            return id;
        }
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

}
