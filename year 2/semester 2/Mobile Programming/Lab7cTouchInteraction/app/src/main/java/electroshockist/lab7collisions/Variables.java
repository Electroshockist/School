package electroshockist.lab7collisions;

public enum Variables {
    ENEMYIMAGE(R.drawable.dvd), FRIENDLYIMAGE(R.drawable.duck);

    private int id;

    Variables(int id) {
        this.id = id;
    }

    public int getID() { return id; }

}
