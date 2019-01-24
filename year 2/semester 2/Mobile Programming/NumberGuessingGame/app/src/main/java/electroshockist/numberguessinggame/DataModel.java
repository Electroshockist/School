package electroshockist.numberguessinggame;

import java.util.Random;

public class DataModel {
    private int num1, num2, highest;
    Random r = new Random();

    public DataModel() {
        this.num1 = r.nextInt(10);
        this.num2 = r.nextInt(10);
        highest = Math.max(num1, num2);
    }

    public void setNum1(int num1) {
        this.num1 = r.nextInt(10);
    }

    public void setNum2(int num2) {
        this.num2 = r.nextInt(10);
    }

    public void setHighest(int highest) {
        this.highest = highest;
    }

    public int getNum1() {
        return num1;
    }

    public int getNum2() {
        return num2;
    }

    public int getHighest() {
        return highest;
    }
}
