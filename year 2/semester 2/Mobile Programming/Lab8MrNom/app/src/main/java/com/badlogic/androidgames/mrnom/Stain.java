package com.badlogic.androidgames.mrnom;

public class Stain {
    public enum Type{
        NORMAL, BLUE, RED
    }
    public static final int VARIANT_1 = 0;
    public static final int VARIANT_2 = 1;
    public static final int VARIANT_3 = 2;
    public static final int VARIANT_4 = 3;
    public static final int VARIANT_5 = 4;

    public int x, y;
    public int type;

    public Stain(int x, int y, int type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }
}
