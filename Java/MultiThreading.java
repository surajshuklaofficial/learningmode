class Counter {
    private int value = 0;

    public synchronized void incrementByOne() {
        value += 1;
    }

    public synchronized void incrementByTwo() {
        value += 2;
    }

    public int getValue() {
        return value;
    }
}

class IncrementByOneThread extends Thread {
    private Counter counter;

    public IncrementByOneThread(Counter counter) {
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            counter.incrementByOne();
            System.out.println("Thread 1: Incremented by 1. Current value: " + counter.getValue());
            try {
                Thread.sleep(100); // Sleep for a short time to simulate some work
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class IncrementByTwoThread extends Thread {
    private Counter counter;

    public IncrementByTwoThread(Counter counter) {
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            counter.incrementByTwo();
            System.out.println("Thread 2: Incremented by 2. Current value: " + counter.getValue());
            try {
                Thread.sleep(150); // Sleep for a short time to simulate some work
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class MultiThreading {
    public static void main(String[] args) {
        Counter sharedCounter = new Counter();

        IncrementByOneThread thread1 = new IncrementByOneThread(sharedCounter); // intialisation
        IncrementByTwoThread thread2 = new IncrementByTwoThread(sharedCounter);

        thread1.start();
        thread2.start();
    }
}
