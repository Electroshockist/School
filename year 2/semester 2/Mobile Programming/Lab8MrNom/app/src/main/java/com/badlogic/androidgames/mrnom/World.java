package com.badlogic.androidgames.mrnom;

import java.util.Random;

public class World {
    static final int WORLD_WIDTH = 10;
    static final int WORLD_HEIGHT = 13;
    static final int SCORE_INCREMENT = 10;
    static final int BLUE_SCORE_DECREMENT = -20;
    static final int RED_SIZE_DECREMENT = 5;
    static final float TICK_INITIAL = 0.5f;
    static final float TICK_DECREMENT = 0.05f;

    public Snake snake;
    public Stain stain;
    public boolean gameOver = false;;
    public int score = 0;

    int totalStains = 0;

    boolean fields[][] = new boolean[WORLD_WIDTH][WORLD_HEIGHT];
    Random random = new Random();
    float tickTime = 0;
    static float tick = TICK_INITIAL;

    public World() {
        snake = new Snake();
        placeStain(Stain.Type.NORMAL);
    }

    private void placeStain(Stain.Type type) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            for (int y = 0; y < WORLD_HEIGHT; y++) {
                fields[x][y] = false;
            }
        }

        int len = snake.parts.size();
        for (int i = 0; i < len; i++) {
            SnakePart part = snake.parts.get(i);
            fields[part.x][part.y] = true;
        }

        int stainX = random.nextInt(WORLD_WIDTH);
        int stainY = random.nextInt(WORLD_HEIGHT);
        while (true) {
            if (fields[stainX][stainY] == false)
                break;
            stainX += 1;
            if (stainX >= WORLD_WIDTH) {
                stainX = 0;
                stainY += 1;
                if (stainY >= WORLD_HEIGHT) {
                    stainY = 0;
                }
            }
        }
        if (totalStains != 0) {
            if (totalStains % 10 == 0) stain = new Stain(stainX, stainY, Stain.VARIANT_4);
            else if (totalStains % 5 == 0) stain = new Stain(stainX, stainY, Stain.VARIANT_5);
        }
        switch (type){
            case NORMAL:
                stain = new Stain(stainX, stainY, random.nextInt(3));
                break;
            case BLUE:
                stain = new Stain(stainX, stainY, Stain.VARIANT_4);
                break;
            case RED:
                stain = new Stain(stainX, stainY, Stain.VARIANT_5);
                break;
        }
        totalStains++;
    }

    public void update(float deltaTime) {
        if (gameOver)
            return;

        tickTime += deltaTime;

        while (tickTime > tick) {
            tickTime -= tick;
            //gameover if size is 0 or less
            if (snake.parts.size() <= 0){
                gameOver = true;
                return;
            }
            snake.advance();
            if (snake.checkBitten()) {
                gameOver = true;
                return;
            }

            SnakePart head = snake.parts.get(0);
            if (head.x == stain.x && head.y == stain.y) {
                if (stain.type == Stain.VARIANT_5){
                    for (int i = 0; i < RED_SIZE_DECREMENT; i++) {
                        snake.parts.remove(snake.parts.size()-1);
                    }
                }
                else {
                    if (stain.type == Stain.VARIANT_4){
                        score += BLUE_SCORE_DECREMENT;
                    }
                    else {
                        score += SCORE_INCREMENT;
                    }
                    snake.eat();
                }
                if (snake.parts.size() == WORLD_WIDTH * WORLD_HEIGHT) {
                    gameOver = true;
                    return;
                }

                else {
                    placeStain(Stain.Type.NORMAL);
                    if (totalStains % 10 == 0) placeStain(Stain.Type.BLUE);
                    else if (totalStains % 5 == 0) placeStain(Stain.Type.RED);
                }

                if (score % 100 == 0 && tick - TICK_DECREMENT > 0) {
                    tick -= TICK_DECREMENT;
                }
            }
        }
    }
}
